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

void add(Bab* mapelList[], int mapelIndex) {
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

    baru->next = nullptr; // Ensure the new node points to nullptr

    if (mapelIndex >= 0 && mapelIndex < 5) {
        if (mapelList[mapelIndex] == nullptr) {
            // If the list is empty, insert at the beginning
            mapelList[mapelIndex] = baru;
        } else {
            // If the list is not empty, add to the end
            Bab* temp = mapelList[mapelIndex];
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = baru;
        }
    } else {
        cout << "Mata pelajaran tidak valid" << endl;
        delete baru; // Free memory if the index is invalid
    }
}

<<<<<<< HEAD
void view()
{
 
}

void hapus() {
  
=======
void view(Bab* mapelList[], int mapelIndex) {
    Bab* ptr = mapelList[mapelIndex];
    while (ptr != nullptr) {
        cout << ptr->namabab << " (" << ptr->mapelbab << ")";
        ptr = ptr->next;
    }
}

void hapus(Bab* mapelList[], int mapelIndex) {
    string namaHapus;
    cout << "Masukkan nama bab yang ingin dihapus: ";
    cin >> namaHapus;

    Bab* current = mapelList[mapelIndex];
    Bab* prev = nullptr;

    while (current != nullptr && current->namabab != namaHapus) {
        prev = current;
        current = current->next;
    }

    if (current == nullptr) {
        cout << "Bab tidak ditemukan." << endl;
        return;
    }

    if (prev == nullptr) {
        mapelList[mapelIndex] = current->next;
    } else {
        prev->next = current->next;
    }

    delete current;
>>>>>>> d02c68ba0f1c0070e3e0fa2fc468757728603715
}


//Program Utama
int main() {
    //Inisialisasi
    int loopsemua = 0, pilihan1;

    do 
    {
        //Inisialisasi bab
        // Bab* mapelList[5];
        // for (int i = 0; i < 5; ++i) 
        //     mapelList[i] = nullptr;
        // int mapelIndex = -1;

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
            add(mapelList, mapelIndex);
            loopsemua=0;
            break;
        case 2:
            view(mapelList, mapelIndex);
            loopsemua=0;
            break;
        case 3:
            hapus(mapelList, mapelIndex);
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