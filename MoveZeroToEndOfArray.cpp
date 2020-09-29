#include <iostream>
#include<vector>
using namespace std;
//int arr = [1,1,0,2,3,0,0,4,0,5,0,0]
//1122300

void getNewArraySwap(vector<int> &arr){
    int j = 0;
    for(int i = 0; i < arr.size(); ++i){
        if((arr[i] != 0) && arr[j] == 0){
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
        
        if(arr[j]!= 0) ++j;
    }
}

void getNewArray(vector<int> &arr)
{
    int i = 0;
    for(int j = 0; j < arr.size(); ++j){
        if(arr[j] != 0){
            arr[i] = arr[j];
            ++i;
        }
    }
    
    for(; i < arr.size(); ++i){
        arr[i] = 0;
    }
}

int main() {
	vector<int>arr =  {1,2};
	
	getNewArraySwap(arr);
	
	 for(int j = 0; j < arr.size(); ++j){
	     
	     cout<<arr[j]<< " ";
	 }
	return 0;
}
