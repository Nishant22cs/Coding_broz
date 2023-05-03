#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void createNote()
{
    ofstream fout;
    string filename, note;
    
    cout << "Enter file name: ";
    cin >> filename;
    cout << "Enter note content: ";
    cin.ignore();
    getline(cin, note);
    
    fout.open(filename.c_str());
    fout << note;
    fout.close();
    
    cout << "Note created successfully!\n";
}

void readNote()
{
    ifstream fin;
    string filename, note;
    
    cout << "Enter file name: ";
    cin >> filename;
    
    fin.open(filename.c_str());
    getline(fin, note);
    fin.close();
    
    cout << "Note content:\n" << note << endl;
}
void updateNote()
{
    fstream file;
    string filename, note;
    
    cout << "Enter file name: ";
    cin >> filename;
    cout << "Enter new note content: ";
    cin.ignore();
    getline(cin, note);
    
    file.open(filename.c_str(), ios::out | ios::trunc);
    file << note;
    file.close();
    
    cout << "Note updated successfully!\n";
}

void deleteNote()
{
    string filename;
    
    cout << "Enter file name: ";
    cin >> filename;
    
    if (remove(filename.c_str()) != 0)
        cout << "Error deleting note\n";
    else
        cout << "Note deleted successfully\n";
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

        switch (choice) {
            case 1:
                create_note();
                break;
            case 2:
                view_notes();
                break;
            case 3:
                exit(0);
            default:
                cout << "Invalid choice! Please try again." <<endl;
        }

        cout << endl; // print newline for formatting
    }
    return 0;
}
