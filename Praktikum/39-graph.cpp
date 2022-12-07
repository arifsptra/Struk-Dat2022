#include <iostream>

using namespace std;

struct peta{
    int jarak;
};

struct peta sales[4][4];
string kota[4] = {"Pati", "Semarang", "Yogyakarta", "Bandung"};

int main(){
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            cout << "Inputkan Jarak dari " << kota[i] << " Ke " << kota[j] << ": ";
            if(i==j){
                sales[i][j].jarak = 0;
                cout << sales[i][j].jarak << endl;
            }else if(i>j){
                sales[i][j].jarak = sales[j][i].jarak;
                cout << sales[i][j].jarak << endl;
            }else{
                cin >> sales[i][j].jarak;
            }
        }
    }
    cout << endl;
    cout << "Datanya: " << endl;
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            cout << sales[i][j].jarak << "\t";
        }
        cout << endl;
    }
    return 0;
}