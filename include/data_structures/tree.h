#ifndef TREE_H
#define TREE_H

template <typename T>
class TreeNode {
public:
	T value;
	TreeNode* left;
	TreeNode* right;

	TreeNode(T val) : value(val), left(nullptr), right(nullptr) {}
	~TreeNode() {
		delete this->left;
		delete this->right;
	}
};

template <typename T>
class BinaryTree {
public:
	TreeNode<T>* root;

	BinaryTree() : root(nullptr) {}
	~BinaryTree() {
		delete this->root;
	}

	void insert(const T& value) {
		if(root == nullptr) {
			root = new TreeNode<T>(value);	
		} else {
			insertHelper(root, value);
		}
	}
private:
	void insertHelper(TreeNode<T>* node, const T& value) {
		if(value < node->value) {
            if(node->left == nullptr) { node->left = new TreeNode<T>(value); }
			else { insertHelper(node->left, value); }
        } else {
            if(node->right == nullptr) { node->right = new TreeNode<T>(value); }
        	else { insertHelper(node->right, value); }
        }
	}
};

#endif //TREE_H