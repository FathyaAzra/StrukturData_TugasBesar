#include <iostream>
#include <string>

using namespace std;

struct Node {
    string namabab;
    string mapelbab;
    int mapelIndex;
    int prioritas;
    Node* next;
};

void add(Node* mapelList[], int mapelIndex) {
    Node* baru = new Node();

    cout << "Mata Pelajaran :\n";
    cout << "1. MM\n";
    cout << "2. Fisika\n";
    cout << "3. Kimia\n";
    cout << "4. Biologi\n";
    cout << "5. TPS\n";
    cout << "Pilih Mata Pelajaran (1-5): ";
    cin >> mapelIndex;

        
    if (mapelIndex >= 1 || mapelIndex <= 5) 
    {
        if (mapelIndex == 1)
            baru->mapelbab = "MM";
        else if (mapelIndex == 2)
            baru->mapelbab = "Fisika";
        else if (mapelIndex == 3)
            baru->mapelbab = "Kimia";
        else if (mapelIndex == 4)
            baru->mapelbab = "Biologi";
        else if (mapelIndex == 5)
            baru->mapelbab = "TPS";      
    } else 
        cout << "Pilihan tidak valid. Silakan pilih lagi.\n";

    cout << "Nama Bab Baru: ";
    cin >> baru->namabab;

    cout << "Prioritas Bab baru (1-5): ";
    cin >> baru->prioritas;

    baru->mapelIndex -= 1;



    if (mapelList[mapelIndex] == nullptr) {
            mapelList[mapelIndex] = baru;
            baru->next = nullptr;
    } else {
        Node* temp = mapelList[mapelIndex];
        while (temp->next != nullptr && temp->next->prioritas >= baru->prioritas)
        {
            baru->next = temp->next;
            temp = temp->next;
        }
        temp->next = baru;
    }
    baru->next = nullptr;
    cout << "Bab berhasil ditambahkan.\n";
}

void view(Node* mapelList[], int mapelIndex) {
    for (int i =0; i<5; i++)
    {

        mapelIndex = i;
        if (mapelList[mapelIndex] == nullptr) {
            cout << "Linked list kosong.\n";
        }
        Node* temp = mapelList[mapelIndex];
        while (temp != nullptr) {
            cout << "Nama Bab: " << temp->namabab << "(" << temp->mapelbab <<")\n";
            temp = temp->next;
        }
        cout<<"==================\n";
    }
}

    
void del(Node* mapelList[], int mapelIndex) {
    if (mapelList == nullptr) {
        cout << "Linked list kosong.\n";
        return;
    }

    string namabab;
    cout << "Masukkan Nomor Mapel yang ingin dihapus: ";
    cin >> mapelIndex;

    cout << "Masukkan Nama Bab yang ingin dihapus: ";
    cin >> namabab;

    Node* temp = mapelList[mapelIndex];
    Node* prev = nullptr;

    // Mencari node dengan namabab yang sesuai
    while (temp != nullptr && temp->namabab != namabab) {
        prev = temp;
        temp = temp->next;
    }

    // Jika node yang ingin dihapus berada di head
    if (temp != nullptr && temp->namabab == namabab) {
        if (prev == nullptr) {
            mapelList[mapelIndex] = temp->next;
        } else {
            prev->next = temp->next;
        }
        delete temp;
        cout << "Bab dengan nama " << namabab << " berhasil dihapus.\n";
    } else {
        cout << "Bab dengan nama " << namabab << " tidak ditemukan.\n";
    }
}


int main() {
    Node* mapelList[5];
        for (int i = 0; i < 5; ++i) 
            mapelList[i] = nullptr;
        int mapelIndex = -1;
    int choice;

    do {
       cout<<"Selamat Datang di PRIORITASIN\n";
        cout<<"========================================\n";
        cout<<"Pilih Fitur :\n";
        cout<<"1. Tambah Bab Materi\n";
        cout<<"2. Lihat Bab Materi Sesuai Mata Pelajaran dan Prioritas\n";
        cout<<"3. Hapus Bab Materi\n";
        cout<<"4. Keluar dari PRIORITASIN\n";
        cout<<"Pilih Fitur :";
        cin>>choice;
        switch (choice) {
            case 1:
                add(mapelList, mapelIndex);
                break;
            case 2:
                view(mapelList, mapelIndex);
                break;
            case 3 :
                del(mapelList, mapelIndex);
            case 4:
                cout << "Program selesai.\n";
                break;
            default:
                cout << "Pilihan tidak valid. Silakan pilih lagi.\n";
        }
        cout<<"========================================\n\n\n";
    } while (choice != 4);

    return 0;
}
