#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

vector <int> V;

void tampil(){
    for(int x=0; x<V.size(); x++){
        cout << V[x] << endl;
    }
}

int main(){
    // Tambah data dibelakang
    V.push_back(28);
    V.push_back(43);
    // Tambah data didepan
    V.insert(V.begin(), 19);
    V.insert(V.begin(), 20);
    // Tambah data ditengah
    V.insert(V.begin()+2, 93);
    V.insert(V.begin()+4, 63);
    // Menghapus data didepan
    V.erase(V.begin());
    // Menghapus data dibelakang
    V.pop_back();
    // Menghapus data ditengah
    V.erase(V.begin()+2);
    // Mengurutkan data
    sort(V.begin(), V.end());

    tampil();

    return 0;
}