#pragma once
#include "DLinkedList.h"
template<class T>
class Stack1 :private DLinkedList<T> {
public:
	void push(T item) {
		this->AddBack(item);
	}
	T pop() {
		T item = this->GetBack();
		this->DeleteBack();
		return item;
	}
	bool IsEmpty() {
		return DLinkedList<T>::IsEmpty();
	}
};