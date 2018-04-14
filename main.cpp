#include <iostream>

class List {
public:
    virtual bool isEmpty() = 0;
    virtual List* getNext() = 0;
    virtual int getValue() = 0;
};

class Empty : public List {
public:
    bool isEmpty() {
        return true;
    }
    
    List* getNext() {
        throw std::runtime_error("Can not call getNext() on Empty()");
    }
    
    int getValue() {
        throw std::runtime_error("Can not call getValue() on Empty()");
    }
};

class Node : public List {
private:
    int value;
    List* next;
public:
    Node(int value) {
        this->value = value;
        this->next = new Empty();
    }
    
    Node(int value, Node *next) {
        this->value = value;
        this->next = next;
    }
    
    bool isEmpty() {
        return false;
    }
    
    List* getNext() {
        return this->next;
    }
    
    int getValue() {
        return this->value;
    }
};

void printList(List* list) {
    if (list->isEmpty() == false) {
        printf("%d ", list->getValue());
        printList(list->getNext());
    }
}

int main(int argc, const char * argv[]) {
    printList(new Node(1, new Node(2, new Node(3))));
    
    return 0;
}
