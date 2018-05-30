#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#define MESSAGE_FULL "Sudah Penuh"
#define MESSAGE_EMPTY "Data Kosong"
#define MESSAGE_DELETE "Data sudah di hapus"
#define MESSAGE_NEW_STACK "Data yang anda masukkan adalah "
#define MESSAGE_NOT_FOUND "Data tidak di temukan "

using namespace std;

int top1,top2,i,j,s[50],batas,pilihan,x;
char ulang = 'y';

void menu()
{
    cout<<"----- PILIHAN -----"<<endl;
    cout<<"1. Add Top 1 "<<endl;
    cout<<"2. Add Top 2 "<<endl;
    cout<<"3. Remove 1"<<endl;
    cout<<"4. Remove 2"<<endl;
    cout<<"5. View "<<endl<<endl;
    cout<<"-------------------"<<endl;
}

void view1()
{
    for(i=0;i<=top1;i++){
        cout<<s[i]<<" ";
    }
}

void view2()
{
    for(j=batas-1;j>=top2;j--){
        cout<<s[j]<<" ";
    }
}

bool isFull()
{
    int full;
    full = top2 - top1;
    if( full == 1 ){
        return true;
    }
    return false;
}

int isEmpty(int type)
{
    if ( type == 1 )
    {
        if( top1 == -1 ){
            return true;
        }
    }
    else if ( type == 2 )
    {
        if( top2 == batas ){
            return true;
        }
    }
    return false;
}

int pushStack(int x, int type)
{
    if ( type == 1 )
    {
        top1 = top1 + 1;
        s[top1] = x;
        return true;
    }
    else if ( type == 2 )
    {
        top2 = top2 - 1;
        s[top2] = x;
        return true;
    }
    return false;
}

int removeStack(int type)
{
    if ( type == 1 )
    {
        if(!isEmpty(1)){
            top1--;
            return true;
        }
    }
    else if ( type == 2 )
    {
        if(!isEmpty(2)){
            top2++;
            return true;
        }
    }
    return false;
}

int main()
{
    cout<<"Masukkan batas : ";
    cin>>batas;

    top1 = -1;
    top2 = batas;

    do
    {
        menu();
        cout<<"masukkan pilihan ";
        cin>>pilihan;
        cout<<"-------------------"<<endl;

        if( pilihan == 1 )
        {
            if(isFull())
            {
                cout<<MESSAGE_FULL;
            }
            else
            {
                cout<<"Masukkan angka : ";
                cin>>x;
                pushStack(x, 1);
                cout<<MESSAGE_NEW_STACK<<s[top1]<<endl;
            }
        }
        else if( pilihan == 2 )
        {
            if(isFull())
            {
                cout<<MESSAGE_FULL;
            }
            else
            {
                cout<<"Masukkan angka : ";
                cin>>x;
                pushStack(x, 2);
                cout<<MESSAGE_NEW_STACK<<s[top2]<<endl;
            }
        }
        else if( pilihan == 3 )
        {
            if(removeStack(1)){
                cout<<MESSAGE_DELETE;
            }
            else{
                cout<<MESSAGE_EMPTY;
            }
        }
        else if( pilihan == 4 )
        {
            if(removeStack(2)){
                cout<<MESSAGE_DELETE;
            }
            else{
                cout<<MESSAGE_EMPTY;
            }
        }
        else
        {
            cout<<"Data Stack 1:"<<endl;
            view1();
            cout<<endl;
            cout<<"Data Stack 2:"<<endl;
            view2();

        }
        cout<<endl;
        cout<<"---------------------- "<<endl;
        cout<<"apakah ingin mengulang ";
        cin>>ulang;
        system("CLS");

    } while( ulang == 'y' || ulang == 'Y');
}
