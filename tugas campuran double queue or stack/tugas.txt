#include <iostream>
#include <stdlib.h>
using namespace std;

int l,r,n,pil,i,j,temp,cari;
int pertama,akhir;
int tengah  = 0;
bool ketemu = false;
bool isSortingDulu = false;
char ulang;

struct siswa{
    int absen,kelas;
    string nama;
};
siswa sis[100];

void awal(){
    l = 0;
    r = -1;
}

void insert_kiri(){
    l--;
    cout<<"Masukkan Absen:";
    cin>>sis[l].absen;
    cout<<"Masukkan Nama:";
    cin>>sis[l].nama;
    cout<<"Masukkan Kelas:";
    cin>>sis[l].kelas;
}

void delete_kiri(){
    sis[l];
    l++;
}

void insert_kanan(){
    r++;
    cout<<"Masukkan Absen:";
    cin>>sis[r].absen;
    cout<<"Masukkan Nama:";
    cin>>sis[r].nama;
    cout<<"Masukkan Kelas:";
    cin>>sis[r].kelas;

}

void delete_kanan(){
    sis[r];
    r--;
}

void sorting(){
    for(i=0;i<n;i++){
        for(j=0;j<n-i-1;j++){
            if(sis[j].absen > sis[j+1].absen){
                temp = sis[j].absen;
                sis[j].absen   = sis[j+1].absen;
                sis[j+1].absen = temp;
            }
        }
    }
}

void pencarian(){
    cout<<"Masukkan no absen = ";
    cin>>cari;
    pertama = l;
    akhir   = n;
    while(pertama <= akhir && !ketemu){
        tengah = (pertama + akhir) / 2;
        if(cari > sis[tengah].absen){
            pertama = tengah + 1;
        } else if(cari < sis[tengah].absen){
            akhir = tengah - 1;
        } else {
            cout<<"absen "<<cari<<" di temukan di urutan ke "<<tengah+1<<endl;
            cout<<"========= Datanya ========="<<endl;
            cout<<"Absen = "<<sis[tengah].absen<<endl;
            cout<<"Nama  = "<<sis[tengah].nama<<endl;
            cout<<"Kelas = "<<sis[tengah].kelas<<endl;
            cout<<"==========================="<<endl;
            ketemu = true;
        }
    }

    if(!ketemu){
        cout<<"absen "<<cari<<" tidak di temukan";
    }
}

bool isEmpty(){
    return l==r+1 ? true : false;
}

bool penuh_kiri(){
    return l==0 ? true : false;
}

bool penuh_kanan(){
    return r==n-1 ? true : false;
}

void view()
{
    cout<<"==========================="<<endl;
    for(i=l;i<=r;i++){
        cout<<"Absen = "<<sis[i].absen<<endl;
        cout<<"Nama  = "<<sis[i].nama<<endl;
        cout<<"Kelas = "<<sis[i].kelas<<endl;
        cout<<"==========================="<<endl;
    }
}

void menu(){
    cout<<"Double Queue"<<endl;
    cout<<"==============="<<endl;
    cout<<"1. Insert kanan "<<endl;
    cout<<"2. Insert kiri "<<endl;
    cout<<"3. Hapus  kanan "<<endl;
    cout<<"4. Hapus  kiri "<<endl;
    cout<<"5. Sorting "<<endl;
    cout<<"6. Pencarian "<<endl;
    cout<<"7. Lihat  data "<<endl;
    cout<<"masukkan pilihan anda ? ";
    cin>>pil;
    if(pil == 1){
        if(!penuh_kanan()){
          insert_kanan();
        } else {
            cout<<"Data penuh"<<endl;
        }
    } else if(pil == 2){
        if(!penuh_kiri()){
            insert_kiri();
        } else {
            cout<<"data kanan harus di isi atau data penuh";
        }
    } else if(pil == 3){
        if(!isEmpty()){
            delete_kanan();
        } else {
            cout<<"Data kosong";
        }
    } else if(pil == 4){
        if(!isEmpty()){
            delete_kiri();
        } else {
            cout<<"Data kosong";
        }
    } else if(pil == 5){
        sorting();
        cout<<"Data Sudah di sorting"<<endl;
        isSortingDulu = true;
    } else if(pil == 6){
        if(isSortingDulu){
            pencarian();
            ketemu = false;
            isSortingDulu = false;
        } else {
            cout<<"Anda harus sorting dahulu"<<endl;
        }
    } else if(pil == 7){
        view();
        cout<<endl;
    }else {
        cout<<"Pilihan salah"<<endl;
    }
}

int main(){
    awal();
    cout<<"masukkan batas data ";
    cin>>n;
    do{
        menu();
        cout<<endl;
        cout<<"apakah anda ingin mengulang ";
        cin>>ulang;
        system("CLS");
    } while(ulang=='y' || ulang == 'Y');
}
