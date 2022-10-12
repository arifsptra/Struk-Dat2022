#include <stdio.h>
#include <iostream>
#include <conio.h>
#include <stdlib.h>

using namespace std;

struct TNode{
    int data;
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

void insertDepan(int databaru)
{
    TNode *baru;
    baru = new TNode;
    baru->data = databaru;
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

void insertBelakang(int databaru){
    TNode *baru;
    baru = new TNode;
    baru->data = databaru;
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

void insertSetelah(int databaru){
    TNode *baru;
    baru = new TNode;
    baru->data = databaru;
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
            if(setelah==bantu->data){
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

void tampil(){
    TNode *bantu;
    bantu=head;
        if(isEmpty()==0)
        {
            while(bantu!=NULL)
            {
                cout<<bantu->data<<" ";
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
            d=hapus->data;
            head=head->next;
            delete hapus;
        }else
        {
            d=tail->data;
            head=tail=NULL;
        }
    cout<<d<<"terhapus";
    }else cout<<"Masih kosong\n";
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
    int pil, databaru;
    do
    {
        system("cls");
        cout<<endl;
        cout<<" ============================"<<endl;
        cout<<" =   PROGRAM LINKED LIST    ="<<endl;
        cout<<" ============================"<<endl;
        cout<<" = 1. Insert Depan          ="<<endl;
        cout<<" = 2. Insert Belakang       ="<<endl;
        cout<<" = 3. Insert Setelah        ="<<endl;
        cout<<" = 4. Delete Depan          ="<<endl;
        cout<<" = 5. Tampil Data           ="<<endl;
        cout<<" = 6. Clear                 ="<<endl;
        cout<<" = 7. Exit                  ="<<endl;
        cout<<" ============================"<<endl;
        cout<<" Masukan Pilihan : ";cin>>pil;
        switch (pil)
        {
            case 1: system("cls");{
                cout<<"Masukan Data = ";cin>>databaru;
                insertDepan(databaru);
                break;
            }
            case 2: system("cls");{
                cout<<"Masukan Data = ";cin>>databaru;
                insertBelakang(databaru);
                break;
            }
            case 3: system("cls");{
                cout<<"Masukan Data = ";cin >>databaru;
                insertSetelah(databaru);
                break;
            }
            case 4: system("cls");{
                hapusDepan();
                break;
            }
            case 5: system("cls");{
                tampil();
                break;
            }
            case 6: system("cls");{
                clear();
                break;
            }
            case 7: system("cls");{
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
    while (pil!=7);
}