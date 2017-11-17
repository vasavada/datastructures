#include <iostream>
#include <cstdlib>
#include <climits>

using namespace std;

void swap(int* x , int* y){
	int temp = *x;
	*x       = *y;
	*y       = temp;
}

class MinHeap{
	int* harr;
	int capacity;
	int heapsize;

public:
	MinHeap(int cap){
		capacity = cap;
		heapsize = 0;
		harr = (int*)malloc(sizeof(int) * cap);
	}

	int parent(int i){
		return ((i - 1) / 2);
	}

	int left(int i){
		return ((2 * i) + 1);
	}

	int right(int i){
		return ((2 * i) + 2);
	}

	void minHeapify(int i){
		int smallest = i;
		int l = left(i);
		int r = right(i);

		if(l < heapsize && harr[l] < harr[smallest]){
			smallest = l;
		}

		if(r < heapsize && harr[r] < harr[smallest]){
			smallest = r;
		}

		if(smallest != i){
			swap(&harr[i] , &harr[smallest]);
			minHeapify(smallest);
		}
	}

	int getMin(){
		return harr[0];
	}

	int extractMin(){
		if(heapsize <= 0){
			cout << "No elements in heap." << endl;
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

	void decreaseKey(int i , int new_val){
		harr[i] = new_val;
		while(i!=0 && harr[i] < harr[parent(i)]){
			swap(&harr[i] , &harr[parent(i)]);
			i = parent(i);
		}
	}

	void insertKey(int k){
		if(heapsize == capacity){
			cout << "Heap already Full, can not insert." << endl;
			return;
		}

		heapsize++;
		int i = heapsize - 1;
		harr[i] = k;

		while(i!= 0 && harr[i] < harr[parent(i)]){
			swap(&harr[parent(i)] , &harr[i]);
			i = parent(i);
		}
	}

	void deleteKey(int i){
		decreaseKey(i , INT_MIN);
		extractMin();
	}
};


class HeapSort{
public:

	void heapify(int arr[] , int n , int i){
		int l = ((2*i) + 1);
		int r = ((2*i) + 2);
		int largest = i;

		if(l < n && arr[l] > arr[largest]){
			largest = l;
		}

		if(r < n && arr[r] > arr[largest]){
			largest = r;
		}

		if(i != largest){
			swap(&arr[i] , &arr[largest]);
			heapify(arr , n , largest);
		}
	}

	void heapSort(int arr[] , int n){
		for(int i = n/2 - 1 ; i >= 0 ; i--){
			heapify(arr , n , i);
		}

		for(int i = n-1 ; i >= 0 ; i--){
			swap(&arr[i] , &arr[0]);
			heapify(arr ,  i , 0);
		}
	}

	void printArray(int arr[] , int n){
		for(int i = 0 ; i < n ; i++){
			cout << arr[i] << " ";
		}
		cout << endl;
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
	cout << h.getMin() << endl;


	HeapSort hs;

	int arr[10] = {9 , 2 , 3 , 4, 1 , 6 , 8 , 7 , 5 , 0};
	hs.printArray(arr , sizeof(arr)/sizeof(arr[0]));
	hs.heapSort(arr , sizeof(arr)/sizeof(arr[0]));
	hs.printArray(arr , sizeof(arr)/sizeof(arr[0]));
	return 0;
}