#include <iostream>
#include <string>

using namespace std;

int main(){
    int n;
    cout << "Masukkan Jumlah Peserta: ";
    cin >> n;
    string peserta[n];
    int rambutanPeserta[n];
    for(int i=0; i<n; i++){
        cout << "Nama Peserta Lomba-" << i+1 << ": ";
        cin >> peserta[i];
        cout << "Jumlah Buah Rambutan: ";
        cin >> rambutanPeserta[i];
    }
    int temp = rambutanPeserta[0];
    string pemenang;
    for(int i=0; i<n; i++){
        if(rambutanPeserta[i] > temp){
            pemenang = peserta[i];
            temp = rambutanPeserta[i];
        }
    }
    cout << "Pemenangnya adalah: " << pemenang << endl;
    cout << "Rambutan Untuk Kak Ros: " << temp;
    return 0;
}