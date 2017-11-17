#include <iostream>
#include <cstdlib>
#include <climits>
#include <vector>

using namespace std;

vector<int> firstSecondSmallest(vector<int> arr){
	vector<int> result;
	if(arr.size() < 2){
		result.push_back(INT_MAX);
		result.push_back(INT_MAX);
		return result;
	}
	
	int first = INT_MAX , second = INT_MAX;
	for(int i = 0 ; i < arr.size() ; i++){
		if(arr[i] < first){
			second = first;
			first = arr[i];
		}else if(arr[i] < second && arr[i] != first){
			second = arr[i];
		}
	}
	result.push_back(first);
	if(second == INT_MAX){
		cout << "There is no second smallest element." << endl;
		result.push_back(INT_MAX);
	}else{
		result.push_back(second);
	}
	return result;
}

void traverseArray(vector<int> arr){
	for(int i = 0 ; i < arr.size() ; i++){
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main(){
	vector<int> v{12 , 13 , 1 , 10 , 34 , 1};
	vector<int> res = firstSecondSmallest(v);
	traverseArray(res);
	return 0;
}