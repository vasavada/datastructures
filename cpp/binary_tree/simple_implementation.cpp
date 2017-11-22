#include <iostream>
#include <cstdlib>

using namespace std;

struct Node{
	int data;
	struct Node* left;
	struct Node* right;
};

struct Node* createNode(int data){
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
	new_node -> data  = data;
	new_node -> right = NULL;
	new_node -> left  = NULL;
	return new_node;
}


int main(){
	struct Node* root = createNode(1);
	root -> left = createNode(2);
	root -> right = createNode(3);
	return 0;
}



/*************************************************
					 ____1____
					/		  \
				___2___	   ___3___
			   /	   \  /		  \
			  4		   5 6		  7

Properties of a Binary tree:
1. Maximum number of nodes at level l of a binary tree is 2^(l - 1)
2. Maximum number of nodes in a binary tree of height h is 2^(h) - 1
3. On a Binary Tree with N nodes, minimum possible height is is ceil(Log2(N + 1))
4. A binary tree with L leaves has at last ceil(Log2L) + 1 levels
5. In Binary tree, number of leaf nodes is always one more than nodes with two children.
*************************************************/


/*************************************************
Types of Binary Tree:
1. Full Binary Tree: A binary tree where each node has 0 or 2 children

2. Complete Binary Tree: A binary tree where all levels are completely filled
except possibly the last level and the last level has all the keys
as left as possible

3. Perfect Binary Tree: A binary tree where all internal nodes have
two children and all leaves are at the same level.

4. Balanced Binary Tree: A binary tree is balanced if height of the tree is
O(Log n) where n is number of nodes.
For Example, AVL tree maintains O(Log n) height by
making sure that the difference between heights of
left and right subtrees is 1.
Red-Black trees maintain O(Log n) height
by making sure that the number of Black nodes
on every root to leaf paths are same and there
are no adjacent red nodes.
Balanced Binary Search trees are performance wise good
as they provide O(log n) time for search, insert and delete.

5. A Degenerate Tree: A Tree where every internal node has one child.
Such trees are performance-wise same as linked list.
*************************************************/