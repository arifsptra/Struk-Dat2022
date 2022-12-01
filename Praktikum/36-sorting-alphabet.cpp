#include <iostream>
#include <bits/stdc++.h>
#include <string>

using namespace std;

struct contact{
    string names;
    int numbers;
};

contact buku_telepon;

vector<contact> C;

void print(vector<contact> na){
    for(int i=0; i<C.size();i++){
        cout << C[i].names << endl;
        cout << "0" << C[i].numbers << endl << endl;
    }
}

bool mycomp(contact &a, contact &b){
    return a.names < b.names;
};

vector<contact> alphabeticallySort(vector<contact> a){
    int n=a.size();
    sort(a.begin(), a.end(), mycomp);
    return a;
}

void input(){
    contact pp;
    cout << "Nama: "; cin >> pp.names;
    cout << "Number: "; cin >> pp.numbers;
    // pp.names = nmplayer[i];
    // pp.numbers = number[i];
    C.push_back(pp);
    C = alphabeticallySort(C);
}

int main(){
    // int n;
    // cout << "enter number of names to be added"; cin >> n;
    // string name;
    // int number;
    // for(int i=0; i<n; i++){
    //     cout << "Name: " << endl;
    //     cin >> name;
    //     cout << "Number: " << endl;
    //     cin >> number;
    //     c.names.push_back(name);
    //     c.numbers.push_back(number);
    // }

    // c = alphabeticallySort(c.names);

    // cout << "Setelah terurut" << endl;
    // print(c);
    int pilih;
    do{
        cin >> pilih;
        switch (pilih)
        {
        case 1:
            input();
            break;
        case 2:
            print(C);
            break;
        default:
            break;
        }
    }while(pilih!=3);
    return 0;
}
