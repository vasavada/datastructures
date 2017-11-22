#include <iostream>
#include <cstdlib>
#include <climits>

using namespace std;

struct Node{
	int data;
	struct Node* left;
	struct Node* right;
};

struct Node* createNode(int data){
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	new_node -> data = data;
	new_node -> left = NULL;
	new_node -> right = NULL;
	return new_node;
}

int height(struct Node* node){
	if(node == NULL){
		return 0;
	}else{
		int lheight = height(node -> left);
		int rheight = height(node -> right);

		if(lheight > rheight){
			return lheight + 1;
		}else{
			return rheight + 1;
		}
	}
}

int main(){
	struct Node *root = createNode(1);
	root->left        = createNode(2);
	root->right       = createNode(3);
	root->left->left  = createNode(4);
	root->left->right = createNode(5);

	cout << "Height of this tree: " << height(root) << " " << endl;
	return 0;
}