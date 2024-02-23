#include <iostream>
using namespace std;

struct Node {
public:
    double val;
    Node* next;
    Node(double value) {
        val = value;
        next = nullptr;
    }
};

struct turn {
    int Size = 0;
    Node* first;

    turn() {
        first = nullptr;
    }
    bool is_empty() {
        return first == nullptr;
    }

    void enqueue(double value) {
        if (first == nullptr) {
            first = new Node(value);
        }
        else {
            Node* current = first;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = new Node(value);

        }
        Size++;
    }
    void dequeue() {
        Node* current = first;
        first = first->next;
        delete current;


        Size--;
    }
    void print() {
        if (is_empty() == true) {
            first = nullptr;
        }
        Node* current = first;
        while (current) {
            cout << current->val << " " << endl;
            current = current->next;
        }
        cout << endl;

    }
    int GetSize() {
        return Size;
    }
    Node* getFront() {
        return first;
    }
    Node* getlast() {
        Node* previous = nullptr;
        Node* current = first;
        while (current->next != nullptr) {
            previous = current;
            current = current->next;
        }

        return previous->next;
    }
};
int main() {
    setlocale(LC_ALL, "RU");
    int numbers[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    turn oddQueue;
    turn evenQueue;

    for (int i = 0; i < 10; i++) {
        if (i % 2 == 0) {
            evenQueue.enqueue(numbers[i]);
        }
        else {
            oddQueue.enqueue(numbers[i]);
        }
    }

    std::cout << "Нечетная очередь: " << endl;
    oddQueue.print();
    std::cout << "Четная очередь: " << endl;
    evenQueue.print();

    std::cout << "указатели на начало и конец evenQueue: " << evenQueue.getFront() << ", " << evenQueue.getlast() << std::endl;
    std::cout << "указатели на начало и конец oddQueue: " << oddQueue.getFront() << ", " << oddQueue.getlast() << std::endl;

    return 0;
}
