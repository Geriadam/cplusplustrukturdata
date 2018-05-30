#ifndef PRAKTIKUM_H_INCLUDED
#define PRAKTIKUM_H_INCLUDED
#include <iostream>

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


#endif // PRAKTIKUM_H_INCLUDED
