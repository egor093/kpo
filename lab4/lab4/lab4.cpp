//#include <iostream>
//#include <string>
//using namespace std;
//
//typedef unsigned char day;
//typedef unsigned char month;
//typedef unsigned short year;
//
//struct  Date
//{
//	day dd;
//	month mm;
//	year yyyy;
//};
//
//bool operator==(Date d1, Date d2)
//{
//	return ((d1.yyyy == d2.yyyy) && (d1.mm == d2.mm) && (d1.dd == d2.dd));
//}
//
//bool operator>(Date d1, Date d2)
//{
//	return ((d1.yyyy > d2.yyyy) || ((d1.yyyy == d2.yyyy) && (d1.mm > d2.mm)) || ((d1.yyyy == d2.yyyy) && (d1.mm == d2.mm) && (d1.dd > d2.dd)));
//}
//
//bool operator<(Date d1, Date d2)
//{
//	return ((d1.yyyy < d2.yyyy) || ((d1.yyyy == d2.yyyy) && (d1.mm < d2.mm)) || ((d1.yyyy == d2.yyyy) && (d1.mm == d2.mm) && (d1.dd < d2.dd)));
//}
//
//int main()
//{
//	setlocale(LC_ALL, "rus");
//
//	Date date1 = { 7,1,1980 };
//	Date date2 = { 7,2,1993 };
//	Date date3 = { 7,1,1980 };
//
//	if (date1 < date2)
//		cout << "Истина" << endl;
//	else
//		cout << "Ложь" << endl;
//
//	if (date1 > date2)
//		cout << "Истина" << endl;
//	else
//		cout << "Ложь" << endl;
//
//	if (date1 == date2)
//		cout << "Истина" << endl;
//	else
//		cout << "Ложь" << endl;
//
//	if (date1 == date3)
//		cout << "Истина" << endl;
//	else
//		cout << "Ложь" << endl;
//
//	return 0;
//}