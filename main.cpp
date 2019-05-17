#include <iostream>
#include <cstring>

using namespace std;

struct Tree {
    int x;
    Tree *left, *right;
};

void add_leaf(Tree *&node, int data);

void my_print(Tree *tree);

bool target_function(Tree *node);

int main() {
    Tree *root = nullptr;
    char str[] = "nastya";
    for (int i = 0; i < strlen(str); i++) {
        add_leaf(root, (int) str[i]);
    }
    cout << "\nmy_print(Tree)" << endl;
    my_print(root);
    cout << endl;
    cout << "target_function\n";
    if (target_function(root)) {
        cout << "true";
    } else {
        cout << "false";
    }
    cout << endl;
//    system("pause");
}

bool target_function(Tree *node) {
    if (node == nullptr) {
        return false;
    }

    if (node->left != nullptr && node->left->x == node->x) {
        return true;
    } else {
        if (target_function(node->left)) {
            return true;
        } else {
            return target_function(node->right);
        }
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

void add_leaf(Tree *&node, int data) {
    if (node == nullptr) {
        Tree *temper = new Tree;
        temper->x = data;
        temper->left = nullptr;
        temper->right = nullptr;
        node = temper;
    } else {
        if (data <= node->x) {
            add_leaf(node->left, data);
        } else {
            add_leaf(node->right, data);
        }
    }
}
