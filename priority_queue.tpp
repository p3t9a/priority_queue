#ifndef PRIORITY_QUEUE_TPP
#define PRIORITY_QUEUE_TPP
#include "priority_queue.h"

template <class T, class CMP>
PriorityQueue<T, CMP>::PriorityQueue() :  h(){}

template <class T, class CMP>
PriorityQueue<T, CMP>::PriorityQueue(const PriorityQueue& pq) : h(pq.h) {}

template <class T, class CMP>
PriorityQueue<T, CMP>& PriorityQueue<T, CMP>::operator=(const PriorityQueue& pq) {
	h = pq.h;
	return *this;
}

template <class T, class CMP>
bool PriorityQueue<T, CMP>::empty() const {
	try {
		return h.empty();
	}
	catch (...) {
		throw;
	}
}

template <class T, class CMP>
int PriorityQueue<T, CMP>::size() const {
	try {
		return h.size();
	}
	catch (...) {
		throw;
	}
}

template <class T, class CMP>
T PriorityQueue<T, CMP>::top() const {
	//peek top element
	try {
		return h.top();
	}
	catch (...) {
		throw;
	}
}

template <class T, class CMP>
void PriorityQueue<T, CMP>::push(T element) {
	//insert a new element
	try {
		h.push(element);
	}
	catch (...) {
		throw;
	}
}

template <class T, class CMP>
void PriorityQueue<T, CMP>::pop() {
	//delete top element
	try {
		h.pop();
	}
	catch (...) {
		throw;
	}

}

template <class T, class CMP>
void PriorityQueue<T, CMP>::change(int i, T value) {
	//change the value of an element
	try {
		h.change(i, value);
	}
	catch (...) {
		throw;
	}
}
#endif