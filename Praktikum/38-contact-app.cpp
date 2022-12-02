#include <iostream>
#include <conio.h>
#include <bits/stdc++.h>
#include <string>

using namespace std;

struct contact {
    string names;
    string phoneNumbers;
    contact *prev;
    contact *next;
};

contact *tail = NULL;
contact *head = NULL;

void insert(){
    contact *baru;
    baru = new contact;
    cout << "Your Name: "; cin >> baru->names;
    cout << "Your Phone Number: "; cin >> baru->phoneNumbers;
    baru->next = NULL;
    baru->prev = NULL;
    if(head==NULL) {
        head = baru;
        tail = baru;
        tail->next = head;
        head->prev = tail;
    } else {
        baru->next = head;
        head->prev = baru;
        head = baru;
        tail->next = head;
        head->prev = tail;
    }
};

void search(){
    contact *bantu;
    if(head==NULL){
        cout << "Data Still Empty!";
    }else{
        int done = 0;
        string name;
        cout << "Search Data: "; cin >> name;
        cout << endl;
        bantu = head;
        do{
            if(name==bantu->names){
                done = 1;
                cout << bantu->names << endl;
                cout << bantu->phoneNumbers << endl;
                cout << "in Memory " << &bantu->names;
                cout << endl << endl;
            }
            bantu = bantu->next;
        }while(bantu!=head);
        if(done==0){
            cout << "Data Not Found!";
        }
    }
}

void deleteData(){
    contact *hapus;
    contact *bantu;
    int done = 0;
    if(head==NULL){
        cout << "Data Still Empty!";
    }else if(head==tail){
        cout << head->names << " Deleted";
        delete head;
        head = NULL;
        tail = NULL;
    }else{
        string data;
        cout << "Delete Data: "; cin >> data;
        bantu = head;
        do{
            if(data==bantu->names){
                if(data==head->names){
                    done=1;
                    hapus = head;
                    head = head->next;
                    cout << hapus->names << " Deleted";
                    delete hapus;
                    tail->next = head;
                    head->prev = tail;
                }else if(data==tail->names){
                    done=1;
                    hapus = tail;
                    tail = tail->prev;
                    cout << hapus->names << " Deleted";
                    delete hapus;
                    tail->next = head;
                    head->prev = tail;
                }else{
                    done=1;
                    bantu->prev->next = bantu->next;
                    bantu->next->prev = bantu->prev;
                    cout << bantu->names << " Deleted";
                    delete hapus;
                }
            }
            bantu = bantu->next;
        }while(bantu!=head);
        if(done==0){
            cout << "Data Not Found!";
        }
    }
}

void edit(){
    contact *bantu;
        int done = 0;
        string name;
        cout << "Search Data: "; cin >> name;
        cout << endl;
        bantu = head;
        do{
            if(name==bantu->names){
                done = 1;
                cout << "Edit Your Data" << endl;
                cout << "Your Name: "; cin >> bantu->names;
                cout << "Your Phone Number: "; cin >> bantu->phoneNumbers;
                cout << endl << endl;
            }
            bantu = bantu->next;
        }while(bantu!=head);
        if(done==0){
            cout << "Data Not Found!";
        }
}

void show(){
    contact *bantu;
    bantu = head;
    int i=0;
    if(head==NULL){
        cout << "Data Not Found!";
    }else{
        do {
            cout << bantu->names << endl;
            cout << bantu->phoneNumbers << endl;
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
        cout << "---- Welcome to Contact App ----" << endl;
        cout << "  1. Insert" << endl;
        cout << "  2. Search" << endl;
        cout << "  3. Delete" << endl;
        cout << "  4. Show" << endl;
        cout << "  5. Edit" << endl;
        cout << "  6. Exit" << endl;
        cout << endl << "Choose [1-5]: ";
        cin >> choose;
        switch (choose)
        {
        case 1: system("cls"); {
            insert();
            break;
        }
        case 2: system("cls"); {
            search();
            break;
        }
        case 3: system("cls"); {
            deleteData();
            break;
        }
        case 4: system("cls"); {
            show();
            break;
        }
        case 5: system("cls"); {
            edit();
            break;
        }
        default:
            break;
        }
        getch();
    } while(choose!=6);
    return 0;
}