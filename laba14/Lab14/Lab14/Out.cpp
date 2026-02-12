#include "stdafx.h"


namespace Out {

	OUT getOut(wchar_t outFile[])
	{
		OUT out = INITOUT;//инициализирует структуру OUT начальными значениями

		out.stream = new ofstream(outFile);//открывает файл 

		if (!out.stream)
			throw ERROR_THROW(112);

		return out;
	};
	//записывает содержимое in.text в выходной поток out.
	void WriteOut(OUT out, In::IN in) {

		if ((*out.stream).is_open()) {
			(*out.stream) << in.text;
		}
	}
	//записывает информацию об ошибке в выходной поток out.
	void WriteError(OUT out, Error::ERROR error) {
		if (error.id != 100)
		{
			(*out.stream) << "Ошибка " << error.id << ": " << error.message << " "
				<< "строка " << error.inext.line << ", позиция: " << error.inext.col << std::endl;
		}
	}

	void Close(OUT out)
	{
		out.stream->close();
	}
}