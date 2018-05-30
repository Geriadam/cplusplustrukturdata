#include <iostream>
using namespace std;

struct circular{
    int f = 0;
    int r = -1;
    int i,j,q[50],x,pil,n;
    char ulang;
} c;

void menu() // menampilkan menu
{
    cout<<"Pilihan "<<endl;
    cout<<"1. Enqueue "<<endl;
    cout<<"2. Dequeue "<<endl;
    cout<<"3. View "<<endl;
}

void view() // untuk melihat data
{
    cout<<"Data : ";
    for(c.i=c.f;c.i<=c.r;c.i++){
        cout<<c.q[c.i]<<" ";
    }
    cout<<"\n";
}

void dequeue() // proses dequeue
{
    c.x = c.q[c.f];
    c.f = c.f+1%c.n;
}

int enqueue(int x) // proses enqueue
{
    c.r = c.r+1%c.n;
    c.q[c.r] = c.x;
}

bool isFull() // mengecek apakah penuh
{
    if(c.r-c.f == c.n-1){
        return true;
    }
    return false;
}

bool isEmpty() // mengecek apakah kosong
{
    if(c.f == c.r+1){
        return true;
    }
    return false;
}

int main()
{
    cout<<"Batas Data ";
    cin>>c.n;
    cout<<endl;
    do{
        cout<<"================"<<endl;
        cout<<"================"<<endl;
        menu();
        cout<<"masukkan pilihan ";
        cin>>c.pil;
        cout<<endl;
        if( c.pil == 1 ){
            if(!isFull()){
                cout<<"Masukkan data ";
                cin>>c.x;
                enqueue(c.x);
                cout<<"\n Data yang anda masukkan adalah "<<c.q[c.r]<<endl;
            }
            else{
                cout<<"Data Penuh"<<endl;
            }
        }
        else if ( c.pil == 2 ){
            if(!isEmpty()){
                dequeue();
                cout<<"Data terhapus "<<c.x<<endl;
            }
            else{
                cout<<"Data Kosong"<<endl;
            }
        }
        else{
            view();
        }
        cout<<endl;
        cout<<"apakah ingin mengulang ";
        cin>>c.ulang;
    }while( c.ulang == 'y' );
}
