#include <iostream>
#include <cstdlib>
#include <climits>
#include <unordered_map>
#include <vector>

using namespace std;

vector<int> twoSum(vector<int> &numbers , int target){
	unordered_map<int , int> hash;
	vector<int> result;
	for(int i = 0 ; i < numbers.size() ; i++){
		int numberToFind = target - numbers[i];

		if(hash.find(numberToFind) != hash.end()){
			result.push_back(hash[numberToFind]);
			result.push_back(i);
			return result;
		}
		hash[numbers[i]] = i;
	}
	return result;
}

void printVector(vector<int> arr){
	for(int i = 0 ; i < arr.size() ; i++){
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main(){
	vector<int> testArr{1 , 2 , 3 , 4 , 5 , 6 , 7 , 8};
	int target = 11;
	vector<int> result;
	result = twoSum(testArr , target);
	printVector(result);
	return 0;
}