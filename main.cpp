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
int main()
{
    int choice;
    
    cout << "Simple Notes Manager\n";
    cout << "---------------------\n";
    
    do
    {
        cout << "1. Create Note\n";
        cout << "2. Read Note\n";
        cout << "3. Update Note\n";
        cout << "4. Delete Note\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice)
        {
            case 1:
                createNote();
                break;
            case 2:
                readNote();
                break;
            case 3:
                updateNote();
                break;
            case 4:
                deleteNote();
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice\n";
        }
        
    } while (choice != 5);
    
    return 0;
}
