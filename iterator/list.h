#pragma once

#include <initializer_list>

template <typename T> class FullSpan;
template <typename T> class NotZero;

template <typename T>
class List {
    T* m_tab = nullptr;
    int m_size = 0;
public:
    List(std::initializer_list<T> l) { 
        m_tab = new T[l.size()]; m_size = l.size();
        auto i = 0;
        for (auto it = l.begin(); it < l.end(); it++, i++) {
            m_tab[i] = *it;
        }
    }
    inline int getSize() const { return m_size; }
    inline T& operator[](int i) { return m_tab[i]; }
    inline FullSpan<T> getFullSpan() { return FullSpan<T>(*this); }
    inline NotZero<T> getNotZero() { return NotZero<T>(*this); }
};