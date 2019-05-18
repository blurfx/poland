#include <stdio.h>
#include <stdlib.h>

struct node {
	int value;
	struct node *left, *right;
};

struct node* createNode(int value) {
	struct node* node = (struct node*)malloc(sizeof(struct node));

	node->value = value;

	node->left = node->right = NULL;
	return node;
}

void removeNode(struct node* node, int removeLeftNode) {
	if (removeLeftNode) {
		free(node->left);
		node->left = NULL;
	}
	else {
		free(node->right);
		node->right = NULL;
	}
}

int main() {
	struct node* root = createNode(10);
	root->left = createNode(20);
	root->right = createNode(30);

	removeNode(root, 1);
	removeNode(root, 0);
	free(root);
	root = NULL;
	return 0;
}