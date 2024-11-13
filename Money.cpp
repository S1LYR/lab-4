#include "Money.h"
#include <iostream>
#include <limits>
#include <string>
#include <cstdlib>

using namespace std;

// ����������� �� ���������
Money::Money() : rubles(0), kopeks(0) {}

// ����������� � �����������
Money::Money(unsigned int r, short int k) : rubles(r), kopeks(k) {
    normalize();
}

// ������������ (���� ������ ������ 100 ��� ������ 0, ��������� � �����)
void Money::normalize() {
    if (kopeks >= 100) {
        rubles += kopeks / 100;
        kopeks = kopeks % 100;
    }
    else if (kopeks < 0) {
        rubles -= (abs(kopeks) / 100) + 1;
        kopeks = 100 - abs(kopeks) % 100;
    }
    if (rubles < 0) rubles = 0;  // ���������� ������ �� ����� ���� ������ ����
}

// �������� ���������� �������
Money& Money::operator++() {
    ++kopeks;
    normalize();  // ������ ����������� ��� ������
    return *this;
}

// �������� ��������� �������
Money& Money::operator--() {
    if (kopeks == 0 && rubles == 0) {
        cout << "������: ������������� ���������� �����!" << endl;
        return *this;
    }
    if (kopeks == 0) {
        --rubles;
        kopeks = 99;
    }
    else {
        --kopeks;
    }
    normalize();  // ������ ����������� ��� ������
    return *this;
}

// �������� ���������� ������ � ������� Money
Money Money::operator+(unsigned int kopeksToAdd) const {
    Money result = *this;
    result.kopeks += kopeksToAdd;
    result.normalize();
    return result;
}

// �������� ��������� ������ �� ������� Money
Money Money::operator-(unsigned int kopeksToSubtract) const {
    Money result = *this;
    if (result.kopeks < kopeksToSubtract) {
        if (result.rubles == 0) {
            cout << "������: ������������ ������� ��� ���������!" << endl;
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

// �������� ������ ���������� � unsigned int (������ �����)
Money::operator unsigned int() const {
    return rubles;
}

// �������� �������� ���������� � double (������� � �����)
Money::operator double() const {
    return kopeks / 100.0;
}

// ����� Money �� �����
void Money::display() const {
    cout << rubles << " ���. " << kopeks << " ���." << endl;
}

// ����� ��� ����� ������ � ����������
void Money::input() {
    string input;
    cout << "������� ���������� ������: ";
    while (true) {
        cin >> input;

        // ���������, ��� ���� ������� ������ �� ����
        bool valid = true;
        for (char c : input) {
            if (!isdigit(c)) {
                valid = false;
                break;
            }
        }

        if (valid) {
            try {
                rubles = stoul(input); // ����������� ������ � unsigned int
                break;
            }
            catch (invalid_argument& e) {
                cout << "������: ������� ������������� ����� ����� ��� ������!" << endl;
            }
            catch (out_of_range& e) {
                cout << "������: ����� ������� ������ ��� ���� unsigned int!" << endl;
            }
        }
        else {
            cout << "������: ������� ������������� ����� ����� ��� ������!" << endl;
        }
    }

    cout << "������� ���������� ������: ";
    while (true) {
        cin >> input;

        // ���������, ��� ���� ������� ������ �� ����
        bool valid = true;
        for (char c : input) {
            if (!isdigit(c)) {
                valid = false;
                break;
            }
        }

        if (valid) {
            try {
                kopeks = stoi(input); // ����������� ������ � short int
                break;
            }
            catch (invalid_argument& e) {
                cout << "������: ������� ����� ����� ��� ������!" << endl;
            }
            catch (out_of_range& e) {
                cout << "������: ����� ������� ������ ��� ���� short int!" << endl;
            }
        }
        else {
            cout << "������: ������� ����� ����� ��� ������!" << endl;
        }
    }

    normalize();
}
