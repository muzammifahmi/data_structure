#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node *prev;
};

// Fungsi untuk menginisialisasi node kepala
Node* inisialisasiKepala() {
    Node *head = new Node();
    head->data = 0;
    head->next = head;
    head->prev = head;
    return head;
}

// Fungsi untuk menambahkan node baru ke dalam daftar
void tambahNode(Node *head, int data) {
    Node *newNode = new Node();
    newNode->data = data;
    newNode->next = head->next;
    newNode->prev = head;
    head->next->prev = newNode;
    head->next = newNode;
    head->data++;
}

// Fungsi untuk menghapus node dari daftar
void hapusNode(Node *head, int data) {
    if (head->data == 0) {
        cout << "Daftar kosong" << endl;
        return;
    }
    Node *current = head->next;
    while (current != head) {
        if (current->data == data) {
            current->prev->next = current->next;
            current->next->prev = current->prev;
            delete current;
            head->data--;
            return;
        }
        current = current->next;
    }
    cout << "Elemen tidak ditemukan" << endl;
}

// Fungsi untuk menampilkan daftar
void tampilkanDaftar(Node *head) {
    if (head->data == 0) {
        cout << "Daftar kosong" << endl;
        return;
    }
    Node *current = head->next;
    while (current != head) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

// Fungsi untuk menampilkan daftar secara terbalik
void tampilkanDaftarTerbalik(Node *head) {
    if (head->data == 0) {
        cout << "Daftar kosong" << endl;
        return;
    }
    Node *current = head->prev;
    while (current != head) {
        cout << current->data << " ";
        current = current->prev;
    }
    cout << endl;
}

// Fungsi untuk mengubah data dari suatu node
void ubahNode(Node *head, int oldData, int newData) {
    if (head->data == 0) {
        cout << "Daftar kosong" << endl;
        return;
    }
    Node *current = head->next;
    while (current != head) {
        if (current->data == oldData) {
            current->data = newData;
            return;
        }
        current = current->next;
    }
    cout << "Elemen tidak ditemukan" << endl;
}

int main() {
    Node *head = inisialisasiKepala();
    int choice, data, oldData, newData;
    
    do {
        cout << "================================" << endl;
        cout << "Program Linked List non Circular" << endl;
        cout << "================================" << endl;
        cout << "Menu :" << endl;
        cout << "1. Tambahkan node" << endl;
        cout << "2. Hapus node" << endl;
        cout << "3. Tampilkan daftar" << endl;
        cout << "4. Tampilkan daftar secara terbalik" << endl;
        cout << "5. Ubah daftar node" << endl;
        cout << "6. Keluar" << endl;
        cout << "================================" << endl;
        cout << "Pilihan : ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "Masukkan data untuk ditambahkan : ";
                cin >> data;
                tambahNode(head, data);
                break;
            case 2:
                cout << "Masukkan data untuk dihapus : ";
                cin >> data;
                hapusNode(head, data);
                break;
            case 3:
                cout << "Daftar : " << endl;
                tampilkanDaftar(head);
                break;
            case 4:
                cout << "Daftar terbalik : " << endl;
                tampilkanDaftarTerbalik(head);
                break;
            case 5:
                cout << "Masukkan data yang ingin diubah : ";
                cin >> oldData;
                cout << "Masukkan data baru : ";
                cin >> newData;
                ubahNode(head, oldData, newData);
                break;
            case 6:
                cout << "Keluar program " << endl;
                break;
            default:
                cout << "Pilihan tidak valid" << endl;
        }
    } while (choice != 6);
    
    return 0;
}
