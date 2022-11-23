#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <conio.h>

using namespace std;

vector <int> V;

int data;
void inputData(){
	cout << "Masukkan data: ";cin>>data;
}

void tampil(){
	for(int i=0; i<V.size(); i++){
		cout << V[i] << endl;
	}
}

void insertAfter(){
}

int main()
{
	int pilih;
	do
	{
		system("cls");
		cout<<"1. Menambah Data Didepan"<<endl;
		cout<<"2. Menambah Data Belakang"<<endl;
		cout<<"3. Menambah Data DiTengah"<<endl;	
		cout<<"4. Menghapus Data DiDepan"<<endl;	
		cout<<"5. Menghapus Data DiBelakang"<<endl;	
		cout<<"6. Menghapus Data DiTengah"<<endl;	
		cout<<"7. Menampilkan Data"<<endl;
		cout<<"8. Sorting Data"<<endl;
		cout<<"9. Keluar"<<endl;
		
		cout<<"Pilihan Anda [1-9] : ";cin>>pilih;
		switch (pilih)
		{
		case 1:
			inputData();
			V.insert(V.begin(), data);
			break;
		case 2:
			inputData();
			V.push_back(data);
			break;
		case 3:
			inputData();
			insertAfter();
			break;
		case 4:
			V.erase(V.begin());
			break;
		case 5:
			V.pop_back();
			break;
		case 6:
			break;
		case 7:
			tampil();
			break;
		case 8:
			sort(V.begin(), V.end());
		default:
			break;
		}
		getch();
	}
	while(pilih!=9);
	
	return 0;
}
