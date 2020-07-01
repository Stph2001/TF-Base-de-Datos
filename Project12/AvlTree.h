#pragma once
#include <list>
#define max(a,b)(a>b?a:b)
using std::list;

template<typename T>
struct Node {
	T elem;
	Node<T>* Right;
	Node<T>* Left;
	int height;

	Node(T elem) :elem(elem), height(0),Left(nullptr), Right(nullptr) {}
};

template<typename T>
class AvlTree
{
private:
	Node<T>* root;
	int length;

public:
	AvlTree(){
		length = 0;
	}
	~AvlTree(){

	}
	void Clear() { clear(root); }
	int Length() { return length; }
	void Add(T elem) { add(root, elem); }
	T Search(T elem) { return search(root, elem); }
	list<T>* SearchAll(T elem) {
		list<T>* elems = new list<T>();
		searchAll(root, elem, elems);
		return elems;
	}

private:
	void clear(Node<T>* node) {
		if (node != nullptr) {
			clear(node->left);
			clear(node->right);
			delete node;
			node = nullptr;
		}
	}
	int height(Node<T> *node){
		return node == nullptr ? 0 : node->height;
	}
	void add(Node<T> *node, T elem){
		if (node == nullptr){
			node = new Node<T>(elem);
			length++;
		}
		else{
			if (elem < node->elem){
				add(node->Left, elem);
			}
			else{
				add(node->Right, elem);
			}
			balance(node);
		}
	}
	void updateHeight(Node<T> *node){
		if (node != nullptr){
			int hl = height(node->Left);
			int hr = height(node->Right);
			node->height = max(hl, hr) + 1;
		}
	}
	void rotateLeft(Node<T> *node){
		Node<T>* aux = node->Right;
		node->Right = aux->Left;
		updateHeight(node);
		aux->Left = node;
		updateHeight(node);
		node = aux;
	}
	void rotateRight(Node<T> *node) {
		Node<T>* aux = node->Left;
		node->Left = aux->Right;
		updateHeight(node);
		aux->Right = node;
		updateHeight(node);
		node = aux;
	}
	void balance(Node<T> *node){
		int hl = height(node->Left);
		int hr = height(node->Right);
		if (hr - hl < -1){
			hl = height(node->Left->Left);
			hr = height(node->Left->Right);
			if (hr > hl){
				rotateLeft(node->Left);
			}
			rotateRight(node);
		}
		else if (hr - hl > 1) {
			hl = height(node->Right->Left);
			hr = height(node->Right->Right);
			if (hl > hr) {
				rotateRight(node->Right);
			}
			rotateLeft(node);
		}
		else {
			updateHeight(node);
		}
	}
	T search(Node<T> *node, T elem){
		if (node == nullptr) return 0;
		if (elem == node->elem) return elem;
		else{
			if (elem > node->elem){
				search(node->Right, elem);
			}
			else if (elem < node->elem){
				search(node->Left, elem);
			}
		}
	}
	void searchAll(Node<T> *node, T elem, list<T>* elems){
		if (node == null) return nullptr;
		if (elem == node->elem) {
			elems->push_back(elem);
			searchAll(node->Right, elem, elems);
		}
		else{
			if (elem > node->elem){
				searchAll(node->Right, elem, elems);
			}
			else if (elem < node->elem){
				searchAll(node->Left, elem, elems);
			}
		}
	}
};
