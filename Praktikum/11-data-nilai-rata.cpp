#include <iostream>

using namespace std;

typedef struct nilai{
    char nim[3];
    char nama[10];
    int nilai;
};

nilai mahasiswa[2];

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
        if(mahasiswa[i].nilai > rata){
            cout << "Mahasiswa ke-" << i+1 << " " << mahasiswa[i].nim << " " << mahasiswa[i].nama << " " <<  mahasiswa[i].nilai << " Lulus" << endl;
        }else {
            cout << "Mahasiswa ke-" << i+1 << " " << mahasiswa[i].nim << " " << mahasiswa[i].nama << " " <<  mahasiswa[i].nilai << " Tidak Lulus" << endl;
        }
        cout << endl;
    }
    return 0;
}