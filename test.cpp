//Just a file to see/put references

#include <iostream>
#include <cstring>
using namespace std;

struct Book {
    char name[30];
    char author[30];
    int id;
    Book* next;
};

struct Student {
    char name[30];
    char email[20];
    char book[20];
    char a[30];
    int id;
    Student* next;
};

Book* start_lib = nullptr;
Student* start = nullptr;

Book* initialize_lib(Book* start);
Student* book_issue(Student* start);
Student* book_return(Student* start);
void display(Student* start);
Book* delete_book(int id);
Book* add_book(char bookname[], char authorname[], int id);
void greetings();
void main_menu();

int main() {
    start_lib = initialize_lib(start_lib);
    greetings();
    main_menu();
    return 0;
}

// void greetings() {
//     // Greetings display
//      printf("\n\n");
//     printf("\t\t\t     ****************************************\n");
//     printf("\t\t\t     *                                      *\n");
//     printf("\t\t\t     *                                      *\n");
//     printf("\t\t\t     *     ----------------------------     *\n");
//     printf("\t\t\t     *      WELCOME TO STUDENT LIBRARY      *\n");
//     printf("\t\t\t     *     ----------------------------     *\n");
//     printf("\t\t\t     *                                      *\n");
//     printf("\t\t\t     *                                      *\n");
//     printf("\t\t\t     ****************************************\n");
//     printf("\n\n");
//     printf("\t\t\t     ****************************************\n");
//     printf("\t\t\t     *                                      *\n");
//     printf("\t\t\t     *       ------------------------       *\n");
//     printf("\t\t\t     *           STUDENT LIBRARY            *\n");
//     printf("\t\t\t     *       ------------------------       *\n");
//     printf("\t\t\t     *                                      *\n");
//     printf("\t\t\t     *                                      *\n");
//     printf("\t\t\t     *       Mumbai,Maharashtra,India       *\n");
//     printf("\t\t\t     *     Email: studentlib@gmail.com      *\n");
//     printf("\t\t\t     *     Contact:8800991010,8800992020    *\n");
//     printf("\t\t\t     *                                      *\n");
//     printf("\t\t\t     ****************************************\n");
//     printf("\n\n\t\t\t             Press any key to continue: ");
//     getch();



    // // Inisialisasi linked list untuk setiap mata pelajaran
    // SubjectLinkedList mathList("Matematika");
    // mathList.addTopic("Aljabar");
    // mathList.addTopic("Trigonometri");
    // mathList.addTopic("Geometri");

    // SubjectLinkedList physicsList("Fisika");
    // physicsList.addTopic("Mekanika");
    // physicsList.addTopic("Termodinamika");
    // physicsList.addTopic("Optika");

    // // Menampilkan topik-topik per mata pelajaran
    // mathList.displayTopics();
    // physicsList.displayTopics();
// }

void main_menu() {
    // Main menu logic
    // ... (Same as in your C code)
}

Book* initialize_lib(Book* start) {
    // Initialization of library books
    // ... (Same as in your C code)
}

Student* book_issue(Student* start) {
    // Book issue logic
    // ... (Same as in your C code)
}

Student* book_return(Student* start) {
    // Book return logic
    // ... (Same as in your C code)
}

void display(Student* start) {
    // Display logic
    // ... (Same as in your C code)
}

Book* delete_book(int id) {
    // Book deletion logic
    // ... (Same as in your C code)
}

Book* add_book(char bookname[], char authorname[], int id) {
    // Book addition logic
    // ... (Same as in your C code)
}
