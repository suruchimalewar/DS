
#include <iostream>
#include <vector>
using namespace std;


void merge(int arr[], int mid,int low, int high){
    int B[100];
    int k = low;
    int i = low;
    int j = mid+1;
    
    while(i <= mid && j <= high){
        if(arr[i] < arr[j]){
            B[k++] = arr[i++];
        } else {
            B[k++] = arr[j++];
        }
    }
    for(; i <= mid; ++i) {
        B[k++] = arr[i];
    }
    for(; j <= high; ++j) {
        B[k++] = arr[j];
    }
    
    for(i=low;i<=high;i++)
         arr[i]=B[i];
}
void mergeSort(int arr[], int low, int high){
    if(low < high){
    int mid = (low+high)/2;
    mergeSort(arr,low, mid);
    mergeSort(arr,mid+1, high);
    
    merge(arr, mid, low , high);
    }
    
}
int main()
{
    int arr[] = {9, 2, 3, 6, 1, 0, 5, 8};
    mergeSort(arr, 0, 7);
    
    for(int i = 0; i < 8; ++i){
        std::cout << arr[i] << endl;
    }
    return 0;
}
