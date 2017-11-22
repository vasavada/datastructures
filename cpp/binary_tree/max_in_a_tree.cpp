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
	new_node -> data      = data;
	new_node -> left      = NULL;
	new_node -> right     = NULL;
	return new_node;
}

int findMax(struct Node* node){
	if(node == NULL){
		return INT_MIN;
	}

	int res = node -> data;
	int lres = findMax(node -> left);
	int rres = findMax(node -> right);

	if (lres > res){
		res = lres;
	}

	if (rres > res){
		res = rres;
	}

	return res;
}

int main(){
	struct Node *root = createNode(1);
	root->left        = createNode(2);
	root->right       = createNode(3);
	root->left->left  = createNode(4);
	root->left->right = createNode(5);


/*************************************************
					 ____1____
					/		  \
				___2___	   	  3
			   /	   \
			  4		   5
*************************************************/


	cout << "Max in this tree: " << findMax(root) << " " << endl;
	return 0;
}