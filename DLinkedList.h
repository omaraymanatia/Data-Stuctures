#pragma once
#include <stdexcept>
using namespace std;
template <class T>
class DNode {
	T val;
	DNode<T>* next;
	DNode<T>* prv;
public:
	DNode(T val) {
		this->val = val;
		next = nullptr;
		prv = nullptr;
	}
	void SetNext(DNode<T>* next) {
		this->next = next;
	}
	DNode<T>* GetNext() {
		return next;
	}
	void SetPrv(DNode<T>* prv) {
		this->prv = prv;
	}
	DNode<T>* GetPrv() {
		return prv;
	}
	void SetVal(T val) {
		this->val = val;
	}
	T GetVal() {
		return val;
	}
};
template <class T>
class DLinkedList {
	DNode<T>* head;
	DNode<T>* tail;
	DNode<T>* find(DNode<T>* tmp, T item) {
		while (tmp != nullptr) {
			if (tmp->GetVal() == item)
				return tmp;
			tmp = tmp->GetNext();
		}
		return nullptr;
	}
public:
	DLinkedList() {
		head = nullptr;
		tail = nullptr;
	}
	void AddFront(T item) {
		DNode <T>* node = new DNode<T>(item);
		if (head == nullptr) {
			head = node;
			tail = node;
		}
		else {
			head->SetPrv(node);
			node->SetNext(head);
			head = node;
		}
	}
	void AddBack(T item) {
		DNode <T>* node = new DNode<T>(item);
		if (head == nullptr) {
			head = node;
			tail = node;
		}
		else {
			tail->SetNext(node);
			node->SetPrv(tail);
			tail = node;
		}
	}
	bool find(T item) {
		if (find(head, item) == nullptr)
			return false;
		return true;
	}
	void Insert(int idx, T item) {
		DNode<T>* node = new DNode<T>(item);
		DNode<T>* tmp = head;
		while (tmp != nullptr && idx > 0) {
			tmp = tmp->GetNext();
			idx--;
		}
		if (tmp == nullptr)
			throw std::runtime_error("Runtime error");
		node->SetNext(tmp->GetNext());
		if (tmp->GetNext() != nullptr)
			tmp->GetNext()->SetPrv(node);
		node->SetPrv(tmp);
		tmp->SetNext(node);
	}
	void Delete(T item) {
		DNode<T>* tmp = find(head, item);
		if (tmp == nullptr)
			throw std::runtime_error("Runtime error");
		if (tmp->GetPrv() == nullptr)
			head = tmp->GetNext();
		else
			tmp->GetPrv()->SetNext(tmp->GetNext());

		if (tmp->GetNext() != nullptr)
			tmp->GetNext()->SetPrv(tmp->GetPrv());

		delete tmp;
	}
	void DeleteFront() {
		if (head == nullptr)
			throw std::runtime_error("Runtime error: List is empty");

		DNode<T>* tmp = head->GetNext();
		if (tmp != nullptr) {
			tmp->SetPrv(nullptr);
			delete head;
			head = tmp;
		}
		else {
			delete head;
			head = nullptr;
		}
	}
	void DeleteBack() {
		if (IsEmpty())
			throw std::runtime_error("Runtime error");
		DNode<T>* tmp = tail->GetPrv();
		if (tmp != nullptr) {
			tmp->SetNext(nullptr);
			delete tail;
			tail = tmp;
		}
		else {
			delete tail;
			head = nullptr;
		}
	}
	bool IsEmpty() {
		return head == nullptr;
	}
	T GetBack() {
		return tail->GetVal();
	}
	T GetFront() {
		return head->GetVal();
	}
	void PrintF() {
		DNode<T>* itr = head;
		for (; itr != nullptr; itr = itr->GetNext())
			cout << itr->GetVal() << ' ';
		cout << '\n';
	}
	void PrintB() {
		DNode<T>* itr = tail;
		for (; itr != nullptr; itr = itr->GetPrv())
			cout << itr->GetVal() << ' ';
		cout << '\n';
	}
};