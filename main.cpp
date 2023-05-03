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
