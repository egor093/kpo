#include "Call.h"
using namespace std;
using namespace Call;
namespace Call {
	int a;
	int _cdecl cdeclf(int a, int b, int c) {
		return a + b + c;
	}
	int _stdcall stdcallf(int& a, int b, int c) {
		return  a * b * c;
	}
	int _fastcall fastcallf(int a, int b, int c, int d){
		return a + b + c + d;
	}
}

int main() {
	int z = 4;
	int& x = z;
	int result_cdecl = cdeclf(2, 6, 8);
	int result_stdcallf = stdcallf(x, 5, 3);
	int result_fastcallf = fastcallf(2, 9, 5, 1);
	cout << result_cdecl << endl;
	cout << result_stdcallf << endl;
	cout << result_fastcallf << endl;
}