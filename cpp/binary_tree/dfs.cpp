#include <iostream>
#include <cstdlib>
#include <climits>
#include <vector>

using namespace std;

struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
};

TreeNode* createNode(int val){
	TreeNode* new_node = (TreeNode*)malloc(sizeof(TreeNode));
	new_node -> left = NULL;
	new_node -> right = NULL;
	new_node -> val = val;
	return new_node;
}

void inOrder(TreeNode* root){
	if(root == NULL) return;
	inOrder(root -> left);
	cout << root -> val << " ";
	inOrder(root -> right);
}

void preOrder(TreeNode* root){
	if(root == NULL) return;
	cout << root -> val << " ";
	preOrder(root -> left);
	preOrder(root -> right);
}

void postOrder(TreeNode* root){
	if(root == NULL) return;
	postOrder(root -> left);
	postOrder(root -> right);
	cout << root -> val << " ";
}

int main(){
	return 0;
}