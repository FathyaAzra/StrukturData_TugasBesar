#include<iostream>
using namespace std;

//membuat tipe data Node (elemen dari linked list)
struct Bab 
{
    string namabab;
    string mapelbab;
    int prioritas;
    Bab* next;
};

void add(int mapelIndex)
{
    int priorlain;
    Bab* baru = new Bab();
    cout<<"Nama Bab Baru :";
    cin>> baru->namabab;

    cout<<"Mata Pelajaran :\n";
    cout<<"- MM\n";
    cout<<"- Fisika\n";
    cout<<"- Kimia\n";
    cout<<"- Biologi\n";
    cout<<"- TPS\n";
    cout<<"Mata Pelajaran :";
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
    //Inisialisasi
    int loopsemua = 0, pilihan1;

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
        cout<<"Pilih Fitur :";
        cin>>pilihan1;
        cout<<"========================================\n";

        switch (pilihan1)
        {
        case 1:
            add(mapelIndex);
            loopsemua=0;
            break;
        case 2:
            view();
            loopsemua=0;
            break;
        case 3:
            hapus();
            loopsemua=0;
            break;
        case 4:
            loopsemua=1;
            break;
        
        default:
            loopsemua=1;
            break;
        }
        
    }
    while (loopsemua == 0);

    cout<<"\n\n Terima Kasih";

    return 0;
}