#include<iostream>
#include<exception>
#include"ArrayList.h"
#include"DLinkedList.h"
#include"Queue1.h"
#include"Stack1.h"
#include"BST.h"
using namespace std;
int main() {
	BST<int>tree;
	tree.Insert(20);
	tree.Insert(40);
	tree.Insert(10);
	tree.Insert(41);
	tree.Insert(30);
	tree.Insert(15);
	tree.Insert(9);
	tree.Remove(9);
	tree.PostOrderTraversal();
}