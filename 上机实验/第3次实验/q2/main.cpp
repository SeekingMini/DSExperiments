#include <iostream>
#include "Queue.h"
using namespace std;

int main() {
    Queue Q;
    ElemType e;

    cout<<"Initialize Queue"<<endl;
    cout<<"Insert 11,3,7,18,15 to Queue"<<endl;
    Q.EnQueue(11);
    Q.EnQueue(3);
    Q.EnQueue(7);
    Q.EnQueue(18);
    Q.EnQueue(15);
    if(Q.QueueEmpty()){
        cout<<"Queue is Empty"<<endl;
    }
    else{
        cout<<"Queue is not Empty"<<endl;
    }
    cout<<"The Length of Queue is "<<Q.QueueLength()<<endl;
    cout<<"Queue is as followed:"<<endl;
    Q.QueueTraverse();
    cout<<endl;
    cout<<"Delete the head element"<<endl;
    Q.DeQueue(&e);
    Q.GetHead(&e);
    cout<<"The head element is "<<e<<endl;
    cout<<"Queue is as followed:"<<endl;
    Q.QueueTraverse();
    
    return 0;
}