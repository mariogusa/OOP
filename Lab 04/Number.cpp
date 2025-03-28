#include "Number.h"
#include <cstring>
#include <algorithm>
#include <stdexcept>

using namespace std;

int Number::charToDigit(char c) const {
    if (c >= '0' && c <= '9')
        return c - '0';
    if (c >= 'A' && c <= 'F')
        return 10 + (c - 'A');
    if (c >= 'a' && c <= 'f')
        return 10 + (c - 'a');
    return -1;
}

char Number::digitToChar(int d) const {
    if (d >= 0 && d <= 9)
        return '0' + d;
    if (d >= 10 && d <= 15)
        return 'A' + (d - 10);
    return '\0';
}

int Number::toBase10() const {
    int decimal = 0;
    for (int i = 0; i < digits; ++i)
        decimal = decimal * base + charToDigit(value[i]);
    return decimal;
}

void Number::fromBase10(int num) {
    if (num == 0) {
        delete[] value;
        value = new char[2]{'0', '\0'};
        digits = 1;
        return;
    }

    int temp = abs(num);
    int len = 0;
    while (temp > 0) {
        temp /= base;
        len++;
    }

    temp = abs(num);
    char* newValue = new char[len + 1];
    newValue[len] = '\0';

    for (int i = len - 1; i >= 0; --i) {
        newValue[i] = digitToChar(temp % base);
        temp /= base;
    }

    if (num < 0) {
        char* tempValue = new char[len + 2];
        tempValue[0] = '-';
        strcpy(tempValue + 1, newValue);
        delete[] newValue;
        newValue = tempValue;
        len++;
    }

    delete[] value;
    value = newValue;
    digits = len;
}

Number::Number(const char* value, int base) : base(base) {
    if (base < 2 || base > 16)
        throw invalid_argument("Invalid base");

    for (int i = 0; value[i] != '\0'; ++i)
        if (charToDigit(value[i]) >= base)
            throw invalid_argument("Invalid digit for base");

    digits = strlen(value);
    this->value = new char[digits + 1];
    strcpy(this->value, value);
}

Number::Number(int num) : base(10) {
    fromBase10(num);
}

Number::~Number() {
    delete[] value;
}

Number::Number(const Number& other) : base(other.base), digits(other.digits) {
    value = new char[digits + 1];
    strcpy(value, other.value);
}

Number& Number::operator=(const Number& other) {
    if (this != &other) {
        delete[] value;
        base = other.base;
        digits = other.digits;
        value = new char[digits + 1];
        strcpy(value, other.value);
    }
    return *this;
}

Number::Number(Number&& other) noexcept : base(other.base), digits(other.digits), value(other.value) {
    other.value = nullptr;
    other.base = 0;
    other.digits = 0;
}

Number& Number::operator=(Number&& other) noexcept {
    if (this != &other) {
        delete[] value;
        base = other.base;
        digits = other.digits;
        value = other.value;
        other.value = nullptr;
        other.base = 0;
        other.digits = 0;
    }
    return *this;
}

Number operator+(const Number& a, const Number& b) {
    int sum = a.toBase10() + b.toBase10();
    Number result("0", max(a.base, b.base));
    result.fromBase10(sum);
    return result;
}

Number operator-(const Number& a, const Number& b) {
    int diff = a.toBase10() - b.toBase10();
    Number result("0", max(a.base, b.base));
    result.fromBase10(diff);
    return result;
}

Number& Number::operator+=(const Number& other) {
    *this = *this + other;
    return *this;
}

Number& Number::operator-=(const Number& other) {
    *this = *this - other;
    return *this;
}

bool operator>(const Number& a, const Number& b) {
    return a.toBase10() > b.toBase10();
}

bool operator<(const Number& a, const Number& b) {
    return a.toBase10() < b.toBase10();
}

bool operator>=(const Number& a, const Number& b) {
    return a.toBase10() >= b.toBase10();
}

bool operator<=(const Number& a, const Number& b) {
    return a.toBase10() <= b.toBase10();
}

bool operator==(const Number& a, const Number& b) {
    return a.toBase10() == b.toBase10();
}

bool operator!=(const Number& a, const Number& b) {
    return a.toBase10() != b.toBase10();
}

char Number::operator[](int index) const {
    if (index < 0 || index >= digits)
        throw out_of_range("Index out of range");
    return value[index];
}

Number& Number::operator--() {
    if (digits <= 1) {
        *this = Number("0", base);
        return *this;
    }

    char* newValue = new char[digits];
    strcpy(newValue, value + 1);
    delete[] value;
    value = newValue;
    digits--;
    return *this;
}

Number Number::operator--(int) {
    Number temp(*this);
    if (digits <= 1) {
        *this = Number("0", base);
    } else {
        char* newValue = new char[digits];
        strncpy(newValue, value, digits - 1);
        newValue[digits - 1] = '\0';
        delete[] value;
        value = newValue;
        digits--;
    }
    return temp;
}

Number& Number::operator=(int num) {
    fromBase10(num);
    return *this;
}

Number& Number::operator=(const char* str) {
    for (int i = 0; str[i] != '\0'; ++i)
        if (charToDigit(str[i]) >= base)
            throw invalid_argument("Invalid digit for base");

    delete[] value;
    digits = strlen(str);
    value = new char[digits + 1];
    strcpy(value, str);
    return *this;
}

void Number::SwitchBase(int newBase) {
    if (newBase < 2 || newBase > 16)
        throw invalid_argument("Invalid base");

    int num = toBase10();
    base = newBase;
    fromBase10(num);
}

void Number::Print() {
    printf("%s\n", value);
}

int Number::GetDigitsCount() const {
    return digits;
}

int Number::GetBase() const {
    return base;
}