#include "IntList.h"

IntList::IntList() : head(nullptr), tail(nullptr) { }
IntList::~IntList() { clear(); }

void IntList::clear() {
    while (this->head) {
        IntNode *nextNode = this->head->next;
        delete head;
        head = nextNode;
    }
    head = nullptr;
    tail = nullptr;
}

void IntList::push_front(int val) {
    if (empty()) {
        this->head = this->tail = new IntNode(val);
    }
    else {
        IntNode *temp = new IntNode(val);
        temp->next = this->head;
        this->head = temp;
    }
}

void IntList::pop_front() {
    if (empty()) {
        return;
    }
    else {
        IntNode *temp = this->head;
        this->head = this->head->next;

        if (empty()) {
            this->tail = nullptr;
        }

        delete temp;
    }
}

bool IntList::empty() const {
    if (this->head == nullptr) {
        return true;
    }
    return false;
}

const int & IntList::front() const { return this->head->value; }
const int & IntList::back() const { return this->tail->value; }

ostream & operator<<(ostream &out, const IntList &list) {
    IntNode *currNode = list.head;

    while (currNode != nullptr) {
        if (currNode->next == nullptr) {
            out << currNode->value;
        }
        else {
            out << currNode->value << " ";
        }
        currNode = currNode->next;
    }

    return out;
}