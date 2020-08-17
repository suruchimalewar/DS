#include <iostream>

using namespace std;

#define I 32767
#define n 6
#define V 7  // # of vertices in Graph
#define E 9  // # of edges in Graph
int set[8] = {-1, -1, -1, -1, -1, -1, -1, -1};  // Array for finding cycle
int res[2][6] = {0};
int visited[9] = {0};
void myUnion(int u, int v){
    if(set[u] < set[v]){
        set[u] += set[v];
        set[v] =u;
    } else {
        set[v] += set[u];
        set[u] =v;
    }
}
void PrintMCST(int T[][V-1], int A[][E]){
    cout << "\nMinimum Cost Spanning Tree Edges\n" << endl;
    for (int i {0}; i<V-1; i++){
        cout << "[" << T[0][i] << "]-----[" << T[1][i] << "]" << endl;
    }
    cout << endl;
}
int find(int u){
    int x = u;
    int v = 0;
 
    while (set[x] > 0){
        x = set[x];
    }
 
    while (u != x){
        v = set[u];
        set[u] = x;
        u = v;
    }
    return x;
}

void KruskalsMCST(int edges[3][9]){
    int i , j, k, u, v;
    
    i = 0;
    while(i < n){
        int min =I;
        for(j = 0; j < 9 ; ++j){
            if(visited[j] ==0 && min > edges[2][j]){
                min = edges[2][j];
                k = j;
                u = edges[0][j];
                v = edges[1][j];
            }
        }
        
        if(find(u) != find(v)){
            res[0][i] = u;
            res[1][i] = v;
            
            myUnion(find(u), find(v));
            ++i;
        }
        
        visited[k] = 1;
    }
     PrintMCST(res, edges);
}
int main() {
    int edges[3][9] = {{ 1, 1,  2,  2, 3,  4,  4,  5,  5},
                       { 2, 6,  3,  7, 4,  5,  7,  6,  7},
                       {25, 5, 12, 10, 8, 16, 14, 20, 18}};
 
    KruskalsMCST(edges);
    
    return 0;
}
