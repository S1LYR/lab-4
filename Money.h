#ifndef MONEY_H
#define MONEY_H

struct Money {
    unsigned int rubles;  // ���������� ������
    short int kopeks;     // ���������� ������

    // ����������� �� ���������
    Money();

    // ����������� � �����������
    Money(unsigned int r, short int k);

    // ������������ (���� ������ ������ 100 ��� ������ 0, ��������� � �����)
    void normalize();

    // �������� ���������� �������
    Money& operator++();

    // �������� ��������� �������
    Money& operator--();

    // �������� ���������� ������ � ������� Money
    Money operator+(unsigned int kopeksToAdd) const;

    // �������� ��������� ������ �� ������� Money
    Money operator-(unsigned int kopeksToSubtract) const;

    // �������� ������ ���������� � unsigned int (������ �����)
    explicit operator unsigned int() const;

    // �������� �������� ���������� � double (������� � �����)
    operator double() const;

    // ����� Money �� �����
    void display() const;

    // ����� ��� ����� ������ � ����������
    void input();
};

#endif // MONEY_H
