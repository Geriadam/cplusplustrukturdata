#include <iostream>
using namespace std;

struct catalog_buku{
    char nama_barang[100],kota_penjual[100];
    int harga,stok;
}cbuku;

struct jasa_pengantar{
    char nama_jasa[100];
    int tarif;
}jp;


int main()
{
    // masukkan inputan
    cout<<"Masukkan Nama Barang\t :";
    cin>>cbuku.nama_barang;
    cout<<"Masukkan Harga:\t\t :";
    cin>>cbuku.harga;
    cout<<"Masukkan stok:\t\t :";
    cin>>cbuku.stok;
    cout<<"Masukkan Kota Penjual:\t :";
    cin>>cbuku.kota_penjual;

    cout<<"---- Jasa Pengantar ----"<<endl;

    cout<<"Masukkan jasa pengantar  :";
    cin>>jp.nama_jasa;
    cout<<"Masukkan tarif\t\t :";
    cin>>jp.tarif;
    cout<<endl<<endl;

    // menampilkan hasil
    cout<<"-- Data yang anda masukkan adalah --"<<endl<<endl;
    cout<<"Nama barang \t :"<<cbuku.nama_barang<<endl;
    cout<<"Harga barang \t :"<<cbuku.harga<<endl;
    cout<<"Stok barang \t :"<<cbuku.stok<<endl;
    cout<<"Kota Penjual \t :"<<cbuku.kota_penjual<<endl<<endl;

    cout<<"---- Jasa Pengantar ----"<<endl<<endl;

    cout<<"Jasa \t :"<<jp.nama_jasa<<endl;
    cout<<"Tarif \t :"<<jp.tarif<<endl<<endl;
    cout<<"------------------------------------";
}
