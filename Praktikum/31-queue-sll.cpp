#include <iostream>
#include <conio.h>

using namespace std;

struct queue
{
    string nama;
    int nilai;
    queue *next;
};

queue *head=NULL, *tail=NULL;
int top=1;
int maxs=5;

int isEmpty(){
    if(tail==NULL)return 1;
    else return 0;
}

void insert_belakang(){
    queue *bantu;
    bantu = new queue;
    cout << "Masukkan Nama: "; cin >> bantu->nama;
    cout << "Masukkan Nilai: "; cin >> bantu->nilai;
    bantu->next = NULL;
    if(head == NULL){
        head = bantu;
        tail = bantu;
    }else{
        tail->next = bantu;
        tail = bantu;
    }
}

void delete_depan(){
    queue *hapus;
    string d;
    if (isEmpty()==0)
    {
        if(head!=tail)
        {
            hapus=head;
            d=hapus->nama;
            head=head->next;
            delete hapus;
            top--;
        }else
        {
            d=tail->nama;
            head=tail=NULL;
        }
    cout<<d<<" terhapus";
    }else cout<<"Masih kosong\n";
}

void tampil_data(){
    queue *bantu;
    bantu = head;
    if(isEmpty()==0)
        {
            while(bantu!=NULL)
            {
                cout << "Nama: " << bantu->nama << endl;
                cout << "Nilai: " << bantu->nilai << endl << endl;
                bantu=bantu->next;
            }
        }else cout <<"Data is empty!\n";
}


int main()
{
    int pilih;
    do
    {
        system("cls");
        cout<<"MENU QUEUE"<<endl;
        cout<<"1. Inqueue"<<endl;
        cout<<"2. Dequeue"<<endl;
        cout<<"3. Tampil Data"<<endl;
        cout<<"4. Keluar"<<endl;
        cout<<endl<<"Pilihan anda [1-4] : ";
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
                delete_depan();
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
    }
    while(pilih!=4);
    return 0;
}
