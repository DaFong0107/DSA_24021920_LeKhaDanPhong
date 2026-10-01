#include <iostream>
using namespace std;

int a[100];
int n = 0;


void ChenViTriDau(int x) {
    for (int i = n; i > 0; i--) {
        arr[i] = arr[i - 1];
    }
    arr[0] = x;
    n++;
}

void ChenViTriCuoi(int x) {
    arr[n] = x;
    n++;
}
void ChenViTriK(int x, int k) {
    if (k < 0 || k > n) return;
    for (int i = n; i > k; i--) {
        arr[i] = arr[i - 1];
    }
    arr[k] = x;
    n++;
}

void XoaViTriDau() {
    if (n == 0) return;
    for (int i = 0; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    n--;
}


void XoaViTriCuoi() {
    if (n > 0) {
        n--;
    }
}

void XoaViTriK(int k) {
    if (k < 0 || k >= n) return;
    for (int i = k; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    n--;
}

void DuyetXuoi() {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

//  Duyệt ngược - O(N)
void DuyetNguoc() {
    for (int i = n - 1; i >= 0; i--) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

}