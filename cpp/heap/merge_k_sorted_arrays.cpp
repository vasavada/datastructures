#include <iostream>
#include <cstdlib>
#include <climits>

using namespace std;

// #define n 4

int n = 4;

struct MinHeapNode{
	int element;	// The element to be stored
	int i;			// index of array from which 
	int j;
};

void swap(MinHeapNode* x , MinHeapNode* y){
	MinHeapNode temp;
	*x = *y;
	*y = temp;
}

class Minheap{
	MinHeapNode* harr;
	int heapSize;

public:
	Minheap(MinHeapNode arr[] , int size){
		heapSize = size;
		harr = arr;
		int i = heapSize - 1 / 2;
		while(i > 0) {
		    minHeapify(i);
		    i--;
		}
	}

	void minHeapify(int i){
		int smallest = i;
		int l = ((2 * i) + 1);
		int r = ((2 * i) + 2);

		if(l < heapSize && harr[l].element < harr[smallest].element){
			smallest = l;
		}

		if(r < heapSize && harr[r].element < harr[smallest].element){
			smallest = r;
		}

		if(smallest != i){
			swap(&harr[smallest] , &harr[i]);
			minHeapify(smallest);
		}
	}

	MinHeapNode getMin(){
		return harr[0];
	}

	void replaceMin(MinHeapNode x){
		harr[0] = x;
		minHeapify(0);
	}
};

int* mergeKArrays(int arr[][n] , int k){
	int* output = new int[n*k];		// storing the output array
	
	// create a min heap with k heap nodes. Every heap node
	// has first element of the array.
	MinHeapNode* harr = new MinHeapNode[k];
	for(int i = 0 ; i < k ; i++){
		harr[i].element = arr[i][0];	// store the first element
		harr[i].i       = i;			// index of array
		harr[i].j       = 1;			// index of next element from the array
	}
	Minheap hp(harr , k); 	// creating the heap

	// Now one by one get the minimum element from min heap and
	// replace it with replace it with next element of its array.
	for(int count = 0 ; count < n * k ; count++){
		// Get the minimum element and store it in output
		MinHeapNode root = hp.getMin();
		output[count]    = root.element;

		// Find the next elelement that will replace current
		// root of heap. The next element belongs to same
		// array as the current root.
		if(root.j < n){
			root.element = arr[root.i][root.j];
			root.j += 1;
		}

		// If root was the last elemnt of its array:
		else{
			root.element = INT_MAX;		// INT_MAX is for infinite

		}
		// replace root with next element of the array:
		hp.replaceMin(root);
	}
	return output;
}

void printArray(int arr[] , int n){
	for(int i = 0 ; i < n ; i++){
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main(){
	// Change n at the top to change number of elements
	// in an array
	int arr[][4] = {
					{2, 6, 12, 34},
					{1, 9, 20, 1000},
					{23, 34, 90, 2000}
				};
	int k = sizeof(arr)/sizeof(arr[0]); 
	int* output = mergeKArrays(arr, k);
	cout << "Merged array is " << endl;
	printArray(output, n*k); 
	return 0;
	return 0;
}