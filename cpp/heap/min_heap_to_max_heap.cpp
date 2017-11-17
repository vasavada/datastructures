#include <iostream>
#include <cstdlib>
#include <climits>

using namespace std;

void swap(int* x , int* y){
	int temp = *x;
	*x       = *y;
	*y       = temp;
}

void maxheapify(int arr[] , int i , int n){
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
		swap(&arr[largest] , &arr[i]);
		maxheapify(arr , largest , n);
	}
}

void convertToMaxheap(int arr[] , int n){
	for(int i = ((n-2) / 2) ; i >= 0 ; --i){
		maxheapify(arr , i , n);
	}
}

void printArray(int arr[] , int n){
	for(int i = 0 ; i < n ; i++){
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main(){

	int arr[] = {3, 5, 9, 6, 8, 20, 10, 12, 18, 9};
    int n = sizeof(arr)/sizeof(arr[0]);
 
	cout << endl << "Min Heap array : ";
	printArray(arr, n);
	convertToMaxheap(arr, n);
	cout << endl << "Max Heap array : ";
	printArray(arr, n);
	return 0;
}