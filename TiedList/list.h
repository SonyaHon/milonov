#include <stdlib.h>
#include <iostream>

#ifndef LIST_H_
#define LIST_H_

template<typename typeName> class TList {
private:
	struct node {

		typeName data;
		node *next;
		node *prev;
		int numm;

		node(typeName _data) {
			next = NULL;
			prev = NULL;
			data = _data;
		}

	};

	node *first;
	node *last;
	int size;

public:
	TList() {
		first = NULL;
		last = NULL;
		size = 0;
	}

	~TList() {
		this->clean();
		delete first;
	}

	void push(typeName _data) {

		node * newnode = new node(_data);

		if (first == NULL) {
			newnode->next = NULL;
			newnode->prev = NULL;
			first = newnode;
			last = newnode;
		}
		else if (first->next == NULL) {
			first->next = newnode;
			first->next->prev = last;
			last = newnode;
		}
		else {
			last->next = newnode;
			last->next->prev = last;
			last = newnode;
		}

		size += 1;
	}

	void erase(int pos) {

		if (first == NULL) {
			return;
		}

		node *temp = first;

		for (int i = 0; i < pos; ++i) {
			temp = temp->next;
		}

		if(first->next == NULL && temp == first) {
			first = NULL;
			return;
		}

		if (temp == first) {
			first = first->next;
			first->prev = NULL;
			delete temp;
		}
		else if (temp == last) {
			last = last->prev;
			last->next = NULL;
			delete temp;
		}
		else {
			temp->prev->next = temp->next;
			temp->next->prev = temp->prev;
			delete temp;
		}
		size -= 1;
	}

	typeName operator[] (int idx) const {
		node *temp = first;
		typeName _data;
		for (int i = 0; i < idx; ++i) {
			temp = temp->next;
		}
		_data = temp->data;
		return _data;
	}

	void reverse() {

		if (first == NULL) {
			return;
		}

		node *temp1 = first->next;

		last->next = last->prev;
		last->prev = NULL;

		first->prev = first->next;
		first->next = NULL;

		node *temp = first;
		first = last;
		last = temp;


		for (int i = 1; i < size - 1; ++i) {
			node* temp2 = temp1->next;
			temp1->next = temp1->prev;
			temp1->prev = temp2;
			temp1 = temp1->prev;
		}

	}

	void insert(typeName _data, int pos) {
		
		node *newnode = new node(_data);

		node *temp = first;
		for (int i = 0; i < pos; ++i) {
			temp = temp->next;
		}

		if (temp == first) {
			newnode->next = first;
			first->prev = newnode;
			first = newnode;
		}
		else if (temp == last) {
			newnode->prev = last;
			last->next = newnode;
			last = newnode;
		}
		else {
			temp->prev->next = newnode;
			newnode->next = temp;
			newnode->prev = temp->prev;
		}

		size += 1;

	}

	void clean() {
		if (first == NULL) return;

		for (node *newnode = first->next; newnode != last; newnode = newnode->next) delete newnode;
		delete first;
		first = NULL;
		size = 0;
	}

	bool isEmpty() {
		if (first == NULL) return true;
		else return false;
	}

	int s() {
		return size;
	}

};

#endif