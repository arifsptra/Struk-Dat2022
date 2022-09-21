#include <iostream>
#include <conio.h>

using namespace std;

typedef struct paket{
    char jenisBarang[30];
    int beratBarang;
    char kotaTujuan[30];
};

paket kirim[100];

void tambahData(int x){
    cout << "Masukkan Jenis Barang: ";
    cin >> kirim[x].jenisBarang;
    cout << "Masukkan Berat Barang: ";
    cin >> kirim[x].beratBarang;
    cout << "Masukkan Kota Tujuan: ";
    cin >> kirim[x].kotaTujuan;
    cout << endl;
}

void hapusData(int x){
    x-=1;
    cout << "Data yang anda hapus: " << endl;
    cout << x << " " << kirim[x].jenisBarang << " " << kirim[x].beratBarang << " " << kirim[x].kotaTujuan;
    cout << endl << endl;
}

void tampilkanData(int n){
    for(int i=1; i<n; i++){
        cout << i << " " << kirim[i].jenisBarang << " " << kirim[i].beratBarang << " " << kirim[i].kotaTujuan;
        cout << endl << endl;
    }
    cout << "Tekan tombol untuk lanjut";
}

int main(){
    int pilih, datake=1;
    do{
        cout << "Menu Utama" << endl;
        cout << "1. Tambah Data" << endl;
        cout << "2. Hapus Data Terakhir" << endl;
        cout << "3. Tampil Data" << endl;
        cout << "9. Keluar" << endl;
        cout << "Pilihan Anda [1-9] : ";
        cin >> pilih;
        cout << endl;
        if(pilih==1){
            tambahData(datake);
            datake++;
        }else if(pilih==2){
            hapusData(datake);
            datake--;
        }else if(pilih==3){
            tampilkanData(datake);
        }
    }while(pilih!=9);
    return 0;
}