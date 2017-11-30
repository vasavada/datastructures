#include <iostream>
#include <cstdlib>
#include <climits>

using nmaespace std;

struct TreeNode{
	TreeNode* left;
	TreeNode* right;
	int val;
};

TreeNode* createNode(int val){
	TreeNode* new_node = (TreeNode*)malloc(sizeof(TreeNode));
	new_node -> val = val;
	new_node -> left = NULL;
	new_node -> right = NULL;
	return new_node;
}

TreeNode* insert(TreeNode* root , int newVal){
	if(node == NULL) return createNode(newVal);
	if(root -> val >= newVal){
		root -> left = insert(root -> left , newval);
	}else{
		root -> right = insert(root -> right , newval);
	}
	return root;
}

int main(){
	return 0;
}