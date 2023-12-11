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

void add(Node* mapelList[], int inputMapelIndex) {
    Node* baru = new Node();

    int mapelIndex = inputMapelIndex;

    cout << "Mata Pelajaran :\n";
    cout << "1. MM\n";
    cout << "2. Fisika\n";
    cout << "3. Kimia\n";
    cout << "4. Biologi\n";
    cout << "5. TPS\n";
    cout << "Pilih Mata Pelajaran (1-5): ";
    cin >> mapelIndex;

    if (mapelIndex >= 1 && mapelIndex <= 5) {
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
    } else {
        cout << "Pilihan tidak valid. Silakan pilih lagi.\n";
        return;
    }

    cout << "Nama Bab Baru: ";
    cin >> baru->namabab;

    cout << "Prioritas Bab baru (1-5): ";
    cin >> baru->prioritas;

    baru->mapelIndex = mapelIndex - 1;

    // Check if the entry already exists
    Node* temp = mapelList[mapelIndex - 1];
    while (temp != nullptr) {
        if (temp->namabab == baru->namabab) {
            cout << "Bab sudah ada dalam mata pelajaran ini. Tidak dapat menambahkan duplikat.\n";
            delete baru; // Clean up the allocated memory for duplicate entry
            return;
        }
        temp = temp->next;
    }

    if (mapelList[mapelIndex - 1] == nullptr) {
        mapelList[mapelIndex - 1] = baru;
        baru->next = nullptr;
    } else {
        temp = mapelList[mapelIndex - 1];
        while (temp->next != nullptr && temp->next->prioritas >= baru->prioritas) {
            temp = temp->next;
        }
        baru->next = temp->next;
        temp->next = baru;
    }
    cout << "Bab berhasil ditambahkan.\n";
}

void viewall(Node* mapelList[]) {
    Node* combinedList = nullptr;
    Node* tailNode = nullptr;

    // Merge all linked lists into one combined list
    for (int i = 0; i < 5; ++i) {
        Node* temp = mapelList[i];

        while (temp != nullptr) {
            Node* newNode = new Node(*temp);
            if (combinedList == nullptr) {
                combinedList = newNode;
                tailNode = newNode;
            } else {
                tailNode->next = newNode;
                tailNode = tailNode->next;
            }

            temp = temp->next;
        }
    }

    // Insertion sort to rearrange nodes based on priorities
    Node* current = combinedList;
    combinedList = nullptr;  // Reset combinedList to reconstruct it with sorted nodes

    while (current != nullptr) {
        Node* next = current->next;

        if (combinedList == nullptr || combinedList->prioritas >= current->prioritas) {
            current->next = combinedList;
            combinedList = current;
        } else {
            Node* currentSorted = combinedList;

            while (currentSorted->next != nullptr && currentSorted->next->prioritas < current->prioritas) {
                currentSorted = currentSorted->next;
            }

            current->next = currentSorted->next;
            currentSorted->next = current;
        }

        current = next;
    }

    // Display the sorted linked list
    cout << "Combined Linked List (Sorted by Priority using Insertion Sort):\n";
    Node* display = combinedList;
    while (display != nullptr) {
        cout << "Nama Bab: " << display->namabab << " (" << display->mapelbab << ")\n";
        display = display->next;
    }
    cout << "==================\n";

    // Clean up memory
    Node* temp = combinedList;
    while (temp != nullptr) {
        Node* toDelete = temp;
        temp = temp->next;
        delete toDelete;
    }
}


void del(Node*& listToDelete) {
    if (listToDelete == nullptr) {
        cout << "Linked list kosong.\n";
        return;
    }

    string namabab;
    cout << "Masukkan Nama Bab yang ingin dihapus: ";
    cin.ignore(); // To clear the input buffer before reading the string
    getline(cin, namabab);

    Node* temp = listToDelete;
    Node* prev = nullptr;

    while (temp != nullptr && temp->namabab != namabab) {
        prev = temp;
        temp = temp->next;
    }

    // Jika node yang ingin dihapus berada di head
    if (temp != nullptr && temp->namabab == namabab) {
        if (prev == nullptr) {
            listToDelete = temp->next;
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

    int choice;
    Node* combinedList = nullptr;
    int selectedMapelIndex = -1;

    do {
        cout << "Selamat Datang di PRIORITASIN\n";
        cout << "========================================\n";
        cout << "Pilih Fitur :\n";
        cout << "1. Tambah Bab Materi\n";
        cout << "2. Lihat Bab Materi Sesuai Mata Pelajaran dan Prioritas\n";
        cout << "3. Hapus Bab Materi\n";
        cout << "4. Keluar dari PRIORITASIN\n";
        cout << "Pilih Fitur :";
        cin >> choice;

        switch (choice) {
            case 1:
                add(mapelList, -1);
                break;
            case 2:
                viewall(mapelList);
                break;
            case 3:
                cout << "Pilih Mata Pelajaran (1-5): ";
                cin >> selectedMapelIndex;
                if (selectedMapelIndex >= 1 && selectedMapelIndex <= 5) {
                    del(mapelList[selectedMapelIndex - 1]);
                } else {
                    cout << "Pilihan tidak valid. Silakan pilih lagi.\n";
                }
                break;
            case 4:
                cout << "Program selesai.\n";
                break;
            default:
                cout << "Pilihan tidak valid. Silakan pilih lagi.\n";
        }

        // ... (other code in the loop)
    } while (choice != 4);

    // Clean up memory for mapelList
    for (int i = 0; i < 5; ++i) {
        Node* temp = mapelList[i];
        while (temp != nullptr) {
            Node* toDelete = temp;
            temp = temp->next;
            delete toDelete;
        }
    }
    return 0;
}