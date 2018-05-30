#include <iostream>
using namespace std;

int main(){
    int data[100],i,j,n,x;
    cout<<"Masukkan batas data ";
    cin>>n;
    for(i=0;i<n;i++){
        cout<<"Masukkan data ke "<<i+1<<" : ";
        cin>>data[i];
    }
    cout<<endl;
    cout<<"Data anda : "<<endl;
    for(i=0;i<n;i++){
        cout<<data[i]<<" ";
    }
    cout<<endl;
    cout<<"Data setelah di sorting"<<endl;
    for(i=0;i<n;i++){
        for(j=0;j<n-i-1;j++){
            if(data[j] > data[j+1]){
                x = data[j];
                data[j]   = data[j+1];
                data[j+1] = x;
            }
        }
    }
    for(i=0;i<n;i++){
        cout<<data[i]<<" ";
    }
}
