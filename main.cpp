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
