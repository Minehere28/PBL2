#include <iostream>
#include <exception>
using namespace std;

#ifndef LINKLIST_H
#define LINKLIST_H

bool ascending(int x, int y);
bool descending(int x, int y);

template <typename T>
class node
{
public:
    T value;
    node<T> *next;
};

template <typename T>
class Linklist
{
    node<T> *begin;
    node<T> *end;
    int n;

public:
    Linklist();
    ~Linklist();
    Linklist(const Linklist &);
    void add(const T &, int);
    void add(const T &);
    void removex(const T &);
    void remove(int);
    T &operator[](int) const;
    void operator=(const Linklist<T> &);
    template <typename U>
    friend ostream &operator<<(ostream &, const Linklist<U> &);
    void sort(bool compFunc(int, int) = ascending);
    int size() const;
};

#endif