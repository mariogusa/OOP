#ifndef NUMBER_H
#define NUMBER_H

class Number {
private:
    char* value;
    int base;
    int digits;

    int charToDigit(char c) const;
    char digitToChar(int d) const;
    int toBase10() const;
    void fromBase10(int num);

public:
    Number(const char* value, int base);
    Number(int num);
    ~Number();

    Number(const Number& other);
    Number& operator=(const Number& other);
    Number(Number&& other) noexcept;
    Number& operator=(Number&& other) noexcept;

    friend Number operator+(const Number& a, const Number& b);
    friend Number operator-(const Number& a, const Number& b);
    Number& operator+=(const Number& other);
    Number& operator-=(const Number& other);

    friend bool operator>(const Number& a, const Number& b);
    friend bool operator<(const Number& a, const Number& b);
    friend bool operator>=(const Number& a, const Number& b);
    friend bool operator<=(const Number& a, const Number& b);
    friend bool operator==(const Number& a, const Number& b);
    friend bool operator!=(const Number& a, const Number& b);

    char operator[](int index) const;

    Number& operator--();
    Number operator--(int);

    Number& operator=(int num);
    Number& operator=(const char* str);

    void SwitchBase(int newBase);
    void Print();
    int GetDigitsCount() const;
    int GetBase() const;
};

#endif