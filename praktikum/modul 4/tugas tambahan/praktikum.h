#ifndef PRAKTIKUM_H_INCLUDED
#define PRAKTIKUM_H_INCLUDED
#include <iostream>
using namespace std;

int total = 0;
char ulang;
bool isSortingDulu = false;

struct catalog_buku{
    char nama_barang[100],kota_penjual[100];
    int harga,stok;
};

struct jasa_pengantar{
    char nama_jasa[100];
    int tarif;
};

struct data_pembayaran{
    char nama_bank[100];
    int no_rekening,jml_transfer;
};

struct data_pembelian{
    catalog_buku cbuku;
    jasa_pengantar jp;
    int jml_pembelian,total_pembelian;
};

struct data_pembeli{
    data_pembelian dpembelian;
    data_pembayaran dpembayaran;
    char nama[100],alamat[100];
};

struct node{
    data_pembeli dpembeli;
    int nomor;
    int index;
    node *next;
    node *prev;
} *head, *tail, *baru, *temp;

void init(){
    head = tail = NULL;
}

void masuk(data_pembeli dpembeli, int nomor){
    baru = new node;
    baru->dpembeli = dpembeli;
    baru->nomor = nomor;
    baru->next = baru->prev = NULL;
    baru->index = total;
    if(head==NULL){
        head = tail = baru;
    }
    else{
        baru->next = head;
        head->prev = baru;
        head = baru;
    }
    total++;
    cout<<"Data berhasil di tambahkan ";
}

void print(){
    cout<<"Nomor \t :"<<baru->nomor<<endl;
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
    cout<<"Masukkan Nomor\t\t ";cin>>baru->nomor;
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
    masuk(baru->dpembeli, baru->nomor);
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

void sorting(){
    cout << endl;
    if(head == NULL){
        cout << "Data masih kosong!\n\n";
    } else {
        node *urutkan1 = head;
        node *urutkan2 = NULL;
        node *bantu1 = NULL;
        node *bantu2 = NULL;
        while(urutkan1 != NULL){
            urutkan2 = head->next;
            while(urutkan2 != NULL){
                bantu1 = urutkan2->prev;
                bantu2 = urutkan2;
                if(bantu2->nomor < bantu1->nomor){
                    if(bantu1 == head && bantu2 == tail){
                        bantu2->next = bantu1;
                        bantu1->prev = bantu2;
                        bantu2->prev = NULL;
                        bantu1->next = NULL;
                        head = bantu2;
                        tail = bantu1;
                        urutkan1 = head;
                    }else if(bantu1 == head && bantu2 != tail){
                        bantu2->next->prev = bantu1;
                        bantu1->next = bantu2->next;
                        bantu2->next = bantu1;
                        bantu1->prev = bantu2;
                        bantu2->prev = NULL;
                        head = bantu2;
                        urutkan1 = head;
                    }else if(bantu1 != head && bantu2 != tail){
                        bantu2->next->prev = bantu1;
                        bantu1->prev->next = bantu2;
                        bantu2->prev = bantu1->prev;
                        bantu1->next = bantu2->next;
                        bantu2->next = bantu1;
                        bantu1->prev = bantu2;
                    }else if(bantu1 != head && bantu2 == tail){
                        bantu1->prev->next = bantu2;
                        bantu2->prev = bantu1->prev;
                        bantu2->next = bantu1;
                        bantu1->prev = bantu2;
                        bantu1->next = NULL;
                        tail = bantu1;
                    }
                }
            urutkan2 = urutkan2->next;
            }
        urutkan1 = urutkan1->next;
        }
    isSortingDulu = true;
    }
}

node* tengah(node* awal, node* akhir)
{
    if (awal == NULL){
        return NULL;
    }
    node* slow = awal;
    node* fast = awal->next;

    while (fast != akhir)
    {
        fast = fast->next;
        if (fast != akhir)
        {
            slow = slow;
            fast = fast->next;
        }
    }

    return slow;
}

node* fungsi_cari(int a)
{
    node* start = head;
    node* last = NULL;
    bool ketemu = false;

    do
    {
        node* mid = tengah(start, last);
        if (mid == NULL){
            return NULL;
        }
        if (mid->nomor == a){
            ketemu = true;
            return mid;
        }else if (mid->nomor < a){
            start = mid->next;
        }else{
            last = mid;
        }
    } while (last == NULL && !ketemu);
    isSortingDulu = false;
    return NULL;
}

#endif // PRAKTIKUM_H_INCLUDED
