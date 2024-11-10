#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#define MAX_BOOKS 1000  // Макрос максимальної кількості книг для зручності програми

// Структура з характеристиками книги
struct Book {
    int id;
    string title;
    string author;
    int year;
    string genre;
};

// Масив для праці з характеристиками книг
Book* library; // Вказівник на масив книг
int bookCount = 0; // Нульова кількість книг

// Ініціалізація динамічіского массива
void writingInfoInArr() {
    library = new Book[MAX_BOOKS];
}

// Функція для зчитування інформації на початку программи
void readInfoFromFile() {
    ifstream file("library.txt");
    if (!file) {
        return;
    }

    while (!file.eof() && bookCount < MAX_BOOKS) {
        file >> library[bookCount].id;
        file >> library[bookCount].title;
        file >> library[bookCount].author;
        file >> library[bookCount].year;
        file >> library[bookCount].genre;
        if (file) {
            bookCount++; // Підрахунок кількості книг
        }
    }
    file.close();
}

// Функція для збереження інформації у файл
void saveArrInFile() {
    ofstream file("library.txt");
    for (int i = 0; i < bookCount; i++) {
        file << library[i].id << endl;
        file << library[i].title << endl;
        file << library[i].author << endl;
        file << library[i].year << endl; 
        file << library[i].genre << endl;
    }
    file.close();
    cout << "" << endl;
    cout << "Info saved in file" << endl;
    cout << "" << endl;
}

// Функція для додавання книг в бібліотеку
void addBook() {
    if (bookCount >= MAX_BOOKS) {
        cout << "Library is filled";
        return;
    }
    
    cout << "" << endl;
    cout << "Enter book's ID: ";
    cin >> library[bookCount].id;
    cout << "Enter book's title: ";
    cin >> library[bookCount].title;
    cout << "Enter author: ";
    cin >> library[bookCount].author;
    cout << "Enter publication year: ";
    cin >> library[bookCount].year;
    while (library[bookCount].year > 2024 || library[bookCount].year < 0) {
        cout << "Error input. Enter publication year again: ";
        cin >> library[bookCount].year;
    }
    cout << "Enter genre: ";
    cin >> library[bookCount].genre;

    bookCount++;
    cout << "" << endl;
    cout << "Book was added" << endl;
    cout << "" << endl;
}

// Функція для видалення книг з бібліотеки
void deleteBook(int id) {
    int index = -1;
    for (int i = 0; i < bookCount; i++) {
        if (library[i].id == id) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        cout << "" << endl;
        cout << "There isn't book with that ID" << endl;
        cout << "" << endl;
        return;
    }

    for (int i = index; i < bookCount - 1; i++) {
        library[i] = library[i + 1];
    }
    bookCount--;

    cout << "" << endl;
    cout << "Book was deleted" << endl;
    cout << "" << endl;
}

// Функція для пошуку книг в бібліотеці
void searchBook(int id) {
    int id2, year;
    string title, author, genre;
    if (id == 1) {
        cout << "Enter book ID: ";
        cin >> id2;
        for (int i = 0; i < bookCount; i++) {
            if (library[i].id == id2) {
                cout << "" << endl;
                cout << "ID: " << library[i].id << endl;
                cout << "Title: " << library[i].title << endl;
                cout << "Author : " << library[i].author << endl;
                cout << "Publication Year: " << library[i].year << endl;
                cout << "Genre: " << library[i].genre << endl;
                cout << "" << endl;
                return;
            }
        }
    }
    if (id == 2) {
        cout << "Enter book Title: ";
        cin >> title;
        for (int i = 0; i < bookCount; i++) {
            if (library[i].title == title) {
                cout << "" << endl;
                cout << "ID: " << library[i].id << endl;
                cout << "Title: " << library[i].title << endl;
                cout << "Author : " << library[i].author << endl;
                cout << "Publication Year: " << library[i].year << endl;
                cout << "Genre: " << library[i].genre << endl;
                cout << "" << endl;
                return;
            }
        }
    }
    if (id == 3) {
        cout << "Enter book Author: ";
        cin >> author;
        for (int i = 0; i < bookCount; i++) {
            if (library[i].author == author) {
                cout << "" << endl;
                cout << "ID: " << library[i].id << endl;
                cout << "Title: " << library[i].title << endl;
                cout << "Author : " << library[i].author << endl;
                cout << "Publication Year: " << library[i].year << endl;
                cout << "Genre: " << library[i].genre << endl;
                cout << "" << endl;
                return;
            }
        }
    }
    if (id == 4) {
        cout << "Enter book Publication Year: ";
        cin >> year;
        for (int i = 0; i < bookCount; i++) {
            if (library[i].year == year) {
                cout << "" << endl;
                cout << "ID: " << library[i].id << endl;
                cout << "Title: " << library[i].title << endl;
                cout << "Author : " << library[i].author << endl;
                cout << "Publication Year: " << library[i].year << endl;
                cout << "Genre: " << library[i].genre << endl;
                cout << "" << endl;
                return;
            }
        }
    }
    if (id == 5) {
        cout << "Enter book Genre: ";
        cin >> genre;
        for (int i = 0; i < bookCount; i++) {
            if (library[i].genre == genre) {
                cout << "" << endl;
                cout << "ID: " << library[i].id << endl;
                cout << "Title: " << library[i].title << endl;
                cout << "Author : " << library[i].author << endl;
                cout << "Publication Year: " << library[i].year << endl;
                cout << "Genre: " << library[i].genre << endl;
                cout << "" << endl;
                return;
            }
        }
    }
    if (id > 0 && id < 6) {
        cout << "" << endl;
        cout << "Input Error" << endl;
        cout << "" << endl;
    }
}

// Функція для змінення книг в бібліотеці
void editBook(int id) {
    for (int i = 0; i < bookCount; i++) {
        if (library[i].id == id) {
            cout << "" << endl;
            cout << "Enter new title: ";
            cin >> library[i].title;
            cout << "Enter new author: ";
            cin >> library[i].author;
            cout << "Enter new publication year: ";
            cin >> library[i].year;
            cout << "Enter new genre: ";
            cin >> library[i].genre;
            cout << "" << endl;
            cout << "Book updated successfully" << endl;
            cout << "" << endl;
            return;
        }
    }
    cout << "" << endl;
    cout << "There isn't book with that ID";
    cout << "" << endl;
}

// Функція для виведення всіх книг
void showBooks() {
    if (bookCount == 0) {
        cout << "The library is empty" << endl;
        return;
    }

    for (int i = 0; i < bookCount; i++) {
        cout << "" << endl;
        cout << "ID: " << library[i].id << endl;
        cout << "Title: " << library[i].title << endl;
        cout << "Author : " << library[i].author << endl;
        cout << "Publication Year: " << library[i].year << endl;
        cout << "Genre: " << library[i].genre << endl;
        cout << "" << endl;
    }
}

// Функція для виведення повної кількості книг
void countTotalBooks() {
    cout << "" << endl;
    cout << "Total count of books: " << bookCount << endl;
    cout << "" << endl;
}

// Функція для виведення кількості книг за жанром
void countBooksOfGenre(string genre) {
    int count = 0;
    for (int i = 0; i < bookCount; i++) {
        if (library[i].genre == genre) {
            count++;
        }
    }
    cout << "" << endl;
    cout << "Count of books of some genre: " << count << endl;
    cout << "" << endl;
    return;
    cout << "" << endl;
    cout << "There isn't that genre" << endl;
    cout << "" << endl;
}

// Функція для виведення повної інформації про книгу за роком
void fullInfoByYear(int year) {
    int help = 0;
    for (int i = 0; i < bookCount; i++) {
        if (library[i].year == year) {
            cout << "" << endl;
            cout << "ID: " << library[i].id << endl;
            cout << "Title: " << library[i].title << endl;
            cout << "Author : " << library[i].author << endl;
            cout << "Publication Year: " << library[i].year << endl;
            cout << "Genre: " << library[i].genre << endl;
            cout << "" << endl;
            help++;
        }
    }
    if (help == 0) {
        cout << "" << endl;
        cout << "There isn't that publication year" << endl;
        cout << "" << endl;
    }
}

// Функція для виведення повної інформації про книгу за жанром
void fullInfoByGenre(string genre) {
    int help = 0;
    for (int i = 0; i < bookCount; i++) {
        if (library[i].genre == genre) {
            cout << "" << endl;
            cout << "ID: " << library[i].id << endl;
            cout << "Title: " << library[i].title << endl;
            cout << "Author : " << library[i].author << endl;
            cout << "Publication Year: " << library[i].year << endl;
            cout << "Genre: " << library[i].genre << endl;
            cout << "" << endl;
            return;
        }
    }
    cout << "" << endl;
    cout << "There isn't that genre" << endl;
    cout << "" << endl;
}

// Функція для перевірки на помилку при введені року
bool isValidYear(int year) {
    return year > 0 && year <= 2024;
}

// Функція для роботи з меню
void menu() {
    int choice, id, year;
    string genre, title, author;
    while (true) {
        cout << "Menu:" << endl;
        cout << "1. Add book" << endl;
        cout << "2. Delete book" << endl;
        cout << "3. Search book" << endl;
        cout << "4. Edit book" << endl;
        cout << "5. Show every books" << endl;
        cout << "6. Total count of books" << endl;
        cout << "7. Count of books of some genre" << endl;
        cout << "8. Show full info about books of some genre" << endl;
        cout << "9. Show full info about books issued in user year" << endl;
        cout << "10. Save data" << endl;
        cout << "11. Exit" << endl;
        cout << "Write your choice: ";
        cin >> choice;

        if (choice > 0 && choice < 12) {
            if (choice == 1) {
                addBook();
            }

            if (choice == 2) {
                cout << "Enter book ID to delete: ";
                cin >> id;
                deleteBook(id);
            }

            if (choice == 3) {
                cout << "1. ID" << endl;
                cout << "2. Title" << endl;
                cout << "3. Author" << endl;
                cout << "4. Publication Year" << endl;
                cout << "5. Genre" << endl;
                cout << "Enter way, how you would like to search book: ";
                cin >> id;
                searchBook(id);
            }

            if (choice == 4) {
                cout << "Enter book ID to edit: ";
                cin >> id;
                editBook(id);
            }

            if (choice == 5) {
                showBooks();
            }

            if (choice == 6) {
                countTotalBooks();
            }

            if (choice == 7) {
                cout << "Enter genre for count: ";
                cin >> genre;
                countBooksOfGenre(genre);
            }

            if (choice == 8) {
                cout << "Enter genre for full info: ";
                cin >> genre;
                fullInfoByGenre(genre);
            }

            if (choice == 9) {
                cout << "Enter publication Year for full info: ";
                cin >> year;
                fullInfoByYear(year);
            }

            if (choice == 10) {
                saveArrInFile();
            }

            if (choice == 11) {
                break;
            }
        }

        else {
            cout << "" << endl;
            cout << "Wrong choice, write again: " << endl;
            cout << "" << endl;
        }
    }
}

int main() {
    writingInfoInArr();
    readInfoFromFile(); 
    menu();          
    saveArrInFile();   
    delete[] library; // Видалення масиву для очистки пам'яті
    return 0;
}

