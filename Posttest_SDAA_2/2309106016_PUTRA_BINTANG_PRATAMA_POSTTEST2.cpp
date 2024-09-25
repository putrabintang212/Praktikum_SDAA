#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

struct AlatBerat //Struct
{
    string nama;
    string jenis;
    string sewaperhari;
    bool disewa;
};

const int maks_data = 100;
AlatBerat *dataAlat[maks_data]; //array pointer ke struct AlatBerat
int jumlahAlat = 0; 

void dataAlatBerat() { //prosedur
    string namaAlat[5] = {"Bulldozer", "Excavator", "Crane", "Forklift", "Dump Truck"};
    string jenisAlat[5] = {"Tanah", "Penggalian", "Pengangkutan", "Pindahan", "Pengangkutan"};
    string sewaAlat[5] = {"500000", "450000", "700000", "300000", "600000"};
      for (int i = 0; i < 5; i++) {
        dataAlat[jumlahAlat] = new AlatBerat;
        dataAlat[jumlahAlat]->nama = namaAlat[i];
        dataAlat[jumlahAlat]->jenis = jenisAlat[i];
        dataAlat[jumlahAlat]->sewaperhari = sewaAlat[i];
        dataAlat[jumlahAlat]->disewa = false;
        jumlahAlat++;
      }
}

bool tambahAlat(){ //fungsi
    system("cls");
    if (jumlahAlat < maks_data) {
        dataAlat[jumlahAlat] = new AlatBerat;
        cout << "Masukkan nama alat berat: ";
        getline(cin, dataAlat[jumlahAlat]->nama);
        cout << "Masukkan jenis alat berat: ";
        getline(cin, dataAlat[jumlahAlat]->jenis);
        cout << "Masukkan sewa per hari: ";
        getline(cin, dataAlat[jumlahAlat]->sewaperhari);
        dataAlat[jumlahAlat]->disewa = false;
        jumlahAlat++;
        cout << "===========================================" << endl;
        cout << "Alat berhasil ditambahkan." << endl;
        cout << "===========================================" << endl;
        return true;
    } else {
        cout << "===========================================" << endl;
        cout << "Data sudah penuh." << endl;
        cout << "===========================================" << endl;
        return false;
    }
}

void tampilkanAlat() { //prosedur
    system("cls");
    if (jumlahAlat == 0) {
        cout << "===========================================" << endl;
        cout << "Tidak ada alat yang tersedia." << endl;
        cout << "===========================================" << endl;
    } else {
        cout << "===========================================" << endl;
        cout << "Alat yang tersedia:" << endl;
        cout << "===========================================" << endl;
        for (int i = 0; i <jumlahAlat; ++i) {
            cout << "Nama Alat: " << dataAlat[i]->nama << endl;
            cout << "Jenis Alat: " << dataAlat[i]->jenis << endl;
            cout << "Harga Sewa Per Hari: " << dataAlat[i]->sewaperhari << endl;
            cout << "Status: " << (dataAlat[i]->disewa ? "Disewa" : "Tersedia") << endl;
            cout << "===========================================" << endl;
        }
    }
}

void updateAlat() { // fungsi
    system("cls");
    tampilkanAlat();
    string namaAlat;
    cout << "Masukkan nama alat yang ingin diupdate: ";
    getline(cin, namaAlat);

    bool alatDitemukan = false;
    for (int i = 0; i < jumlahAlat; ++i) {
        if (dataAlat[i]->nama == namaAlat) {
            cout << "===========================================" << endl;
            cout << "Masukkan data baru untuk alat " << namaAlat << endl;
            cout << "Nama baru: ";
            getline(cin, dataAlat[i]->nama);
            cout << "Jenis baru: ";
            getline(cin, dataAlat[i]->jenis);
            cout << "Harga Sewa per Hari baru: ";
            getline(cin, dataAlat[i]->sewaperhari);
            dataAlat[i]->disewa = false; 
            alatDitemukan = true;
            cout << "===========================================" << endl;
            cout << "Data alat berhasil diupdate." << endl;
            cout << "===========================================" << endl;
            break;
        }
    }

    if (!alatDitemukan) {
        cout << "===========================================" << endl;
        cout << "Alat dengan nama " << namaAlat << " tidak ditemukan." << endl;
        cout << "===========================================" << endl;
    }
}


bool hapusAlat() { //fungsi
    system("cls");
    tampilkanAlat();
    string namaAlat;
    cout << "Masukkan nama alat yang ingin dihapus: ";
    getline(cin, namaAlat);

    bool alatDitemukan = false;
    for (int i = 0; i < jumlahAlat; ++i) {
        if (dataAlat[i]->nama == namaAlat) {
            delete dataAlat[i]; 
            for (int j = i; j < jumlahAlat - 1; ++j) {
                dataAlat[j] = dataAlat[j + 1];
            }
            jumlahAlat--;
            alatDitemukan = true;
            cout << "===========================================" << endl;
            cout << "Alat berhasil dihapus." << endl;
            cout << "===========================================" << endl;
            break;
        }
    }

    if (!alatDitemukan) {
        cout << "===========================================" << endl;
        cout << "Alat tidak ditemukan." << endl;
        cout << "===========================================" << endl;
        return false;
    }

    return true;
}

int main() { //fungsi utama
    system("cls");    
    dataAlatBerat(); 
    int pilihan;
    do {
        cout << "\nMenu Utama:" << endl;
        cout << "1. Tambah data alat" << endl;
        cout << "2. Tampilkan data alat" << endl;
        cout << "3. Update data alat" << endl;
        cout << "4. Hapus data alat" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;
        cin.ignore();

        switch (pilihan) {
            case 1:
                tambahAlat();
                break;
            case 2:
                tampilkanAlat();
                break;
            case 3:
                updateAlat();
                break;
            case 4:
                hapusAlat();
                break;
            case 5:
                cout << "===========================================" << endl;
                cout << "Terima kasih telah menggunakan program kami." << endl;
                cout << "===========================================" << endl;
                break;
            default:
                cout << "===========================================" << endl;
                cout << "Pilihan tidak valid." << endl;
                cout << "===========================================" << endl;
                break;
        }
    } while (pilihan != 5);

    return 0;
}
