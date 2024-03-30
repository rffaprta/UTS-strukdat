#include <iostream>
#include <string>
using namespace std;

// Variabel global
int HargaAkhir = 0;
int orang;

// Struct data penumpang
struct Penumpang {
    string name;
    string tujuan;
    int kode;
    int kelas;
    int harga;
    string jk;
    string kls;
    Penumpang* next; // Pointer buat penumpang selanjutnya di linked list
};

// Fungsi data penumpang
void isidata(Penumpang*& head, int size) {
    for (int i = 0; i < size; i++) {
        Penumpang* baru = new Penumpang;
        cout << "Masukan Nama           : ";
        cin.ignore();
        getline(cin, baru->name);
        cout << "Masukan Kode Tujuan    : ";
        cin >> baru->kode;
        cout << "Masukan Kode Kelas     : ";
        cin >> baru->kelas;
        cout << "Jenis Kelamin (L/P)    : ";
        cin >> baru->jk;
        cout << "=============================================================================" << endl;
        baru->next = NULL;

        if (head == NULL) {
            head = baru;
        } else {
            Penumpang* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = baru;
        }
    }
}

// Fungsi harga tiket
void Hrg(Penumpang*& head) {
    Penumpang* temp = head;
    while (temp != NULL) {
        switch (temp->kode) {
            case 1:
                temp->harga = 4000000; // Harga tiket Jerman
                temp->tujuan = "Jerman";
                break;
            case 2:
                temp->harga = 3500000; // Harga tiket Jepang
                temp->tujuan = "Jepang";
                break;
            case 3:
                temp->harga = 3000000; // Harga tiket Singapura
                temp->tujuan = "Singapura";
                break;
        }
        switch (temp->kelas) {
            case 1:
                temp->harga = temp->harga; // Ekonomi
                temp->kls = "Ekonomi";
                break;
            case 2:
                temp->harga = (temp->harga * 125) / 100; // Bisnis
                temp->kls = "Bisnis";
                break;
            case 3:
                temp->harga = (temp->harga * 150) / 100; // First Class
                temp->kls = "First Class";
                break;
        }
        temp = temp->next;
    }
}

// Tampil data penumpang
//linked list
void tampildata(Penumpang* head) {
    cout << "\nData Penumpang:\n";
    Penumpang* temp = head;
    while (temp != NULL) {
        cout << "Nama : " << temp->name << ", Tujuan : " << temp->tujuan << ", Kelas : " << temp->kls << ", Harga : " << temp->harga << "IDR" << ", Jenis Kelamin : " << temp->jk << endl;
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    // Variabel lokal
    char ulang;
    Penumpang* head = NULL;

    // Loop
    do {
        char beli;

        // Tampilan menu tiket pesawat
        cout << "\nBANDARA SAYA" << endl;
        cout << "---------------" << endl << endl;

        cout << "Kode Tujuan " << "   Tujuan   " << " Harga Tiket   " << "         Kelas        " << endl;
        cout << "    1       " << "    Jerman  " << " Rp. 4.000.000 " << " 1.Ekonomi (+0%)      " << endl;
        cout << "    2       " << "    Jepang  " << " Rp. 3.500.000 " << " 2.Bisnis (+25%)                    " << endl;
        cout << "    3       " << "  Singapura " << " Rp. 3.000.000 " << " 2.First Class (+50%)    " << endl;

        cout << endl;

        cout << "Mau Beli Tiket Pesawat (Y/N) ? ";
        cin >> beli;

        // Kondisional
        // Client beli apa tidak
        if (beli == 'Y' || beli == 'y') {
            // Menentukan jumlah penumpang
            cout << "Jumlah Penumpang? ";
            cin >> orang;
            cout << "=============================================================================" << endl;
            // manggil fungsi untuk masukkan data penumpang
            isidata(head, orang);
            // Memanggil fungsi untuk nentuin harga tiket
            Hrg(head);
            // Memanggil fungsi untuk nampilin data penumpang
            tampildata(head);
            // Menentukan beli lagi atau tidak
            cout << "Mau melakukan transaksi lagi (Y/T)? ";
            cin >> ulang;
        } else {
            cout << endl << "Terima Kasih Telah mengunjungi program kami " << endl;
            ulang = 'T';
        }
    } while (ulang == 'Y' || ulang == 'y');

    return 0;
}
