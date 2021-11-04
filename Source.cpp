#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<fstream>


struct _Queue {
    char value;
    _Queue* next;
};

class Queue {

    _Queue* begin, * end;
public:

    void enqueue(char value) {
        if (this->end == nullptr) {
            this->end = new _Queue();
            this->begin = this->end;
            this->end->value = value;
            this->end->next = nullptr;
        }
        else {
            this->end->next = new _Queue();
            this->end->next->value = value;
            this->end = end->next;
        }
    }

    char dequeue() {
        char value = this->begin->value;
        this->begin = this->begin->next;
        return value;
    }

    bool empty() {
        return this->begin == nullptr;
    }
};

Queue digits, chars, other;


int main() {
    std::string filename = "test.txt";
    FILE* input_file = fopen(filename.c_str(), "r");

    if (input_file == nullptr) {
        return EXIT_FAILURE;
    }

    while (!feof(input_file)) {
        char c = getc(input_file);
        if ('0' <= c && c <= '9') {
            digits.enqueue(c);
        }
        else if (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z')) {
            chars.enqueue(c);
        }
        else {
            other.enqueue(c);
        }
    }

    std::cout << "digits" << std::endl;
    while (!digits.empty()) {
        std::cout << digits.dequeue() << std::endl;
    }

    std::cout << "Chars" << std::endl;
    while (!chars.empty()) {
        std::cout << chars.dequeue() << std::endl;
    }

    std::cout << "Other" << std::endl;
    while (!other.empty()) {
        std::cout << other.dequeue() << std::endl;
    }

    return 0;
}