#include <iostream>
#include <cstring>

using namespace std;

struct Tree {
    int x;
    Tree *left, *right;
};

void add_leaf(Tree *&root, int data);

void my_print(Tree *tree);

int search(Tree *root, int k, int &count);

bool dfs(Tree *root);

int main() {
    int k = 5;
    Tree *tree = new Tree;
    tree->x = 9;
    tree->left = nullptr;
    tree->right = nullptr;
    add_leaf(tree, 11);
    for (int i = 1; i < 6; i++) {
        add_leaf(tree, i);
    }
    add_leaf(tree, 41);
    add_leaf(tree, 10);
    cout << "\nmyprint(Tree)" << endl;
    my_print(tree);
    cout << endl;
    int count = 0;
    if (search(tree, k, count))
        cout << "true" << endl;
    else cout << "false" << endl;

    char str[] = "nastya";
    tree = nullptr;
    for (int i = 0; i < strlen(str); i++) {
        add_leaf(tree, (int) str[i]);
    }
    cout << "int  str" << endl;
    my_print(tree);
    cout << endl;
    cout << "dfs\n";
    if (dfs(tree)) cout << "true ";
    cout << endl;
    system("pause");
}

bool dfs(Tree *root) {
    if (root == nullptr) {
        return false;
    }
    int k = root->x;
    int count = 0;
    if (search(root, k, count) >= 2) {
        return true;
    }
    dfs(root->left);
    dfs(root->right);
}

int search(Tree *root, int k, int &count) {
    if (root == nullptr) {
        return count;
    }

    if (root->x == k) count++;

    if (k <= root->x) {
        search(root->left, k, count);
    } else {
        search(root->right, k, count);
    }
}

void my_print(Tree *tree) {
    if (tree == nullptr) {
        return;
    }
    cout << tree->x << " ";
    my_print(tree->left);
    my_print(tree->right);
}

void add_leaf(Tree *&root, int data) {
    if (root == nullptr) {
        Tree *temper = new Tree;
        temper->x = data;
        temper->left = nullptr;
        temper->right = nullptr;
        root = temper;
    } else {
        if (data <= root->x) {
            add_leaf(root->left, data);
        } else add_leaf(root->right, data);
    }
}
