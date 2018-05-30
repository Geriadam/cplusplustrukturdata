#include <iostream>
#include <stdlib.h>
using namespace std;

struct node{
    string nama;
    int absen;
    node *next;
};

node *head;
node *tail;
node *baru;

void masuk(string nama, int absen){
    baru        = new node;
    baru->nama  = nama;
    baru->absen = absen;
    if(head==NULL){
        head = baru;
        head->next = NULL;
    }
    else{
        baru->next = head;
        head = baru;
    }
    cout<<"Data berhasil di tambahkan ";
}

void masukkan(){
    baru = new node;
    cout<<"Masukkan Nama ";
    cin>>baru->nama;
    cout<<"Masukkan Absen ";
    cin>>baru->absen;
    masuk(baru->nama, baru->absen);
}

void tampil(){
    cout<<endl;
    cout<<"====================================="<<endl;
    while(head!=NULL){
        cout<<"Nama anda  = \t"<<head->nama<<endl;
        cout<<"Absen anda = \t"<<head->absen<<endl;
        head=head->next;
        cout<<"==============================="<<endl;
    }
}

void menu(){
    cout<<"--- Menu --- "<<endl;
    cout<<"1. Masukkan Data "<<endl;
    cout<<"2. Lihat Data "<<endl;
    cout<<"Masukkan Pilihan = ";
}

int main(){
    int pilihan;
    char ulang;
    do {
        menu();
        cin>>pilihan;
        if(pilihan == 1){
            masukkan();
        }
        else if(pilihan == 2){
            tampil();
        }
        else{
            cout<<"Pilihan salah "<<endl;
        }

        cout<<"Apakah anda ingin mengulang ? ";
        cin>>ulang;
        system("cls");
    } while (ulang == 'y' || ulang == 'Y');
}
