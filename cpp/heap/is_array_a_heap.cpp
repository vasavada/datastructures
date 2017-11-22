#include <iostream>
#include <cstdlib>
#include <climits>

using namespace std;

// Time Complexity: O(n)
bool isArrayMaxHeap(int arr[] , int i , int n){
	if(i > (n-2) / 2){
		return 1;
	}

	if(arr[i] >= arr[2*i + 1] && 
		arr[i] >= arr[2*i + 2] && 
		isArrayMaxHeap(arr , 2*i + 1 , n) && 
		isArrayMaxHeap(arr , 2*i + 2 , n))
	{
		return 1;
	}

	return 0;
}

bool isArrayMinHeap(int arr[] , int i , int n){
	if(i > (n-2) / 2){
		return 1;
	}

	if(arr[i] <= arr[2*i + 1] && 
		arr[i] <= arr[2*i + 2] && 
		isArrayMinHeap(arr , 2*i + 1 , n) && 
		isArrayMinHeap(arr , 2*i + 2 , n))
	{
		return 1;
	}

	return 0;
}

int main(){
	int arr[] = {90, 15, 10, 7, 12, 2, 7, 3};
	int n = sizeof(arr) / sizeof(int);
	isArrayMaxHeap(arr, 0, n) ? cout << "Yes" : cout << "No";
	cout << endl;
	return 0;
}