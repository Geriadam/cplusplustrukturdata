#include <iostream>
#include <stdlib.h>
#include "praktikum.h"
using namespace std;

int pilihan, cari;
void menu(){
    cout<<"Total data = "<<total<<endl;
    cout<<"--- Menu --- "<<endl;
    cout<<"1. Insert "<<endl;
    cout<<"2. Sorting "<<endl;
    cout<<"3. Search "<<endl;
    cout<<"4. Lihat Data "<<endl;
    cout<<"Masukkan Pilihan = ";
    cin>>pilihan;
    if(pilihan == 1){
        masukkanDepan();
    }
    else if(pilihan == 2){
        sorting();
        cout<<"Data berhasil di sorting"<<endl;
    }
    else if(pilihan == 3){
        if(isSortingDulu){
            cout<<"Masukkan nomor yang di cari ";
            cin>>cari;
            temp = fungsi_cari(cari);
            if(temp != NULL){
                cout<<"nomor "<<temp->nomor<<" ketemu"<<endl;
            } else {
                cout<<"Data tidak ketemu"<<endl;
            }
        } else {
            cout<<"Harus sorting dahulu"<<endl;
        }
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
