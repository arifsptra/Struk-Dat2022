#include <iostream>
#include <vector>

using namespace std;

struct peta{
    int jarak;
};

struct peta sales[7][7] = {{0, 7, 0, 5, 0, 0, 0,},
                            {7, 0, 8, 9, 7, 0, 0}, 
                            {0, 8, 0, 0, 5, 0, 0}, 
                            {5, 9, 0, 0, 15, 6, 0}, 
                            {0, 7, 5, 15, 0, 8, 9},
                            {0, 0, 0, 6, 8, 0, 11}, 
                            {0, 0, 0, 0, 9, 11, 0}};

vector <int> tampung;

int cariTampung(int a){
    for(int i=0; i<tampung.size(); i++){
        if(a==tampung[i]){
            return 1;
            break;
        }
    }
    return 0;
}

int main(){
    cout << "Datanya: " << endl;
    for(int i=0; i<7; i++){
        for(int j=0; j<7; j++){
            cout << sales[i][j].jarak << "\t";
            if(sales[i][j].jarak != 0){
                if(cariTampung(sales[i][j].jarak) == 0){
                    tampung.push_back(sales[i][j].jarak);
                }
            }
        }
        cout << endl;
    }

    for(int i=0; i<tampung.size(); i++){
        cout << tampung[i] << " ";
    }
    return 0;
}