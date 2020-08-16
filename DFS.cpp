#include <iostream>
#include <queue>

using namespace std;
 
void DFS(int start, vector<vector<int>> A, int n){
   static vector<int> V(n,0);
   if(V[start] == 0) {
       cout << start <<  " " ;
       V[start] = 1;
       for(int j = 1; j <=n; j++)
       {
           if(V[j] == 0 && A[start][j] == 1) {
                DFS(j, A, n);
           }
       }
   }
}
 
int main (){
 
    vector<vector<int>> A = {{0, 0, 0, 0, 0, 0, 0, 0},
                   {0, 0, 1, 1, 1, 0, 0, 0},
                   {0, 1, 0, 1, 0, 0, 0, 0},
                   {0, 1, 1, 0, 1, 1, 0, 0},
                   {0, 1, 0, 1, 0, 1, 0, 0},
                   {0, 0, 0, 1, 1, 0, 1, 1},
                   {0, 0, 0, 0, 0, 1, 0, 0},
                   {0, 0, 0, 0, 0, 1, 0, 0}};
 
    cout << "Vertex: 1 -> " << flush;
    DFS(4, A, 8);
 
    cout << "Vertex: 4 -> " << flush;
    //DFS(4, A, 8);
 
 
    return 0;
}
