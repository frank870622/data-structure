#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *link;
}NODE;

NODE* xor4(NODE* a,NODE* b){
    int c = (int)a^(int)b;
    return (NODE*)c;
};
NODE* xor8(NODE* a,NODE* b){
    long long int c = (long long int)a^(long long int)b;
    return (NODE*)c;
};

int main(){
    NODE *maie;
    maie = (NODE *)malloc(sizeof(NODE));
    maie->data = 1;

    maie->link = NULL;
    NODE *first = maie;

    for (int i=2;i<=20;++i){
        NODE *second;
        second = (NODE *)malloc(sizeof(NODE));
        second->data = i;
        if(i == 2){
            maie->link = second;
        }
        else{
            if(sizeof(NODE*) == 4)  maie->link = xor4(maie->link,second);
            else if(sizeof(NODE*) == 8)    maie->link = xor8(maie->link,second);
        }
        second->link = maie;
        maie = second;
    }
    printf("The data from left to right:\n");
    maie = first;
    NODE* second = maie->link;
    printf("%d, ",maie->data);
    for(int i = 2;i<=20;++i){
        NODE* temp = second;
        if(i == 20) printf("%d ",second->data);
        else        printf("%d, ",second->data);
        if(sizeof(NODE*) == 4)  second = xor4(second->link,maie);
        else if(sizeof(NODE*) == 8)   second = xor8(second->link,maie);
        maie = temp;
    }
    printf("\n\nThe data from right to left:\n");
    printf("%d, ",maie->data);
    second = maie->link;
    for(int i=2;i<=20;++i){
        NODE* temp = second;
        if(i == 20) printf("%d ",second->data);
        else        printf("%d, ",second->data);
        if(sizeof(NODE*) == 4)  second = xor4(second->link,maie);
        else if(sizeof(NODE*) == 8)    second = xor8(second->link,maie);
        maie = temp;
    }
    printf("\n");
    return 0;
}
