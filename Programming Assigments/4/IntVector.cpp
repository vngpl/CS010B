#include "IntVector.h"

IntVector::IntVector(unsigned capacity, int value) {
    _capacity = capacity;
    _size = capacity;

    if (capacity == 0) {
        _data = nullptr;
    } 
    else {
        _data = new int[capacity];
        for (unsigned i = 0; i < capacity; ++i) {
            _data[i] = value;
        }
    }
}

IntVector::~IntVector() {
    delete[] _data;
    _data = nullptr;
}

unsigned IntVector::size() const { return _size; }
unsigned IntVector::capacity() const { return _capacity; }

bool IntVector::empty() const {
    if (_size == 0) {
        return true;
    }
    return false;
}

const int & IntVector::at(unsigned index) const {
    if (index >= _size) {
        throw out_of_range("IntVector::at_range_check");
    }
    return _data[index];
}

int & IntVector::at(unsigned index) {
    if (index >= _size) {
        throw out_of_range("IntVector::at_range_check");
    }
    return _data[index];
}

void IntVector::insert(unsigned index, int value) {
    if (index > _size) {
        throw out_of_range("IntVector::insert_range_check");
    }
    
    if (_size + 1 > _capacity) {
        expand();
    }

    _size += 1;

    for (unsigned i = index; i < _size; ++i) {
        _data[i + 1] = _data[i];
    }

    _data[index] = value;
}

void IntVector::erase(unsigned index) {
    if (index >= _size) {
        throw out_of_range("IntVector::erase_range_check");
    }

    for (unsigned i = index; i < _size - 1; ++i) {
        _data[i] = _data[i + 1];
    }

    _size -= 1;
}

const int & IntVector::front() const {
    if (_size == 0) {
        throw out_of_range("IntVector::front_range_check");
    }
    return _data[0];     
}

int & IntVector::front() {
    if (_size == 0) {
        throw out_of_range("IntVector::front_range_check");
    }
    return _data[0]; 
}

const int & IntVector::back() const {
    if (_size == 0) {
        throw out_of_range("IntVector::back_range_check");
    }
    return _data[_size - 1]; 
}

int & IntVector::back() {
    if (_size == 0) {
        throw out_of_range("IntVector::back_range_check");
    }
    return _data[_size - 1]; 
}

void IntVector::assign(unsigned n, int value) {
    if (n > _capacity) {
        if (_capacity == 0 || n > _capacity * 2) {
            expand(n);
        }
        else if (n - _capacity > _capacity * 2) {
            expand(n - _capacity);
        }
        else {
            expand();
        }
    }

    for (unsigned i = 0; i < n; ++i) {
        _data[i] = value;
    }

    _size = n;
}

void IntVector::push_back(int value) {
    if (_size + 1 > _capacity) {
        expand();
    }

    _size += 1;

    _data[_size - 1] = value;
}

void IntVector::pop_back() {
    _size -= 1;
}

void IntVector::clear() {
    _size = 0;
}

void IntVector::resize(unsigned n, int value) {
    if (n < _size) {
        _size = n;
    }
    else {
        if (n > _capacity) {
            if (_capacity == 0 || n > _capacity * 2) {
                expand(n);
            }
            else if (n - _capacity > _capacity * 2) {
                expand(n - _capacity);
            }
            else {
                expand();
            }
        }
        
        for (unsigned i = _size; i < n; ++i) {
            _data[i] = value;
        }

        _size = n;
    }
}

void IntVector::reserve(unsigned n) {
    if (n > _capacity) {
        expand(n);
        _capacity = n;
    }
}

void IntVector::expand() {
    if (_capacity == 0) {
        _capacity = 1;
    }
    else {
        _capacity *= 2;
    }

    int *temp = new int[_capacity];

    for (unsigned i = 0; i < _size; ++i) {
        temp[i] = _data[i];
    }

    delete[] _data;
    _data = temp;
}

void IntVector::expand(unsigned amount) {
    if (amount > _capacity) {
        _capacity = amount;

        int *temp = new int[_capacity];

        for (unsigned i = 0; i < _size; ++i) {
            temp[i] = _data[i];
        }
        
        delete[] _data;
        _data = temp;
    }    
}