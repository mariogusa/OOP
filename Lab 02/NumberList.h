#ifndef NUMBERLIST_H
#define NUMBERLIST_H

class NumberList {
    int numbers[10];
    int count;
public:
    void Init();          // count will be 0
    bool Add(int x);      // adds x to the list; if count >= 10, returns false
    void Sort();          // sorts the numbers array
    void Print();         // prints the current list
};

#endif // NUMBERLIST_H