#include <iostream>
#include <exception>
#include <stdexcept>
#include "Linklist.h"
using namespace std;

bool ascending(int x, int y)
{
    return x > y;
}

bool descending(int x, int y)
{
    return x < y;
}
template <typename T>
int Linklist<T>::size() const
{
    return n;
}

template <typename T>
T &Linklist<T>::operator[](int index) const
{
    if (index < 0 || index >= n || n == 0)
    {
        throw runtime_error("Invalid index of list!");
    }
    node<T> *current = begin;
    for (int i = 0; i < index; i++)
    {
        current = current->next;
    }
    return current->value;
}

template <typename T>
Linklist<T>::Linklist()
{
    begin = new node<T>;
    end = new node<T>;
    begin->next = end;
    end->next = NULL;
    n = 0;
}

template <typename T>
Linklist<T>::~Linklist()
{
    node<T> *current = begin;
    node<T> *tmp;
    for (int i = 0; i < n; i++)
    {
        tmp = current;
        current = current->next;
        delete tmp;
    }
    if (n == 0)
    {
        delete begin;
        delete end;
    }
    if (n == 1)
    {
        delete end;
    }
}

template <typename T>
void Linklist<T>::add(const T &x, int index)
{
    if (index < 0 || index > n)
    {
        throw runtime_error("Invalid index of list!");
    }
    if (index == 0 && n == 0)
    {
        begin->value = x;
        n += 1;
        return;
    }
    if (n == 1)
    {
        if (index == 1)
        {
            end->value = x;
            n += 1;
            return;
        }
        else
        {
            end->value = begin->value;
            begin->value = x;
            n += 1;
            return;
        }
    }
    if (index == 0)
    {
        node<T> *tmp = new node<T>;
        tmp->value = x;
        tmp->next = begin;
        begin = tmp;
        n += 1;
        return;
    }
    node<T> *current = begin;
    for (int i = 0; i < index - 1; i++)
    {
        current = current->next;
    }
    node<T> *tmp = new node<T>;
    tmp->value = x;
    tmp->next = current->next;
    current->next = tmp;
    if (current == end)
    {
        end = tmp;
    }
    n += 1;
    return;
}

template <typename T>
void Linklist<T>::add(const T &x)
{
    int index = n;
    if (index == 0 && n == 0)
    {
        begin->value = x;
        n += 1;
        return;
    }
    if (n == 1)
    {
        if (index == 1)
        {
            end->value = x;
            n += 1;
            return;
        }
        else
        {
            end->value = begin->value;
            begin->value = x;
            n += 1;
            return;
        }
    }
    if (index == 0)
    {
        node<T> *tmp = new node<T>;
        tmp->value = x;
        tmp->next = begin;
        begin = tmp;
        n += 1;
        return;
    }
    node<T> *current = begin;
    for (int i = 0; i < index - 1; i++)
    {
        current = current->next;
    }
    node<T> *tmp = new node<T>;
    tmp->value = x;
    tmp->next = current->next;
    current->next = tmp;
    if (current == end)
    {
        end = tmp;
    }
    n += 1;
    return;
}

template <typename T>
Linklist<T>::Linklist(const Linklist &l)
{
    begin = new node<T>;
    end = new node<T>;
    begin->next = end;
    end->next = NULL;
    n = 0;
    node<T> *current = l.begin;
    for (int i = 0; i < l.n; i++)
    {
        this->add(current->value);
        current = current->next;
    }
}

template <typename T>
void Linklist<T>::operator=(const Linklist &l)
{
    begin = new node<T>;
    end = new node<T>;
    begin->next = end;
    end->next = NULL;
    n = 0;
    node<T> *current = l.begin;
    for (int i = 0; i < l.n; i++)
    {
        this->add(current->value);
        current = current->next;
    }
}

template <typename T>
void Linklist<T>::removex(const T &x)
{
    if (n == 0)
    {
        throw runtime_error("Error remove from empty list!");
        return;
    }
    node<T> *current = begin;
    for (int i = 0; i < n; i++)
    {
        if (current->value == x)
        {
            break;
        }
    }
    node<T> *tmp;
    while (current != end)
    {
        current->value = current->next->value;
        tmp = current;
        current = current->next;
    }
    if (n <= 2)
    {
        n -= 1;
        return;
    }
    else
    {
        end = tmp;
        end->next = NULL;
        delete current;
        n -= 1;
        return;
    }
}

template <typename T>
void Linklist<T>::remove(int index) // xoa phan tu o vi tri x
{
    if (n == 0 || index < 0 || index >= n)
    {
        throw runtime_error("Invalid index of list!");
    }
    node<T> *current = begin;
    for (int i = 0; i < index; i++)
    {
        current = current->next;
    }
    node<T> *tmp;
    while (current != end)
    {
        current->value = current->next->value;
        tmp = current;
        current = current->next;
    }
    if (n <= 2)
    {
        n -= 1;
        return;
    }
    else
    {
        end = tmp;
        end->next = NULL;
        delete current;
        n -= 1;
        return;
    }
}

template <typename T>
ostream &operator<<(ostream &out, const Linklist<T> &l)
{
    if (l.n == 0)
    {
        out << "The list is empty " << endl;
        return out;
    }
    out << "[";
    node<T> *current = l.begin;
    for (int i = 0; i < l.n; i++)
    {
        if (i == l.n - 1)
        {
            out << *(current->value) << "]";
        }
        else
        {
            out << *(current->value) << " , ";
        }
        current = current->next;
    }
    out << endl;
    return out;
}

template <typename T>
void Linklist<T>::sort(bool compfunc(int, int))
{
    for (int i = 1; i < n; i++)
    {
        node<T> *current = begin;
        for (int j = 0; j < n - i; j++)
        {
            if (compfunc(current->value, current->next->value))
            {
                int tmp = current->value;
                current->value = current->next->value;
                current->next->value = tmp;
            }
            current = current->next;
        }
    }
}
