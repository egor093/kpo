#pragma once
#pragma once
#include "stdafx.h"
#include "In.h"

namespace Out {

	struct OUT//структура хранит информацию о выходном файле.
	{
		wchar_t outFile[PARM_MAX_SIZE];//Массив для хранения имени выходного файла
		std::ofstream* stream; //Указатель на выходной поток для записи в выходной файл
	};

	static const OUT INITOUT{ L"", NULL };					// начальные данные для выходного потока
	OUT getOut(wchar_t outFile[]);							// создание выходного потока
	void WriteOut(OUT out, In::IN in);						// вывод обработанного текста в выходной файл
	void WriteError(OUT out, Error::ERROR error);			// вывод ошибки в выходной файл
	void Close(OUT out);									// закрытие выходного потока
}