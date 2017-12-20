#include <iostream>
using namespace std;

int findheight(int parent[],int x){
    for(;parent[x] >= 0;x = parent[x]);
    return parent[x];
}
void heightunion(int parent[],int i,int j,int roota,int rootb){
    int temp = roota + rootb;
    if(roota > rootb){
        parent[i] = j;
    }
    else if(roota < rootb){
        parent[j] = i;
    }
    else {
        parent[j] = i;
        parent[i] = parent[i] - 1;
    }
}
int main(){
    int n;
    cin >> n;
    int parent[n] = {-1};
    for(int i=0;i<n;++i)    parent[i] = -1;
    for(int i=1;i<n;++i){
        heightunion(parent,0,i,findheight(parent,0),findheight(parent,i));
    }
    cout << "NODE   parent\n";
    for(int i=0;i<n;++i){
        cout << i << "\t";
        if (parent[i] < 0)  {
            cout << "root\n";
            continue;
        }
        cout << parent[i] << "\n";
    }
    return 0;
}
