#include <iostream>
#include <map>
#include <set>
using namespace std;

int main() {
    int n;
    cout << "=== Program Analisis Fungsi One-to-One ===" << endl;
    cout << "Masukkan jumlah pasangan (domain, kodomain): ";
    cin >> n;

    map<int, int> fungsi;   // menyimpan domain -> kodomain
    set<int> kodomainSet;   // menyimpan kodomain unik

    bool validFungsi = true;
    bool injektif = true;

    cout << "Masukkan pasangan domain dan kodomain (misal: 1 5):" << endl;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;

        // Cek apakah domain sudah pernah muncul
        if (fungsi.find(x) != fungsi.end()) {
            if (fungsi[x] != y) {
                validFungsi = false; // satu domain punya dua output berbeda
            }
        } else {
            fungsi[x] = y;
        }
    }

    // Jika valid fungsi, cek injektif
    if (validFungsi) {
        for (auto pasangan : fungsi) {
            int y = pasangan.second;
            if (kodomainSet.find(y) != kodomainSet.end()) {
                injektif = false; // ada output ganda
            }
            kodomainSet.insert(y);
        }
    }

    // Output hasil
    cout << "\n=== HASIL ANALISIS ===" << endl;
    if (!validFungsi) {
        cout << "Pasangan yang dimasukkan BUKAN fungsi." << endl;
        cout << "Alasannya: ada satu domain yang memiliki lebih dari satu kodomain (One-to-Many)." << endl;
    } else {
        cout << "Pasangan yang dimasukkan membentuk sebuah fungsi." << endl;

        cout << "Range fungsi = { ";
        for (int y : kodomainSet) {
            cout << y << " ";
        }
        cout << "}" << endl;

        if (injektif) {
            cout << " Fungsi ini adalah ONE-TO-ONE (Injektif)." << endl;
            cout << "Penjelasan: setiap domain memiliki kodomain unik, "
                 << "tidak ada dua domain berbeda yang menuju kodomain sama." << endl;
        } else {
            cout << " Fungsi ini BUKAN One-to-One." << endl;
            cout << "Jenis fungsi: MANY-TO-ONE (beberapa domain berbeda menuju kodomain yang sama)." << endl;
            cout << "Penjelasan: ada minimal dua domain berbeda yang menghasilkan output identik." << endl;
        }
    }

    return 0;
}
