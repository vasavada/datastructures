#include <iostream>
#include <cstdlib>
#include <climits>
#include <queue>

using namespace std;

struct Node{
	int data;
	struct Node* left;
	struct Node* right;
};

Node* createNode(int data){
	Node* new_node    = (struct Node*)malloc(sizeof(struct Node));
	new_node -> left  = NULL;
	new_node -> right = NULL;
	new_node -> data  = data;
	return new_node;
}

void printLevelOrder(struct Node* node){
	if(node == NULL){
		return;
	}

	queue<struct Node*> q;

	q.push(node);

	while(q.empty() == false){
		Node* node = q.front();
		cout << node -> data << " ";
		q.pop();

		if(node -> left != NULL){
			q.push(node -> left);
		}

		if(node -> right != NULL){
			q.push(node -> right);
		}
	}
}

int main(){
/*************************************************
					 ____1____
					/		  \
				___2___	   ___3___
			   /	   \  /	   	  \
			  4		   5 6		   7
*************************************************/
	Node *root = createNode(1);
	root->left        = createNode(2);
	root->right       = createNode(3);
	root->left->left  = createNode(4);
	root->left->right = createNode(5);
	root->right->left  = createNode(6);
	root->right->right = createNode(7);

	printLevelOrder(root);
	return 0;
}