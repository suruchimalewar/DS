
#include <iostream>
#include <vector>
using namespace std;

void InsertInHeap(vector<int>& vec, int key){
    int i = vec.size();
    vec.emplace_back(key);
    
    while(i > 0 && (key > vec[(i % 2 == 0) ? (i/2) - 1 : i/2 ])){
        vec[i] = vec[(i % 2 == 0 )? (i/2) - 1 : i/2 ];
        i = (i % 2 == 0 )? (i/2) - 1 : i/2 ;
    }
    vec[i] = key;
}

int DeleteInHeap(vector<int>& vec) {
    int x = vec[0];
    int size = vec.size();
    vec[0] = vec[size - 1];
    //2i + 1 and 2i + 2
    int i = 0;
    int j = 1;
    while(j < size - 2){
        if(j < size - 2 &&  vec[j+1] > vec[j]) ++j;// to find left or right child is greater
        
        // to check if root is greater or need to stop algo
        if(vec[i] < vec[j]) {
            int temp = vec[i];
            vec[i] = vec[j];
            vec[j] = temp;
            
            i = j;
            j =  2 * i;
        } else break;
    }
    
    return x;
}

void createHeap(vector<int> a){
    for(auto i : a)
    {
        InsertInHeap(a, i);
    }
}
void Print(vector<int>& v){
    for(auto i : v)
    {
        cout << i << endl;
    }
}

void heapify(vector<int> A){
    int n = A.size();
    for (i = (n/2) - 1; i >=0; --i){
        j = 2 * i + 1;
        while(j < n){
            if( j < n && A[j + 1] > A[j]) j++;
            if(A[j] > A[i]) {
                int temp = A[i];
                A[i] = A[j];
                A[j] = temp;
                i = j;
                j = 2 *i +1;
            } else break;
        }
    }
}

int main()
{
    vector<int> a = {10, 20, 30, 25, 5, 40, 35};
    //createHeap(a);
   // Print(a);
    vector<int> v = {45, 35, 15, 30, 10, 12, 6, 5, 20};
    //Print(v);

 
    InsertInHeap(v, 50);
  // Print(v);
  int x =  DeleteInHeap(v);
  cout << x << endl;
  Print(v);
    return 0;
}
  
