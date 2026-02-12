#pragma once
#include<iostream>
namespace Call {
	int _cdecl cdeclf(int, int, int);
	int _stdcall stdcallf(int&, int, int);
	int _fastcall fastcallf(int, int, int, int);

}