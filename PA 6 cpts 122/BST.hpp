#pragma once
#include "BSTNode.hpp"
#include <iostream>
#include <fstream>
#include <string>
using std::cout;
using std::cerr;
using std::endl;
using std::string;
using std::ifstream;

template <class T>
class BST {
public:
    BST();
    ~BST();

    void insert(char character, const string& morseCode);
    void printCurrentTree();
    void convertTextToMorse(const string& filename);
    void buildTreeFromFile(const string& filename);
    string search(char character) const;

private:
    BSTNode<T>* mpRoot;

    void inorderTraversal(BSTNode<T>* pTree);
    void destroyTree(BSTNode<T>* pTree);
};

template<class T>
inline BST<T>::BST() : mpRoot(nullptr) {}


template<class T>
inline BST<T>::~BST() {
    destroyTree(mpRoot);
}

template<class T>
inline void BST<T>::insert(char character, const string& morseCode)
{
    BSTNode<T>* newNode = new BSTNode<T>(character, morseCode);
    if (mpRoot == nullptr) {
        mpRoot = newNode;
    }
    else {
        BSTNode<T>* current = mpRoot;
        while (current != nullptr) {
            if (character < current->getText()) {
                if (current->getLeft() == nullptr) {
                    current->setLeft(newNode);
                    break;
                }
                else {
                    current = current->getLeft();
                }
            }
            else if (character > current->getText()) {
                if (current->getRight() == nullptr) {
                    current->setRight(newNode);
                    break;
                }
                else {
                    current = current->getRight();
                }
            }
            else {
                std::cout << "Duplicate character found: " << character << std::endl;
                break;
            }
        }
    }
}

template<class T>
inline void BST<T>::printCurrentTree() {
    cout << "Current Tree (Inorder Traversal):" << std::endl;
    inorderTraversal(mpRoot);
    cout << endl;
}

template<class T>
inline void BST<T>::convertTextToMorse(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Error opening file: " << filename << endl;
        return;
    }

    char ch;
    while (file.get(ch)) {
        if (ch == '\n') {
            cout << endl;
        }
        else {
            if (islower(ch)) {
                ch = toupper(ch);
            }
            if ((ch >= 'A' && ch <= 'Z') || ch == ',' || ch == '.') {
                string morse = search(ch);
                if (!morse.empty()) {
                    cout << morse << " ";
                }
                else {
                    cout << " ";
                }
            }
        }
    }

    file.close();
}

template<class T>
inline std::string BST<T>::search(char character) const {
    BSTNode<T>* current = mpRoot;
    while (current != nullptr) {
        if (current->getText() == character) {
            return current->getMorsecode();
        }
        else if (character < current->getText()) {
            current = current->getLeft();
        }
        else {
            current = current->getRight();
        }
    }
    return "";
}

template<class T>
inline void BST<T>::buildTreeFromFile(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error opening file: " << filename << endl;
        return;
    }

    char character;
    string morseCode;
    while (file >> character >> morseCode) {
        insert(character, morseCode);
    }

    file.close();
}



template<class T>
inline void BST<T>::inorderTraversal(BSTNode<T>* pTree) {
    if (pTree != nullptr) {
        inorderTraversal(pTree->getLeft());
        cout << pTree->getText() << ": " << pTree->getMorsecode() << endl;
        inorderTraversal(pTree->getRight());
    }
}


template<class T>
inline void BST<T>::destroyTree(BSTNode<T>* pTree) {
    if (pTree != nullptr) {
        destroyTree(pTree->getLeft());
        destroyTree(pTree->getRight());
        delete pTree;
    }
}
