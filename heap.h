#ifndef HEAP_H
#define HEAP_H
#include <utility>
#include <iostream>
#include <vector>
template <class T>
class Greater {
public:
	bool operator ()(T, T) const;
};

template <class T>
class Less {
public:
	bool operator ()(T, T) const;
};

template <class T, class CMP = Greater<T>>
class Heap {
	int n;//size of heap
	std::vector <T> t;//container
	CMP compare;//custom comparator
	
	void sift_down(int);//recreate heap properties by pressing down the element to it's position
	void sift_up(int);//recreate heap properties by lifting the element to it's position
	std::pair<int, int> children(int) const;//returns indexes of element's children
	int parent(int) const;//returns index of element's parent
	bool leaf(int) const;//returns whether the element is a leaf or not
public:
	Heap();
	Heap(const Heap&);
	Heap(const std::vector <T>&);
	Heap& operator = (const Heap&);

	void push(T);//insert a new element
	void pop();//delete top element
	void change(int, T);//change the value of an element
	T top() const;//peek top element
	bool empty() const;
	int size() const;

	class OutOfBounds {};
	class Empty {};
};
#include "heap.tpp"
#endif // !HEAP_H

