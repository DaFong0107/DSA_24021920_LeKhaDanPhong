#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;

    Node(int x) {
        data = x;
        prev = next = nullptr;
    }
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() {
        head = tail = nullptr;
    }

    DoublyLinkedList(const DoublyLinkedList&) = delete;
    DoublyLinkedList& operator=(const DoublyLinkedList&) = delete;

 
    void ChenViTriDau(int x) {
        Node* p = new Node(x);

        if (head == nullptr) {
            head = tail = p;
            return;
        }

        p->next = head;
        head->prev = p;
        head = p;
    }

    
    void ChenViTriCuoi(int x) {
        Node* p = new Node(x);

        if (tail == nullptr) {
            head = tail = p;
            return;
        }

        tail->next = p;
        p->prev = tail;
        tail = p;
    }

    
    void ChenViTrii(int i, int x) {
        if (i < 0) return;

        if (i == 0) {
            insertHead(x);
            return;
        }

        Node* p = head;
        int j = 0;

        for (; p != nullptr && j < i; j++)
            p = p->next;

        
        if (p == nullptr) {
            if (j == i) {
                insertTail(x);
            }
         
            return;
        }

        Node* q = new Node(x);

        q->prev = p->prev;
        q->next = p;

        p->prev->next = q;
        p->prev = q;
    }

  
    void XoaViTriDau() {
        if (head == nullptr) return;

        Node* p = head;
        head = head->next;

        if (head != nullptr)
            head->prev = nullptr;
        else
            tail = nullptr;

        delete p;
    }

    
    void XoaViTriCuoi() {
        if (tail == nullptr) return;

        Node* p = tail;
        tail = tail->prev;

        if (tail != nullptr)
            tail->next = nullptr;
        else
            head = nullptr;

        delete p;
    }


    void XoaViTriK(int k) {
        if (k < 0 || head == nullptr) return;

        Node* p = head;

        for (int j = 0; p != nullptr && j < k; j++)
            p = p->next;

        if (p == nullptr) return;

        if (p == head) {
            deleteHead();
            return;
        }

        if (p == tail) {
            deleteTail();
            return;
        }

        p->prev->next = p->next;
        p->next->prev = p->prev;

        delete p;
    }

    void DuyetXuoi() const {
        Node* p = head;

        while (p != nullptr) {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }

    
    void DuyetNguoc() const {
        Node* p = tail;

        while (p != nullptr) {
            cout << p->data << " ";
            p = p->prev;
        }
        cout << endl;
    }

    ~DoublyLinkedList() {
        while (head != nullptr)
            deleteHead();
    }
};

