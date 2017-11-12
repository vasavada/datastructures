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
	int heapsize;
	int capacity;

public:
	MinHeap(int);
	void minHeapify(int);
	int parent(int);
	int left(int);
	int right(int);
	void insertKey(int);
	void decreaseKey(int , int);
	int getMin();
	int extractMin();
	void deleteKey(int);
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
	int l = MinHeap::left(i);
	int r = MinHeap::right(i);

	if(l < heapsize && harr[l] < harr[smallest]){
		smallest = l;
	}

	if(r < heapsize && harr[r] < harr[smallest]){
		smallest = r;
	}

	if(smallest != i){
		swap(&harr[i] , &harr[smallest]);
		MinHeap::minHeapify(smallest);
	}
}

void MinHeap::insertKey(int k){
	if(heapsize == capacity){
		cout << "Heap is Full, can not insert any more." << endl;
		return;
	}

	heapsize++;
	int i = heapsize - 1;
	harr[i] = k;

	while(i != 0 && harr[MinHeap::parent(i)] > harr[i]){
		swap(&harr[MinHeap::parent(i)] , &harr[i]);
		i = parent(i);
	}
}

void MinHeap::decreaseKey(int i , int new_val){
	harr[i] = new_val;
	while(i != 0 && harr[MinHeap::parent(i)] > harr[i]){
		swap(&harr[MinHeap::parent(i)] , &harr[i]);
		i = MinHeap::parent(i);
	}
}

int MinHeap::getMin(){
	return harr[0];
}

int MinHeap::extractMin(){
	if(heapsize <= 0){
		return INT_MAX;
	}
	if(heapsize == 1){
		heapsize--;
		return harr[0];
	}

	int root = harr[0];
	harr[0] = harr[heapsize - 1];
	heapsize--;
	MinHeap::minHeapify(0);
	return root;
}

void MinHeap::deleteKey(int i){
	MinHeap::decreaseKey(i , INT_MIN);
	MinHeap::extractMin();
}

int main(){
	MinHeap h(11);
	h.insertKey(3);
	h.insertKey(2);
	h.deleteKey(1);
	h.insertKey(15);
	h.insertKey(5);
	h.insertKey(4);
	h.insertKey(45);
	cout << h.extractMin() << " ";
	cout << h.getMin() << " ";
	h.decreaseKey(2, 1);
	cout << h.getMin();
	return 0;
}