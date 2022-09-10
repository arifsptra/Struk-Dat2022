#include <iostream>

using namespace std;

int main(){
    int n;
    cout << "Masukkan Jumlah N: ";
    cin >> n;
    int temp=5;
    int value=0;
    for(int i=0; i<n; i++){
        value+=temp;
        temp+=5;
    }
    cout << "Hasil: " << value;
    return 0;
}