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

void add(int mapelIndex)
{
    int priorlain;
    Bab* baru = new Bab();
    cout<<"Nama Bab Baru :\n";
    cin>> baru->namabab;

    cout<<"Mata Pelajaran :\n";
    cout<<"- MM\n";
    cout<<"- Fisika\n";
    cout<<"- Kimia\n";
    cout<<"- Biologi\n";
    cout<<"- TPS\n";
    cout<<"Mata Pelajaran :\n";
    cin>> baru->mapelbab;

    //Inisialisasi untuk pengelompokkan
    if (baru->mapelbab == "MM") 
            mapelIndex = 0;
        else if (baru->mapelbab == "Fisika")
            mapelIndex = 1;
        else if (baru->mapelbab == "Kimia")
            mapelIndex = 2;
        else if (baru->mapelbab == "Biologi")
            mapelIndex = 3;
        else if (baru->mapelbab == "TPS")
            mapelIndex = 4;

    cout<<"Prioritas 1-5 : ";
    cin>> baru->prioritas;

    if (mapelIndex != -1) 
    {
        Bab* mapelList[mapelIndex];
        Bab* temp = mapelList[mapelIndex];
        if (temp == nullptr || temp->prioritas < baru->prioritas) {
            baru->next = temp;
            mapelList[mapelIndex] = baru;
        } else {
            while (temp->next != nullptr && temp->next->prioritas >= baru->prioritas) {
                temp = temp->next;
            }
            baru->next = temp->next;
            temp->next = baru;
        }
    } else {
        cout << "Mata pelajaran tidak valid" << endl;
    }
}

void view()
{

}

void hapus()
{
    Bab* ptr;
    cout<<"Masukkan nama bab : ";
    cin>>ptr->namabab;
}

//Program Utama
int main() {
    do 
    {
        //Inisialisasi bab
        Bab* mapelList[5];
        for (int i = 0; i < 5; ++i) 
            mapelList[i] = nullptr;
        int mapelIndex = -1;

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
            add(mapelIndex);
            break;
        case 2:
            view();
            break;
        case 3:
            hapus();
            break;
        case 4:
            loopsemua=1;
            break;
        
        default:
            loopsemua=1;
            break;
        }
        
    }
    while (loopsemua=0);

    cout<<"\n\n Terima Kasih";

    return 0;
}