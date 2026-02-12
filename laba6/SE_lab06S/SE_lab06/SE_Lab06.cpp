#include <iostream>
#include <string>
#include <iomanip>
#include <windows.h>
#include "E:\study\kpo\laba6\SE_lab06S\SE_lab06L\Dictionary.h"
#pragma comment(lib, "D:/study/kpo/laba6/SE_lab06S/Debug/SE_lab06L.lib")


using namespace std;
using namespace dictionary;

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	try {
#ifdef TEST_CREATE_01
		Instance d1 = Create("Преподаватели,но сназванием, которое больше 20", 7);
#elif defined TEST_CREATE_02
		Instance d1 = Create("Преподаватели", 101);
#elif defined TEST_DICTIONARY
		Instance d1 = Create("Преподаватели", 6);
#elif !defined TEST_DICTIONARY
		Instance d1 = Create("Преподаватели", 7);
#endif

		Entry e1 = { 1, "Барковский" }, e2 = { 2, "Белодед" }, e3 = { 3, "Наркевич" }, e4 = { 4, "Шиман" }, e5 = { 5, "Чайковский" }, e6 = { 6, "Якубенко" }, e7 = { 7, "Север" }, e8 = { 3, "Докурно" };
		AddEntry(d1, e1);
		AddEntry(d1, e2);
		AddEntry(d1, e3);
		AddEntry(d1, e4);
		AddEntry(d1, e5);
		AddEntry(d1, e6);
#ifdef TEST_DICTIONARY
		AddEntry(d1, e7);
#elif defined TEST_ADDENTRY_03
		Entry e9 = { 12, "Валушко" }, e10 = { 21, "Валушко" };
		AddEntry(d1, e9);
		AddEntry(d1, e10);
#elif defined TEST_ADDENTRY_04
		AddEntry(d1, e8);
#endif

#ifdef TEST_DELENTRY_06
		DelEntry(d1, 25);
#elif defined TEST_DICTIONARY
		DelEntry(d1, 2);
#endif

#ifdef TEST_GETENTRY_05
		GetEntry(d1, 22);
#elif defined TEST_DICTIONARY
		DelEntry(d1, 4);
#endif

#ifdef TEST_UPDENTRY_07
		Entry newentry = { 16, "Смирнов" };
		UpdEntry(d1, 22, newentry);
#elif defined TEST_UPDENTRY_08
		Entry newentry = { 5, "Смирнов" };
		Dictionary::UpdEntry(d1, 1, newentry);
#elif defined TEST_DICTIONARY
		Entry newentry = { 16, "Смирнов" };
#endif	
#if defined TEST_DICTIONARY
		Dictionary::UpdEntry(d1, 3, newentry);
#endif

		Print(d1);
		Instance d2 = Create("Студенты", 7);
		Entry s1 = { 1, "Угоренко" }, s2 = { 8, "Бабич" }, s3 = { 3, "Лужецкий" }, s4 = { 4, "Касач" }, s5 = { 5, "Попович" }, s6 = { 6, "Закревский" }, s7 = { 7, "Шахнович" };
		AddEntry(d2, s1);
		AddEntry(d2, s2);
		AddEntry(d2, s3);
		AddEntry(d2, s4);
		AddEntry(d2, s5);
		AddEntry(d2, s6);
		AddEntry(d2, s7);
		Entry newentry2 = { 2, "Яскевич" };
		UpdEntry(d2, 8, newentry2);
		Print(d2);
		Delete(d1);
		Delete(d2);
	}
	catch (const char* e) {
		cout << e << endl;
	};
	system("pause");
	return 0;
}