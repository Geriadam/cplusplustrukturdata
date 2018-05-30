#include <iostream>
#include <stdlib.h>
#include "praktikum.h"
using namespace std;

struct node{
    data_pembeli dpembeli;
    int nomor = 0;
    node *next;
    node *prev;
} *head, *tail, *baru, *after, *letak;

int pilihan;
char ulang;
char nama_barang[100];
int total = 0;

void init(){
    head = tail = NULL;
}

void masuk(data_pembeli dpembeli, int type){
    baru = new node;
    baru->dpembeli = dpembeli;
    baru->nomor++;
    baru->next = baru->prev = NULL;
    if(head==NULL){
        head = tail = baru;
    }
    else if(type == 1){
        baru->next = head;
        head->prev = baru;
        head = baru;
    }
    else if(type == 2){
        tail->next = baru;
        baru->prev = tail;
        tail = baru;
    }
    total++;
    cout<<"Data berhasil di tambahkan ";
}

void masuk_tengah(data_pembeli dpembeli, int nomor){
    int letak,i;
    letak = head->nomor;

    baru = new node;
    baru->nomor++;
    baru->dpembeli = dpembeli;
    if(head==NULL){
        head = tail = baru;
    }else{
        after = head;
        for(i=1;i<nomor;i++){
            after = after->next;
        }
        if(i==nomor&&after->next==NULL){
            tail->next = baru;
            baru->prev = tail;
            tail = baru;
        } else {
            baru->prev=after;
            baru->next=after->next;
            after->next->prev=baru;
            after->next=baru;
        }
    }
    total++;
}

void print(){
    cout<<"Nama barang \t :"<<baru->dpembeli.dpembelian.cbuku.nama_barang<<endl;
    cout<<"Harga barang \t :"<<baru->dpembeli.dpembelian.cbuku.harga<<endl;
    cout<<"Stok akhir \t :"<<baru->dpembeli.dpembelian.cbuku.stok<<endl;
    cout<<"Kota Penjual \t :"<<baru->dpembeli.dpembelian.cbuku.kota_penjual<<endl<<endl;

    cout<<"========== Jasa Pengantar ==========="<<endl;
    cout<<"Jasa \t\t :"<<baru->dpembeli.dpembelian.jp.nama_jasa<<endl;
    cout<<"Tarif \t\t :"<<baru->dpembeli.dpembelian.jp.tarif<<endl<<endl;

    cout<<"========== Detail Pembelian ========="<<endl;
    cout<<"Nama Pembeli \t :"<<baru->dpembeli.nama<<endl;
    cout<<"Alamat Pembeli \t :"<<baru->dpembeli.alamat<<endl;
    cout<<"Jumlah \t\t :"<<baru->dpembeli.dpembelian.jml_pembelian<<endl;
    cout<<"Total \t\t :"<<baru->dpembeli.dpembelian.total_pembelian<<endl<<endl;

    cout<<"========== Detail Pembayaran ========"<<endl;
    cout<<"Nama bank \t :"<<baru->dpembeli.dpembayaran.nama_bank<<endl;
    cout<<"No rekening \t :"<<baru->dpembeli.dpembayaran.no_rekening<<endl;
    cout<<"Jumlah Transfer  :"<<baru->dpembeli.dpembayaran.jml_transfer<<endl;
}

void inputan(){
    cout<<"Masukkan Nama Barang\t :";cin>>baru->dpembeli.dpembelian.cbuku.nama_barang;
    cout<<"Masukkan Harga:\t\t :";cin>>baru->dpembeli.dpembelian.cbuku.harga;
    cout<<"Masukkan stok:\t\t :";cin>>baru->dpembeli.dpembelian.cbuku.stok;
    cout<<"Masukkan Kota Penjual:\t :";cin>>baru->dpembeli.dpembelian.cbuku.kota_penjual;
    cout<<endl;

    cout<<"---- Jasa Pengantar ----"<<endl;

    cout<<"Masukkan jasa pengantar  :";cin>>baru->dpembeli.dpembelian.jp.nama_jasa;
    cout<<"Masukkan tarif\t\t :";cin>>baru->dpembeli.dpembelian.jp.tarif;
    cout<<endl;

    cout<<"---- Detail pembelian ----"<<endl;

    cout<<"Nama pembeli \t\t :";cin>>baru->dpembeli.nama;
    cout<<"Alamat pembeli \t\t :";cin>>baru->dpembeli.alamat;
    cout<<"Jumlah pembelian \t :";cin>>baru->dpembeli.dpembelian.jml_pembelian;
    cout<<endl;

    cout<<"---- Detail pembayaran ----"<<endl;
    cout<<"Nama bank :";cin>>baru->dpembeli.dpembayaran.nama_bank;
    cout<<"No rekening :";cin>>baru->dpembeli.dpembayaran.no_rekening;
    cout<<"Jumlah Transfer :";cin>>baru->dpembeli.dpembayaran.jml_transfer;
    cout<<endl<<endl;

    baru->dpembeli.dpembelian.total_pembelian = baru->dpembeli.dpembelian.jml_pembelian * baru->dpembeli.dpembelian.cbuku.harga;
    baru->dpembeli.dpembelian.cbuku.stok = baru->dpembeli.dpembelian.cbuku.stok - baru->dpembeli.dpembelian.jml_pembelian;
}

void masukkanDepan(){
    cout<<endl;
    baru = new node;
    inputan();
    masuk(baru->dpembeli, 1);
}

void masukkanBelakang(){
    cout<<endl;
    baru = new node;
    inputan();
    masuk(baru->dpembeli, 2);
}

void masukTengah(){
    cout<<endl;
    baru = new node;
    cout<<"Masukkan data setelah nomor = ";
    cin>>baru->nomor;
    cout<<"========= Data ================"<<endl;
    inputan();
    masuk_tengah(baru->dpembeli, baru->nomor);
}

void tampil(){
    cout<<endl;
    int i=0;
    baru = head;
    cout<<"==================================================================="<<endl;
    while(baru!=NULL){
        i++;
        print();
        baru=baru->next;
        cout<<"===============================[ "<<i<<" ]==============================="<<endl;
    }
}

void menu(){
    cout<<"Total data = "<<total<<endl;
    cout<<"--- Menu --- "<<endl;
    cout<<"1. Insert Depan "<<endl;
    cout<<"2. Insert Belakang "<<endl;
    cout<<"3. Lihat Data "<<endl;
    cout<<"Masukkan Pilihan = ";
    cin>>pilihan;
    if(pilihan == 1){
        masukkanDepan();
    }
    else if(pilihan == 2){
        masukkanBelakang();
    }
    else if(pilihan == 3){
        //masukTengah();
        tampil();
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
