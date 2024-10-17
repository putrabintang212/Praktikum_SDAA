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
AlatBerat* tail = nullptr;

void tambahAlatBerat(const string& nama, const string& jenis, const string& sewa) {
    AlatBerat* newAlat = new AlatBerat;
    newAlat->nama = nama;
    newAlat->jenis = jenis;
    newAlat->sewaperhari = sewa;
    newAlat->disewa = false;
    newAlat->next = nullptr;

    if (head == nullptr) {
        head = tail = newAlat;
    } else {
        newAlat->next = head;
        head = newAlat;
    }
}

void dataAlatBerat() {
    tambahAlatBerat("Bulldozer", "Tanah", "500000");
    tambahAlatBerat("Excavator", "Penggalian", "450000");
    tambahAlatBerat("Crane", "Pengangkutan", "700000");
    tambahAlatBerat("Forklift", "Pindahan", "300000");
    tambahAlatBerat("Dump Truck", "Pengangkutan", "600000");
}

void tambahAlatStack() {
    string nama, jenis, sewaperhari;
    cout << "Masukkan nama alat berat: ";
    getline(cin, nama);
    cout << "Masukkan jenis alat berat: ";
    getline(cin, jenis);
    cout << "Masukkan harga sewa per hari: ";
    getline(cin, sewaperhari);

    tambahAlatBerat(nama, jenis, sewaperhari);
    cout << "Alat berhasil ditambahkan ke stack." << endl;
}

void hapusAlatStack() {
    if (head == nullptr) {
        cout << "Stack kosong, tidak ada alat yang bisa dihapus." << endl;
    } else {
        AlatBerat* temp = head;
        head = head->next;
        cout << "Alat " << temp->nama << " berhasil dihapus dari stack." << endl;
        delete temp;
    }
}

void tambahAlatQueue() {
    string nama, jenis, sewaperhari;
    cout << "Masukkan nama alat berat: ";
    getline(cin, nama);
    cout << "Masukkan jenis alat berat: ";
    getline(cin, jenis);
    cout << "Masukkan harga sewa per hari: ";
    getline(cin, sewaperhari);

    AlatBerat* newAlat = new AlatBerat;
    newAlat->nama = nama;
    newAlat->jenis = jenis;
    newAlat->sewaperhari = sewaperhari;
    newAlat->disewa = false;
    newAlat->next = nullptr;

    if (tail == nullptr) {
        head = tail = newAlat;
    } else {
        tail->next = newAlat;
        tail = newAlat;
    }

    cout << "Alat berhasil ditambahkan ke queue." << endl;
}

void hapusAlatQueue() {
    if (head == nullptr) {
        cout << "Queue kosong, tidak ada alat yang bisa dihapus." << endl;
    } else {
        AlatBerat* temp = head;
        head = head->next;
        if (head == nullptr) {
            tail = nullptr;
        }
        cout << "Alat " << temp->nama << " berhasil dihapus dari queue." << endl;
        delete temp;
    }
}

void tampilkanAlat() {
    if (head == nullptr) {
        cout << "Tidak ada alat yang tersedia." << endl;
    } else {
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

void quickSortAscending(AlatBerat* start, AlatBerat* end) {
    if (start == end || start == nullptr || end == nullptr) return;
    AlatBerat* pivot = start;
    AlatBerat* current = start->next;
    while (current != nullptr) {
        if (current->nama < pivot->nama) {
            swap(start->nama, current->nama);
            swap(start->jenis, current->jenis);
            swap(start->sewaperhari, current->sewaperhari);
        }
        current = current->next;
    }
    quickSortAscending(start->next, end);
}

void quickSortDescending(AlatBerat* start, AlatBerat* end) {
    if (start == end || start == nullptr || end == nullptr) return;
    AlatBerat* pivot = start;
    AlatBerat* current = start->next;
    while (current != nullptr) {
        if (current->nama > pivot->nama) {
            swap(start->nama, current->nama);
            swap(start->jenis, current->jenis);
            swap(start->sewaperhari, current->sewaperhari);
        }
        current = current->next;
    }
    quickSortDescending(start->next, end);
}

int main() {
    dataAlatBerat();
    int pilihan;

    do {
        cout << "\nMenu Utama:" << endl;
        cout << "1. Tambah data ke Stack" << endl;
        cout << "2. Pop data dari Stack" << endl;
        cout << "3. Tambah data ke Queue" << endl;
        cout << "4. Dequeue data dari Queue" << endl;
        cout << "5. Tampilkan data alat" << endl;
        cout << "6. Urutkan data ascending" << endl;
        cout << "7. Urutkan data descending" << endl;
        cout << "8. Keluar" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;
        cin.ignore();

        switch (pilihan) {
            case 1:
                tambahAlatStack();
                break;
            case 2:
                hapusAlatStack();
                break;
            case 3:
                tambahAlatQueue();
                break;
            case 4:
                hapusAlatQueue();
                break;
            case 5:
                tampilkanAlat();
                break;
            case 6:
                quickSortAscending(head, tail);
                cout << "Data berhasil diurutkan secara ascending." << endl;
                tampilkanAlat();
                break;
            case 7:
                quickSortDescending(head, tail);
                cout << "Data berhasil diurutkan secara descending." << endl;
                tampilkanAlat();
                break;
            case 8:
                cout << "Terima kasih telah menggunakan program kami." << endl;
                break;
            default:
                cout << "Pilihan tidak valid." << endl;
                break;
        }
    } while (pilihan != 8);

    return 0;
}
