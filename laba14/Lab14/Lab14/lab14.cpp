#include "stdafx.h"  // Включение стандартных заголовочных файлов

int _tmain(int argc, _TCHAR* argv[])
{
    // Инициализация аргументов командной строки
    argc = 1;
    argv[0] = (_TCHAR*)L"-in:E:\\study\\kpo\\laba14\\Lab14\\Lab14\\in.txt.txt";//первый аргумент как путь к входному файлу

    setlocale(LC_ALL, "Rus");  

    // Инициализация логирования и выходных данных
    Log::LOG log = Log::INITLOG;
    Out::OUT out = Out::INITOUT;

    try
    {
        // Получение параметров из аргументов командной строки
        Parm::PARM parm = Parm::getparm(argc, argv);

        // Инициализация логирования и выходных данных на основе полученных параметров
        log = Log::getlog(parm.log);
        out = Out::getOut(parm.out);

        // Запись начальной информации в лог
        Log::WriteLog(log);
        Log::WriteParm(log, parm);

        // Чтение входного файла и обработка данных
        In::IN in = In::getin(parm.in); // возвращает структуру IN с обработанными данными.
        Log::WriteIn(log, in); // Запись обработанных данных во входной лог
        Out::WriteOut(out, in); // Запись обработанных данных в выходной файл

        // Закрытие логирования и выходных данных
        Log::Close(log);
        Out::Close(out);
    }
    catch (Error::ERROR e)
    {
        // Обработка ошибок: запись ошибки в лог и выходной файл
        Log::WriteError(log, e);
        Out::WriteError(out, e);
    }

    return 0;
}
