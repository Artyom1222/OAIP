#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <conio.h>
#include <algorithm>

using namespace std;

struct Node {
    char word;
    Node* left;
    Node* right;
};

void add(Node** tree, char a) {
    if (*tree == NULL)
    {
        (*tree) = new Node;
        (*tree)->word = a;
        (*tree)->left = (*tree)->right = NULL;
        return;
    }
    if (a > (*tree)->word) {
        add(&(*tree)->right, a);
    }
    else {
        add(&(*tree)->left, a);
    }
}

void insert(Node** root, string word) {
    for (int i = 0; i < word.size(); i++)
    {
        add(root, word[i]);
    }
}



void see_1(Node* seeTree, int u) {
    if (!seeTree) {

        return;
    }
    else {
        see_1(seeTree->left, ++u);
        for (int i = 0; i < u; ++i) cout << "|";
        cout << "->" << seeTree->word << endl;
        u--;
    }
    see_1(seeTree->right, ++u);
}

void print(Node* root) {
    if (root == nullptr) {
        return;
    }

    print(root->left);
    cout << root->word << endl;
    print(root->right);
}

int countWords(Node* root, char letter) {
    if (root == nullptr) {
        return 0;
    }

    int count = 0;

    if (root->word == letter) {
        count++;
    }

    count += countWords(root->left, letter);
    count += countWords(root->right, letter);

    return count;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Node* root = nullptr;

    ifstream file("word.txt");

    if (!file.is_open()) {
        cout << "Нет такого файла" << endl;
        return 0;
    }

    string word;

    while (file >> word) {
        insert(&root, word);
    }
    cout << word << endl << endl;
    file.close();
    see_1(root, 0);
    cout << "Введите букву: ";
    char letter = _getch();
    int count = countWords(root, letter);

    cout << endl << "Количество узлов, содержащих слова, начинающиеся с " << letter << ": " << count << endl;

    return 0;
}