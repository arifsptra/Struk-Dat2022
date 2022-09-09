#include <iostream>
#include <string>

using namespace std;

int main(){
    typedef struct InfoLomba{
        string namaPeserta;
        int rambutanPeserta;
    };
    int n;
    cout << "Masukkan Jumlah Peserta: ";
    cin >> n;
    cout << endl;
    InfoLomba peserta[n];
    for(int i=0; i<n; i++){
        cout << "Masukkan Nama Peserta: ";
        cin >> peserta[i].namaPeserta;
        cout << "Jumlah Rambutan Peserta: ";
        cin >> peserta[i].rambutanPeserta;
        cout << endl;
    }
    int temp=0;
    string pemenang;
    for(int i=0; i<n; i++){
        if(peserta[i].rambutanPeserta > temp){
            temp = peserta[i].rambutanPeserta;
            pemenang = peserta[i].namaPeserta;
        }
    }
    cout << "Pemenangnya Adalah: " << pemenang << endl;
    cout << "Rambutan Untuk Kak Ros: " << temp;
    return 0;
}

