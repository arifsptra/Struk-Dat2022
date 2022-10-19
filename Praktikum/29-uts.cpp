#include <stdio.h>
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

struct TNode{
    int nilaiX;
    int nilaiY;
    string target;
    TNode *next;
};

TNode *head, *tail;

void init (){
    head = NULL;
    tail = NULL;
}

int isEmpty(){
    if(tail==NULL)return 1;
    else return 0;
}

int databaru1, databaru2;
string databaru3;

void inputData(){
    cout<<"Masukan Data X: ";cin>>databaru1;
    cout<<"Masukan Data Y: ";cin>>databaru2;
    cout<<"Masukkan Target: ";cin>>databaru3;
}

void insertDepan(int databaru1, int databaru2, string databaru3)
{
    TNode *baru;
    baru = new TNode;
    baru->nilaiX = databaru1;
    baru->nilaiY = databaru2;
    baru->target = databaru3;
    baru->next = NULL;
    if(isEmpty()==1)
    {
        head=tail=baru;
        tail->next=NULL;
    }else
    {
        baru->next = head;
        head=baru;
    }
    cout<<"Data masuk\n";
}

void insertBelakang(int databaru1, int databaru2, string databba3){
    TNode *baru;
    baru = new TNode;
    baru->nilaiX = databaru1;
    baru->nilaiY = databaru2;
    baru->target = databaru3;
    baru->next = NULL;
    if(head==NULL){
        head=baru;
        tail=baru;
    }else{
        tail->next = baru;
        tail=baru;
    }
    cout<<"Data masuk\n";
}

void insertSetelah(int databaru1, int databaru2, string databaru3){
    TNode *baru;
    baru = new TNode;
    baru->nilaiX = databaru1;
    baru->nilaiY = databaru2;
    baru->target = databaru3;
    TNode *bantu;
    bantu = new TNode;
    int setelah;
    if(head==NULL){
        head=baru;
        tail=baru;
    }else{
        cout<<"Setelah Data = ";cin >>setelah;
        int ketemu=0;
        bantu=head;
        do{
            if(setelah==bantu->nilaiX){
                baru->next = bantu->next;
                bantu->next = baru;
                ketemu=1;
            }
            bantu=bantu->next;
        }while(bantu!=NULL);
        if(ketemu==0){
            tail->next = baru;
            tail=baru;
        }
    }
    cout<<"Data masuk\n";
}

void insertSebelum(int databaru1, int databaru2, string databaru3){
    TNode *baru;
    baru = new TNode;
    baru->nilaiX = databaru1;
    baru->nilaiY = databaru2;
    baru->target = databaru3;
    TNode *bantu;
    bantu = new TNode;
    int sebelum;
    if(head==NULL){
        head=baru;
        tail=baru;
    }else{
        cout<<"Sebelum Data = ";cin >>sebelum;
        int ketemu=0;
        bantu=head;
        do{
            if(sebelum==bantu->next->nilaiX){
                baru->next = bantu->next;
                bantu->next = baru;
                ketemu=1;
                break;
            }
            bantu=bantu->next;
        }while(bantu!=NULL);
        if(ketemu==0){
            tail->next = baru;
            tail=baru;
        }
    }
    cout<<"Data masuk\n";
}

void cariData(){
    TNode *bantu;
    int cari;
    if(head==NULL){
        cout<<"Data Masih Kosong";
    }else{
        cout<<"Cari Data = ";cin >>cari;
        int ketemu=0;
        bantu=head;
        do{
            if(cari==bantu->nilaiX){
                cout<<bantu->nilaiX<<" ";
                cout<<bantu->nilaiY<<" ";
                cout<<bantu->target<<" ";
                cout<<"Ada di memori "<<bantu->next;
                ketemu=1;
            }
            bantu=bantu->next;
        }while(bantu!=NULL);
        if(ketemu==0){
            cout<<"Maaf, data tidak ditemukan!";
        }
    }
}

void tampil(){
    TNode *bantu;
    bantu=head;
        if(isEmpty()==0)
        {
            while(bantu!=NULL)
            {
                cout<<bantu->nilaiX<<" ";
                cout<<bantu->nilaiY<<" ";
                cout<<bantu->target<<" " << endl;
                bantu=bantu->next;
            }
        }else cout <<"Masih kosong\n";
}

void hapusDepan()
{
    TNode *hapus;
    int d;
    if (isEmpty()==0)
    {
        if(head!=tail)
        {
            hapus=head;
            d=hapus->nilaiX;
            head=head->next;
            delete hapus;
        }else
        {
            d=tail->nilaiX;
            head=tail=NULL;
        }
    cout<<d<<" terhapus";
    }else cout<<"Masih kosong\n";
}

void hapusBelakang()
{
    TNode *hapus, *bantu;
    bantu=head;
    int d;
    hapus=tail;
    do{
        if(bantu->next->nilaiX==tail->nilaiX){
            tail=bantu;
            d=tail->next->nilaiX;
            delete hapus;
            tail->next=NULL;
        }
        bantu=bantu->next;
    }while(bantu!=NULL);
    cout<<d<<" terhapus";
}

void hapusTengah(int hapusData){
    TNode *hapus, *bantu;
    bantu=head;
    do{
        if(bantu->next->nilaiX==hapusData){
            hapus=bantu->next;
            bantu->next=bantu->next->next;
            delete hapus;
            break;
        }
        bantu = bantu->next;     
    }while(bantu!=NULL);
    cout<<hapusData<<" terhapus";
}

void clear()
{
    TNode *bantu, *hapus;
    bantu =head;
    while(bantu!=NULL)
    {
        hapus=bantu;
        bantu=bantu->next;
        delete hapus;
    }
    head = NULL;
    printf("clear");
}

main()
{
    int pil;
    do
    {
        system("cls");
        cout<<endl;
        cout<<" ====================================="<<endl;
        cout<<" =        PROGRAM LINKED LIST        ="<<endl;
        cout<<" =   Arif Saputra - A11.2021.13480   ="<<endl;
        cout<<" ====================================="<<endl;
        cout<<" = 1. Insert Depan                   ="<<endl;
        cout<<" = 2. Insert Belakang                ="<<endl;
        cout<<" = 3. Insert Tengah Setelah data     ="<<endl;
        cout<<" = 4. Insert Tengah Sebelum data     ="<<endl;
        cout<<" = 5. Delete Depan                   ="<<endl;
        cout<<" = 6. Delete Belakang                ="<<endl;
        cout<<" = 7. Delete Tengah                  ="<<endl;
        cout<<" = 8. Mencari Data                   ="<<endl;
        cout<<" = 9. Menampilkan Data               ="<<endl;
        cout<<" = 10.Keluar                         ="<<endl;
        cout<<" ====================================="<<endl;
        cout<<" Masukan Pilihan Anda [1-10]: ";cin>>pil;
        switch (pil)
        {
            case 1: system("cls");{
                inputData();
                insertDepan(databaru1, databaru2, databaru3);
                break;
            }
            case 2: system("cls");{
                inputData();
                insertBelakang(databaru1, databaru2, databaru3);
                break;
            }
            case 3: system("cls");{
                inputData();
                insertSetelah(databaru1, databaru2, databaru3);
                break;
            }
            case 4: system("cls");{
                inputData();
                insertSebelum(databaru1, databaru2, databaru3);
                break;
            }
            case 5: system("cls");{
                hapusDepan();
                break;
            }
            case 6: system("cls");{
                hapusBelakang();
                break;
            }
            case 7: system("cls");{
                int hapusData;
                cout << "Hapus Data: "; cin >> hapusData;
                hapusTengah(hapusData);
                break;
            }
            case 8: system("cls");{
                cariData();
                break;
            }
            case 9: system("cls");{
                tampil();
                break;
            }
            case 10: system("cls");{
                return 0;
                break;
            }

            default: system("cls");
            {
                cout<<"\n Maaf, Pilihan yang anda pilih tidak tersedia!";
            }
        }
        getch();
    }
    while (pil!=10);
}