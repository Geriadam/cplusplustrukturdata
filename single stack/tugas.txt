/*
    Nama : Geri adam saputra
    NPM  : 06.2017.1.06914
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>


#define MESSAGE_FULL "Sudah Penuh"
#define MESSAGE_EMPTY "Data Kosong"
#define MESSAGE_DELETE "Data sudah di hapus"
#define MESSAGE_NEW_STACK "Data yang anda masukkan adalah "
#define MESSAGE_NOT_FOUND "Data tidak di temukan "

using namespace std;

int top,i,j,s[100],batas,pilihan,x,y;
char ulang = 'y';

int initialize()
{
    top = -1;
}

int isFull()
{
    if( top == batas - 1 )
        return true;
    return false;
}

int isEmpty()
{
    if ( top == -1 )
        return true;
    return false;
}

int removeStack()
{
    top = top - 1;
    if(top)
        return true;
    return false;
}

int pushStack(int x)
{
    top = top + 1;
    s[top] = x;
    if(s[top])
        return true;
    return false;
}

int removeSpesific(int y)
{
    y--;
    if( y <= top ){
        for(j=y;j<=top;j++)
        {
            s[j]=s[j+1];
            if(s[j] == s[top]){
                top = top - 1;
            }
        }
        return true;
    }
    return false;
}

void viewStack()
{
    for ( i=0;i<=top;i++ )
    {
        cout<<" - "<<s[i]<<" "<<endl;
    }
}

void menuStack()
{
    cout<<"----- PILIHAN -----"<<endl;
    cout<<"1. Add "<<endl;
    cout<<"2. Remove "<<endl;
    cout<<"3. Remove Spesific"<<endl;
    cout<<"4. View "<<endl<<endl;
    cout<<"-------------------"<<endl;
}


int main()
{
    initialize();
    cout<<"Masukkan batas : ";
    cin>>batas;
    do
    {
        menuStack();
        cout<<"masukkan pilihan ";
        cin>>pilihan;
        cout<<"-------------------"<<endl;

        if( pilihan == 1 )
        {
            if(isFull())
            {
                cout<<MESSAGE_FULL<<endl;
            }
            else
            {
                cout<<"Masukkan angka : ";
                cin>>x;
                pushStack(x);
                cout<<MESSAGE_NEW_STACK<<s[top]<<endl;
            }
        }
        else if( pilihan == 2 )
        {
            if(removeStack())
                cout<<MESSAGE_DELETE<<endl;
        }
        else if( pilihan == 3 )
        {
            cout<<"Masukkan angka : ";
            cin>>y;
            if(removeSpesific(y))
            {
                cout<<MESSAGE_DELETE<<endl;
            }
            else
            {
                cout<<MESSAGE_NOT_FOUND<<endl;
            }
        }
        else
        {
            if(isEmpty())
            {
                cout<<MESSAGE_EMPTY;
            }
            else
            {
                cout<<"Data :"<<endl;
                viewStack();
            }
        }
        cout<<endl;
        cout<<"---------------------- "<<endl;
        cout<<"apakah ingin mengulang ";
        cin>>ulang;
        system("CLS");
    } while( ulang == 'y' || ulang == 'Y');
}
