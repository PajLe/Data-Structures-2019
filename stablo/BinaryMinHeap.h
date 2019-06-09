#pragma once
class BinaryMinHeap
{
	int* array; 
	long length; 
	long numOfElements;
public:
	BinaryMinHeap(long len) { 
		length = len;
		numOfElements = 0;
		array = new int[length + 1]; 
	}
	~BinaryMinHeap() { delete[] array; } 
	bool isEmpty() { 
		return numOfElements == 0;
	}; 
	void insert(int el);
	int deleteRoot();
	static void HeapSort(int* a, long n) {
		BinaryMinHeap heap(n + 1);// Umetanje elemenata polja u heap
		for (long i = 0; i < n; i++)
			heap.insert(a[i]);
		// Brisanje korena i smestanje u polje
		long i = 0;
		while (!heap.isEmpty())
			a[i++] = heap.deleteRoot();
	}
	void printHeap(); // implementacija za heap moze i bez pomocnih struktura

	// zadaci sa kolokvijuma:

	void update(int val, int add); // SP_Kol_II_2016 zad: 1b

private:
	void upheap(int index);
	void downheap(int index);
	void exch(int index1, int index2);
};

