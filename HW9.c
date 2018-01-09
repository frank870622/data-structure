#include <stdio.h>
#include <stdlib.h>
int findmax(int[],int);

int main(){
    int act;
    scanf("%d",&act);
    int startv[act],endv[act],requir[act];
    int trash;
    for (int i=0; i<act; ++i){
        scanf("%d",&trash);
        scanf("%d",&startv[i]);
        scanf("%d",&endv[i]);
        scanf("%d",&requir[i]);
    }
    int maxnode = findmax(startv,act) + 1;
    int maxnode2 = findmax(endv,act) + 1;
    if (maxnode2 > maxnode) maxnode = maxnode2;
    int ev[maxnode],lv[maxnode];
    for(int i=0; i<maxnode; ++i){
        ev[i] = 0;
    }
    ev[0] = 0;
    for(int i=0; i<act; ++i){
        if(ev[endv[i]] < ev[startv[i]] + requir[i])
            ev[endv[i]] = ev[startv[i]] + requir[i];
    }
    for(int i=0; i<act; ++i){
        if(ev[endv[i]] < ev[startv[i]] + requir[i])
            ev[endv[i]] = ev[startv[i]] + requir[i];
    }
    for(int i=0; i<maxnode; ++i){
        lv[i] = ev[maxnode-1];
    }
    for(int i=act-1; i>=0; --i){
        if(lv[startv[i]] > lv[endv[i]] - requir[i])
            lv[startv[i]] = lv[endv[i]] - requir[i];
    }
    printf("a.\n\tee\tle\n");
    for(int i=0; i<maxnode; ++i){
        printf("%d\t%d\t%d\n",i,ev[i],lv[i]);
    }

    int ee[act],te[act];
    for(int i=0; i<act; ++i){
        ee[i] = 0;
    }
    for(int i=0;i<act;++i){
        if(ee[i] < ev[startv[i]])
            ee[i] = ev[startv[i]];
    }
    for(int i=0; i<act; ++i){
        te[i] = lv[act-1];
    }
    for(int i=act-1;i>=0;--i){
        if(te[i] > lv[endv[i]] - requir[i])
            te[i] = lv[endv[i]] - requir[i];
    }
    int s[act];
    char c[act];
    for(int i=0; i<act; ++i){
        s[i] = abs(ee[i] - te[i]);
        if(s[i] == 0)   c[i] = 'Y';
        else    c[i] = 'N';
    }
    printf("\nb.\n\te\tl\ts\tc\n");
    for(int i=0; i<act; ++i){
        printf("%d\t%d\t%d\t%d\t%c\n",i+1,ee[i],te[i],s[i],c[i]);
    }

    return 0;
}

int findmax(int array[],int act){
    int max = -1;
    for(int i=0; i<act; ++i){
        if(array[i] > max)  max = array[i];
    }
    return max;
}
