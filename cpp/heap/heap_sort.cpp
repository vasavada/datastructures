#include <iostream>
#include <cstdlib>

using namespace std;

void swap(int* x , int* y){
	int temp = *x;
	*x = *y;
	*y = temp;
}

void heapify(int arr[] , int n , int i){
	int l = ((2 * i) + 1);
	int r = ((2 * i) + 2);
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
	for(int i = (n/2) - 1 ; i >= 0 ; i--){
		heapify(arr , n , i);
	}

	for(int i = n-1 ; i >= 0 ; i--){
		swap(&arr[0] , &arr[i]);
		heapify(arr , i , 0);
	}
}

void printArray(int arr[] , int n){
	for(int i = 0 ; i < n ; i++){
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main(){

	int arr[10] = {9 , 2 , 3 , 4, 1 , 6 , 8 , 7 , 5 , 0};
	printArray(arr , sizeof(arr)/sizeof(arr[0]));
	heapSort(arr , sizeof(arr)/sizeof(arr[0]));
	printArray(arr , sizeof(arr)/sizeof(arr[0]));
	return 0;
}