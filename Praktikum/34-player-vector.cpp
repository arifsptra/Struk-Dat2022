// Tugas Kelompok 

// 1. Arif Saputra                      - A11.2021.13480
// 2. Nikolas Adi Kurniatmaja Sijabat   - A11.2021.13800
// 3. Vander Mulya                      - A11.2021.13343

#include<iostream>
#include<vector>
#include<conio.h>
#include<algorithm>
#include<string.h>
#include <bits/stdc++.h>

using namespace std;
struct player
{
    char nama[30];
    int nilai;

};
vector <player> V;
int maksimal=5;

// Fungsi untuk membandingkan nilai pemain
bool compare(player &x, player &y)
{
	return x.nilai > y.nilai;
}

int main()
{
    int p=0;
    string nmplayer[10]={"Agus","Indah","Heru","Kiki","Bagus","Yuli","Budi","Carlie","Linda","Putri"};
    int point[10]={100,50,110,120,80,90,140,95,160,115};
    cout<<"Daftar Player dan Nilai"<<endl;
    for(int a=0;a<10;a++)
    {
        system("cls");

        // 1. Lakukan Penambahan Data Dibelakang
        V.push_back(player());
        strcpy(V[a].nama, nmplayer[a].c_str());
        V[a].nilai = point[a];

        // 2. Sorting Data secara DESCENDING
        sort(V.begin(), V.end(), compare);

        // Hapus Data paling belakang, jika data yg ada > maksimal
		if (V.size() > maksimal)
		{
			V.insert(V.end() - 1, player());
            V.erase(V.end() - 1);
		}

        // Tampilkan Data
        if(a<maksimal){
            p++;
        }
		for (int i=0; i<p; i++)
		{
            cout << V[i].nama << " " << V[i].nilai << endl;
		}
	    cout << endl;
        getch();
    }
    return 0;
}
