#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void insertDiAwal(Node** head, int newData) {
    Node* newNode = new Node;
    newNode->data = newData;
    newNode->next = *head;
    *head = newNode;
}

void hapusData(Node** head, int dataToDelete) {
    if (*head == NULL) {
        cout << "Linked list kosong" << endl;
        return;
    }

    Node* current = *head;
    Node* prev = NULL;

    while (current != NULL) {
        if (current->data == dataToDelete) {
            if (prev == NULL) {
                *head = current->next;
            } else {
                prev->next = current->next;
            }
            delete current;
            return;
        }
        prev = current;
        current = current->next;
    }
    cout << "Data tidak ditemukan dalam daftar" << endl;
}

void cetakList(Node* head) {
    if (head == NULL) {
        cout << "Linked list kosong" << endl;
        return;
    }
    
    Node* current = head;
    while (current != NULL) {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Node* head = NULL;
    int newData;
    
    cout << "APLIKASI PENERAPAN LINKED LIST" << endl;
    cout << "Untuk berhenti, masukkan -1" << endl;
    cout << "==============================" << endl;
    
    cout << "Masukkan data : ";
    cin >> newData;
    
    while (newData != -1) {
        insertDiAwal(&head, newData);
        cout << "Masukkan data : ";
        cin >> newData;
    }
    
    cout << "Daftar asli: ";
    cetakList(head);
    
    int dataToDelete;
    cout << "Masukkan data yang ingin dihapus: ";
    cin >> dataToDelete;
    
    hapusData(&head, dataToDelete);
    cetakList(head);
    
    return 0;
}
