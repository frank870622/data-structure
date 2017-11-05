#include <stdio.h>
#include <stdlib.h>


typedef struct{
  int x;
  int y;
}pos;

pos walk(int x,int y){
    pos step = {x,y};
    return step;
}

void print(char[],pos,pos,int,int);
char go(char[],pos,pos,int,int);

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    char map[n*m];
    pos start,end;
    for(int i=0;i<n*m;++i){
        char a;
        a = getchar();
        if(a == '\n'){
            --i;
            continue;
        }
        map[i] = a;
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if(map[i*m+j] == 's'){
                start.x = i;
                start.y = j;
                map[i*m+j] = '0';
            }
            if(map[i*m+j] == 'd'){
                end.x = i;
                end.y = j;
                map[i*m+j] = '0';
            }
        }
    }
    if(go(map,walk(start.x,start.y),walk(end.x,end.y),n,m) == '0'){
        printf("No route\n");
        return 0;
    }
    print(map,start,end,n,m);
    return 0;
}

char go(char map[], pos start, pos end,int n,int m){
    if(map[start.x*m+start.y] == '0'){
        map[start.x*m+start.y] = '*';

        if(map[end.x*m + end.y] == '0'){
            if((start.x-1 >=0) && (start.y+1 < m)){
                go(map,walk(start.x-1,start.y+1),end,n,m);
            }
            if(start.y+1 < m){
                go(map,walk(start.x,start.y+1),end,n,m);
            }
            if((start.x+1 < n) && (start.y+1 < m)){
                go(map,walk(start.x+1,start.y+1),end,n,m);
            }
            if(start.x+1 < n){
                go(map,walk(start.x+1,start.y),end,n,m);
            }
            if((start.x+1 < n) && (start.y-1 >= 0)){
                go(map,walk(start.x+1,start.y-1),end,n,m);
            }
            if(start.y-1 >= 0){
                go(map,walk(start.x,start.y-1),end,n,m);
            }
            if((start.x-1 >= 0) && (start.y-1 >= 0)){
                go(map,walk(start.x-1,start.y-1),end,n,m);
            }
            if(start.x-1 >= 0){
                go(map,walk(start.x-1,start.y),end,n,m);
            }
            if(map[end.x*m + end.y] != '0') return map[end.x*m + end.y];
            map[start.x*m+start.y] = '0';
        }
    }
    return map[end.x*m + end.y];
}

void print(char map[],pos start,pos end,int n,int m){
    int steps = 0;
    for(int i=0;i<n*m;++i)  if(map[i] == '*')   ++steps;
    map[start.x * m + start.y] = 's';
    map[end.x * m + end.y] = 'd';
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            printf("%c",map[(i*m)+j]);
        }
        printf("\n");
    }
    printf("%d steps\n",steps);
}
