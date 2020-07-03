#pragma once
#include <list>
#include <functional>
#include <string>
#include <string.h>
#define max(a,b)(a>b?a:b)
using namespace std;

template<typename T>
struct Node {
	T elem;
	Node<T>* Right;
	Node<T>* Left;
	int height;
	int Row;
	Node(T elem, int row) : elem(elem), height(0), Left(nullptr), Right(nullptr), Row(row) {}
};

template<typename T>
class AvlTree
{
private:
	Node<T>* root;
	function<int(T elem1, T elem2)> compare;
	function<bool(string search, T elem1)> checkContains;
	function<bool(string search, T elem1)> checkStart;
	function<bool(string search, T elem1)> checkEnd;
	int length;

public:
	AvlTree(function<int(T, T)> c, function<bool(string, T)> h, function<bool(string, T)> s, function<bool(string, T)> e){
		length = 0;
		root = nullptr;
		compare = c;
		checkContains = h;
		checkStart = s;
		checkEnd = e;
	}
	~AvlTree(){

	}
	void Clear() { clear(root); }
	int Length() { return length; }
	void Add(T elem, int row) { add(root, elem, row); }
	void Remove(T elem) { remove(root, elem); }
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
	list<T>* Contains(string searcher) {
		list<T>* elems = new list<T>();
		contains(root, searcher, elems);
		return elems;
	}
	list<T>* NotContains(string searcher) {
		list<T>* elems = new list<T>();
		notContains(root, searcher, elems);
		return elems;
	}
	list<T>* StartWith(string searcher) {
		list<T>* elems = new list<T>();
		startWith(root, searcher, elems);
		return elems;
	}
	list<T>* EndWith(string searcher) {
		list<T>* elems = new list<T>();
		endWith(root, searcher, elems);
		return elems;
	}
	list<T>* InOrder() {
		list<T>* elems = new list<T>();
		inOrder(root, elems);
		return elems;
	}
	list<T>* InReverse() {
		list<T>* elems = new list<T>();
		inReverse(root, elems);
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
	void add(Node<T> *&node, T elem, int row){
		if (node == nullptr){
			node = new Node<T>(elem, row);
			length++;
		}
		else{
			add(compare(elem, node->elem) == -1 ? node->Left : node->Right, elem, row);
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
		if (node == nullptr) { return 0; }
		if (compare(elem, node->elem) == 0) return elem;
		else{
			if (compare(elem, node->elem) == 1){
				return search(node->Right, elem);
			}
			else if (compare(elem, node->elem) == -1){
				return search(node->Left, elem);
			}
		}
	}
	void equals(Node<T> *&node, T elem, list<T>* elems){
		if (node == nullptr) return;
		if (compare(elem, node->elem) == 0) {
			elems->push_back(elem);
			equals(node->Right, elem, elems);
			equals(node->Left, elem, elems);
		}
		else{
			if (compare(elem, node->elem) == 1){
				equals(node->Right, elem, elems);
			}
			else if (compare(elem, node->elem) == -1){
				equals(node->Left, elem, elems);
			}
		}
	}
	void greaterThan(Node<T> *&node, T elem, list<T>* elems){
		if (node == nullptr) return;
		if (compare(elem, node->elem) == -1){
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
		if (compare(elem, node->elem) == 1){
			elems->push_back(node->elem);
			lessThan(node->Right, elem, elems);
			lessThan(node->Left, elem, elems);
		}
		else {
			lessThan(node->Left, elem, elems);
		}
	}
	void contains(Node<T>*& node, string searcher, list<T>* elems) {
		if (node == nullptr) return;
		if (checkContains(searcher, node->elem)) elems->push_back(node->elem);
		contains(node->Right, searcher, elems);
		contains(node->Left, searcher, elems);
	}
	void notContains(Node<T>*& node, string searcher, list<T>* elems) {
		if (node == nullptr) return;
		if (!checkContains(searcher, node->elem)) elems->push_back(node->elem);
		notContains(node->Right, searcher, elems);
		notContains(node->Left, searcher, elems);
	}
	void startWith (Node<T>*& node, string searcher, list<T>* elems) {
		if (node == nullptr) return;
		if (checkStart(searcher, node->elem)) elems->push_back(node->elem);
		startWith(node->Right, searcher, elems);
		startWith(node->Left, searcher, elems);
	}
	void endWith(Node<T>*& node, string searcher, list<T>* elems){
		if (node == nullptr) return;
		if (checkEnd(searcher, node->elem)) elems->push_back(node->elem);
		endWith(node->Right, searcher, elems);
		endWith(node->Left, searcher,elems);
	}
	void inOrder(Node<T> *&node, list<T>* elems) {
		if (node == nullptr) return;
		inOrder(node->Left, elems);
		elems->push_back(node->elem);
		inOrder(node->Right, elems);
	}
	void inReverse(Node<T>*& node, list<T>* elems) {
		if (node == nullptr) return;
		inReverse(node->Left, elems);
		elems->push_front(node->elem);
		inReverse(node->Right, elems);
	}
	void remove(Node<T>*& node, T elem) {
		if (node == nullptr) return;
		if (compare(elem, node->elem) == 0) removeAux(node);
		else {
			if (compare(elem, node->elem) == -1) remove(node->Left, elem);
			else remove(node->Right, elem);
			balance(node);
		}
	}
	void removeAux(Node<T>*& node) {
		if (node->Left != nullptr) node->elem = maxim(node->Left);
		else {
			Node<T>* aux = node;
			node = node->Right;
			delete aux;
		}
	}
	T maxim(Node<T>*& node) {
		if (node->Right == nullptr) {
			Node<T>* aux = node;
			node = node->Left;
			T auxElem = aux->elem;
			delete aux;
			return auxElem;
		}
		else {
			T auxElem = maxim(node->Right);
			balance(node);
			return auxElem;
		}
	}
};


