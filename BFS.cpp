// Online C++ compiler to run C++ online.
// Write C++ code in this online editor and run it.

#include <iostream>
#include <queue>

using namespace std;
void BFS (vector<vector<int>> A, int start, int end) {
    int i = start;
    
    vector<int> V(7, 0);
    queue<int> q;
    
    cout << i << " ";
    
    V[i] = 1;
    q.push(i);
    
    while(!q.empty()){
        int i = q.front();
        q.pop();
        for(int j = 1; j <= end; ++j) {
            if(V[j] == 0 && A[i][j] == 1) {
                cout << j << " ";
                V[j] = 1;
                q.push(j);
            }
        }
    }
    
}
int main() {
 vector<vector<int>> A = {{0, 0, 0, 0, 0, 0, 0, 0},
                   {0, 0, 1, 1, 1, 0, 0, 0},
                   {0, 1, 0, 1, 0, 0, 0, 0},
                   {0, 1, 1, 0, 1, 1, 0, 0},
                   {0, 1, 0, 1, 0, 1, 0, 0},
                   {0, 0, 0, 1, 1, 0, 1, 1},
                   {0, 0, 0, 0, 0, 1, 0, 0},
                   {0, 0, 0, 0, 0, 1, 0, 0}};
 
    cout << "Vertex: 1 -> " << flush;
    BFS(A, 1, 7);
 
    cout << "Vertex: 4 -> " << flush;
    BFS(A, 4, 7);
    return 0;
}
