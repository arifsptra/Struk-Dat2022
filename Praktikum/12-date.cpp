#include <iostream>
// #include <string>

using namespace std;

typedef struct waktu{
    int tgl, bln, thn;
};

typedef struct nilai{
    char nim[3];
    char nama[10];
    int nilai;
    waktu tgl_lahir;
};

nilai mahasiswa[100];
// string bln;

void tanggal(waktu x){
    switch(x.bln){
        case 1:
            cout << "Januari";
            break;
        case 2:
            cout << "Februari";
            break;
        case 3:
            cout << "Maret";
            break;
        case 4:
            cout << "April";
            break;
        case 5:
            cout << "Mei";
            break;
        case 6:
            cout << "Juni";
            break;
        case 7:
            cout << "Juli";
            break;
        case 8:
            cout << "Agustus";
            break;
        case 9:
            cout << "September";
            break;
        case 10:
            cout << "Oktober";
            break;
        case 11:
            cout << "November";
            break;
        case 12:
            cout << "Desember";
            break;
    }
}

int main(){
    int rata;
    char result;
    int n=0;
    do{
        cout << "Mahasiswa ke-" << n+1 << endl;
        cout << "Masukkan NIM: ";
        cin >> mahasiswa[n].nim;
        cout << "Masukkan Nama: ";
        cin >> mahasiswa[n].nama;
        cout << "Masukkan Tanggal Lahir: ";
        cin >> mahasiswa[n].tgl_lahir.tgl >> mahasiswa[n].tgl_lahir.bln >> mahasiswa[n].tgl_lahir.thn;
        cout << "Masukkan nilai: ";
        cin >> mahasiswa[n].nilai;
        cout << endl;
        rata+=mahasiswa[n].nilai;
        n++;
        cout << "Apakah ada data lagi: [y/n] ";
        cin >> result;
        cout << endl;
    }while(result == 'y' || result == 'Y');
    rata/=(n);
    for(int i=0; i<n; i++){
        if(mahasiswa[i].nilai >= rata){
            cout << "Mahasiswa ke-" << i+1 << " " << mahasiswa[i].nim << " " << mahasiswa[i].nama << " " <<  mahasiswa[i].nilai << " Lulus" << endl;
        }else {
            cout << "Mahasiswa ke-" << i+1 << endl;
            cout << "NIM: " << mahasiswa[i].nim << endl;
            cout << "Nama: " << mahasiswa[i].nama << endl;
            cout << "Tanggal Lahir: ";
            cout << mahasiswa[i].tgl_lahir.tgl << " ";
            tanggal(mahasiswa[i].tgl_lahir);
            cout << " " << mahasiswa[i].tgl_lahir.thn << endl;
            cout << "Nilai: " <<  mahasiswa[i].nilai << endl;
            cout << "Tidak Lulus" << endl;
        }
        cout << endl;
    }
    return 0;
}