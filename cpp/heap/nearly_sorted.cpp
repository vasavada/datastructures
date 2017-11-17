#include <iostream>
#include <cstdlib>
#include <climits>

using namespace std;

void swap(int* x , int* y){
	int temp = *x;
	*x       = *y;
	*y       = temp;
}

class Minheap{
	int* harr;
	int heapsize;

public:
	Minheap(int a[] , int size){
		heapsize = size;
		harr = a;
		int i = (heapsize - 1) / 2;
		while(i >= 0){
			minHeapify(i);
			i--;
		}
	}

	int extractMin(){
		if(heapsize <= 0){
			return INT_MAX;
		}
		
		int root = harr[0];
		harr[0] = harr[heapsize - 1];
		heapsize--;
		minHeapify(0);
		return root;
	}

	int replaceMin(int x){
		int root = harr[0];
		harr[0] = x;
		if(root < x){
			minHeapify(0);
		}
		return root;
	}

	void minHeapify(int i){
		int smallest = i;
		int l = ((2*i) + 1);
		int r = ((2*i) + 2);

		if(l < heapsize && harr[l] < harr[smallest]){
			smallest = l;
		}

		if(r < heapsize && harr[r] < harr[smallest]){
			smallest = r;
		}

		if(smallest != i){
			swap(&harr[smallest] , &harr[i]);
			minHeapify(smallest);
		}
	}


};
void sortK(int arr[] , int n , int k){
	int* harr = new int[k + 1];
	// int* harr = (int*)malloc(sizeof(int) * (k+1));
	for(int i = 0 ; i < k && i < n ; i++){
		harr[i] = arr[i];
	}
	Minheap hp(harr , k + 1);

	for(int i = k + 1 , ti = 0 ; ti < n ; i++ , ti++){
		if(i < n){
			arr[ti] = hp.replaceMin(arr[i]);
		}else{
			arr[ti] = hp.extractMin();
		}
	}
}

void printArray(int arr[] , int n){
	for(int i = 0 ; i < n ; i++){
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main(){
	int k = 3;
	int arr[] = {2, 6, 3, 12, 56, 8};
	int n = sizeof(arr)/sizeof(arr[0]);

	sortK(arr, n, k);
 
	cout << "Following is sorted array: " << endl;
	printArray (arr, n);
	return 0;
}