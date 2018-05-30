#include <iostream>

using namespace std;
int data[100], i, j, y, batas, temp;

void view_data(){
    for(i=0; i<batas; i++){
        cout<<data[i]<<" ";
    }
}

void sort_asc(){
    for(i=0;i<batas;i++){
        temp = data[i];
        j = i-1;
        while(data[j] > temp && j>=0 ){
            data[j+1]= data[j];
            j--;
        }
        data[j+1] = temp;
    }
}

void sort_desc(){
    for(i=0;i<batas;i++){
        temp = data[i];
        j = i-1;
        while(data[j] < temp && j >= 0 ){
            data[j+1]= data[j];
            j--;
        }
        data[j+1] = temp;
    }
}

int main()
{
    cout<<"Masukkan Batas :";
    cin>>batas;

    for(i=0;i<batas;i++){
        cout<<"Masukkan Data Ke-"<<i+1<<" :";
        cin>>data[i];
    }
    cout<<"\nDatanya :";
    view_data();

    sort_asc();
    cout<<"\nData ASC :";
    for(i=0; i<batas; i++){
        cout<<data[i]<<" ";
    }

    sort_desc();
    cout<<"\nData DESC :";
    for(i=0; i<batas; i++){
        cout<<data[i]<<" ";
    }

}
