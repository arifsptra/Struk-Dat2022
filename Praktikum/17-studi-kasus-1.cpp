// Lantai kamar tidur pak bejo masih berupa tanah.
// pak bejo bermaksud meng-keramik lantai kamar tidurnya.
// Buatlah program untuk menentukan BERAPA Uang yang Harus
// disiapkan pak Bejo utk MEMBELI Keramik?

#include <iostream>

using namespace std;

float multiply(float x, float y){
    return x*y;
}

float divide(float x, float y){
    return x/y;
}

float roundingUp(int x){
    float modulus = x%1;
    float result = (x+1)-modulus;
    return result;
}

int main(){
    float pkam, lkam;
    cout << "Masukkan Pangjang Kamar    : "; cin >> pkam;
    cout << "Masukkan Luas Kamar        : "; cin >> lkam;
    float luaskam = multiply(pkam, lkam);
    float pker, lker;
    cout << "Masukkan Panjang Keramik   : "; cin >> pker;
    cout << "Masukkan Luas Keramik      : "; cin >> lker;
    float luasker = multiply(pker, lker);
    float jmlker = divide(luaskam, luasker);
    float iksd;
    cout << "Masukkan Isi Keramik per-Kardus    : "; cin >> iksd;
    float jmldus = roundingUp(divide(jmlker, iksd));
    float hrg;
    cout << "Masukkan Harga per-Dus             : "; cin >> hrg;
    float uang = multiply(jmldus, hrg);
    cout << "Anda Harus Membayar: " << uang;
    return 0;
}