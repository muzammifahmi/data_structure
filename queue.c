#include <stdio.h>
#include <stdlib.h>

// Mendefinisikan struktur Circular Queue
typedef struct CircularQueue {
    int kapasitas;
    int *elemen;
    int kepala;
    int ekor;
    int hitung;
} CircularQueue;

// Fungsi untuk menginisialisasi antrian
CircularQueue *inisialisasiAntrian(int kapasitas) {
    CircularQueue *cq = (CircularQueue *)malloc(sizeof(CircularQueue));
    cq->elemen = (int *)malloc(kapasitas * sizeof(int));
    cq->kepala = -1;
    cq->ekor = -1;
    cq->kapasitas = kapasitas;
    cq->hitung = 0;
    return cq;
}

// Periksa apakah antrian penuh
int antrianPenuh(CircularQueue *cq) {
    return (cq->ekor + 1) % cq->kapasitas == cq->kepala;
}

// Periksa apakah antrian kosong
int antrianKosong(CircularQueue *cq) {
    return cq->kepala == -1;
}

// Tambahkan elemen ke dalam antrian
void masukkanKeAntrian(CircularQueue *cq, int elemen) {
    if (!antrianPenuh(cq)) {
        if (cq->kepala == -1) {
            cq->kepala = 0;
        }
        cq->ekor = (cq->ekor + 1) % cq->kapasitas;
        cq->elemen[cq->ekor] = elemen;
        cq->hitung++;
    } else {
        printf("Antrian penuh!\n");
    }
}

// Hapus elemen dari antrian
int hapusDariAntrian(CircularQueue *cq) {
    if (antrianKosong(cq)) {
        printf("Antrian kosong!\n");
        return -1;
    }

    int elemen = cq->elemen[cq->kepala];
    cq->kepala = (cq->kepala + 1) % cq->kapasitas;
    cq->hitung--;

    if (cq->hitung == 0) {
        cq->kepala = -1;
        cq->ekor = -1;
    }

    return elemen;
}

// Cari sebuah elemen dalam antrian
int cariDalamAntrian(CircularQueue *cq, int elemen) {
    if (antrianKosong(cq)) {
        return -1;
    }

    for (int i = cq->kepala; ; i = (i + 1) % cq->kapasitas) {
        if (cq->elemen[i] == elemen) {
            return i;
        }
        if (i == cq->ekor) break;
    }

    return -1;
}

// Ubah sebuah elemen dalam antrian berdasarkan indeks
void ubahAntrian(CircularQueue *cq, int indeks, int elemen) {
    if (!antrianKosong(cq) && indeks >= cq->kepala && indeks <= cq->ekor) {
        cq->elemen[indeks] = elemen;
    }
}

// Dapatkan total jumlah elemen dalam antrian
int hitungAntrian(CircularQueue *cq) {
    return cq->hitung;
}

// Hitung rata-rata penggunaan kapasitas antrian
float rataRataAntrian(CircularQueue *cq) {
    return (cq->hitung > 0) ? (float)cq->hitung / cq->kapasitas * 100 : 0;
}

// Temukan nilai maksimum dalam antrian
int maksimumAntrian(CircularQueue *cq) {
    if (antrianKosong(cq)) {
        printf("Antrian kosong.\n");
        return -1;
    }

    int maksimum = cq->elemen[cq->kepala];
    for (int i = cq->kepala; ; i = (i + 1) % cq->kapasitas) {
        if (cq->elemen[i] > maksimum) {
            maksimum = cq->elemen[i];
        }
        if (i == cq->ekor) break;
    }

    return maksimum;
}

// Temukan nilai minimum dalam antrian
int minimumAntrian(CircularQueue *cq) {
    if (antrianKosong(cq)) {
        printf("Antrian kosong.\n");
        return -1;
    }

    int minimum = cq->elemen[cq->kepala];
    for (int i = cq->kepala; ; i = (i + 1) % cq->kapasitas) {
        if (cq->elemen[i] < minimum) {
            minimum = cq->elemen[i];
        }
        if (i == cq->ekor) break;
    }

    return minimum;
}

int main() {
    // Contoh penggunaan Circular Queue
    CircularQueue *cq = inisialisasiAntrian(5);
    masukkanKeAntrian(cq, 10);
    masukkanKeAntrian(cq, 20);
    masukkanKeAntrian(cq, 30);
    masukkanKeAntrian(cq, 40);
    masukkanKeAntrian(cq, 50);

    printf("Elemen antrian: ");
    for (int i = cq->kepala; ; i = (i + 1) % cq->kapasitas) {
        printf("%d ", cq->elemen[i]);
        if (i == cq->ekor) break;
    }
    printf("\n");

    printf("Jumlah elemen dalam antrian: %d\n", hitungAntrian(cq));
    printf("Rata-rata penggunaan kapasitas antrian: %.2f%%\n", rataRataAntrian(cq));
    printf("Nilai maksimum dalam antrian: %d\n", maksimumAntrian(cq));
    printf("Nilai minimum dalam antrian: %d\n", minimumAntrian(cq));

    // Pembersihan memori
    free(cq->elemen);
    free(cq);

    return 0;
}
