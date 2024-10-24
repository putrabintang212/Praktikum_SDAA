#include <iostream>
#include <string>
#include <cmath>

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
    tambahAlatBerat("Loader", "Angkut", "550000");
    tambahAlatBerat("Motor Grader", "Tanah", "400000");
    tambahAlatBerat("Skid Steer", "Pengangkutan", "650000");
    tambahAlatBerat("Scraper", "Tanah", "350000");
    tambahAlatBerat("Compactor", "Padat", "500000");
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

int jumpSearch(int arr[], int n, int x) {
    int step = sqrt(n);
    int prev = 0;
    while (arr[min(step, n) - 1] < x) {
        prev = step;
        step += sqrt(n);
        if (prev >= n) return -1;
    }
    while (arr[prev] < x) {
        prev++;
        if (prev == min(step, n)) return -1;
    }
    if (arr[prev] == x) return prev;
    return -1;
}

int fibSearch(int arr[], int x, int n) {
    int fib2 = 0;
    int fib1 = 1;
    int fib = fib2 + fib1;
    while (fib < n) {
        fib2 = fib1;
        fib1 = fib;
        fib = fib2 + fib1;
    }
    int offset = -1;
    while (fib > 1) {
        int i = min(offset + fib2, n - 1);
        if (arr[i] < x) {
            fib = fib1;
            fib1 = fib2;
            fib2 = fib - fib1;
            offset = i;
        } else if (arr[i] > x) {
            fib = fib2;
            fib1 = fib1 - fib2;
            fib2 = fib - fib1;
        } else return i;
    }
    if (fib1 && arr[offset + 1] == x) return offset + 1;
    return -1;
}

int* getArraySewa(int& size) {
    size = 0;
    AlatBerat* current = head;
    while (current != nullptr) {
        size++;
        current = current->next;
    }
    int* arr = new int[size];
    current = head;
    for (int i = 0; i < size; i++) {
        arr[i] = stoi(current->sewaperhari);
        current = current->next;
    }
    return arr;
}

void getStringArray(string arr[], int& size) {
    size = 0;
    AlatBerat* current = head;
    while (current != nullptr) {
        size++;
        current = current->next;
    }
    current = head;
    for (int i = 0; i < size; i++) {
        arr[i] = current->nama;
        current = current->next;
    }
}

int boyerMooreSearch(string text, string pattern) {
    int m = pattern.size();
    int n = text.size();
    int badChar[256];
    for (int i = 0; i < 256; i++) badChar[i] = -1;
    for (int i = 0; i < m; i++) badChar[(int) pattern[i]] = i;
    int s = 0;
    while (s <= (n - m)) {
        int j = m - 1;
        while (j >= 0 && pattern[j] == text[s + j]) j--;
        if (j < 0) return s;
        else s += max(1, j - badChar[(int) text[s + j]]);
    }
    return -1;
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
        cout << "8. Cari sewa menggunakan Jump Search" << endl;
        cout << "9. Cari sewa menggunakan Fibonacci Search" << endl;
        cout << "10. Cari nama alat menggunakan Boyer-Moore" << endl;
        cout << "11. Keluar" << endl;
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
            case 8: {
                int size;
                int* arr = getArraySewa(size);
                int x;
                cout << "Masukkan harga sewa yang ingin dicari: ";
                cin >> x;
                int index = jumpSearch(arr, size, x);
                if (index != -1) {
                    AlatBerat* current = head;
                    for (int i = 0; i < index; i++) {
                        current = current->next;
                    }
                    // Menampilkan seluruh data alat berat
                    cout << "Data ditemukan: " << endl;
                    cout << "Nama Alat: " << current->nama << endl;
                    cout << "Jenis Alat: " << current->jenis << endl;
                    cout << "Harga Sewa Per Hari: " << current->sewaperhari << endl;
                    cout << "Status: " << (current->disewa ? "Disewa" : "Tersedia") << endl;
                } else {
                    cout << "Harga tidak ditemukan." << endl;
                }
                delete[] arr;
                break;
            }

            case 9: {
                int size;
                int* arr = getArraySewa(size);
                int x;
                cout << "Masukkan harga sewa yang ingin dicari: ";
                cin >> x;
                int index = fibSearch(arr, x, size);
                if (index != -1) {
                    AlatBerat* current = head;
                    for (int i = 0; i < index; i++) {
                        current = current->next;
                    }
                    cout << "Data ditemukan: " << endl;
                    cout << "Nama Alat: " << current->nama << endl;
                    cout << "Jenis Alat: " << current->jenis << endl;
                    cout << "Harga Sewa Per Hari: " << current->sewaperhari << endl;
                    cout << "Status: " << (current->disewa ? "Disewa" : "Tersedia") << endl;
                } else {
                    cout << "Harga tidak ditemukan." << endl;
                }
                delete[] arr;
                break;
            }
            case 10: {
                string alat;
                cout << "Masukkan nama alat yang ingin dicari: ";
                getline(cin, alat);
                AlatBerat* current = head;
                bool found = false;
                
                while (current != nullptr) {
                    if (boyerMooreSearch(current->nama, alat) != -1) {
                        found = true;
                        // Menampilkan seluruh data alat berat
                        cout << "Data ditemukan: " << endl;
                        cout << "Nama Alat: " << current->nama << endl;
                        cout << "Jenis Alat: " << current->jenis << endl;
                        cout << "Harga Sewa Per Hari: " << current->sewaperhari << endl;
                        cout << "Status: " << (current->disewa ? "Disewa" : "Tersedia") << endl;
                        break;
                    }
                    current = current->next;
                }
                
                if (!found) {
                    cout << "Alat tidak ditemukan." << endl;
                }
                break;
            }

            case 11:
                cout << "Terima kasih telah menggunakan program kami." << endl;
                break;
            default:
                cout << "Pilihan tidak valid." << endl;
                break;
        }
    } while (pilihan != 11);

    return 0;
}
