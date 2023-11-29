#ifndef __SORTEDSET_H__
#define __SORTEDSET_H__

#include "IntList.h"

class SortedSet : public IntList {
    public:
        SortedSet();
        SortedSet(const SortedSet &);
        SortedSet(const IntList &);
        ~SortedSet();
        bool in(int) const;
        SortedSet operator|(const SortedSet &) const;
        SortedSet operator&(const SortedSet &) const;
        void add(int);
        void push_front(int);
        void push_back(int);
        void insert_ordered(int);
        SortedSet & operator|=(const SortedSet &);
        SortedSet & operator&=(const SortedSet &);
};

#endif