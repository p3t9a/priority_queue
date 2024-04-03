#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H
#include "heap.h"

template <class T, class CMP = Greater<T>>
class PriorityQueue {
	Heap<T, CMP> h;
public:
	PriorityQueue();
	PriorityQueue(const PriorityQueue&);
	PriorityQueue& operator = (const PriorityQueue&);
	void push(T);//insert a new element
	void pop();//delete top element
	void change(int, T);//change the value of an element
	T top() const;//peek top element
	bool empty() const;
	int size() const;
};

template <class T>
class MinPriorityQueue : public PriorityQueue<T, Less<T>> {};

template <class T>
class MaxPriorityQueue : public PriorityQueue<T, Greater<T>> {};
#include "priority_queue.tpp"
#endif // !PRIORITY_QUEUE_H
