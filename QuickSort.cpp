
#include <iostream>
#include <vector>
using namespace std;

void swap(int &a, int &b){
    int t = a;
    a = b;
    b = t;
}
int partition(int arr[], int low, int high){
    int pi = arr[low];
    int i = low;
    int j = high;
     while(i < j){
        do{++i;}while(arr[i] <= pi);
        
        do{--j;} while(arr[j] > pi);
        if(i<j)
        swap(arr[i], arr[j]);
    }
    
    swap(arr[j], arr[low]);
    return j;
    
}

void QuickSort(int arr[], int low, int high){
    int p;
    if(low< high){
        p = partition(arr, low, high);
        QuickSort(arr, low, p);
        QuickSort(arr, p+1, high);
    }
}

int main()
{
    int arr[] = {9, 2, 3, 6, 1, 0, 5, 8};
    QuickSort(arr, 0, 8);
    
    for(int i = 0; i < 8; ++i){
        std::cout << arr[i] << endl;
    }
    return 0;
}
