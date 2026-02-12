#include <iostream>

#include "Lexer.h"
#include "Error.h"
#include "Parm.h"
#include "Log.h"
#include "LT.h"
#include "IT.h"
#include "In.h"

int _tmain(int argc, _TCHAR* argv[])
{
    setlocale(LC_ALL, "rus");

    Log::LOG log = Log::INITLOG;    //начальная инициализация LOG

    LT::LexTable lextable = LT::Create(LT_MAXSIZE);
    IT::IdTable idtable = IT::Create(TI_MAXSIZE);

    try
    {
        Parm::PARM parm = Parm::getparm(argc, argv);
        
        log = Log::getlog(parm.log);//создание поотока для записи
        Log::WriteLog(log);         //время создания
        Log::WriteParm(log, parm);
        
        In::IN in = In::getin(parm.in, parm.out);   //преобразование исходного текста
        
        Log::WriteLine(log, (char*)"-- Лесический анализ --\n", "");

        Lexer::Analyze(in, lextable, idtable);

        Log::WriteLine(log, (char*)"-- Результаты анализа --\n", "");

        Log::WriteLexTable(log, lextable);
        Log::WriteIdTable(log, idtable);

        Log::WriteLine(log, (char*)"Проблемы не найдены.", "");
        Log::Close(log);

        LT::Delete(lextable);
        IT::Delete(idtable);
    }

    catch (Error::ERROR e) 
    {
        std::cout << e.message << std::endl;
        Log::WriteError(log, e);

        LT::Delete(lextable);
        IT::Delete(idtable);

        Log::Close(log);
        return -2;
    }

    Log::Close(log);
    return 0;
}