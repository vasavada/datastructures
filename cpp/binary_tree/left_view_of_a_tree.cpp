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

struct TreeNode* newNode(int val){
	struct TreeNode* new_node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
	new_node -> left          = NULL;
	new_node -> right         = NULL;
	new_node -> val           = val;
	return new_node;
}

vector<vector<int>> ret;

void buildVector(TreeNode* root , int depth){
	if(root == NULL) return;
	if(ret.size() == depth) ret.push_back(vector<int>());

	ret[depth].push_back(root -> val);
	buildVector(root -> left , depth + 1);
	buildVector(root -> right , depth + 1);
}

void printVector(vector<int> arr){
	for(int i = 0 ; i < arr.size() ; i++){
		cout << arr[i] << " ";
	}
	cout << endl;
}

vector<vector<int>> leftView(TreeNode* root , int level){
	buildVector(root , 0);
	for(int i = 0 ; i < ret.size() ; i++){
			int temp = ret[i][0];
			ret[i].clear();
			ret[i].push_back(temp);
	}
	return ret;
}


void printVectorOfVector(vector<vector<int>> arr){
	for(int i = 0 ; i < arr.size() ; i++){
		for(int j = 0 ; j < arr[i].size() ; j++){
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

int main(){
	struct TreeNode *root = newNode(12);
	root->left = newNode(10);
	root->right = newNode(30);
	root->right->left = newNode(25);
	root->right->right = newNode(40);
	vector<vector<int>> result = leftView(root , 0);
	printVectorOfVector(result);
	return 0;
}