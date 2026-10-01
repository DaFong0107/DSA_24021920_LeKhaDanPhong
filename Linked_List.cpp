#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
};
Node* makeNode(int x) {
    Node* newNode = new Node();
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}

void TruyCapViTriK(Node * head, int k) {
    Node* p = head;
    int index = 0;
    while (p != NULL && index < k) {
        p = p->next;
        index++;
    }
    if (p == NULL) {
        cout << "Sai Vi Tri" << endl;
    }
    else {
        cout << "Phan tu o vi tri " << k << " : " << p->data << endl;
    }
}

void ChenViTriDau(Node * &head, int x) {
    Node* newNode = makeNode(x);
    newNode->next = head;
    head = newNode;
}

void ChenViTriCuoi(Node * &head, int x) {
    Node* newNode = makeNode(x);
    if (head == NULL) {
        head = newNode;
        return;
    }
    Node* p = head;
    while (p->next != NULL) {
        p = p->next;
    }
    p->next = newNode;
}

void ChenViTriK(Node * &head, int x, int k) {
    if (k == 0) {
        insertFirst(head, x);
        return;
    }
    Node* p = head;
    for (int i = 0; i < k - 1 && p != NULL; i++) {
        p = p->next;
    }
    if (p == NULL) return;
    Node* newNode = makeNode(x);
    newNode->next = p->next;
    p->next = newNode;
}

void XoaViTriDau(Node * &head) {
    if (head == NULL) return;
    Node* temp = head;
    head = head->next;
    delete temp;
}

void XoaViTriCuoi(Node * &head) {
    if (head == NULL) return;
    if (head->next == NULL) {
        delete head;
        head = NULL;
        return;
    }
    Node* p = head;
    while (p->next->next != NULL) {
        p = p->next;
    }
    delete p->next;
    p->next = NULL;
}

void XoaViTriK(Node * &head, int k) {
    if (head == NULL) return;
    if (k == 0) {
        deleteFirst(head);
        return;
    }
    Node* p = head;
    for (int i = 0; i < k - 1 && p->next != NULL; i++) {
        p = p->next;
    }
    if (p->next == NULL) return;
    Node* temp = p->next;
    p->next = temp->next;
    delete temp;
}

void DuyetXuoi(Node * head) {
    Node* p = head;
    while (p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

void DuyetNguoc(Node * head) {
    int temp[100];
    int count = 0;
    Node* p = head;
    while (p != NULL) {
        temp[count++] = p->data;
        p = p->next;
    }
    for (int i = count - 1; i >= 0; i--) {
        cout << temp[i] << " ";
    }
    cout << endl;
}