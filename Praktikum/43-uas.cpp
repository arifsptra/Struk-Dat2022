#include <iostream>
#include <conio.h>
// #include <>

using namespace std;

struct lagu{
    string judul;
    int durasi;
    string genre;
    lagu *prev;
    lagu *next;
};

lagu *head = NULL;
lagu *tail = NULL;

string jdl[10] = {"Hati Hati Dijalan", "Ambyar", "Sisa Rasa", "What have You Done", "Going Under", "The Catalyst", "Menghapus Jejakmu", "Milik Orang"};
int drs[10] = {4, 6, 5, 6, 5, 7, 6, 8};
string gnr[10] = {"POP", "DANGDUT", "POP", "ROCK", "ROCK", "ROCK", "POP", "DANGDUT"};
string kelgnr[10];

// void kelompokGenre(){
//     int x=0;
//     for(int i = 0; i < 10; i++){
//         if(i==0){
//             kelgnr[x]=gnr[i];
//             x++;
//         }else{
//             for(int j = 0; j < x; j++){
//                 if(kelgnr[x-1]!=gnr[i]){
//                     kelgnr[x] = gnr[i];
//                     x++;
//                 }
//             }
//         }
//     }
// }

void templateInput(){
    cin.ignore();
    cout << "Masukkan Judul: ";  std::getline(std::cin, jdl[9]);
    cout << "Masukkan Durasi: "; cin >> drs[9];
    cout << "Masukkan Genre: "; cin >> gnr[9];
}

void tambahBelakang(string j, int d, string g){
    lagu *baru;
    baru = new lagu;
    baru->judul = j;
    baru->durasi = d;
    baru->genre = g;
    baru->next = NULL;
    baru->prev = NULL;
    if(head==NULL){
        head = baru;
        tail = baru;
        tail->next = head;
        head->prev = tail;
    }else {
        tail->next = baru;
        baru->prev = tail;
        tail = baru;
        tail->next = head;
        head->prev = tail;
    }
}

void hapusData(){
    lagu *hapus;
    lagu *bantu;
    int done = 0;
    if(head==NULL){
        cout << "Data Still Empty!";
    }else if(head==tail){
        cout << head->genre << " Deleted";
        delete head;
        head = NULL;
        tail = NULL;
    }else{
        string data;
        cout << "Delete Data: "; cin >> data;
        for(int i=0; i<3; i++){
            bantu = head;
            do{
                if(data==bantu->genre){
                    if(data==head->genre){
                        done=1;
                        hapus = head;
                        head = head->next;
                        cout << hapus->genre << " Deleted" << endl;
                        delete hapus;
                        tail->next = head;
                        head->prev = tail;
                    }else if(data==tail->genre){
                        done=1;
                        hapus = tail;
                        tail = tail->prev;
                        cout << hapus->genre << " Deleted" << endl;
                        delete hapus;
                        tail->next = head;
                        head->prev = tail;
                    }else{
                        done=1;
                        bantu->prev->next = bantu->next;
                        bantu->next->prev = bantu->prev;
                        cout << bantu->genre << " Deleted" << endl;
                        delete hapus;
                    }
                }
                bantu = bantu->next;
            }while(bantu!=head);
        }
        if(done==0){
            cout << "Data Not Found!";
        }
    }
}

void tampilData(){
    lagu *bantu;
    bantu = head;
    do {
        cout << bantu->genre << "\t\t" << bantu->durasi << "\t" << bantu->judul << endl;
        bantu = bantu->next;
    } while(bantu!=head);
}

void cariData(){
    lagu *bantu;
    bantu=head;
    string cari1, cari2;
    bool ketemu=false;
    int x=1;
    if(head==NULL)
    {
        cout<<"Data Kosong"<<endl;  getch();
    }
    else
    {
        cout<<"Masukkan Genre 1 : ";
        cin.ignore(1, '\n');
        getline(cin,cari1);
        cout << "\n\nGenre Lagu yang dicari ";
        do
        {
            if(cari1==bantu->genre)
            {
                ketemu=true;
                cout<< x << " ";
            }
            bantu=bantu->next;
            x++;
        }
        while(bantu!=head);
        x = 1;
        cout << "\n\nGenre lagu lainnya\n" << endl;
        do
        {
            if(cari1!=bantu->genre)
            {
                ketemu=true;
                cout<< bantu->genre << " diurutan : " << x << " "<<endl;
            }
            bantu=bantu->next;
            x++;
        }
        while(bantu!=head);
        getch();
    }
    if (ketemu==false)
    {
        cout<<"Genre Tidak Ditemukan"<<endl;  getch();
    }
}

int main(){
    for(int i=0; i<8; i++){
        // cout << jdl[i] << " " << drs[i] << " " << gnr[i] << endl;
        tambahBelakang(jdl[i], drs[i], gnr[i]);
    }

    int pilih;
    do{
        system("cls");
        cout << "Implementasi DLL: Player Musik" << endl;
        cout << "1. Tambah Belakang" << endl;
        cout << "2. Hapus Data" << endl;
        cout << "3. Tampil Data" << endl;
        cout << "4. Cari Data" << endl;
        cout << "5. Exit" << endl;
        cout << endl << "Pilihan Anda [1-5]: "; 
        cin >> pilih;
        switch (pilih)
        {
        case 1: system("cls");
            templateInput();
            tambahBelakang(jdl[9], drs[9], gnr[9]);
            break;
        case 2: system("cls");
            hapusData();
            break;
        case 3: system("cls");
            tampilData();
            break;
        case 4: system("cls");
            cariData();
            break;
        default:
            break;
        }
        getch();
    }while(pilih!=5);
    return 0;
}