#pragma once
#include <stdlib.h>
#include <iostream>

template<typename T> class TTree {
private:

	//RTTI 
	struct node {
		T data;
		node*   left;
		node*   right;

		node(T _data) {
			data = _data;
			left = NULL;
			right = NULL;
		}


	};

	node* root;
public:

	TTree() {
		root = NULL;
	}

	~TTree() {

	}

	node* getRoot(){
		return root;
	}

	void traverse(void (callback)(T )) {

	}

	void traverse(node* temp, void (callback)(T _data)) {
		if(temp == NULL) return;
		traverse(temp->left, callback);
		callback(temp->data);
		traverse(temp->right, callback);
	}

	void draw1() {
		std::cout << " ***" << std::endl;
		std::cout << "*****" << std::endl;
		std::cout << "*****" << std::endl;
		std::cout << " ***" << std::endl;
		std::cout << "  |" << std::endl;
		std::cout << " ~^~" << std::endl;
	}

	bool  includes(T _data) {

		node *temp = root;

		while (temp != NULL) {
			if (temp->data == _data) {
				return true;
			}
			else if (temp->data > _data) {
				temp = temp->right;
			}
			else if (temp->data < _data) {
				temp = temp->left;
			}
		}

		return false;

	}

	void push(T _data) {
		node *newnode = new node(_data);

		if (root == NULL)  {
			root = newnode;
			return;
		}

		node *temp = root;

		while (temp != NULL) {
			if (temp->data >= newnode->data) {
				if (temp->right == NULL) {
					temp->right = newnode;
					return;
				}
				else {
					temp = temp->right;
				}
			}
			else if (temp->data < newnode->data) {
				if (temp->left == NULL) {
					temp->left = newnode;
					return;
				}
				else {
					temp = temp->left;
				}
			}
		}

	}
};