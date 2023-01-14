#include <iostream>
#include <conio.h>
#include <bits/stdc++.h>
#include <string>

using namespace std;

struct node {
    string judul;
    int durasi;
    node *prev;
    node *next;
};

node *tail = NULL;
node *head = NULL;

void insert(){
    node *baru;
    node *bantu;
    baru = new node;
    cout << "Masukkan Judul: "; cin >> baru->judul;
    cout << "Masukkan Durasi: "; cin >> baru->durasi;
    baru->next = NULL;
    baru->prev = NULL;
    if(head==NULL){
        head = baru;
        tail = baru;
        tail->next = head;
        head->prev = tail;
    }else {
        string data;
        cout << "Setelah Data: "; cin >> data;
        bantu = head;
        do{
            if(data==bantu->judul){
                baru->next = bantu->next;
                baru->prev = bantu;
                bantu->next = baru;
                bantu->next->prev = baru;
            }
            bantu = bantu->next;
        }while(bantu!=head);
    }
};

void deleteData(){
    node *hapus;
    if(head==NULL){
        cout << "List Masih Kosong";
    }else if(head==tail){
        delete head;
        head = NULL;
        tail = NULL;
    }else{
        hapus = tail;
        tail = tail->prev;
        cout << hapus->judul << " Terhapus";
        delete hapus;
        tail->next = head;
        head->prev = tail;
    }
}

void show(){
    node *bantu;
    bantu = head;
    int i=0;
    if(head==NULL){
        cout << "Data Not Found!";
    }else{
        do {
            cout << bantu->judul << endl;
            cout << bantu->durasi << endl;
            cout << endl;
            bantu = bantu->next;
            i++;
        }while(bantu!=head);
    }
}

int main(){
    int choose;
    do{
        system("cls");
        cout << "---- Welcome to node App ----" << endl;
        cout << "  1. Insert" << endl;
        cout << "  2. Delete" << endl;
        cout << "  3. Show" << endl;
        cout << "  4. Exit" << endl;
        cout << endl << "Choose [1-5]: ";
        cin >> choose;
        switch (choose)
        {
        case 1: system("cls"); {
            insert();
            break;
        }
        case 2: system("cls"); {
            deleteData();
            break;
        }
        case 3: system("cls"); {
            show();
            break;
        }
        default:
            break;
        }
        getch();
    } while(choose!=4);
    return 0;
}