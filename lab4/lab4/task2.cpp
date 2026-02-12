#include <iostream>
#include <string>

using namespace std;

typedef string Type;
typedef string CPU;
typedef string GPU;
typedef int RAM;
typedef int Memory;
typedef string Camera;
typedef string Data;


struct Discipline {

    Type type;
    CPU CPU;
    GPU GPU;
    RAM numOfRAM;
    Memory numOfMemory;
    Camera camera;
    Data data;
};

ostream& operator<<(ostream& os, const Discipline& discipline) {
    os << "Тип компьютера : " << discipline.type << endl;
    os << "Процессор: " << discipline.CPU << endl;
    os << "Видеокарта: " << discipline.GPU << endl;
    os << "Размер ОЗУ(ГБ): " << discipline.numOfRAM << endl;
    os << "Размер жесткого диска(ГБ): " << discipline.numOfMemory << endl;
    os << "Наличие камеры(да/нет): " << discipline.camera << endl;
    os << "Дата приобретения: " << discipline.data << endl;
    return os;
}

bool operator<(const Discipline& discipline1, const Discipline& discipline2) {
    return discipline1.numOfMemory < discipline2.numOfMemory;
}


int main() {
    setlocale(LC_ALL, "rus");
    Discipline  discipline1 = { "ПК", "AMD Ryzen 5600", "AMD Radeon 5700xt", 16, 1000, "нет", "12 03 2022"};
    Discipline  discipline2 = { "Ноутбук", "Intel Core i5-9400f", "Nvidia geforce rtx 3060" , 36, 500, "нет", "30 01 2019"};

    cout << "Информация о компьютере 1:" << endl;
    cout << discipline1 << endl;
    cout << "Информация о компьютере 2:" << endl;
    cout << discipline2 << endl;

    if (discipline1 < discipline2) {
        cout << "Компьютер 1 имеет меньший размер жесткого диска." << endl;
    }
    else {
        cout << "Компьютер 2 имеет меньший размер жесткого диска." << endl;
    }
    return 0;
}
