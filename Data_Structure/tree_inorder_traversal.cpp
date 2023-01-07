#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
	int key;
	struct TreeNode* left, * right;
} TreeNode;

void insert_node(TreeNode** root, int key)
{
	TreeNode* p, * t;// p: parent node, t: current node
	TreeNode* n;// n: new node to be inserted
	t = *root;
	p = NULL;
	// Search first
	while (t != NULL) {
		if (key == t->key) {
			return; 
		}
		p = t;
		if (key < t->key) t = t->left;
		else t = t->right;
	}
	// Since the key is not in the tree, insertion is possible.
	n = (TreeNode*)malloc(sizeof(TreeNode));
	if (n == NULL) return;
	n->key = key;
	n->left = n->right = NULL;

	if (p != NULL)
		if (key < p->key) // 목표 key가 현재 노드보다 작은 경우 
			p->left = n; 
		else p->right = n; // 목표 key가 현재 노드보다 큰 경우 
	else *root = n;
}

void inorder(TreeNode* root) {
	if (root) {
		inorder(root->left); // Left subtree
		printf("%5d\t", root->key); // Visit root node
		inorder(root->right);// Right subtree
	}
}


int random(int n) {
	return rand() % n;
}

void main() {
	TreeNode* root = NULL;

	int input_size = 1000;
	int data_maxval = 10000;

	// output: sorted result
	int* input = (int*)malloc(sizeof(int) * input_size);

	// generate an input data randomly
	for (int i = 0; i < input_size; i++) {
		input[i] = random(data_maxval);
		insert_node(&root, input[i]);
	}

	inorder(root);
}