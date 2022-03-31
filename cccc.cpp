#include<iostream>
#include<string>
using namespace std;

struct node{
    int info;
    struct node* pnext;
};
typedef struct node NODE;

struct queue{
    NODE* phead;
    NODE* ptail;
};
typedef struct queue QUEUE;

void Init(QUEUE& Q){
    Q.phead = NULL;
    Q.ptail = NULL;
}
int isEmpty(QUEUE Q){
    return Q.phead == NULL;
}
int size(QUEUE Q){
    int count = 0;
    NODE* p=Q.phead;
    while(p){
        count++;
        p=p->pnext;
    }
    return count;
}
NODE* getNode(int x){
    NODE *p;
    p = new NODE;
    if(p == NULL){
        return NULL;
    }
    p->info =  x;
    p->pnext = NULL;
    return p;
}
void enqueue(QUEUE& Q, int x){
    NODE* new_ele = getNode(x);
    if(isEmpty(Q)){
        Q.phead = new_ele;
        Q.ptail = Q.phead;
    }
    else{
        Q.ptail -> pnext = new_ele;
        Q.ptail = new_ele;
    }
}
int dequeue(QUEUE& Q){
    NODE* p = Q.phead;
    Q.phead =  p->pnext;
    int x = p->info;
    delete p;
    return x;
}
int main(){
    QUEUE Q;
    Init(Q);
    enqueue(Q,1);
    enqueue(Q,2);
    enqueue(Q,3);
    enqueue(Q,4);
    enqueue(Q,5);
    
    cout<<dequeue(Q)<<endl;
    cout<<dequeue(Q)<<endl;
    cout<<dequeue(Q)<<endl;
    cout <<"Size: " <<size(Q) <<endl;
    return 0;
}
