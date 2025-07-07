#ifndef TREE_HPP
#define TREE_HPP

template <typename T>
class TreeNode {
public:
	T value;
	TreeNode(T val) : value(val) {}
};

template <typename T>
class BinaryTree {
public:
	TreeNode<T>* root;
	BinaryTree<T>* left;
	BinaryTree<T>* right;
	
	BinaryTree() : root(nullptr), left(nullptr), right(nullptr) {}
	~BinaryTree() {
		delete this->root;
		delete this->left;
		delete this->right;
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
            if(left == nullptr) {
	            left = new BinaryTree<T>();
            	left->root = new TreeNode<T>(value);
            } else {
	            left->insert(value);
            }
        } else {
            if(right == nullptr) {
	            right = new BinaryTree<T>();
            	right->root = new TreeNode<T>(value);
            } else {
	            right->insert(value);
            }
        }
	}
};

#endif // TREE_HPP