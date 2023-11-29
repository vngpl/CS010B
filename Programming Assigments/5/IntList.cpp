#include "IntList.h"

IntList::IntList() : head(nullptr), tail(nullptr) { }

IntList::IntList(const IntList &cpy) {
    this->head = nullptr;
    this->tail = nullptr;

    if (cpy.head != nullptr) {
        IntNode *currNode = cpy.head;

        while (currNode != nullptr) {
            push_back(currNode->value);
            currNode = currNode->next;
        }
    }
}

IntList::~IntList() { clear(); }

void IntList::clear() {
    while (!empty()) {
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

void IntList::push_back(int val) {
    if (empty()) {
        this->head = this->tail = new IntNode(val);
    }
    else {
        this->tail = this->tail->next = new IntNode(val);
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

void IntList::selection_sort() {
    IntNode *i = this->head;

    while (i != nullptr) {
        IntNode *minNode = i;
        IntNode *nextNode = i->next;

        while (nextNode != nullptr) {
            if (nextNode->value < minNode->value) {
                minNode = nextNode;
            }
            nextNode = nextNode->next;
        }

        swap(i->value, minNode->value);

        i = i->next;
    }
}

void IntList::insert_ordered(int val) {
    if (empty() || val <= this->head->value) {
        push_front(val);
    }
    else if (val >= this->tail->value) {
        push_back(val);
    }
    else {
        IntNode *insertNode = new IntNode(val);
        IntNode *currNode = this->head;
        IntNode *nextNode = currNode->next;

        while (nextNode != nullptr) {
            if (val <= nextNode->value) {
                insertNode->next = nextNode;
                currNode->next = insertNode;
                break;
            }
            else {
                nextNode = nextNode->next;
                currNode = currNode->next;
            }
        }
    }
}

void IntList::remove_duplicates() {
    IntNode *i = this->head;

    while (i != nullptr) {
        IntNode *prevNode = i;
        IntNode *nextNode = i->next;

        while (nextNode != nullptr) {
            if (nextNode->value == i->value) {
                prevNode->next = nextNode->next;

                if (this->tail == nextNode) {
                    this->tail = prevNode;
                }

                delete nextNode;
                nextNode = prevNode->next;
            }
            else {
                prevNode = nextNode;
                nextNode = nextNode->next;
            }
        }
        i = i->next;
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

IntList & IntList::operator=(const IntList &rhs) {
    if (this != &rhs) {
        clear();

        if (rhs.head != nullptr) {
            IntNode *currNode = rhs.head;

            while (currNode != nullptr) {
                push_back(currNode->value);
                currNode = currNode->next;
            }
        }
    }
    return *this;
}

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