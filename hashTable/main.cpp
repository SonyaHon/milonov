#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include "../String/mystring.h"
#include "../TiedList/list.h"
#include <vector>

typedef mystring Str;

class HashTable {

private:

	struct pair {
		Str key;
		Str data;
	};

	TList<pair> *table;

	int hashFunc(Str);
	int m_size;
	int elemAmount;

public:
	HashTable(int size);
	void push(Str, Str);
	Str find(Str);
	void erase(Str);
	int size();

	Str operator[](const Str &str);
	Str operator[](int idx);
};

Str HashTable::operator[](int idx) {
	static int savedIdx = 0;
	static int itL = 0;
	static int itH = -1;

	if(savedIdx != idx - 1) {
		itL = 0;
		itH = -1;
		savedIdx = 0;
	}

	savedIdx = idx;

	if (itH == -1) {
		for (int i = 0; i < m_size; ++i) {
			if (!table[i].isEmpty()) {
				itH = i;
				break;
			}
		}
	}

	if(itL >= table[itH].s()) {
		itL = 0;
		for(int i = itH + 1; i < m_size; ++i) {
			if(!table[i].isEmpty()) {
				itH = i;
				break;
			}
		}
	}

	if(itH >= m_size) {
		itH = -1;
		itL = 0;
	}

	return table[itH][itL++].data;
}

Str HashTable::operator[](const Str &str) {
	int num = hashFunc(str);
	for (int i = 0; i < table[num].s(); ++i) {
		if (str == table[num][i].key) return table[num][i].data;
	}
}

int HashTable::size() {
	return elemAmount;
}

void HashTable::erase(Str key) {
	int num = hashFunc(key);
	elemAmount -= 1;
	for (int i = 0; i < table[num].s(); ++i) {
		if (key == table[num][i].key) {
			table[num].erase(i);
			return;
		}

	}
}

Str HashTable::find(Str key) {
	int num = hashFunc(key);

	for (int i = 0; i < table[num].s(); ++i) {
		if (key == table[num][i].key) return table[num][i].data;
	}
}

void HashTable::push(Str key, Str data) {
	int num = hashFunc(key);

	pair p;
	p.key = key;
	p.data = data;

	table[num].push(p);

	elemAmount += 1;
}

int HashTable::hashFunc(Str str) {
	return str.size() % m_size;
}

HashTable::HashTable(int size) {
	m_size = size;
	table = new TList<pair>[size];
	elemAmount = 0;
}

int main(int argc, char ** argv) {

	HashTable table(10);

	table.push("1", "1");
	table.push("2", "2");
	table.push("3", "3");
	table.push("4", "4");

	std::cout << table.size() << std::endl << std::endl;

	for(int i = 0; i < table.size(); ++i) {
		std::cout << table[i] << std::endl;
	}

	table.erase("1");
	table.push("1", "1");

	std::cout << std::endl << table.size() << std::endl << std::endl;

	for(int i = 0; i < table.size(); ++i) {
		std::cout << table[i] << std::endl;
	}


	return 0;
}