#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void create_note() {
    string note;
    cout << "Enter your note:" << endl;//note enter 
    getline(cin, note);

    ofstream fout("notes.txt", ios::app); // open file in append mode
    fout << note << endl; // write note to file
    fout.close(); // close file

    cout << "Note created successfully!" << endl;
}

void view_notes() {
    ifstream fin("notes.txt");
    string note;

    if (fin.peek() == ifstream::traits_type::eof()) { // check if file is empty
        cout << "No notes found!" << endl;
        return;
    }

    cout << "Your notes:" << endl;

    while (getline(fin, note)) {
        cout << note << endl; // print note to console
    }

    fin.close();
}

int main() {
    int choice;

    while (true) {
        cout << "1. Create a note" << endl;
        cout << "2. View notes" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // ignore newline character in input buffer

        switch (choice) {//switch case
            case 1:
                create_note();
                break;
            case 2:
                view_notes();
                break;
            case 3:
                exit(0);
            default:
                cout << "Invalid choice! Please try again." << endl;
        }

        cout << endl; // print newline for formatting
    }
    return 0;
}
