#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

struct AlatBerat
{
    string nama;
    string jenis;
    string sewaperhari;
    bool disewa;
};

const int maks_data = 100;
AlatBerat *dataAlat[maks_data];
int jumlahAlat = 0;

bool tambahAlat(){
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

void tampilkanAlat() {
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

void updateAlat (const string &namaAlat, const AlatBerat &dataBaru, int index = 0){
    if (index < jumlahAlat) {
        cout << "===========================================" << endl;
        cout << "Alat dengan nama " << namaAlat << " tidak ditemukan." << endl;
        cout << "===========================================" << endl;
        return;
    } 

    if (dataAlat[index]->nama == namaAlat) {
        *dataAlat[index] = dataBaru; // Update data menggunakan pointer
        cout << "===========================================" << endl;
        cout << "Data alat dengan nama " << namaAlat << " berhasil diupdate." << endl;
        cout << "===========================================" << endl;
        return;
    }

    updateAlat(namaAlat, dataBaru, index + 1); 
}

bool hapusAlat() {
    system("cls");
    tampilkanAlat();
    string namaAlat;
    cout << "Masukkan nama alat yang ingin dihapus: ";
    getline(cin, namaAlat);

    bool alatDitemukan = false;
    for (int i = 0; i < jumlahAlat; ++i) {
        if (dataAlat[i]->nama == namaAlat) {
            delete dataAlat[i]; // Hapus pointer dari memori
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

int main() {
    system("cls");
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
                {
                    string namaAlat;
                    AlatBerat dataBaru;
                    cout << "===========================================" << endl;
                    cout << "Masukkan nama alat yang ingin diupdate: ";
                    getline(cin, namaAlat);
                    cout << "Masukkan data baru" << endl;
                    cout << "Nama: ";
                    getline(cin, dataBaru.nama);
                    cout << "Jenis: ";
                    getline(cin, dataBaru.jenis);
                    cout << "Harga Sewa per Hari: ";
                    getline(cin, dataBaru.sewaperhari);
                    dataBaru.disewa = false; // Reset status sewa
                    updateAlat(namaAlat, dataBaru);
                }
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
