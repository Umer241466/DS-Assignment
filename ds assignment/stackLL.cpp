#include <iostream>
using namespace std;
class Node {
private:
    int data;
    Node* next;
public:
    Node(int value) : data(value), next(nullptr) {}

    void setNext(Node* n) { next = n; }
    Node* getNext() const { return next; }
    int getData() const { return data; }
};

class Stack {
private:
    Node* topNode;
public:
    Stack() : topNode(nullptr) {}

    bool empty() const {
        return topNode == nullptr;
    }

    void push(int value) {
        Node* newNode = new Node(value);
        newNode->setNext(topNode);
        topNode = newNode;
        cout << value << " pushed onto stack.\n";
    }

    void pop() {
        if (empty()) {
            cout << "Stack Underflow! Nothing to pop.\n";
            return;
        }
        Node* temp = topNode;
        cout << topNode->getData() << " popped from stack.\n";
        topNode = topNode->getNext();
        delete temp;
    }

    int top() const {
        if (empty()) {
            cout << "Stack is empty!\n";
            return -1;
        }
        return topNode->getData();
    }

    void display() const {
        if (empty()) {
            cout << "Stack is empty.\n";
            return;
        }
        cout << "Stack (top to bottom): ";
        Node* temp = topNode;
        while (temp != nullptr) {
            cout << temp->getData() << " ";
            temp = temp->getNext();
        }
        cout << endl;
    }

    ~Stack() {
        while (!empty()) {
            pop();
        }
    }
};
int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.display();
    cout << "Top element of stack " << s.top() << endl;
    s.pop();
    s.display();
    cout << "Top element of stack after pop " << s.top() << endl;
    return 0;
}
