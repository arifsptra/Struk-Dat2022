#include <iostream>

using namespace std;

int main(){
    int x;
    cout << "Masukkan Jumlah Uang yang Sudah Dibayarkan: ";
    cin >> x;
    int kekurangan = x*0.25;
    int harga = x + kekurangan;
    cout << "Harga Panci Sebenarnya: " << harga;
    return 0;
}