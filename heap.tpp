#ifndef HEAP_TPP
#define HEAP_TPP
#include "heap.h"
#include <utility>

template <class T, class CMP>
Heap<T, CMP>::Heap() : n(0), t(NULL) {}

template <class T, class CMP>
Heap<T, CMP>::Heap(const Heap& h) : n(h.n), t(h.t) {}

template <class T, class CMP>
Heap<T, CMP>::Heap(const std::vector<T>& v) {
	*this = make_heap(v);
}

template <class T, class CMP>
Heap<T, CMP>& Heap<T, CMP>::operator = (const Heap& h) {
	t = h.t;
	n = h.n;
	return *this;
}

template <class T, class CMP>
void Heap<T, CMP>::sift_down(int i) {
	//recreate heap properties by pressing down the element to it's position
	try {
		if (leaf(i)) {
			return;
		}
		std::pair<int, int> ch = children(i);
		
		//find the greatest value out of parent and children provided by the compare function
		int m = i;
		if (ch.first > 0 && ch.first < n && compare(t[ch.first], t[m])) {
			m = ch.first;
		}
		if (ch.second > 0 && ch.second < n && compare(t[ch.second], t[m])) {
			m = ch.second;
		}
		if (i == m) {
			return;
		}

		std::swap(t[i], t[m]);
		sift_down(m);
	}
	catch (...) {
		throw;
	}
}

template <class T, class CMP>
void Heap<T, CMP>::sift_up(int i) {
	//recreate heap properties by lifting the element to it's position
	try {
		if (i == 0) {//it's the root, can't lift any further
			return;
		}
		int p = parent(i);
		//swap and reorder if it should be above it's parent
		if (compare(t[i], t[p])) {
			std::swap(t[i], t[p]);
			sift_up(p);
		}
	}
	catch (...) {
		throw;
	}
}

template <class T, class CMP>
std::pair<int, int> Heap<T, CMP>::children(int i) const {
	//returns indexes of element's children
	if (i < 0 || i >= n) {
		throw OutOfBounds();
	}
	std::pair<int, int> ch;
	ch.first = 2 * i + 1;
	ch.second = 2 * i + 2;
	if (ch.first >= n) {
		ch.first = -1;
	}
	if (ch.second >= n) {
		ch.second = -1;
	}
	return ch;
}

template <class T, class CMP>
int Heap<T, CMP>::parent(int i) const {
	//returns index of element's parent
	if (i < 0 || i >= n) {
		throw OutOfBounds();
	}
	int p = (i - 1) / 2;
	if (p < 0) {
		p = -1;
	}
	return p;
}

template <class T, class CMP>
bool Heap<T, CMP>::leaf(int i) const {
	//returns whether element is a leaf or not
	if (i < 0 || i >= n) {
		throw OutOfBounds();
	}
	return i >= n / 2 ? true : false;
}

template <class T, class CMP>
bool Heap<T, CMP>::empty() const{
	return n == 0;
}

template <class T, class CMP>
int Heap<T, CMP>::size() const{
	return n;
}

template <class T, class CMP>
T Heap<T, CMP>::top() const{
	//peek top element
	if (empty()) {
		throw Empty();
	}
	return t[0];
}

template <class T, class CMP>
void Heap<T, CMP>::push(T element) {
	t.push_back(element);
	++n;	
	if (n == 1) {//one node is always a heap so no work needs to be done
		return;
	}
	try {
		sift_up(n - 1);
	}
	catch (...) {
		throw;
	}
}

template <class T, class CMP>
void Heap<T, CMP>::pop() {
	if (empty()) {
		throw Empty();
	}
	std::swap(t[0], t[n - 1]);//swap root and last leaf elements

	t.pop_back();//delete last element which was the root before
	--n;
	if (!empty()) {
		sift_down(0);//get the element in the root to it's place if there is still something in the heap
	}
	
}

template <class T, class CMP>
void Heap<T, CMP>::change(int i, T value) {
	if (i < 0 || i >= n) {
		throw OutOfBounds();
	}
	t[i] = value;
	//if the value increased it will lift up in the heap if it decreased it will go down
	sift_up(i);
	sift_down(i);
}

template <class T>
bool Greater<T>::operator ()(T a, T b) const {
	return a > b;
}

template <class T>
bool Less<T>::operator ()(T a, T b) const {
	return a < b;
}
#endif