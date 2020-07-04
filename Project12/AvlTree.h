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
	void Add(T elem) { add(root, elem); }
	void Remove(T elem) { remove(root, elem); }
	int Search(T elem) { return search(root, elem); }

	list<int>* Equals(T elem) {
		list<int>* rows = new list<int>();
		equals(root, elem, rows);
		return rows;
	}
	list<int>* GreaterThan(T elem){
		list<int>* rows = new list<int>();
		greaterThan(root, elem, rows);
		return rows;
	}
	list<int>* LessThan(T elem){
		list<int>* rows = new list<int>();
		lessThan(root, elem, rows);
		return rows;
	}
	list<int>* Contains(string searcher) {
		list<int>* rows = new list<int>();
		contains(root, searcher, rows);
		return rows;
	}
	list<int>* NotContains(string searcher) {
		list<int>* rows = new list<int>();
		notContains(root, searcher, rows);
		return rows;
	}
	list<int>* StartWith(string searcher) {
		list<int>* rows = new list<int>();
		startWith(root, searcher, rows);
		return rows;
	}
	list<int>* EndWith(string searcher) {
		list<int>* rows = new list<int>();
		endWith(root, searcher, rows);
		return rows;
	}
	list<int>* InOrder() {
		list<int>* rows = new list<int>();
		inOrder(root, rows);
		return rows;
	}
	list<int>* InReverse() {
		list<int>* rows = new list<int>();
		inReverse(root, rows);
		return rows;
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
			node = new Node<T>(elem, length);
			length++;
		}
		else{
			add(compare(elem, node->elem) == -1 ? node->Left : node->Right, elem);
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
	int search(Node<T> *&node, T elem){
		if (node == nullptr) { return -1; }
		if (compare(elem, node->elem) == 0) return node->Row;
		else{
			if (compare(elem, node->elem) == 1){
				return search(node->Right, elem);
			}
			else if (compare(elem, node->elem) == -1){
				return search(node->Left, elem);
			}
		}
	}
	void equals(Node<T> *&node, T elem, list<int>* rows){
		if (node == nullptr) return;
		if (compare(elem, node->elem) == 0) {
			rows->push_back(node->Row);
			equals(node->Right, elem, rows);
			equals(node->Left, elem, rows);
		}
		else{
			if (compare(elem, node->elem) == 1){
				equals(node->Right, elem, rows);
			}
			else if (compare(elem, node->elem) == -1){
				equals(node->Left, elem, rows);
			}
		}
	}
	void greaterThan(Node<T> *&node, T elem, list<int>* rows){
		if (node == nullptr) return;
		if (compare(elem, node->elem) == -1){
			rows->push_back(node->Row);
			greaterThan(node->Right, elem, rows);
			greaterThan(node->Left, elem, rows);
		}
		else {
			greaterThan(node->Right, elem, rows);
		}
	}
	void lessThan(Node<T>*& node, T elem, list<int>* rows) {
		if (node == nullptr) return;
		if (compare(elem, node->elem) == 1){
			rows->push_back(node->Row);
			lessThan(node->Right, elem, rows);
			lessThan(node->Left, elem, rows);
		}
		else {
			lessThan(node->Left, elem, rows);
		}
	}
	void contains(Node<T>*& node, string searcher, list<int>* rows) {
		if (node == nullptr) return;
		if (checkContains(searcher, node->elem)) rows->push_back(node->Row);
		contains(node->Right, searcher, rows);
		contains(node->Left, searcher, rows);
	}
	void notContains(Node<T>*& node, string searcher, list<int>* rows) {
		if (node == nullptr) return;
		if (!checkContains(searcher, node->elem)) rows->push_back(node->Row);
		notContains(node->Right, searcher, rows);
		notContains(node->Left, searcher, rows);
	}
	void startWith (Node<T>*& node, string searcher, list<int>* rows) {
		if (node == nullptr) return;
		if (checkStart(searcher, node->elem)) rows->push_back(node->Row);
		startWith(node->Right, searcher, rows);
		startWith(node->Left, searcher, rows);
	}
	void endWith(Node<T>*& node, string searcher, list<int>* rows){
		if (node == nullptr) return;
		if (checkEnd(searcher, node->elem)) rows->push_back(node->Row);
		endWith(node->Right, searcher, rows);
		endWith(node->Left, searcher,rows);
	}
	void inOrder(Node<T> *&node, list<int>* rows) {
		if (node == nullptr) return;
		inOrder(node->Left, rows);
		rows->push_back(node->Row);
		inOrder(node->Right, rows);
	}
	void inReverse(Node<T>*& node, list<int>* rows) {
		if (node == nullptr) return;
		inReverse(node->Left, rows);
		rows->push_front(node->Row);
		inReverse(node->Right, rows);
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


