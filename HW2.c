#include <stdio.h>
int n = 1;
int board[8][8] = {0};
int movey[7] = {1,2,2,1,-1,-2,-2,-1};
int movex[7] = {-2,-1,1,2,2,1,-1,-2};
void findnpos(int *x,int *y){
    int nextx[7];
    int nexty[7];
    int npos[7];
    for(int i=0;i<n;++i){
        nextx[i] = *x + movex[i];
        nexty[i] = *y + movey[i];
        if((nextx[i]<0) || (nextx[i]>= n) || (nexty[i]<0) || (nexty[i]>=n) || ((board[nextx[i]][nexty[i]])!=0)){
            npos[i] = -1;
        }
        else {
            npos[i] = 0;
        }
        if(npos[i] != -1){
            npos[i] = numberofnpos(nextx[i],nexty[i]);
        }
    }
    int modehistory[64] = {-1};
    int mode = decideroad(npos,modehistory);
    for (int i=63;i>0;--i){
         modehistory[i] = modehistory[i-1];
    }
    modehistory[0] = mode;
    if(mode != -1){
        *x = *x + movex[mode];
        *y = *y + movey[mode];
    }
    else{
        //printf("error");
        //exit(1);
    }

}
int numberofnpos(int x,int y){
    int npos = 0;
    int nextx[7];
    int nexty[7];
    for(int i=0;i<n;++i){
        nextx[i] = x + movex[i];
        nexty[i] = y + movey[i];
    }
    for(int i=0;i<n;++i){
        if((nextx[i]>=0) && (nextx[i]<n) && (nexty[i]>=0) && (nexty[i]<n) && (board[nextx[i]][nexty[i]]) == 0){
           ++npos;
        }
    }
    return npos;
}
int decideroad(int npos[],int modehistory[]){
    int way = 9;
    int mode = -1;
    for(int i=0;i<n;++i){
        if(npos[i] != -1 ){
            if(npos[i] < way){
                way = npos[i];
                mode = i;
            }
        }
    }
    for (int i=0;i<64;++i){
        if(npos[modehistory[i]] == way){
            mode = modehistory[i];
            break;
        }
    }
    return mode;
}
int main(){
    for (;n<=8;++n){
        for(int i=0;i<n;++i)
            for(int j=0;j<n;++j)
                board[i][j] = 0;
        board[0][0] = 1;
        int x=0,y=0;
        for (int m=2;m <= n*n;++m){
            findnpos(&x,&y);
            board[x][y] = m;
        }
        for (int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                printf("%d\t",board[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}
