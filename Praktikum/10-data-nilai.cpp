#include <iostream>

using namespace std;

typedef struct nilai{
    char nim[3];
    char nama[10];
    int nilai;
};

nilai mahasiswa[2];

int main(){
    for(int i=0; i<2; i++){
        cout << "Mahasiswa ke-" << i+1 << endl;
        cout << "Masukkan NIM: ";
        cin >> mahasiswa[i].nim;
        cout << "Masukkan Nama: ";
        cin >> mahasiswa[i].nama;
        cout << "Masukkan Nilai: ";
        cin >> mahasiswa[i].nilai;
        cout << endl;
    }
    for(int i=0; i<2; i++){
        cout << "Mahasiswa ke-" << i+1 << endl;
        cout << "NIM    : " << mahasiswa[i].nim << endl;
        cout << "Nama   : " << mahasiswa[i].nama << endl;
        cout << "Nilai  : " << mahasiswa[i].nilai << endl;
        cout << endl;
    }
    return 0;
}