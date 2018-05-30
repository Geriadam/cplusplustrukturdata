#include <iostream>
#include <stdlib.h>
using namespace std;

int l,r,q[100],x,n,pil,i,j;
char ulang;

void awal(){
    l = 0;
    r = -1;
}

void insert_kiri(int x){
    l--;
    q[l] = x;
}

void delete_kiri(){
    x = q[l];
    l++;
}

void insert_kanan(int x){
    r++;
    q[r] = x;
}

void delete_kanan(){
    x = q[r];
    r--;
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
    for(i=l;i<=r;i++){
        cout<<q[i]<<" ";
    }
}

void menu(){
    cout<<"Double Queue"<<endl;
    cout<<"==============="<<endl;
    cout<<"1. Insert kanan "<<endl;
    cout<<"2. Insert kiri "<<endl;
    cout<<"3. Hapus  kanan "<<endl;
    cout<<"4. Hapus  kiri "<<endl;
    cout<<"5. Lihat  data "<<endl;
    cout<<"masukkan pilihan anda ? ";
    cin>>pil;
    if(pil == 1){
        if(!penuh_kanan()){
            cout<<"Masukkan data kanan ";
            cin>>x;
            insert_kanan(x);
            cout<<"data yang anda masukkan adalah "<<x<<endl;
        } else {
            cout<<"Data kanan penuh"<<endl;
        }
    } else if(pil == 2){
        if(!penuh_kiri()){
            cout<<"Masukkan data kiri ";
            cin>>x;
            insert_kiri(x);
            cout<<"data yang anda masukkan adalah "<<x<<endl;
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
        cout<<"Data ";
        view();
        cout<<endl;
    } else {
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
