#include <iostream>
using namespace std;

struct buku
{
    char judul[30];
    char isbn[100];
    char pengarang[100];
};

int main()
{
    struct buku bk[50];
    int i,jml_buku;
    cout<<"Jumlah buku : ";
    cin>>jml_buku;
    for(i = 0; i<jml_buku; i++){
        cout<<"Judul buku \t: ";
        cin>>bk[i].judul;
        cout<<"No ISBN \t: ";
        cin>>bk[i].isbn;
        cout<<"Pengarang \t: ";
        cin>>bk[i].pengarang;
    }
    cout<<"Hasil \n";
    for(i = 0; i<jml_buku; i++){
        cout<<"----------------------"<<endl;
        cout<<"Judul buku \t: "<<bk[i].judul<<endl;
        cout<<"No ISBN \t: "<<bk[i].isbn<<endl;
        cout<<"Pengarang \t: "<<bk[i].pengarang<<endl;
    }
}
