// Udinus akan membantu korban bencana alam dengan mengirim sembako.
// Paket sembako dikemas pada wadah berupa Tabung.
// dan semua paket2 tsb akan dimasukan ke peti kemas.
// Buatlah program untuk Menentukan Berapa Paket Sembako
// yang bisa dimasukan kedalam Peti Kemas?

#include <iostream>

using namespace std;

int main(){
    int ppk, lpk, tpk;
    cout << "Masukkan Panjang Peti Kemas    : "; cin >> ppk;
    cout << "Masukkan Lebar Peti Kemas      : "; cin >> lpk; 
    cout << "Masukkan Tinggi Peti Kemas     : "; cin >> tpk;
    int volpk = ppk*lpk*tpk;
    int jari, tingtab;
    cout << "Masukkan Jari-Jari             : "; cin >> jari;
    cout << "Masukkan Tinggi Tabung         : "; cin >> tingtab;
    int voltab = 3.14*(jari*jari)*tingtab;
    int jmltab = volpk/voltab;
    cout << "Paket Sembako yang dapat dimasukkan: " << jmltab;
    cout << endl;
    cout << volpk << " " << voltab << " " << jmltab << endl;
    return 0;
}