#include <stdio.h>
#include <stdlib.h>
int n = 1;
int printanswer = 1;
int board[8][8];
int movex[8] = {1,2,2,1,-1,-2,-2,-1};
int movey[8] = {-2,-1,1,2,2,1,-1,-2};

int decideroad(int npos[],int modehistory[]){
    int way = 9;
    int mode = -1;
    for(int i=0;i<8;++i){
        if(npos[i] != -1 ){
            if(npos[i] < way){
                way = npos[i];
                mode = i;
            }
        }
    }
    /*
    for (int i=0;i<64;++i){
        if(npos[modehistory[i]] == way){
            mode = modehistory[i];
            break;
        }
    }
    */
    return mode;
}

int numberofnpos(int x,int y){
    int npos = 0;
    int nextx[8];
    int nexty[8];
    for(int i=0;i<8;++i){
        nextx[i] = x + movex[i];
        nexty[i] = y + movey[i];
    }
    for(int i=0;i<8;++i){
        if((nextx[i]>=0) && (nextx[i]<n) && (nexty[i]>=0) && (nexty[i]<n) && (board[nextx[i]][nexty[i]]) == 0){
           ++npos;
        }
    }
    return npos;
}

void findnpos(int *x,int *y){
    int nextx[8];
    int nexty[8];
    int npos[8];
    for(int i=0;i<8;++i){
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
        printanswer = 0;
    }

}

int main(){
    for (;n<=8;++n){
        printanswer = 1;
        for(int i=0;i<8;++i) {
            for(int j=0;j<8;++j){
                board[i][j] = 0;
		}
	}
        board[0][0] = 1;
        int x=0,y=0;
        for (int m=2;m <= n*n;++m){
            findnpos(&x,&y);
            board[x][y] = m;
        }
        if(printanswer == 1){
            printf("%d:\n",n);
            for (int i=0;i<n;++i){
                for(int j=0;j<n;++j){
                    printf("%d\t",board[i][j]);
                }
                printf("\n");
            }
        }
        else if(printanswer == 0){
            printf("%d:\nno solution\n",n);
        }
        printf("\n");
    }
    return 0;
}
