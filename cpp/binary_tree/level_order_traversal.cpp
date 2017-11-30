#include <iostream>
#include <cstdlib>
#include <climits>
#include <queue>
#include <vector>

using namespace std;

struct Node{
	int data;
	Node* left;
	Node* right;
};

Node* createNode(int data){
	Node* new_node    = (Node*)malloc(sizeof(Node));
	new_node -> left  = NULL;
	new_node -> right = NULL;
	new_node -> data  = data;
	return new_node;
}

void printLevelOrder(Node* node){
	if(node == NULL){
		return;
	}

	queue<Node*> q;
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

// return vector of vector<int>
// where each level is stored in vector<int>
vector<vector<int>> ret;
void buildVector(Node* root , int depth){
	if(root == NULL) return;
	if(ret.size() == depth) ret.push_back(vector<int>());

	ret[depth].push_back(root -> data);
	buildVector(root -> left , depth + 1);
	buildVector(root -> right , depth + 1);
}

vector<vector<int>> levelOrder(Node* root){
	buildVector(root , 0);
	return ret;
}

int main(){
/*************************************************
					 ____1____
					/		  \
				___2___	   ___3___
			   /	   \  /	   	  \
			  4		   5 6		  7
*************************************************/
	Node *root             = createNode(1);
	root -> left           = createNode(2);
	root -> right          = createNode(3);
	root -> left -> left   = createNode(4);
	root -> left -> right  = createNode(5);
	root -> right -> left  = createNode(6);
	root -> right -> right = createNode(7);

	printLevelOrder(root);
	return 0;
}