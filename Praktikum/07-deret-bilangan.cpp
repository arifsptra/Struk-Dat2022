#include <iostream>

using namespace std;

int main(){
    int n, m;
    cout << "Masukkan Nilai Awal: ";
    cin >> n;
    cout << "Masukkan Nilai Akhir: ";
    cin >> m;
    int temp=0;
    for(int i=n; i<=m; i++){
        if(i%5==0){
            temp++;
        }
    }
    cout << temp;
    return 0;
}