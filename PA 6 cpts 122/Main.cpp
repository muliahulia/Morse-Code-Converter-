#include <iostream>
#include <fstream>
#include "BST.hpp" 

using namespace std;
#include <iostream>
#include <fstream>
#include "BST.hpp" 

using namespace std;

int main() {
    BST<char> morseTree;
    morseTree.buildTreeFromFile("MorseTable.txt");

    int choice;
    do {
        cout << "Select from Menu\n" << endl;
        cout << "1. Print current tree\n" << endl;
        cout << "2. Convert text from convert.txt file to Morse code\n" << endl;
        cout << "3. Exit \n" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            system("cls");
            morseTree.printCurrentTree();
            system("pause");

            break;
        case 2:
            system("cls");
            morseTree.convertTextToMorse("convert.txt");
            cout << "\n" << endl;
            system("pause");
            break;
        case 3:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 3);

    return 0;
}
