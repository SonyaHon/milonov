#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

void print(void *value) {
	std::cout << (*int)value << std::endl;
}

int main(int argc, char **argv) {

	TTree<int> tree;
	std::string str

	while(1) {
		std::cin >> str;
		if(str == "exit") {
			exit(0);
		}
		else if(str == "push") {
			std::cin >> str;
			int arg = atoi(str.c_str());
			tree.push(arg);
		} 
		else if(str == "draw") {
			tree.draw1();
		}
		else if(str == "print") {
			tree.traverse(tree.getRoot(), &print);
		}
		else if(str == "includes") {
			std::cin >> str;
			int arg = atoi(str.c_str());
			if(tree.includes(arg)) {
				puts("YES");
			}
			else {
				puts("NO");
			}
		}	
	}
	return 0;
}
