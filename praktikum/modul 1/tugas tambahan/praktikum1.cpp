#include <iostream>
#include "praktikum.h"
using namespace std;

data_pembeli dpembeli;

int main()
{
    // masukkan inputan
    cout<<"Masukkan Nama Barang\t :";cin>>dpembeli.dpembelian.cbuku.nama_barang;
    cout<<"Masukkan Harga:\t\t :";cin>>dpembeli.dpembelian.cbuku.harga;
    cout<<"Masukkan stok:\t\t :";cin>>dpembeli.dpembelian.cbuku.stok;
    cout<<"Masukkan Kota Penjual:\t :";cin>>dpembeli.dpembelian.cbuku.kota_penjual;
    cout<<endl;

    cout<<"---- Jasa Pengantar ----"<<endl;

    cout<<"Masukkan jasa pengantar  :";cin>>dpembeli.dpembelian.jp.nama_jasa;
    cout<<"Masukkan tarif\t\t :";cin>>dpembeli.dpembelian.jp.tarif;
    cout<<endl;

    cout<<"---- Detail pembelian ----"<<endl;

    cout<<"Nama pembeli \t\t :";cin>>dpembeli.nama;
    cout<<"Alamat pembeli \t\t :";cin>>dpembeli.alamat;
    cout<<"Jumlah pembelian \t :";cin>>dpembeli.dpembelian.jml_pembelian;
    cout<<endl;

    cout<<"---- Detail pembayaran ----"<<endl;
    cout<<"Nama bank :";cin>>dpembeli.dpembayaran.nama_bank;
    cout<<"No rekening :";cin>>dpembeli.dpembayaran.no_rekening;
    cout<<"Jumlah Transfer :";cin>>dpembeli.dpembayaran.jml_transfer;
    cout<<endl<<endl;

    dpembeli.dpembelian.total_pembelian = dpembeli.dpembelian.jml_pembelian * dpembeli.dpembelian.cbuku.harga;
    dpembeli.dpembelian.cbuku.stok = dpembeli.dpembelian.cbuku.stok - dpembeli.dpembelian.jml_pembelian;


    cout<<"-- Data yang anda masukkan adalah --"<<endl<<endl;

    cout<<"Nama barang \t :"<<dpembeli.dpembelian.cbuku.nama_barang<<endl;
    cout<<"Harga barang \t :"<<dpembeli.dpembelian.cbuku.harga<<endl;
    cout<<"Stok akhir \t :"<<dpembeli.dpembelian.cbuku.stok<<endl;
    cout<<"Kota Penjual \t :"<<dpembeli.dpembelian.cbuku.kota_penjual<<endl<<endl;

    cout<<"---- Jasa Pengantar ----"<<endl<<endl;

    cout<<"Jasa \t :"<<dpembeli.dpembelian.jp.nama_jasa<<endl;
    cout<<"Tarif \t :"<<dpembeli.dpembelian.jp.tarif<<endl<<endl;

    cout<<"---- Detail Pembelian ----"<<endl<<endl;


    cout<<"Nama Pembeli \t :"<<dpembeli.nama<<endl;
    cout<<"Alamat Pembeli \t :"<<dpembeli.alamat<<endl;
    cout<<"Jumlah \t\t :"<<dpembeli.dpembelian.jml_pembelian<<endl;
    cout<<"Total \t\t :"<<dpembeli.dpembelian.total_pembelian<<endl<<endl;

    cout<<"---- Detail pembayaran ----"<<endl<<endl;

    cout<<"Nama bank \t :"<<dpembeli.dpembayaran.nama_bank<<endl;
    cout<<"No rekening \t :"<<dpembeli.dpembayaran.no_rekening<<endl;
    cout<<"Jumlah Transfer  :"<<dpembeli.dpembayaran.jml_transfer<<endl;
}
