#pragma once
#include "DLinkedList.h"
template<class T>
class Queue1 :private DLinkedList<T> {
public:
	void push(T item) {
		this->AddBack(item);
	}
	T pop() {
		T item = this->GetFront();
		this->DeleteFront();
		return item;
	}
	bool IsEmpty() {
		return DLinkedList<T>::IsEmpty();
	}
};