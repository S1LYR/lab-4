#include "Money.h"
#include <iostream>
#include <limits>
#include <string>
#include <cstdlib>

using namespace std;

Money::Money() : rubles(0), kopeks(0) {}


Money::Money(unsigned int r, short int k) : rubles(r), kopeks(k) {
    normalize();
}

void Money::normalize() {
    if (kopeks >= 100) {
        rubles += kopeks / 100;
        kopeks = kopeks % 100;
    }
    else if (kopeks < 0) {
        rubles -= (abs(kopeks) / 100) + 1;
        kopeks = 100 - abs(kopeks) % 100;
    }
    if (rubles < 0) rubles = 0;  
}

Money& Money::operator++() {
    ++kopeks;
    normalize();  
    return *this;
}

Money& Money::operator--() {
    if (kopeks == 0 && rubles == 0) {
        cout << "Îøèáêà: îòðèöàòåëüíîå êîëè÷åñòâî äåíåã!" << endl;
        return *this;
    }
    if (kopeks == 0) {
        --rubles;
        kopeks = 99;
    }
    else {
        --kopeks;
    }
    normalize();  // Ïðîñòî íîðìàëèçóåì áåç âûâîäà
    return *this;
}

// Îïåðàöèÿ äîáàâëåíèÿ êîïååê ê îáúåêòó Money
Money Money::operator+(unsigned int kopeksToAdd) const {
    Money result = *this;
    result.kopeks += kopeksToAdd;
    result.normalize();
    return result;
}

// Îïåðàöèÿ âû÷èòàíèÿ êîïååê èç îáúåêòà Money
Money Money::operator-(unsigned int kopeksToSubtract) const {
    Money result = *this;
    if (result.kopeks < kopeksToSubtract) {
        if (result.rubles == 0) {
            cout << "Îøèáêà: íåäîñòàòî÷íî ñðåäñòâ äëÿ âû÷èòàíèÿ!" << endl;
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

// Îïåðàöèÿ ÿâíîãî ïðèâåäåíèÿ ê unsigned int (òîëüêî ðóáëè)
Money::operator unsigned int() const {
    return rubles;
}

// Îïåðàöèÿ íåÿâíîãî ïðèâåäåíèÿ ê double (êîïåéêè â ðóáëè)
Money::operator double() const {
    return kopeks / 100.0;
}

// Âûâîä Money íà ýêðàí
void Money::display() const {
    cout << rubles << " ðóá. " << kopeks << " êîï." << endl;
}

// Ìåòîä äëÿ ââîäà äàííûõ ñ êëàâèàòóðû
void Money::input() {
    string input;
    cout << "Ââåäèòå êîëè÷åñòâî ðóáëåé: ";
    while (true) {
        cin >> input;

        // Ïðîâåðÿåì, ÷òî ââîä ñîñòîèò òîëüêî èç öèôð
        bool valid = true;
        for (char c : input) {
            if (!isdigit(c)) {
                valid = false;
                break;
            }
        }

        if (valid) {
            try {
                rubles = stoul(input); // Ïðåîáðàçóåì ñòðîêó â unsigned int
                break;
            }
            catch (invalid_argument& e) {
                cout << "Îøèáêà: ââåäèòå ïîëîæèòåëüíîå öåëîå ÷èñëî äëÿ ðóáëåé!" << endl;
            }
            catch (out_of_range& e) {
                cout << "Îøèáêà: ÷èñëî ñëèøêîì âåëèêî äëÿ òèïà unsigned int!" << endl;
            }
        }
        else {
            cout << "Îøèáêà: ââåäèòå ïîëîæèòåëüíîå öåëîå ÷èñëî äëÿ ðóáëåé!" << endl;
        }
    }

    cout << "Ââåäèòå êîëè÷åñòâî êîïååê: ";
    while (true) {
        cin >> input;

        // Ïðîâåðÿåì, ÷òî ââîä ñîñòîèò òîëüêî èç öèôð
        bool valid = true;
        for (char c : input) {
            if (!isdigit(c)) {
                valid = false;
                break;
            }
        }

        if (valid) {
            try {
                kopeks = stoi(input); // Ïðåîáðàçóåì ñòðîêó â short int
                break;
            }
            catch (invalid_argument& e) {
                cout << "Îøèáêà: ââåäèòå öåëîå ÷èñëî äëÿ êîïååê!" << endl;
            }
            catch (out_of_range& e) {
                cout << "Îøèáêà: ÷èñëî ñëèøêîì âåëèêî äëÿ òèïà short int!" << endl;
            }
        }
        else {
            cout << "Îøèáêà: ââåäèòå öåëîå ÷èñëî äëÿ êîïååê!" << endl;
        }
    }

    normalize();
}
