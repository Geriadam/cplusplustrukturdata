#include <iostream>
using namespace std;

int main(){
    int data[100],batas,i,j,cari,x;
    int awal    = 0;
    int tengah  = 0;
    bool ketemu = false;

    cout<<"Masukkan Batas :";
    cin>>batas;
    for(i=0;i<batas;i++){
        cout<<"Masukkan Data Ke-"<<i+1<<" :";
        cin>>data[i];
    }
    for(i=0;i<batas;i++){
        for(j=0;j<batas-i-1;j++){
            if(data[j] > data[j+1]){
                x = data[j];
                data[j]   = data[j+1];
                data[j+1] = x;
            }
        }
    }
    cout<<"\nDatanya :";
    for(i=0; i<batas; i++){
        cout<<data[i]<<" ";
    }


    cout<<"Masukkan data yang akan di cari ";
    cin>>cari;
    while(awal <= batas && !ketemu){
        tengah = (awal + batas) / 2;
        if(cari > data[tengah]){
            awal = tengah + 1;
        } else if(cari < data[tengah]){
            batas = tengah - 1;
        } else {
            cout<<"data "<<cari<<" di temukan di urutan ke "<<tengah+1<<endl;
            ketemu = true;
        }
    }

    if(!ketemu){
        cout<<"data "<<cari<<" tidak di temukan";
    }
}
