#include <iostream>
#include <string>
#include <queue>
#include <stdlib.h>
using namespace std;
int maxnumber = 0;
typedef struct node{
    int k;
    struct node *leftchild;
    struct node *rightchild;
    struct node *parent;
}NODE;

NODE *insertnode(NODE*,int);
void levelorder(NODE*);
NODE *searchnode(NODE*,int);

void deletion(NODE* binary){
    int deletenumber = binary->k;
    if((binary->rightchild == NULL) && (binary->leftchild == NULL)){
        if(binary->parent->rightchild == binary){
            binary->parent->rightchild = NULL;
        }
        else if(binary->parent->leftchild == binary){
            binary->parent->leftchild = NULL;
        }
        binary->k = NULL;
        binary->rightchild = NULL;
        binary->leftchild = NULL;
        binary = NULL;
    }
    else {
        NODE* temp = binary;
        if(temp->rightchild != NULL){
                temp = temp->rightchild;
                while((temp->rightchild != NULL) || (temp->leftchild != NULL)){
                        if(temp->leftchild != NULL) temp = temp->leftchild;
                        else if(temp->rightchild != NULL)   temp = temp->rightchild;
                }
        }
        else if(temp->leftchild != NULL){
            temp = temp->leftchild;
            while((temp->rightchild != NULL) || (temp->leftchild != NULL)){
                        if(temp->rightchild != NULL) temp = temp->rightchild;
                        else if(temp->leftchild != NULL)    temp = temp->leftchild;
                }
        }
        binary->k = temp->k;
        if(temp->parent->rightchild == temp){
            temp->parent->rightchild = NULL;
        }
        else if(temp->parent->leftchild == temp){
            temp->parent->leftchild = NULL;
        }
        temp->k = NULL;
        temp->rightchild = NULL;
        temp->leftchild = NULL;
        temp = NULL;
    }
    --maxnumber;
}

int main(){
    NODE *binary;
    NODE *first = binary;
    binary->k = NULL;
    binary->leftchild = NULL;
    binary->rightchild = NULL;
    binary->parent = NULL;
    string input;
    cin >> input;
    for(int i=0;i <= input.length();++i){
        if((input[i] == ',') || (i == input.length())){
            int j=i-1;
            int mut = 1;
            int number = 0;
            while((input[j]!=',') && (j!=-1)){
                number += ((int)input[j] - 48)*mut;
                mut = mut*10;
                --j;
            }
            binary = insertnode(first,number);
            ++maxnumber;
        }
    }
    cout << "Create Binary search tree\n" ;
    levelorder(first);

    char answer;
    do{
        cout << "Delete element?(Y/N):";
        cin >> answer;
        if(answer == 'Y'){
            cout << "Choice element:";
            int numb;
            cin >> numb;
            NODE *thedeletonode = searchnode(first,numb);
            if(thedeletonode == NULL){
                cout << numb << " is not in the tree\n";
            }
            else{
                deletion(thedeletonode);
                levelorder(first);
            }
        }
        else if (answer == 'N'){
        }
    }while(answer == 'Y');

    return 0;
}

NODE *insertnode(NODE *binary,int number){
    if(binary->k == NULL){
        binary->k = number;
    }
    else if(binary->k == number){
        cout << "error input" << "\n";
        exit(1);
    }
    else if(binary->k > number){
        if(binary->leftchild == NULL){
            NODE *child;
            child = (NODE *)malloc(sizeof(NODE));
            child->k = NULL;
            child->leftchild = NULL;
            child->rightchild = NULL;
            child->parent = binary;
            binary->leftchild = child;
        }
        insertnode(binary->leftchild,number);
    }
    else if(binary->k < number){
        if(binary->rightchild == NULL){
            NODE *child;
            child = (NODE *)malloc(sizeof(NODE));
            child->k = NULL;
            child->leftchild = NULL;
            child->rightchild = NULL;
            child->parent = binary;
            binary->rightchild = child;
        }
        insertnode(binary->rightchild,number);
    }
    return binary;
}


void levelorder(NODE* binary){
    queue<NODE*> q;
    q.push(binary);
    int nowcount = 0;
    int printtime = 0;
    int level = 1;
    while(!q.empty()){
        NODE *now = q.front();
        q.pop();
        if(now-> k == NULL){
            cout << "* ";
        }
        else {
            cout << now->k << " ";
            ++printtime;
        }
        ++nowcount;
        if(printtime == maxnumber){
            cout << "\n";
            break;
        }
        if(nowcount == level){
            cout << "\n";
            level *= 2;
            nowcount = 0;
        }

        if(now->leftchild != NULL){
            q.push(now->leftchild);

        }
        if(now->leftchild == NULL){
                NODE *temp;
                temp = (NODE *)malloc(sizeof(NODE));
                temp->k = NULL;
                temp->leftchild = NULL;
                temp->rightchild = NULL;
                q.push(temp);
        }
        if(now->rightchild != NULL){

            q.push(now->rightchild);
        }
        if(now->rightchild == NULL){
                NODE *temp;
                temp = (NODE *)malloc(sizeof(NODE));
                temp->k = NULL;
                temp->leftchild = NULL;
                temp->rightchild = NULL;
                q.push(temp);
        }
    }
}

NODE *searchnode(NODE* binary,int numb){
    if(binary){
        if(binary->k == numb){
            return binary;
        }
        else if(binary->k > numb){
            if(binary->leftchild != NULL)   searchnode(binary->leftchild,numb);
            else return NULL;
        }
        else if(binary->k < numb){
            if(binary->rightchild != NULL)  searchnode(binary->rightchild,numb);
            else return NULL;
        }
    }
}
