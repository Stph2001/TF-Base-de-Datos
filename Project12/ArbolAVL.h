#pragma once
template<typename T>
struct Node {
	T elem;
	Node* Right;
	Node* Left;
	int height;

	Node(T elem) :elem(elem), height(0),Left(nullptr), Right(nullptr) {}
};

template<typename T>
class ArbolAVL
{
private:
	Node<T>* root;
	int length;

public:
	ArbolAVL(){
		length = 0;
	}
	~ArbolAVL(){

	}
	void Clear() { clear(root); }
	int Lenght() { return length; }

private:
	void clear(Node* node) {
		if (node != nullptr) {
			clear(node->left);
			clear(node->right);
			delete node;
			node = nullptr;
		}
	}
	int height(Node *node){
		return node == nullptr ? 0 : node->height;
	}
	void Add(Node *node, T elem){
		if (node == nullptr){
			node = new Node<T>(elem);
			length++;
		}
		else{
			
		}
	}

	void AVLBST<T, R, NONE>::add(Node*& node, T elem) {
	if (node == nullptr) {
		node = new Node(elem);
		++len;
	}
	else {
		if (key(elem) < key(node->element)) {
			add(node->left, elem);
		}
		else {
			add(node->right, elem);
		}
		balance(node);
	}
}
};









template<typename T, typename R = T, T NONE = 0>
class AVLBST
{
	struct Node;

	Node* root;
	function<R(T)>key;
	int len;

public:
	AVLBST(function<R(T)>key = [](T a) {return a; })
		:key(key), root(nullptr), len(0) {}
	~AVLBST() {
		clear(root);
	}

	int height() {
		return height(root);
	}
	int size() {
		return len;
	}
	void clear() {
		clear(root);
	}

	void add(T elem) {
		add(root, elem);
	}
	void inOrder(function<void(T)>proc) {
		inOrder(root, proc);
	}

private:
	void clear(Node*& node);
	int height(Node* node);
	void add(Node*& node, T elem);
	void inOrder(Node* node, function<void(T)>proc);

	void updateHeight(Node* node);
	void rotateLeft(Node*& node);
	void rotateRight(Node*& node);
	void balance(Node*& node);
};

template<typename T, typename R, T NONE>
void AVLBST<T, R, NONE>::clear(Node*& node) {
	if (node != nullptr) {
		clear(node->left);
		clear(node->right);
		delete node;
		node = nullptr;
	}
}

template<typename T, typename R, T NONE>
int AVLBST<T, R, NONE>::height(Node* node) {
	return node == nullptr ? -1 : node->height;
}

template<typename T, typename R, T NONE>
void AVLBST<T, R, NONE>::add(Node*& node, T elem) {
	if (node == nullptr) {
		node = new Node(elem);
		++len;
	}
	else {
		if (key(elem) < key(node->element)) {
			add(node->left, elem);
		}
		else {
			add(node->right, elem);
		}
		balance(node);
	}
}

template<typename T, typename R, T NONE>
void AVLBST<T, R, NONE>::inOrder(Node* node, function<void(T)>proc) {
	if (node != nullptr) {
		inOrder(node->left, proc);
		proc(node->element);
		inOrder(node->right, proc);
	}
}

#define max(a,b)(a>b?a:b)

template<typename T, typename R, T NONE>
void AVLBST<T, R, NONE>::updateHeight(Node* node) {
	if (node != nullptr) {
		int hl = height(node->left);
		int hr = height(node->right);

		node->height = max(hl, hr) + 1;
	}
}

template<typename T, typename R, T NONE>
void AVLBST<T, R, NONE>::rotateLeft(Node*& node) {
	Node* aux = node->right;
	node->right = aux->left;
	updateHeight(node);
	aux->left = node;
	updateHeight(node);
	node = aux;
}

template<typename T, typename R, T NONE>
void AVLBST<T, R, NONE>::rotateRight(Node*& node) {
	Node* aux = node->left;
	node->left = aux->right;
	updateHeight(node);
	aux->right = node;
	updateHeight(node);
	node = aux;
}

template<typename T, typename R, T NONE>
void AVLBST<T, R, NONE>::balance(Node*& node) {
	int hl = height(node->left);
	int hr = height(node->right);

	if (hr - hl < -1) {
		hl = height(node->left->left);
		hr = height(node->left->right);
		if (hr > hl) {
			rotateLeft(node->left);
		}
		rotateRight(node);
	}
	else if (hr - hl > 1) {
		hl = height(node->right->left);
		hr = height(node->right->right);
		if (hl > hr) {
			rotateRight(node->right);
		}
		rotateLeft(node);
	}
	else {
		updateHeight(node);
	}
}