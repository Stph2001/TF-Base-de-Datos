#pragma once
#include <list>
#include <functional>
#define max(a,b)(a>b?a:b)
using namespace std;

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
	function<double(T elem)> compare;
	int length;

public:
	AvlTree(function<double(T)> c){
		length = 0;
		root = nullptr;
		compare = c;
	}
	~AvlTree(){

	}
	void Clear() { clear(root); }
	int Length() { return length; }
	void Add(T elem) { add(root, elem); }
	T Search(T elem) { return search(root, elem); }
	list<T>* Equals(T elem) {
		list<T>* elems = new list<T>();
		equals(root, elem, elems);
		return elems;
	}
	list<T>* GreaterThan(T elem){
		list<T>* elems = new list<T>();
		greaterThan(root, elem, elems);
		return elems;
	}
	list<T>* LessThan(T elem){
		list<T>* elems = new list<T>();
		lessThan(root, elem, elems);
		return elems;
	}

private:
	void clear(Node<T> *&node) {
		if (node != nullptr) {
			clear(node->Left);
			clear(node->Right);
			delete node;
			node = nullptr;
		}
	}
	int height(Node<T> *&node){
		return node == nullptr ? 0 : node->height;
	}
	void add(Node<T> *&node, T elem){
		if (node == nullptr){
			node = new Node<T>(elem);
			length++;
		}
		else{
			if (compare(elem) < compare(node->elem)){
				add(node->Left, elem);
			}
			else{
				add(node->Right, elem);
			}
			balance(node);
		}
	}
	void updateHeight(Node<T> *&node){
		if (node != nullptr){
			int hl = height(node->Left);
			int hr = height(node->Right);
			node->height = max(hl, hr) + 1;
		}
	}
	void rotateLeft(Node<T> *&node){
		Node<T>* aux = node->Right;
		node->Right = aux->Left;
		updateHeight(node);
		aux->Left = node;
		updateHeight(node);
		node = aux;
	}
	void rotateRight(Node<T> *&node) {
		Node<T>* aux = node->Left;
		node->Left = aux->Right;
		updateHeight(node);
		aux->Right = node;
		updateHeight(node);
		node = aux;
	}
	void balance(Node<T> *&node){
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
	T search(Node<T> *&node, T elem){
		if (node == nullptr) { cout << "Nada :c";  return 0; }
		if (compare(elem) == compare(node->elem)) return elem;
		else{
			if (compare(elem) > compare(node->elem)){
				return search(node->Right, elem);
			}
			else if (compare(elem) < compare(node->elem)){
				return search(node->Left, elem);
			}
		}
	}
	void equals(Node<T> *&node, T elem, list<T>* elems){
		if (node == nullptr) return;
		if (compare(elem) == compare(node->elem)) {
			elems->push_back(elem);
			equals(node->Right, elem, elems);
			equals(node->Left, elem, elems);
		}
		else{
			if (compare(elem) > compare(node->elem)){
				equals(node->Right, elem, elems);
			}
			else if (compare(elem) < compare(node->elem)){
				equals(node->Left, elem, elems);
			}
		}
	}
	void greaterThan(Node<T> *&node, T elem, list<T>* elems){
		if (node == nullptr) return;
		if (compare(elem) < compare(node->elem)){
			elems->push_back(node->elem);
			greaterThan(node->Right, elem, elems);
			greaterThan(node->Left, elem, elems);
		}
		else {
			greaterThan(node->Right, elem, elems);
		}
	}
	void lessThan(Node<T>*& node, T elem, list<T>* elems) {
		if (node == nullptr) return;
		if (compare(elem) > compare(node->elem)){
			elems->push_back(node->elem);
			lessThan(node->Right, elem, elems);
			lessThan(node->Left, elem, elems);
		}
		else {
			lessThan(node->Left, elem, elems);
		}
	}
};
