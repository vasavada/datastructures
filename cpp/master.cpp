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
	int heapsize;
	int capacity;
	int* harr;

public:

	MinHeap(int cap){
		heapsize = 0;
		capacity = cap;
		// c++ style definition:
		harr = new int[cap];

		// old style:
		// harr = (int*)malloc(sizeof(int) * cap);
	}

	// parent element index:
	int parent(int i){
		return ((i - 1) / 2);
	}

	// left element index:
	int left(int i){
		return ((2 * i) + 1);
	}

	// right element index:
	int right(int i){
		return ((2 * i) + 2);
	}

	void minHeapify(int i){
		int smallest = i;
		int l = left(i);
		int r = right(i);

		if(l < heapsize && harr[smallest] > harr[l]){
			smallest = l;
		}

		if(r < heapsize && harr[smallest] > harr[r]){
			smallest = r;
		}

		if(smallest != i){
			swap(&harr[smallest] , &harr[i]);
			minHeapify(smallest);
		}
	}

	void insertKey(int k){
		if(heapsize == capacity){
			cout << "Heap is already Full. Can not insert" << endl;
			return;
		}

		heapsize++;
		int i = heapsize - 1;
		harr[i] = k;

		while(i != 0 && harr[parent(i)] > harr[i]){
			swap(&harr[parent(i)] , & harr[i]);
			i = parent(i);
		}
	}

	void decreaseKey(int i , int new_val){
		harr[i] = new_val;
		while(i != 0 && harr[parent(i)] > harr[i]){
			swap(&harr[parent(i)] , &harr[i]);
			i = parent(i);
		}
	}

	int getMin(){
		return harr[0];
	}

	int extractMin(){
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
		minHeapify(0);
		return root;
	}

	void deleteKey(int i){
		decreaseKey(i , INT_MIN);
		extractMin();
	}
};

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