#include <iostream>
#include <conio.h>

using namespace std;

struct stack
{
    string nama_paket;
    int berat;
    stack *next;
};

stack *head=NULL, *tail=NULL;
int top=1;
int maxs=5;

int isEmpty(){
    if(tail==NULL)return 1;
    else return 0;
}

void insert_belakang(){
    stack *bantu;
    bantu = new stack;
    cout << "Masukkan Nama Paket: "; cin >> bantu->nama_paket;
    cout << "Masukkan Berat: "; cin >> bantu->berat;
    bantu->next = NULL;
    if(head == NULL){
        head = bantu;
        tail = bantu;
    }else{
        tail->next = bantu;
        tail = bantu;
    }
}

void delete_belakang(){
    stack *hapus, *bantu;
    bantu=head;
    string d;
    hapus=tail;
    do{
        if(bantu->next->nama_paket==tail->nama_paket){
            tail=bantu;
            d=tail->next->nama_paket;
            delete hapus;
            tail->next=NULL;
            top--;
        }
        bantu=bantu->next;
    }while(bantu!=NULL);
    cout<<d<<" terhapus";
}

void tampil_data(){
    stack *bantu;
    bantu = head;
    if(isEmpty()==0)
        {
            while(bantu!=NULL)
            {
                cout << "Nama Paket: " << bantu->nama_paket << endl;
                cout << "Berat: " << bantu->berat << endl << endl;
                bantu=bantu->next;
            }
        }else cout <<"Data is empty!\n";
}

int main()
{
    int pilih;
    do{
        system("cls");
        cout<<"MENU STACK"<<endl;
        cout<<"1. Push Data"<<endl;
        cout<<"2. Pop Data"<<endl;
        cout<<"3. Tampil Data"<<endl;
        cout<<"4. Keluar"<<endl;
        cout<<endl<<"Choose [1-4] : ";
        cin>>pilih;
        switch (pilih){
            case 1: system("cls"); {
                if(top<=maxs){
                    insert_belakang();
                    top++;
                }else{
                    cout << "Sorry, memory is full!" << endl;
                }
                break;
            }
            case 2: system("cls"); {
                delete_belakang();
                break;
            }
            case 3: system("cls"); {
                tampil_data();
                break;
            }case 4: system("cls");{
                return 0;
                break;
            }
            default: system("cls"); {
                cout << "Please, correct your input!";
            }
        }
        getch();
    } while(pilih!=4);
    return 0;
}
