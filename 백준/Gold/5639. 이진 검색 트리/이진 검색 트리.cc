// 5639

#include <iostream>
#include <vector>

using namespace std;

struct Node {
	int data;
	Node* left;
	Node* right;
};

Node* insertNode(Node* node, int n);
void postOrder(Node* node);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	Node* root = NULL;

	int n;
	while (cin >> n) {
		root = insertNode(root, n);
	}

	postOrder(root);

	
	return 0;
}

void postOrder(Node* node) {
	if (node->left != NULL)postOrder(node->left);
	if (node->right != NULL)postOrder(node->right);
	cout << node->data << "\n";
}

Node* insertNode(Node* node, int n) {
	if (node == NULL) {
		node = new Node();
		node->data = n;
		node->left = node->right = NULL;
	}
	else if (n < node->data)
		node->left = insertNode(node->left, n);
	else
		node->right = insertNode(node->right, n);

	return node;
}