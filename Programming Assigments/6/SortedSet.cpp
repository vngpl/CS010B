#include "SortedSet.h"

SortedSet::SortedSet() : IntList() { }
SortedSet::SortedSet(const SortedSet &cpy) : IntList(cpy) { }
SortedSet::SortedSet(const IntList &list) : IntList(list) { remove_duplicates(); selection_sort(); }
SortedSet::~SortedSet() { }

bool SortedSet::in(int value) const {
    IntNode *currNode = head;
    while (currNode != nullptr) {
        if (currNode->value == value) {
            return true;
        }
        currNode = currNode->next;
    }
    return false;
}

SortedSet SortedSet::operator|(const SortedSet &rhs) const { 
    SortedSet unionSet = *this;
    IntNode *currNode = rhs.head;

    while (currNode != nullptr) {
        if (!unionSet.in(currNode->value)) {
            unionSet.add(currNode->value);
        }
        currNode = currNode->next;
    }

    unionSet.remove_duplicates();
    unionSet.selection_sort();
    return unionSet;
}

SortedSet SortedSet::operator&(const SortedSet &rhs) const { 
    SortedSet intersectSet;
    IntNode *currNode = rhs.head;

    while (currNode != nullptr) {
        if (in(currNode->value) && rhs.in(currNode->value)) {
            intersectSet.add(currNode->value);
        }
        currNode = currNode->next;
    }

    intersectSet.selection_sort();
    return intersectSet;
}

void SortedSet::add(int value) {
    if (!in(value)) {
        IntList::insert_ordered(value); 
    }
}

void SortedSet::push_front(int value) { add(value); }
void SortedSet::push_back(int value) { add(value); }
void SortedSet::insert_ordered(int value) { add(value); }
SortedSet & SortedSet::operator|=(const SortedSet &rhs) { return *this = *this | rhs; }
SortedSet & SortedSet::operator&=(const SortedSet &rhs) { return *this = *this & rhs; }
