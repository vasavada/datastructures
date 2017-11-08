#include <iostream>
#include <cstdlib>
#include <climits>

using namespace std;

void swap(int* x , int* y){
	int temp = *x;
	*x = *y;
	*y = temp;
}


class MinHeap{
	int* harr;
	int capacity;
	int heapsize;

public:
	MinHeap(int);
	void minHeapify(int);
	int parent(int);
	int left(int);
	int right(int);
	int extractMin();
	void decreaseKey(int , int);
	int getMin();
	void deleteKey(int);
	void insertKey(int);
};

MinHeap::MinHeap(int cap){
	capacity = cap;
	heapsize = 0;
	harr = (int*)malloc(sizeof(int) * cap);
	// harr = new int[cap];
}

int MinHeap::parent(int i){
	return ((i - 1) / 2);
}

int MinHeap::left(int i){
	return ((2 * i) + 1);
}

int MinHeap::right(int i){
	return ((2 * i) + 2);
}

void MinHeap::minHeapify(int i){
	int smallest = i;
	int l = left(i);
	int r = right(i);

	if(l < heapsize && arr[l] < arr[smallest]){
		smallest = l;
	}

	if(r < heapsize && arr[r] < arr[smallest]){
		smallest = r;
	}

	if(smallest != i){
		swap(&harr[i] , &harr[smallest]);
		MinHeap::minHeapify(smallest);
	}
}

int main(){
	return 0;
}