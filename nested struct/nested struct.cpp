#include <iostream>
using namespace std;

struct pelanggan
{
    char nama_pelanggan[100];
    int telepon_pelanggan;
};

struct buku
{
    char judul_buku[100];
    int isbn_buku;
};

struct peminjaman
{
    int tanggal;
    int bulan;
    int tahun;
    struct pelanggan p;
    struct buku b;
}pm;

int main()
{
    cout<<"-----------------------------"<<endl;
    cout<<"Masukkan data berikut :"<<endl;
    cout<<"Nama Pelanggan\t\t:";
    cin>>pm.p.nama_pelanggan;
    cout<<"Telepon Pelanggan\t:";
    cin>>pm.p.telepon_pelanggan;
    cout<<"Judul Buku\t\t:";
    cin>>pm.b.judul_buku;
    cout<<"ISBN Buku\t\t:";
    cin>>pm.b.isbn_buku;
    cout<<"-----------------------------"<<endl;
    cout<<"Tanggal Pinjam\t\t:";
    cin>>pm.tanggal;
    cout<<"Bulan Pinjam\t\t:";
    cin>>pm.bulan;
    cout<<"Tahun Pinjam\t\t:";
    cin>>pm.tahun;
    cout<<"-----------------------------"<<endl<<endl;
    cout<<"Data Yang Anda Masukkan"<<endl;
    cout<<"Nama Pelanggan\t\t:"<<pm.p.nama_pelanggan<<endl;
    cout<<"Telepon Pelanggan\t:"<<pm.p.telepon_pelanggan<<endl;
    cout<<"Judul Buku\t\t:"<<pm.b.judul_buku<<endl;
    cout<<"ISBN Buku\t\t:"<<pm.b.isbn_buku<<endl;
    cout<<"-----------------------------"<<endl;
    cout<<"Tanggal Pinjam\t\t:"<<pm.tanggal<<"-"<<pm.bulan<<"-"<<pm.tahun;

}

