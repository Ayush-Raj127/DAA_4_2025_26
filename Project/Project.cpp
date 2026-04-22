#include <iostream>
#include <string>
using namespace std;

const int MAX = 100;

int binarySearch(string titles[], int n, string key) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (titles[mid] == key)
            return mid;
        else if (titles[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

void insertBook(string titles[], string authors[], int ids[], int &n, string title, string author, int id) {
    int i = n - 1;
    while (i >= 0 && titles[i] > title) {
        titles[i + 1] = titles[i];
        authors[i + 1] = authors[i];
        ids[i + 1] = ids[i];
        i--;
    }
    titles[i + 1] = title;
    authors[i + 1] = author;
    ids[i + 1] = id;
    n++;
}

void display(string titles[], string authors[], int ids[], int n) {
    for (int i = 0; i < n; i++) {
        cout << ids[i] << " | " << titles[i] << " | " << authors[i] << endl;
    }
}

int main() {
    string titles[MAX], authors[MAX];
    int ids[MAX];
    int n = 0;
    int choice;

    do {
        cout << "\n1. Add Book\n2. Search Book\n3. Display All\n4. Exit\nEnter choice: ";
        cin >> choice;

        if (choice == 1) {
            string title, author;
            int id;
            cin.ignore();
            cout << "Enter title: ";
            getline(cin, title);
            cout << "Enter author: ";
            getline(cin, author);
            cout << "Enter ID: ";
            cin >> id;
            insertBook(titles, authors, ids, n, title, author, id);
        } 
        else if (choice == 2) {
            string key;
            cin.ignore();
            cout << "Enter title to search: ";
            getline(cin, key);
            int index = binarySearch(titles, n, key);
            if (index != -1) {
                cout << "Found: " << ids[index] << " | " << titles[index] << " | " << authors[index] << endl;
            } else {
                cout << "Book not found\n";
            }
        } 
        else if (choice == 3) {
            display(titles, authors, ids, n);
        }

    } while (choice != 4);

    return 0;
}