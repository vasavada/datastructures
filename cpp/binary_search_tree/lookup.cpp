#include <iostream>
#include <cstdlib>
#include <climits>

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
	return new_val;
}

bool lookup(TreeNode* root , int target){
	if(root == NULL) return false;
	if(root -> val == target){
		return true;
	}else{
		if(target < root -> data){
			return lookup(root -> left , target);
		}else{
			return lookup(root -> right , target);
		}
	}
}

int main(){
	return 0;
}