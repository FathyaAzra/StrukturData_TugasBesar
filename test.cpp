#include <iostream>
#include <string>

using namespace std;

struct Node {
    string namabab;
    int mapelIndex;
    Node* next;
    string mapelbab;
};

class BabLinkedList {
private:
    Node* head;

public:
    BabLinkedList() {
        head = nullptr;
    }

    void add() {
    Node* baru = new Node();
    cout << "Nama Bab Baru: ";
    cin >> baru->namabab;

    int mapelIndex = -1; 

    do {
        cout << "Mata Pelajaran :\n";
        cout << "1. MM\n";
        cout << "2. Fisika\n";
        cout << "3. Kimia\n";
        cout << "4. Biologi\n";
        cout << "5. TPS\n";
        cout << "Pilih Mata Pelajaran (1-5): ";
        cin >> mapelIndex;

        
        if (mapelIndex < 1 || mapelIndex > 5) {
            cout << "Pilihan tidak valid. Silakan pilih lagi.\n";
        } else {
            
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
        }
    } while (mapelIndex < 1 || mapelIndex > 5);

    baru->mapelIndex = mapelIndex - 1;

    baru->next = nullptr;

    if (head == nullptr) {
        head = baru;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = baru;
    }
    cout << "Bab berhasil ditambahkan.\n";
}

   void view() {
    if (head == nullptr) {
        cout << "Linked list kosong.\n";
        return;
    }
    cout << "Daftar Bab:\n";
    Node* temp = head;
    while (temp != nullptr) {
        cout << "Nama Bab: " << temp->namabab << ", Mata Pelajaran: " << temp->mapelbab << endl;
        temp = temp->next;
    }
    }

    
    void del() {
    if (head == nullptr) {
        cout << "Linked list kosong.\n";
        return;
    }

    string namabab;
    cout << "Masukkan Nama Bab yang ingin dihapus: ";
    cin >> namabab;

    Node* temp = head;
    Node* prev = nullptr;

    // Mencari node dengan namabab yang sesuai
    while (temp != nullptr && temp->namabab != namabab) {
        prev = temp;
        temp = temp->next;
    }

    // Jika node yang ingin dihapus berada di head
    if (temp != nullptr && temp->namabab == namabab) {
        if (prev == nullptr) {
            head = temp->next;
        } else {
            prev->next = temp->next;
        }
        delete temp;
        cout << "Bab dengan nama " << namabab << " berhasil dihapus.\n";
    } else {
        cout << "Bab dengan nama " << namabab << " tidak ditemukan.\n";
    }

    int mapelIndex;
    cout << "Masukkan Mapel Index yang ingin dihapus (1-5): ";
    cin >> mapelIndex;

    Node* temp2 = head;
    Node* prev2 = nullptr;

    // Mencari node dengan mapelIndex yang sesuai
    while (temp2 != nullptr && temp2->mapelIndex != mapelIndex) {
        prev2 = temp2;
        temp2 = temp2->next;
    }

    // Jika node yang ingin dihapus berada di head
    if (temp2 != nullptr && temp2->mapelIndex == mapelIndex) {
        if (prev2 == nullptr) {
            head = temp2->next;
        } else {
            prev2->next = temp2->next;
        }
        delete temp2;
        cout << "Bab dengan Mapel Index " << mapelIndex << " berhasil dihapus.\n";
    } 
}

};

int main() {
    BabLinkedList linkedList;
    int choice;

    do {
       cout<<"Selamat Datang di PRIORITASIN\n";
        cout<<"========================================\n";
        cout<<"Pilih Fitur :\n";
        cout<<"1. Tambah Bab Materi\n";
        cout<<"2. Lihat Bab Materi Sesuai Mata Pelajaran dan Prioritas\n";
        cout<<"3. Hapus Bab Materi\n";
        cout<<"4. Keluar dari PRIORITASIN\n";
        cout<<"Pilih Fitur :\n";
        cout<<"========================================\n";
        cin>>choice;

        switch (choice) {
            case 1:
                linkedList.add();
                break;
            case 2:
                linkedList.view();
                break;
            case 3:
                linkedList.del();
                break;
            case 4:
                cout << "Program selesai.\n";
                break;
            default:
                cout << "Pilihan tidak valid. Silakan pilih lagi.\n";
        }
    } while (choice != 4);

    return 0;
}
