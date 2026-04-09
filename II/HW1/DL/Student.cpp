#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cctype>   
using namespace std;

struct Contact {
    string name;
    string phone;
};

const string FILENAME = "kpop.txt";

bool isValidPhone10(const string& phone) {
    if (phone.size() != 10) return false;
    for (char ch : phone) {
        if (!isdigit((unsigned char)ch)) return false;
    }
    return true;
}

vector<Contact> loadFile() {
    vector<Contact> book;
    ifstream fin(FILENAME);
    if (!fin) return book; 
    string line;
    while (getline(fin, line)) {
        size_t pos = line.find(',');
        if (pos == string::npos) continue;
        Contact c;
        c.name = line.substr(0, pos);
        c.phone = line.substr(pos + 1);
        if (!c.name.empty() && !c.phone.empty()){
            book.push_back(c);
        }
    }
    return book;
}

void saveFile(const vector<Contact>& book) {
    ofstream fout(FILENAME);
    for (auto &c : book) {
        fout << c.name << "," << c.phone << "\n";
    }
}

int findByName(const vector<Contact>& book, const string& name) {
    for (int i = 0; i < (int)book.size(); i++) {
        if (book[i].name == name) {
            return i;
        }
    }
    return -1;
}

bool insertContact(vector<Contact>& book, const string& name, const string& phone) {  //You need to code

    return true;
}

bool updateContact(vector<Contact>& book, const string& name, const string& newPhone) { //You need to code
    
    return true;
}

bool deleteContact(vector<Contact>& book, const string& name) { //You need to code
    
    return true;
}

void listAll(const vector<Contact>& book) {
    cout << "\n--- K-POP Phonebook ---\n";
    if (book.empty()) {
        cout << "(empty)\n";
        return;
    }
    for (auto &c : book) {
        cout << c.name << " : " << c.phone << "\n";
    }
}

int main() {
    vector<Contact> book = loadFile();
    while (true) {
        cout << "\n1.Insert 2.Update 3.Delete 4.List 5.Exit\n> ";
        int op;
        cin >> op;
        if (op == 1) { 
            string name, phone;
            cout << "Name: ";
            cin >> name;
            cout << "Phone: ";
            cin >> phone;
            if (!isValidPhone10(phone)) {
                cout << "Invalid phone (must be 10 digits)\n";
                continue;
            }
            if (insertContact(book, name, phone)) {
                saveFile(book);
                cout << "Inserted\n";
            } else {
                cout << "Name already exists\n";
            }
        } 
        else if (op == 2) { 
            string name, newPhone;
            cout << "Name to update: ";
            cin >> name;
            cout << "New phone: ";
            cin >> newPhone;

            if (updateContact(book, name, newPhone)) {
                saveFile(book);
                cout << "Updated\n";
            } else {
                cout << "Not found\n";
            }

        } 
        else if (op == 3) { 
            string name;
            cout << "Name to delete: ";
            cin >> name;

            if (deleteContact(book, name)) {
                saveFile(book);
                cout << "Deleted\n";
            } else {
                cout << "Not found\n";
            }

        } 
        else if (op == 4) {
            listAll(book);

        }
        else if (op == 5) {
            cout << "Bye!\n";
            break;

        } 
        else {
            cout << "Invalid choice.\n";
        }
    }
    return 0;
}
