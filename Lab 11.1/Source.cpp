#include <iostream>
#include <fstream>
#include <string>
using namespace std;
void CreateBIN(char* fname) // створення файлу символів з введених рядків
{
    ofstream fout(fname, ios::binary); // відкрили файл для запису
    char ch; // відповідь користувача – чи продовжувати введення
    int n;
    cout << "Enter number of elements: "; cin >> n;
    double* s = new double[n]; // введений користувачем рядок
    do
    {
        cin.get(); // очищуємо буфер клавіатури – щоб не було символу
        cin.sync(); // "кінець рядка", який залишився після вводу числа
        cout << "enter line: ";
        for (unsigned i = 0; i < n; i++) {
            cin >> s[i];// ввели рядок
            fout.write((char*)&s[i], sizeof(s[i]));
        }// записали символ у файл
        cout << "continue? (y/n): "; cin >> ch;
    } while (ch == 'y' || ch == 'Y');
    cout << endl;
}
void PrintBIN(char* fname) // виведення файлу на екран
{
    ifstream fin(fname, ios::binary); // відкрили файл для зчитування
    double c; // прочитаний символ
    while (fin.read((char*)&c, sizeof(c))) // поки можна прочитати символ
    {
        cout << c << endl; // виводимо його на екран
    }
    cout << endl;
}
void ProcessBIN(char* fname, char* gname) // переписати із файлу f
{ // у файл g символи-цифри
    ifstream f(fname, ios::binary); // відкрили файл для зчитування
    ofstream g(gname, ios::binary); // відкрили файл для запису
    double c; // прочитаний символ
    while (f.read((char*)&c, sizeof(c))) // поки можна прочитати символ
    {
        if (c < 0)
            g.write((char*)&c, sizeof(c)); // записуємо його у файл g
    }
}

int main()
{
    // binary files
    char fname[100]; // ім'я першого файлу
    cout << "enter file name 1: "; cin >> fname;
    CreateBIN(fname); // ввели рядки файлу з клавіатури
    PrintBIN(fname); // вивели вміст першого файлу на екран
    char gname[100]; // ім'я другого файлу
    cout << "enter file name 2: "; cin >> gname;
    ProcessBIN(fname, gname);
    PrintBIN(gname); // вивели вміст другого файлу на екран

    return 0;
}