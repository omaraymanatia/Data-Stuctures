#pragma once
template<class T>
class Node {
	T val;
	Node* left;
	Node* right;
public:
	Node(T val) {
		this->val = val;
		left = right = nullptr;
	}
	void SetVal(T val) {
		this->val = val;
	}
	void SetLeft(Node* left) {
		this->left = left;
	}
	void SetRight(Node* right) {
		this->right = right;
	}
	T GetVal() {
		return val;
	}
	Node* GetLeft() {
		return left;
	}
	Node* GetRight() {
		return right;
	}
};
template<class T>
class BST {
	Node<T>* insert(Node<T>* root, T item) {
		if (root == nullptr)
			return new Node<T>(item);
		if (item < root->GetVal())
			root->SetLeft(insert(root->GetLeft(), item));
		else if (item > root->GetVal())
			root->SetRight(insert(root->GetRight(), item));
		else
			throw exception("Runtime error");
		return root;
	}
	Node<T>* remove(Node<T>* root, int item) {
		if (root == nullptr) 
			return nullptr;
		if (item > root->GetVal())
			root->SetRight(remove(root->GetRight(), item));
		else if (item < root->GetVal())
			root->SetLeft(remove(root->GetLeft(), item));
		else {
			if (root->GetLeft() == nullptr) {
				Node<T>* tmp = root->GetRight();
				delete root;
				return tmp;
			}
			else if (root->GetRight() == nullptr) {
				Node<T>* tmp = root->GetLeft();
				delete root;
				return tmp;
			}
			else {
				Node<T>* tmp = getmin(root->GetRight());
				root->SetVal(tmp->GetVal());
				root->SetRight(remove(root->GetRight(), tmp->GetVal()));
			}
		}
		return root;
	}
	Node<T>* search(Node<T>* root, T item) {
		if (root == nullptr || root->GetVal() == item)
			return root;
		if (item < root->GetVal())
			return search(root->GetLeft(), item);
		else
			return search(root->GetRight(), item);
	}
	Node<T>* getmax(Node<T>* root) {
		while (root->GetRight() != nullptr)
			root = root->GetRight();
		return root;
	}
	Node<T>* getmin(Node<T>* root) {
		while (root->GetLeft() != nullptr)
			root = root->GetLeft();
		return root;
	}
	void preordertraversal(Node<T>* root) {
		if (root == nullptr)
			return;
		cout << root->GetVal() << ' ';
		preordertraversal(root->GetLeft());
		preordertraversal(root->GetRight());
	}
	void inordertraversal(Node<T>* root) {
		if (root == nullptr)
			return;
		inordertraversal(root->GetLeft());
		cout << root->GetVal() << ' ';
		inordertraversal(root->GetRight());
	}
	void postordertraversal(Node<T>* root) {
		if (root == nullptr)
			return;
		postordertraversal(root->GetLeft());
		postordertraversal(root->GetRight());
		cout << root->GetVal() << ' ';
	}
	Node<T>* root;
public:
	BST() {
		root = nullptr;
	}
	void Insert(T item) {
		root = insert(root, item);
	}
	void Remove(T item) {
		root = remove(root, item);
		cout << root->GetVal() << '\n';
	}
	bool Search(T item) {
		Node<T>* ret = search(root, item);
		return ret != nullptr;
	}
	T GetMax() {
		Node<T>* ret = getmax(root);
		if (ret == nullptr)
			throw exception("Runtime error");
		return ret->GetVal();
	}
	T GetMin() {
		Node<T>* ret = getmin(root);
		if (ret == nullptr)
			throw exception("Runtime error");
		return ret->GetVal();
	}
	void PreOrderTraversal() {
		preordertraversal(root);
	}
	void InOrderTraversal() {
		inordertraversal(root);
	}
	void PostOrderTraversal() {
		postordertraversal(root);
	}
};