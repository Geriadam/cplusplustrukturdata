#include <iostream>
using namespace std;
int F =0, R=-1, x, n,  Q[100], c=0, pilihan;
char ulang;
void awal(){
  F= 0;
  R= -1;
}

void tulis(){
    if(R-F == n-1){
        cout<<"Data Penuh";
    }else{
        cout<<"Masukkan X:";
        cin>> x;
        R = R+1%n;
        Q[R] = x;
    }
}

void del(){
    if(F == R+1){
        cout<<"Data Kosong";
    }else{
        x = Q[F];
        F= F+1%n;
        cout<<"Data Terhapus :"<<x;
    }
}

void lihat(){
    cout<<"Datanya: ";
    for(int i=F;i<=R;i++){
        cout<<Q[i];
    }
    cout<<endl;
}
int main(){

    cout << "Masukkan Batas Queue: ";
    cin>>n;

    do{
        lihat();

    cout<<"\nPilihan :"<<endl;
    cout<<"1. Tambah"<<endl;
    cout<<"2. Delete "<<endl;
    cout<<"3. Reset "<<endl;
    cout<<"Masukkan Pilihan: ";
    cin>> pilihan;
        if(pilihan==1){
            tulis();
        }else if(pilihan==2){
            del();
        }else if(pilihan==3){
            awal();
        }
        cout<<endl;
        cout<<"Mau ulangi Lagi (Y/N)";
        cin>>ulang;
    }while(ulang=='y' || ulang=='Y');
}
