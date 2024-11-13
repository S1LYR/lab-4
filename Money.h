#ifndef MONEY_H
#define MONEY_H

struct Money {
    unsigned int rubles;  // количество рублей
    short int kopeks;     // количество копеек

    // Конструктор по умолчанию
    Money();

    // Конструктор с параметрами
    Money(unsigned int r, short int k);

    // Нормализация (если копеек больше 100 или меньше 0, переводим в рубли)
    void normalize();

    // Операция добавления копейки
    Money& operator++();

    // Операция вычитания копейки
    Money& operator--();

    // Операция добавления копеек к объекту Money
    Money operator+(unsigned int kopeksToAdd) const;

    // Операция вычитания копеек из объекта Money
    Money operator-(unsigned int kopeksToSubtract) const;

    // Операция явного приведения к unsigned int (только рубли)
    explicit operator unsigned int() const;

    // Операция неявного приведения к double (копейки в рубли)
    operator double() const;

    // Вывод Money на экран
    void display() const;

    // Метод для ввода данных с клавиатуры
    void input();
};

#endif // MONEY_H
