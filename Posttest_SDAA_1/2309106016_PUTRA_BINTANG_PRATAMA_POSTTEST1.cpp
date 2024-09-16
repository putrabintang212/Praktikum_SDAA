#include <iostream>
using namespace std;

// fungsi rekursif untuk menghitung nilai pada Segitiga Pascal
int hitungPascal(int baris, int kolom) {
    if (kolom == 0 || kolom == baris) {
        return 1;
    } else {
        return hitungPascal(baris - 1, kolom - 1) + hitungPascal(baris - 1, kolom);
    }
}

// fungsi print segitiga pascal
void print(int tingkat) {
    for (int baris = 0; baris < tingkat; baris++) {
        for (int kolom = 0; kolom <= baris; kolom++) {
            cout << hitungPascal(baris, kolom) << " ";
        }
        cout << endl;
    }
}

int main() {
    int tingkat = 3; 
    print(tingkat);
    return 0;
}
