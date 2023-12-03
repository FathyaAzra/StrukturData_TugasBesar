#include <iostream>
using namespace std;

//Inisialisasi
    int loopsemua = 0, pilihan1;
    Bab* start = nullptr;

//membuat tipe data Node (elemen dari linked list)
struct Bab 
{
    char namabab[30];
    char mapelbab[30];
    int prioritas;
    Bab* next;
};

void prioritas()
{
    //sesuai prioritas
}

void mapel()
{
    //pisah per mapel. inside procedure prioritas
}


//Procedure-procedure fitur
void add()
{
    Bab* baru = new Bab();
    cout<<"Nama Bab Baru :\n";
    cin>> baru->namabab;

    cout<<"Mata Pelajaran :\n";
    cout<<"1. MM\n";
    cout<<"2. Fisika\n";
    cout<<"3. Kimia\n";
    cout<<"4. Biologi\n";
    cout<<"5. TPS\n";
    cout<<"Mata Pelajaran :\n";
    cin>> baru->mapelbab;
    mapel();

    cout<<"Prioritas UTBK :\n";
    cin>> baru->prioritas;
    if (start == NULL)
        {
            start = baru;
        }
    else {
        //mencari ujung dari linked list
        Bab* temp = start;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = baru;
    }
}

void view()
{

}

//Program Utama
int main() {
    do 
    {
        //Halaman Depan
        cout<<"Selamat Datang di PRIORITASIN\n";
        cout<<"========================================\n";
        cout<<"Pilih Fitur :\n";
        cout<<"1. Tambah Bab Materi\n";
        cout<<"2. Lihat Bab Materi Sesuai Mata Pelajaran dan Prioritas\n";
        cout<<"3. Hapus Bab Materi\n";
        cout<<"4. Keluar dari PRIORITASIN\n";
        cout<<"Pilih Fitur :\n";
        cout<<"========================================\n";
        cin>>pilihan1;

        switch (pilihan1)
        {
        case 1:
            add();
            break;
        case 2:
            /* code */
            break;
        case 3:
            /* code */
            break;
        case 4:
            /* code */
            break;
        
        default:
            break;
        }
        
    }
    while (loopsemua=0);

    cout<<"\n\n Terima Kasih";

    return 0;
}