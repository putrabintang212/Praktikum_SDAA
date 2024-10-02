#include <iostream>
#include <string>

using namespace std;

struct AlatBerat {
    string nama;
    string jenis;
    string sewaperhari;
    bool disewa;
    AlatBerat* next;  
};

AlatBerat* head = nullptr;

void dataAlatBerat() {
    string namaAlat[5] = {"Bulldozer", "Excavator", "Crane", "Forklift", "Dump Truck"};
    string jenisAlat[5] = {"Tanah", "Penggalian", "Pengangkutan", "Pindahan", "Pengangkutan"};
    string sewaAlat[5] = {"500000", "450000", "700000", "300000", "600000"};

    for (int i = 0; i < 5; i++) {
        AlatBerat* newAlat = new AlatBerat;
        newAlat->nama = namaAlat[i];
        newAlat->jenis = jenisAlat[i];
        newAlat->sewaperhari = sewaAlat[i];
        newAlat->disewa = false;
        newAlat->next = head;
        head = newAlat;
    }
}

bool tambahAlat() {
    system("cls");
    AlatBerat* newAlat = new AlatBerat;
    cout << "Masukkan nama alat berat: ";
    getline(cin, newAlat->nama);
    cout << "Masukkan jenis alat berat: ";
    getline(cin, newAlat->jenis);
    cout << "Masukkan sewa per hari: ";
    getline(cin, newAlat->sewaperhari);
    newAlat->disewa = false;
    newAlat->next = head;
    head = newAlat;

    cout << "===========================================" << endl;
    cout << "Alat berhasil ditambahkan." << endl;
    cout << "===========================================" << endl;
    return true;
}

void tampilkanAlat() {
    system("cls");
    if (head == nullptr) {
        cout << "===========================================" << endl;
        cout << "Tidak ada alat yang tersedia." << endl;
        cout << "===========================================" << endl;
    } else {
        cout << "===========================================" << endl;
        cout << "Alat yang tersedia:" << endl;
        cout << "===========================================" << endl;

        AlatBerat* current = head;
        while (current != nullptr) {
            cout << "Nama Alat: " << current->nama << endl;
            cout << "Jenis Alat: " << current->jenis << endl;
            cout << "Harga Sewa Per Hari: " << current->sewaperhari << endl;
            cout << "Status: " << (current->disewa ? "Disewa" : "Tersedia") << endl;
            cout << "===========================================" << endl;
            current = current->next;
        }
    }
}

void updateAlat() {
    system("cls");
    tampilkanAlat();

    string namaAlat;
    cout << "Masukkan nama alat yang ingin diupdate: ";
    getline(cin, namaAlat);

    AlatBerat* current = head;
    bool alatDitemukan = false;

    while (current != nullptr) {
        if (current->nama == namaAlat) {
            cout << "===========================================" << endl;
            cout << "Masukkan data baru untuk alat " << namaAlat << endl;
            cout << "Nama baru: ";
            getline(cin, current->nama);
            cout << "Jenis baru: ";
            getline(cin, current->jenis);
            cout << "Harga Sewa per Hari baru: ";
            getline(cin, current->sewaperhari);
            current->disewa = false;
            alatDitemukan = true;
            cout << "===========================================" << endl;
            cout << "Data alat berhasil diupdate." << endl;
            cout << "===========================================" << endl;
            break;
        }
        current = current->next;
    }

    if (!alatDitemukan) {
        cout << "===========================================" << endl;
        cout << "Alat dengan nama " << namaAlat << " tidak ditemukan." << endl;
        cout << "===========================================" << endl;
    }
}

bool hapusAlat() {
    system("cls");
    tampilkanAlat();

    string namaAlat;
    cout << "Masukkan nama alat yang ingin dihapus: ";
    getline(cin, namaAlat);

    AlatBerat* current = head;
    AlatBerat* prev = nullptr;
    bool alatDitemukan = false;

    while (current != nullptr) {
        if (current->nama == namaAlat) {
            if (prev == nullptr) {
                head = current->next;
            } else {
                prev->next = current->next;
            }
            delete current;
            alatDitemukan = true;
            cout << "===========================================" << endl;
            cout << "Alat berhasil dihapus." << endl;
            cout << "===========================================" << endl;
            break;
        }
        prev = current;
        current = current->next;
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
