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

struct node* insert(struct node* node, int value) {
	if (node == NULL) return createNode(value);

	if (value < node->value) {
		node->left = insert(node->left, value);
	}
	else {
		node->right = insert(node->right, value);
	}
	return node;
}

struct node* search(struct node* node, int value) {
	if (node == NULL || node->value == value) {
		return node;
	}

	if (node->value < value)
		return search(node->left, value);
	else
		return search(node->right, value);
}

struct node* findMinimumNode(struct node* node)
{
	struct node* cur = node;

	while (cur && cur->left != NULL)
		cur = cur->left;

	return cur;
}

struct node* removeNode(struct node* node, int value) {
	
	if (node == NULL) return node;


	if (node->value < value)
		node->left = removeNode(node->left, value);
	else if(node->value > value)
		node->right = removeNode(node->right, value);
	else {
		if (node->left == NULL) {
			struct node* temp = node->right;
			free(node);
			return temp;
		}
		else if (node->right == NULL) {
			struct node* temp = node->right;
			free(node);
			return temp;
		}
		struct node* temp = findMinimumNode(node);
		node->value = temp->value;
		node->right = removeNode(node->right, temp->value);
	}
	return search(node->right, value);
}

int main() {
	struct node *root = insert(NULL, 5);

	insert(root, 2);
	insert(root, 6);

	insert(root, 4);
}