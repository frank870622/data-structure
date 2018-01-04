#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
int a = 10000;
int cost[9][9] = {
    0,5,4,2,a,a,a,a,a,
    a,0,a,a,3,a,a,a,a,
    a,1,0,a,2,8,a,a,a,
    a,a,1,0,a,7,a,a,a,
    a,a,a,a,0,a,7,10,15,
    a,a,a,a,a,0,a,3,a,
    a,a,a,a,a,a,0,a,6,
    a,a,a,a,a,a,a,0,5,
    a,a,a,a,a,a,a,a,0
};


void allCosts(int,int);
void findpath(int,int[]);


int main(){
    int v,f;
    cin >> v >> f;
    allCosts(v,f);
    return 0;
}

void findpath(int f,int parent[]){
    if(f != parent[f])
        findpath(parent[f],parent);
    if(f == parent[f])  cout << f;
    else    cout << "->" << f;
}

void allCosts(int v,int f){
    int distance[9][9];
    int parent[9][9];
    bool found[9][9];
    int i,j,k;
    for(i = 0; i < 9; ++i)
        for(j = 0; j < 9; ++j){
            distance[i][j] = 10000;
            parent[i][j] = -1;
            found[i][j] = false;
        }
    for(k = 0; k < 9; ++k){
        parent[k][k] = k;
        distance[k][k] = 0;
        for(i = 0; i < 9; ++i){
            int m,mpos;
            m = a;
            mpos = -1;
            for(j = 0; j < 9; ++j){
                if(distance[k][j] < m && !found[k][j]){
                    m = distance[k][j];
                    mpos = j;
                }
            }
            if(mpos == -1)  break;
            found[k][mpos] = true;
            for(j = 0; j < 9; ++j){
                if(!found[k][j])
                    if(distance[k][mpos] + cost[mpos][j] < distance[k][j]){
                        distance[k][j] = distance[k][mpos] + cost[mpos][j];
                        parent[k][j] = mpos;
                    }
            }
        }
    }

    if(distance[v][f] > 100)    cout << "No solution";
    else{
        cout << "Distance :" << distance[v][f] << "\n";
        cout << "The route for the shortest path : ";
        findpath(f,parent[v]);
    }

}
