#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struktur data untuk mahasiswa
struct Mahasiswa {
    int nim;
    char nama[50];
    float nilai;
};

// Fungsi untuk menukar dua elemen dalam array mahasiswa
void swap(struct Mahasiswa *a, struct Mahasiswa *b) {
    struct Mahasiswa temp = *a;
    *a = *b;
    *b = temp;
}

// Fungsi untuk menampilkan data mahasiswa
void display(struct Mahasiswa *mahasiswa, int n) {
    printf("NIM\tNama\t\tNilai\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%s\t\t%.2f\n", mahasiswa[i].nim, mahasiswa[i].nama, mahasiswa[i].nilai);
    }
    printf("\n");
}

// Fungsi Shell Sort untuk mengurutkan mahasiswa berdasarkan nama
void shellSort(struct Mahasiswa *mahasiswa, int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            struct Mahasiswa temp = mahasiswa[i];
            int j;
            for (j = i; j >= gap && strcmp(mahasiswa[j - gap].nama, temp.nama) > 0; j -= gap) {
                mahasiswa[j] = mahasiswa[j - gap];
            }
            mahasiswa[j] = temp;
        }
    }
}

// Fungsi Partition untuk Quick Sort berdasarkan NIM
int partition(struct Mahasiswa *mahasiswa, int low, int high) {
    int pivot = mahasiswa[high].nim;
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (mahasiswa[j].nim < pivot) {
            i++;
            swap(&mahasiswa[i], &mahasiswa[j]);
        }
    }
    swap(&mahasiswa[i + 1], &mahasiswa[high]);
    return (i + 1);
}

// Fungsi Quick Sort untuk mengurutkan mahasiswa berdasarkan NIM
void quickSort(struct Mahasiswa *mahasiswa, int low, int high) {
    if (low < high) {
        int pi = partition(mahasiswa, low, high);
        quickSort(mahasiswa, low, pi - 1);
        quickSort(mahasiswa, pi + 1, high);
    }
}

int main() {
    int n;
    printf("Masukkan jumlah mahasiswa: ");
    scanf("%d", &n);

    // Alokasi dinamis untuk array mahasiswa
    struct Mahasiswa *mahasiswa = (struct Mahasiswa *)malloc(n * sizeof(struct Mahasiswa));

    for (int i = 0; i < n; i++) {
        printf("\nData Mahasiswa ke-%d:\n", i + 1);
        printf("NIM: ");
        scanf("%d", &mahasiswa[i].nim);
        printf("Nama: ");
        getchar(); // Menghapus newline dari buffer
        fgets(mahasiswa[i].nama, sizeof(mahasiswa[i].nama), stdin);
        mahasiswa[i].nama[strcspn(mahasiswa[i].nama, "\n")] = '\0'; // Menghapus newline dari fgets
        printf("Nilai: ");
        scanf("%f", &mahasiswa[i].nilai);
    }

    printf("\nData Sebelum Diurutkan:\n");
    display(mahasiswa, n);

    // Mengurutkan berdasarkan nama dengan Shell Sort
    shellSort(mahasiswa, n);

    // Mengurutkan berdasarkan NIM dengan Quick Sort
    quickSort(mahasiswa, 0, n - 1);

    printf("Data Setelah Diurutkan:\n");
    display(mahasiswa, n);

    // Pembersihan memori
    free(mahasiswa);
    return 0;
}
