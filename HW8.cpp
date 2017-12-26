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


//void allCosts(int,int);
void findpath(int,int[]);
int choose(int distance[],bool found[]){
    int i,m,mpos;
    m = a;
    mpos = -1;
    for(i = 0; i < 9; ++i){
        if(distance[i] < m && !found[i]){
            m = distance[i];
            mpos = i;
        }
    }
    return mpos;
}
void shortestpath(int v,int f){
    int distance[9];
    bool found[9];
    int parent[9];
    int i,j,k;
    for(i = 0; i < 9 ; ++i){
        distance[i] = 10000;
        found[i] = false;
        parent[i] = -1;
    }
    parent[v] = v;
    distance[v] = 0;
    for(i = 0; i < 9; ++i){
        j = choose(distance,found);
        if(a == -1) break;
        found[j] = true;
        for(k = 0; k < 9; ++k){
            if(!found[k])
                if(distance[j] + cost[j][k] < distance[k]){
                    distance[k] = distance[j] + cost[j][k];
                    parent[k] = j;
                }
        }
    }
    if(distance[f] < 100){
        cout << "Distance :" << distance[f] << "\n";
        cout << "The route for the shortest path :";
        findpath(f,parent);
    }
    else cout << "No solution";
}


int main(){
    int v,f;
    cin >> v >> f;
    shortestpath(v,f);
    //allCosts(v,f);
    return 0;
}

void findpath(int f,int parent[]){
    if(f != parent[f])
        findpath(parent[f],parent);
    if(f == parent[f])  cout << f;
    else    cout << "¡÷" << f;
}
/*
void allCosts(int v,int f){
    int distance[9][9];
    int parent[9];
    bool found[9];
    for(int r = 0; r < 9; ++ r) {
        parent[r] = -1;
        found[r] = false;
    }
    parent[v] = v;
    int i,j,k;
    for(i = 0; i < 9; ++i)
        for(j = 0; j < 9; ++j){
            distance[i][j] = cost[i][j];
            //if(distance[i][j] < 100 && distance[i][j] != 0)    parent[j] = i;
        }
    for(k = 0; k < 9; ++k)
        for(i = 0; i < 9; ++i){
            for(j = 0; j < 9; ++j)
                if(distance[i][k] + distance[k][j] < distance[i][j]){
                    distance[i][j] = distance[i][k] + distance[k][j];
                    //cout << i << " " << j << " " << k << " " <<distance[i][j] << "\n";
                    parent[j] = k;
                }
        }

    if(distance[v][f] > 100)    cout << "No solution";
    else{
        cout << distance[v][f] << "\n";

        for(int r = 0; r < 9; ++r){
            cout << parent[r] << " ";
        }

        cout << "\n";
        findpath(f,parent);
    }

}
*/
