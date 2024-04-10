#pragma once
#include <string>
using std::string;

template <class T>
class BSTNode {
public:
    BSTNode(T ch, const string& morse) : text(ch), morseCode(morse), left(nullptr), right(nullptr) {}

    T getText() const { return text; }
    string getMorsecode() const { return morseCode; }
    BSTNode<T>* getLeft() const { return left; }
    BSTNode<T>* getRight() const { return right; }

    void setText(T text) { this->text = text; }
    void setMorsecode(const string& morseCode) { this->morseCode = morseCode; }
    void setLeft(BSTNode<T>* left) { this->left = left; }
    void setRight(BSTNode<T>* right) { this->right = right; }

private:
    T text;
    string morseCode;
    BSTNode<T>* left;
    BSTNode<T>* right;
};
