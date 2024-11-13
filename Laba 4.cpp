#include <iostream>
#include <limits>
#include "Money.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    Money m1;  // Создаем объект Money
    m1.input();  // Вводим данные с клавиатуры
    m1.display();  // Отображаем введенные данные

    unsigned int kopeksToAdd;
    cout << "Введите количество копеек для добавления: ";
    while (true) {
        cin >> kopeksToAdd;
        if (cin.fail() || kopeksToAdd < 0) {
            cout << "Ошибка: введите положительное целое число!" << endl;
            cin.clear();  // очищаем флаг ошибки
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // игнорируем неверный ввод
        }
        else {
            break;
        }
    }

    // Добавляем копейки и выводим результат
    cout << "Сумма::" << endl;

    m1 = m1 + kopeksToAdd;
    m1.display();

    // Унарная операция ++
    cout << "Унарная операция сложения(одна копейка):" << endl;
    ++m1;
    m1.display();  // После инкремента выводим результат

    // Унарная операция --
    cout << "Унарная операция вычитания(одна копейка):" << endl;

    --m1;
    m1.display();  // После декремента выводим результат

    // Ввод для вычитания копеек
    unsigned int kopeksToSubtract;
    cout << "Введите количество копеек для вычитания: ";
    while (true) {
        cin >> kopeksToSubtract;
        if (cin.fail() || kopeksToSubtract < 0) {
            cout << "Ошибка: введите положительное целое число!" << endl;
            cin.clear();  // очищаем флаг ошибки
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // игнорируем неверный ввод
        }
        else {
            break;
        }
    }

    // Вычитаем копейки и выводим результат
    m1 = m1 - kopeksToSubtract;
    m1.display();

    // Приведение к unsigned int (только рубли)
    unsigned int rub = static_cast<unsigned int>(m1);
    cout << "Только рубли (unsigned int): " << rub << endl;

    // Приведение к double (копейки в рубли)
    double kopeksInRubles = static_cast<double>(m1);
    cout << "Копейки, переведенные в рубли (double): " << kopeksInRubles << endl;

    return 0;
}
