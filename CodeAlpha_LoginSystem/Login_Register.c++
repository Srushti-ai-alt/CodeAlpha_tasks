#include <iostream>
#include <fstream>
using namespace std;


void registerUser() {
    string username, password;
    
    cout << "\n--- Registration ---\n";
    cout << "Enter username: ";
    cin >> username;
    
    cout << "Enter password: ";
    cin >> password;

    
    ifstream inFile(username + ".txt");
    if (inFile) {
        cout << "❌ Username already exists! Try another.\n";
        return;
    }
    inFile.close();

    
    ofstream outFile(username + ".txt");
    outFile << username << endl << password;
    outFile.close();

    cout << "✅ Registration Successful!\n";
}


void loginUser() {
    string username, password, storedUser, storedPass;

    cout << "\n--- Login ---\n";
    cout << "Enter username: ";
    cin >> username;

    cout << "Enter password: ";
    cin >> password;

  
    ifstream inFile(username + ".txt");
    if (!inFile) {
        cout << "❌ User not found!\n";
        return;
    }

    getline(inFile, storedUser);
    getline(inFile, storedPass);
    inFile.close();

   
    if (username == storedUser && password == storedPass) {
        cout << "✅ Login Successful!\n";
    } else {
        cout << "❌ Invalid password!\n";
    }
}


int main() {
    int choice;

    do {
        cout << "\n===== MENU =====\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                loginUser();
                break;
            case 3:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "❌ Invalid choice!\n";
        }
    } while (choice != 3);

    return 0;
}