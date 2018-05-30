#include <iostream>
#include <stdlib.h>
using namespace std;

struct node{
    int absen;
    node *next;
    node *prev;
} *head, *tail, *after, *baru;

int pilihan;
char ulang;

void init(){
    head = tail = NULL;
}

void masuk(int absen, int type){
    int letak;
    baru = new node;
    baru->absen = absen;
    baru->next = baru->prev = NULL;
    letak = absen;
    if(head == NULL){
        head = baru;
        tail = baru;
    }
    else if(type == 1){
        baru->next = head;
        head->prev = baru;
        head = baru;
    }
    else if(type == 2){
        baru->prev = tail;
        tail->next = baru;
        tail = baru;
    }
    cout<<"Data berhasil di tambahkan"<<endl;
}

void masuk_tengah(int absen, int letak){
    baru = new node;
    baru->absen = absen;
    if(head==NULL){
        head = tail = baru;
    }
    else{
        after = head;
        while(after->absen!=letak)
            after = after->next;
        baru->prev = after;
        baru->next = after->next;
        after->next->prev = baru;
        after->next = baru;
    }
}

void masukkanDepan(){
    cout<<endl;
    baru = new node;
    cout<<"Masukkan data absen ";
    cin>>baru->absen;
    masuk(baru->absen, 1);
}

void masukkanBelakang(){
    cout<<endl;
    baru = new node;
    cout<<"Masukkan data absen ";
    cin>>baru->absen;
    masuk(baru->absen, 2);
}

void masukkanTengah(){
    cout<<endl;
    int letak;
    baru = new node;
    cout<<"Masukkan letak ";
    cin>>letak;
    cout<<"Masukkan data absen ";
    cin>>baru->absen;
    masuk_tengah(baru->absen, letak);
}

void tampil(){
    cout<<endl;
    int i=0;
    baru = head;
    cout<<"==================================================================="<<endl;
    while(baru!=NULL){
        i++;
        cout<<"Data absen "<<baru->absen<<endl;
        baru=baru->next;
        cout<<"===============================[ "<<i<<" ]==============================="<<endl;
    }
}

void menu(){
    cout<<"--- Menu --- "<<endl;
    cout<<"1. Insert Depan "<<endl;
    cout<<"2. Insert Belakang "<<endl;
    cout<<"3. Insert Tengah "<<endl;
    cout<<"4. Lihat Data "<<endl;
    cout<<"Masukkan Pilihan = ";
    cin>>pilihan;
    if(pilihan == 1){
        masukkanDepan();
    }
    else if(pilihan == 2){
        masukkanBelakang();
    }
    else if(pilihan == 3){
        masukkanTengah();
    }
    else if(pilihan == 4){
        tampil();
    }
    else{
        cout<<"Pilihan salah "<<endl;
    }
}

int main(){
    init();
    do {
        menu();
        cout<<"Apakah anda ingin mengulang ? ";
        cin>>ulang;
        system("cls");
    } while (ulang == 'y' || ulang == 'Y');
}


