#include "BinaryMinHeap.h"
#include <iostream>
#include <queue>
#include <math.h>

void BinaryMinHeap::insert(int el) {
	if (numOfElements == length - 1) return;
	numOfElements++; 
	int i = numOfElements;
	while (i > 1 && array[i / 2] > el)
	{ 
		array[i] = array[i / 2];
		i /= 2;
	}
	array[i] = el;
}

int BinaryMinHeap::deleteRoot() {
	if (numOfElements == 0) throw new int(3);
	int result = array[1];
	int last = array[numOfElements]; 
	numOfElements--; 
	long i = 1; 
	while (2 * i < numOfElements + 1) { 
		long child = 2 * i;
		if (child + 1 < numOfElements + 1 && array[child + 1] < array[child])
			child += 1;
		if (last <= array[child]) break;
		array[i] = array[child];
		i = child; 
	}
	array[i] = last;
	return result;
}

void BinaryMinHeap::printHeap() {
	if (numOfElements < 1) return;
	std::queue<int> q;
	q.push(1);
	int level = 0;
	while (!q.empty()) {
		int el = q.front();
		q.pop();
		if (el == (int)pow(2, level)) {
			level++;
			std::cout << std::endl;
		}
		std::cout << array[el] << " ";
		
		
		if (el * 2 <= numOfElements) q.push(el * 2);
		if (el * 2 + 1 <= numOfElements) q.push(el * 2 + 1);
	}
}

void BinaryMinHeap::update(int val, int add) {
	int i = 1;
	if (val < array[i]) return; // manji od najmanjeg elementa u heap-u
	while (i <= numOfElements) {
		if (array[i] == val) break;
		i++;
	}
	if (i > numOfElements) return; // presli smo ceo niz a nismo nasli val

	array[i] += add;
	if (add < 0) upheap(i);
	else downheap(i);
}

void BinaryMinHeap::upheap(int index) {
	if (index > numOfElements) return;
	while (index > 1 && array[index] < array[index / 2]) {
		exch(index, index / 2);
		index /= 2;
	}
}

void BinaryMinHeap::downheap(int index) {
	while (index*2 <= numOfElements) {
		int j = index * 2;
		if (j < numOfElements && array[j + 1] < array[j]) j++; // nadjemo najmanje dete
		if (array[index] > array[j]) exch(index, j); // ako je najmanje dete manje od roditelja, zamenimo ih
		else break;
		index = j;
	}
}

void BinaryMinHeap::exch(int index1, int index2) {
	int pom = array[index1];
	array[index1] = array[index2];
	array[index2] = pom;
}
