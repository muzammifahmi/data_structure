#include <iostream>
#include <queue>
#include <string>
#include <limits> // Untuk menggunakan std::numeric_limits
#include <cstdlib> // Untuk menggunakan std::system

using namespace std;

struct Pelanggan {
    std::string nama;
    int nomorTiket;
    Pelanggan(const std::string& n, int t) : nama(n), nomorTiket(t) {}
};

static int nomorAntrianTerakhir = 0;

void tampilkanAntrian(const std::queue<Pelanggan>& antrian) {
    system("cls"); // Membersihkan layar konsol sebelum menampilkan daftar antrian
    cout << "==========================" << endl;
    cout << "APLIKASI PENGELOLAAN TIKET" << endl;
    cout << "==========================" << endl;
    std::cout << "Daftar Antrian Tiket:\n";
    
    if(antrian.empty()) {
        std::cout << "Tidak ada pelanggan dalam antrian\n";
    } else {
        std::queue<Pelanggan> antrianDuplikat = antrian;
        int nomorAntrian = 1;
        
        while (!antrianDuplikat.empty()) {
            const Pelanggan& pelanggan = antrianDuplikat.front();
            std::cout << nomorAntrian << ". " << pelanggan.nama << " (Nomor Tiket: " << pelanggan.nomorTiket << ")\n";
            nomorAntrian++;
            antrianDuplikat.pop();
        }
    }
}

int main() {
    std::queue<Pelanggan> antrianTiket;
    system("cls"); // Membersihkan layar konsol saat program dimulai
    
    while(true) {
        cout << "==========================" << endl;
        cout << "APLIKASI PENGELOLAAN TIKET" << endl;
        cout << "==========================" << endl;
        cout << "1. Tambahkan pelanggan ke antrian\n";
        cout << "2. Layani pelanggan selanjutnya\n";
        cout << "3. Tampilkan daftar antrian\n";
        cout << "4. Keluar\n";
        cout << "==========================" << endl;
        cout << "Silahkan memilih menu : ";
        
        int pilihan;
        
        // Memeriksa apakah input adalah angka atau bukan
        if (!(cin >> pilihan)) {
            // Jika input bukan angka, membersihkan buffer input dan memberikan pesan kesalahan
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            system("cls"); // Membersihkan layar konsol jika input tidak valid
            cout << "Pilihan tidak valid. Harap masukkan nomor menu yang valid." << endl;
            continue; // Mengulangi loop untuk meminta input kembali
        }
        
        if(pilihan == 1) {
            std::string nama;
            system("cls"); // Membersihkan layar konsol sebelum meminta input nama pelanggan

            cout << "==========================" << endl;
            cout << "APLIKASI PENGELOLAAN TIKET" << endl;
            cout << "==========================" << endl;
            cout << "Masukkan nama pelanggan: ";
            std::cin >> nama;

            int nomorTiket = ++nomorAntrianTerakhir;
            antrianTiket.push(Pelanggan(nama, nomorTiket));
            system("cls"); // Membersihkan layar konsol setelah pelanggan ditambahkan

            cout << "==========================" << endl;
            cout << "APLIKASI PENGELOLAAN TIKET" << endl;
            cout << "==========================" << endl;
            std::cout << "Pelanggan " << nama << " telah ditambahkan ke antrian dengan nomor tiket " << nomorTiket << "\n";
        } else if(pilihan == 2) {
            if(antrianTiket.empty()) {
                system("cls"); // Membersihkan layar konsol jika antrian kosong

                cout << "==========================" << endl;
                cout << "APLIKASI PENGELOLAAN TIKET" << endl;
                cout << "==========================" << endl;
                std::cout << "Antrian kosong\n";
            } else {
                Pelanggan pelanggan = antrianTiket.front();
                antrianTiket.pop();
                system("cls"); // Membersihkan layar konsol sebelum menampilkan pesan

                cout << "==========================" << endl;
                cout << "APLIKASI PENGELOLAAN TIKET" << endl;
                cout << "==========================" << endl;
                std::cout << "Melayani pelanggan " << pelanggan.nama << " dengan nomor tiket " << pelanggan.nomorTiket << "\n";
            }
        } else if(pilihan == 3) {
            tampilkanAntrian(antrianTiket);
        } else if(pilihan == 4) {
            break;
        } else {
            system("cls"); // Membersihkan layar konsol jika input tidak valid
            std::cout << "Pilihan tidak valid\n";
        }

        cout << "Kembali ke menu awal? (tekan 'y' untuk kembali): ";
        char kembali;
        cin >> kembali;
        if (kembali != 'y' && kembali != 'Y')
            break;
        system("cls"); // Membersihkan layar konsol sebelum kembali ke menu awal
    }
    
    return 0;
}
