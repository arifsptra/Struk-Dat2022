#include <iostream>

using namespace std;

int main(){
    int n;
    cout << "Masukkan Jumlah Peserta: ";
    cin >> n;
    int peserta[n];
    for(int i=0; i<n; i++){
        cout << "Rambutan Peserta ke-" << i+1 << ": ";
        cin >> peserta[i];
    }
    int temp = peserta[0];
    for(int i=0; i<n; i++){
        if(peserta[i] > temp){
            temp = peserta[i];
        }
    }
    cout << "Rambutan Untuk Kak Ros: " << temp;
    return 0;
}