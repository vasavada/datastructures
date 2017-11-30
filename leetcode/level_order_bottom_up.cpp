#include <iostream>
#include <cstdlib>
#include <vector>
#include <cstdlib>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int>> ret;

void buildVector(TreeNode* root , int depth){
	if(root == NULL) return;
	if(ret.size() == depth) ret.push_back(vector<int>());

	ret[depth].push_back(root -> val);
	buildVector(root -> left , depth + 1);
	buildVector(root -> right , depth + 1);
}

vector<vector<int>> levelOrderBottom(TreeNode* root){
	buildVector(root , 0);
	reverse(ret.begin() , ret.end());
	return ret;
}

int main(){
	return 0;
}