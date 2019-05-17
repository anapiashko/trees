#include<iostream>

using namespace std;

struct tree {
	int x;
	tree *left, *right;
};

void PrintLKP(tree* Tree);

void add_leaf(tree*& root, int data);

void myprint(tree*Tree);

int search(tree* root, int k, int& count);

bool obxod(tree* root);

int main() {
	int k =5;
	tree* Tree = new tree;
	Tree->x = 9;
	Tree->left = nullptr;
	Tree->right = nullptr;
	add_leaf(Tree,11);
	for (int i = 1; i < 6; i++) {
		add_leaf(Tree, i);
	}
	add_leaf(Tree, 41);
	add_leaf(Tree, 10);
	PrintLKP(Tree);
	cout << "\nmyprint(Tree)" << endl;
	myprint( Tree);
	cout << endl;
	int count = 0;
	if (search(Tree, k,count))
		cout << "true" << endl;
	else cout << "false" << endl;

	char str[] = "nastya";
	Tree = nullptr;
	for (int i = 0; i < strlen(str); i++) {
		add_leaf(Tree, (int)str[i]);
	}
	cout << "int  str" << endl;
	myprint(Tree);
	cout << endl;
	cout << "obxod\n";
	if( obxod(Tree)) cout << "true ";
	cout << endl;
	system("pause");
}

bool obxod(tree* root) {
	if (root == nullptr) {
		return false;
	}
	int k = root->x;
	int count = 0;
	if (search(root, k, count) >= 2) {
		return true;
	}
	obxod(root->left);
	obxod(root->right);
}

int search(tree* root, int k , int& count) {
	if (root == nullptr) {
		return count;
	}
	
	if (root->x == k) count++;

	if (k <= root->x) {
		search(root->left, k,count);
	}
	else {
		search(root->right, k,count);
	}
}

void PrintLKP(tree* tree){
	if (!tree) {return; } // пустое дерево – окончание рекурсии
	PrintLKP(tree->left); // обход левого поддерева
	cout <<  tree->x << "  "; // вывод информации о корне
	PrintLKP(tree->right); // обход правого поддерева
}

void myprint(tree* Tree) {
	if (Tree == nullptr) {
		return;
	}
	cout << Tree->x << " ";
	myprint(Tree->left);
	myprint(Tree->right);
}

void add_leaf(tree*& root , int data) {
	if (root == nullptr) {
		tree* temper = new tree;
		temper->x = data;
		temper->left = nullptr;
		temper->right = nullptr;
		root = temper;
	}
	else {
		if (data <= root->x) {
			add_leaf(root->left, data);
		}
		else add_leaf(root->right, data);
	}
}
