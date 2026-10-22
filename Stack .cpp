//Dùng List
#include <iostream>
using namespace std;

#define MAX 1000

struct StackList {
    int arr[MAX];
    int topIndex;

    void init() {
        topIndex = -1;
    }

    bool isEmpty() { return topIndex == -1; }
    bool isFull() { return topIndex == MAX - 1; }
    int size() { return topIndex + 1; }

    // thêm đầu
    void push(int val) {
        if (isFull()) {
            cout << "Stack day!\n";
            return;
        }
        topIndex++;
        arr[topIndex] = val;
    }
    // xóa đầu
    int pop() {
        if (isEmpty()) return -1;
        int k = arr[topIndex];
        topIndex--;
        return k;
    }

    int top() {
        if (isEmpty()) return -1;
        return arr[topIndex];
    }
};

//Dùng literal List

struct StackLinkedList {
    Node* head;
    int h;

    void init() {
        head = nullptr;
        h = 0;
    }

    bool isEmpty() { return head == nullptr; }
    int size() { return n; }

    // Thêm đầu (đỉnh Stack)
    void push(int val) {
        Node* newNode = new Node();
        newNode->data = val;
        newNode->next = head;
        head = newNode;
        n++;
    }

    // Xóa đầu (xóa đỉnh Stack)
    int pop() {
        if (isEmpty()) return -1;
        Node* temp = head;
        int k = temp->data;
        head = head->next;
        delete temp;
        n--;
        return k;
    }

    int top() {
        if (isEmpty()) return -1;
        return head->data;
    }
};