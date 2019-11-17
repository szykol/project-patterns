#pragma once

#include "list.h"


template <typename T>
class FullSpan {
    List<T>& m_parent;
    int m_idx = 0;
public:
    FullSpan(List<T>& parent) : m_parent(parent) {}
    inline T& First() const { m_parent[0]; }
    inline T& Next() { return m_parent[++m_idx]; }
    inline T& CurrentItem() { return m_parent[m_idx]; }
    inline bool IsDone() { return m_idx == m_parent.getSize() + 1; }
};

template <typename T>
class NotZero {
    List<T>& m_parent;
    int m_idx = 0;
public:
    NotZero(List<T>& parent) : m_parent(parent) {}
    inline T& First() const { m_parent[0]; }
    inline void Next() { 
        while(m_idx <= m_parent.getSize() + 1)
        {
            m_idx++;
            if(m_parent[m_idx] != 0)
                break;
        }
    }
    inline T& CurrentItem() {
        if (m_parent[m_idx] == 0) {
            Next();
        } 
        return m_parent[m_idx];
    }
    inline bool IsDone() { return m_idx >= m_parent.getSize() + 1; }
};