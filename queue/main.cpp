#include <iostream>
#define MESSAGE_DELETE "data sudah terhapus"
#define MESSAGE_FULL "data sudah penuh"
#define MESSAGE_EMPTY "data masih kosong"

using namespace std;

int i,j,f,r,q[50],x,pil,n;
char ulang;

void start()
{
    f = 0;
    r = -1;
}

void menu()
{
    cout<<"Pilihan "<<endl;
    cout<<"1. Enqueue "<<endl;
    cout<<"2. Dequeue "<<endl;
    cout<<"3. Reset "<<endl;
}

void view()
{
    cout<<"Data : ";
    for(i=f;i<=r;i++){
        cout<<q[i]<<" ";
    }
    cout<<"\n";
}

void remove()
{
    x = q[f];
    f = f + 1;
}

int empty()
{
    if(f == r + 1)
    {
        return true;
    }
    return false;
}

int full()
{
    if(r == n - 1)
    {
        return true;
    }
    return false;
}

int insert(int x)
{
    r = r + 1;
    q[r] = x;
}


int main()
{
    cout<<"Batas Data ";
    cin>>n;
    cout<<endl;
    start();
    do{
        cout<<"================"<<endl;
        view();
        cout<<"================"<<endl;
        menu();
        cout<<"masukkan pilihan ";
        cin>>pil;
        cout<<endl;
        if( pil == 1 ){
            if(full())
            {
                cout<<MESSAGE_FULL<<endl;
            }
            else{
                cout<<"Masukkan data ";
                cin>>x;
                insert(x);
                cout<<"\n Data yang anda masukkan adalah "<<q[r]<<endl;
            }
        }
        else if ( pil == 2 ){
            if(empty()){
                cout<<MESSAGE_EMPTY<<endl;
            }
            else{
                remove();
            }
        }
        else{
            start();
        }
        cout<<endl;
        cout<<"apakah ingin mengulang ";
        cin>>ulang;
    }while( ulang == 'y' );
}
