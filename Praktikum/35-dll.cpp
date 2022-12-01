#include <iostream>
#include <conio.h>

using namespace std;

struct dll {
    int nilai;
    dll *next;
    dll *prev;
};

dll *head = NULL;
dll *tail = NULL;

int nilaiData;

void inputData(){
    cout << "Masukkan Nilai: "; cin >> nilaiData;
};

void tambahDataDepan(int nilaiData){
    dll *baru;
    baru = new dll;
    baru->nilai = nilaiData;
    baru->next = NULL;
    baru->prev = NULL;
    if(head==NULL) { // Jika list masih kosong
        head = baru;
        tail = baru;
        tail->next = head;
        head->prev = tail;
    } else { // jika list sudah ada isinya
        baru->next = head;
        head->prev = baru;
        head = baru;
        tail->next = head;
        head->prev = tail;
    }
}

void tambahDataTengah(int nilaiData){
    dll *baru;
    dll *bantu;
    baru = new dll;
    baru->nilai = nilaiData;
    baru->next = NULL;
    baru->prev = NULL;
    if(head==NULL){
        head = baru;
        tail = baru;
        tail->next = head;
        head->prev = tail;
    }else {
        int data;
        cout << "Setelah Data: "; cin >> data;
        bantu = head;
        do{
            if(data==bantu->nilai){
                baru->next = bantu->next;
                baru->prev = bantu;
                bantu->next = baru;
                bantu->next->prev = baru;
            }
            bantu = bantu->next;
        }while(bantu!=head);
    }
}

void tambahDataBelakang(int nilaiData){
    dll *baru;
    baru = new dll;
    baru->nilai = nilaiData;
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

void hapusDataDepan(){
    dll *hapus;
    if(head==NULL){
        cout << "List Masih Kosong";
    }else if(head==tail){
        cout << head->nilai << " Terhapus";
        delete head;
        head = NULL;
        tail = NULL;
    }else{
        hapus = head;
        head = head->next;
        cout << hapus->nilai << " Terhapus";
        delete hapus;
        tail->next = head;
        head->prev = tail;
    }
}

void hapusDataTengah(){
    dll *hapus;
    dll *bantu;
    int ketemu=0;
    if(head==NULL){
        cout << "List Masih Kosong";
    }else{
        int data;
        cout << "Hapus Data: "; cin >> data;
        bantu = head;
        do{
            if(data==bantu->nilai){
                ketemu=1;
                bantu->prev->next = bantu->next;
                bantu->next->prev = bantu->prev;
                cout << bantu->nilai << " Terhapus";
                delete hapus;
            }
            bantu = bantu->next;
        }while(bantu!=head);
        if(ketemu==0){
            cout << "Data Tidak ditemukan";
        }
    }
}

void hapusDataBelakang(){
    dll *hapus;
    if(head==NULL){
        cout << "List Masih Kosong";
    }else if(head==tail){
        delete head;
        head = NULL;
        tail = NULL;
    }else{
        hapus = tail;
        tail = tail->prev;
        cout << hapus->nilai << " Terhapus";
        delete hapus;
        tail->next = head;
        head->prev = tail;
    }
}

void cariData(){
    dll *bantu;
    if(head==NULL){
        cout << "List Masih Kosong";
    }else{
        int data;
        cout << "Hapus Data: "; cin >> data;
        bantu = head;
        do{
            if(data==bantu->nilai){
                cout << bantu->nilai << " Ketemu" << endl;
                cout << "di Memori " << &bantu->nilai;
            }
            bantu = bantu->next;
        }while(bantu!=head);
    }
}

void tampilDataDepan(){
    dll *bantu;
    bantu = head;
    do {
        cout << bantu->nilai << endl;
        bantu = bantu->next;
    } while(bantu!=head);
}

void tampilDataBelakang(){
    dll *bantu;
    bantu = tail;
    do {
        cout << bantu->nilai << endl;
        bantu = bantu->prev;
    } while(bantu!=tail);
}

int main(){
    int pilih;
    do {
        system("cls");
        cout << "Struktur Data: Double Linked List Circular" << endl;
        cout << "1. Tambah Data di Depan" << endl;
        cout << "2. Tambah Data di Tengah" << endl;
        cout << "3. Tambah Data di Belakang" << endl;
        cout << "4. Hapus Data di Depan" << endl;
        cout << "5. Hapus Data di Tengah" << endl;
        cout << "6. Hapus Data di Belakang" << endl;
        cout << "7. Cari Data" << endl;
        cout << "8. Tampil Data dari Depan" << endl;
        cout << "9. Tampil Data dari Belakang" << endl;
        cout << "10. Selesai" << endl;
        cout << endl << "Pilihan Anda [1-10]: ";
        cin >> pilih;
        switch (pilih)
        {
        case 1: system("cls"); {
            inputData();
            tambahDataDepan(nilaiData);
            break;
        }
        case 2: system("cls"); {
            inputData();
            tambahDataTengah(nilaiData);
            break;
        }
        case 3: system("cls"); {
            inputData();
            tambahDataBelakang(nilaiData);
            break;
        }
        case 4: system("cls"); {
            hapusDataDepan();
            break;
        }
        case 5: system("cls"); {
            hapusDataTengah();
            break;
        }
        case 6: system("cls"); {
            hapusDataBelakang();
            break;
        }
        case 7: system("cls"); {
            cariData();
            break;
        }
        case 8: system("cls"); {
            tampilDataDepan();
            break;
        }
        case 9: system("cls"); {
            tampilDataBelakang();
            break;
        }
        default:
            break;
        }
        getch();
    } while(pilih!=10);
    return 0;
}
