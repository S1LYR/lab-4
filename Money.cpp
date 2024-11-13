#include "Money.h"
#include <iostream>
#include <limits>
#include <string>
#include <cstdlib>

using namespace std;

// Конструктор по умолчанию
Money::Money() : rubles(0), kopeks(0) {}

// Конструктор с параметрами
Money::Money(unsigned int r, short int k) : rubles(r), kopeks(k) {
    normalize();
}

// Нормализация (если копеек больше 100 или меньше 0, переводим в рубли)
void Money::normalize() {
    if (kopeks >= 100) {
        rubles += kopeks / 100;
        kopeks = kopeks % 100;
    }
    else if (kopeks < 0) {
        rubles -= (abs(kopeks) / 100) + 1;
        kopeks = 100 - abs(kopeks) % 100;
    }
    if (rubles < 0) rubles = 0;  // Количество рублей не может быть меньше нуля
}

// Операция добавления копейки
Money& Money::operator++() {
    ++kopeks;
    normalize();  // Просто нормализуем без вывода
    return *this;
}

// Операция вычитания копейки
Money& Money::operator--() {
    if (kopeks == 0 && rubles == 0) {
        cout << "Ошибка: отрицательное количество денег!" << endl;
        return *this;
    }
    if (kopeks == 0) {
        --rubles;
        kopeks = 99;
    }
    else {
        --kopeks;
    }
    normalize();  // Просто нормализуем без вывода
    return *this;
}

// Операция добавления копеек к объекту Money
Money Money::operator+(unsigned int kopeksToAdd) const {
    Money result = *this;
    result.kopeks += kopeksToAdd;
    result.normalize();
    return result;
}

// Операция вычитания копеек из объекта Money
Money Money::operator-(unsigned int kopeksToSubtract) const {
    Money result = *this;
    if (result.kopeks < kopeksToSubtract) {
        if (result.rubles == 0) {
            cout << "Ошибка: недостаточно средств для вычитания!" << endl;
            return result;
        }
        result.rubles -= 1;
        result.kopeks = 100 + result.kopeks - kopeksToSubtract;
    }
    else {
        result.kopeks -= kopeksToSubtract;
    }
    result.normalize();
    return result;
}

// Операция явного приведения к unsigned int (только рубли)
Money::operator unsigned int() const {
    return rubles;
}

// Операция неявного приведения к double (копейки в рубли)
Money::operator double() const {
    return kopeks / 100.0;
}

// Вывод Money на экран
void Money::display() const {
    cout << rubles << " руб. " << kopeks << " коп." << endl;
}

// Метод для ввода данных с клавиатуры
void Money::input() {
    string input;
    cout << "Введите количество рублей: ";
    while (true) {
        cin >> input;

        // Проверяем, что ввод состоит только из цифр
        bool valid = true;
        for (char c : input) {
            if (!isdigit(c)) {
                valid = false;
                break;
            }
        }

        if (valid) {
            try {
                rubles = stoul(input); // Преобразуем строку в unsigned int
                break;
            }
            catch (invalid_argument& e) {
                cout << "Ошибка: введите положительное целое число для рублей!" << endl;
            }
            catch (out_of_range& e) {
                cout << "Ошибка: число слишком велико для типа unsigned int!" << endl;
            }
        }
        else {
            cout << "Ошибка: введите положительное целое число для рублей!" << endl;
        }
    }

    cout << "Введите количество копеек: ";
    while (true) {
        cin >> input;

        // Проверяем, что ввод состоит только из цифр
        bool valid = true;
        for (char c : input) {
            if (!isdigit(c)) {
                valid = false;
                break;
            }
        }

        if (valid) {
            try {
                kopeks = stoi(input); // Преобразуем строку в short int
                break;
            }
            catch (invalid_argument& e) {
                cout << "Ошибка: введите целое число для копеек!" << endl;
            }
            catch (out_of_range& e) {
                cout << "Ошибка: число слишком велико для типа short int!" << endl;
            }
        }
        else {
            cout << "Ошибка: введите целое число для копеек!" << endl;
        }
    }

    normalize();
}
