#include<iostream>
#define max 10
using namespace std;
class queue{
    int item[max],front,rear;
    public:
    void create(queue*);
    void isempty(queue*);
    void isfull(queue*);
    void insert(queue*,int);
    int remove(queue*);
    void display(queue*);
};
void queue::create(queue *p){
    p->front=p->rear=-1;
    cout<<"\nQueue is created.";
}
void queue::isempty(queue *p){
    if(p->rear==p->front){
        cout<<"\nQueue is empty.";
    }
    else{
        cout<<"\nQueue is NOT empty.";
    }
}
void queue::isfull(queue *p){
    if(p->rear==max-1){
        cout<<"\nQueue is full.";
    }
    else{
        cout<<"\nQueue is NOT full.";
    }
}
void queue::insert(queue *p,int val){
    if(p->rear==max-1){
        cout<<"\nQueue Overflows.";
    }
    else{
        ++p->rear;
        p->item[p->rear]=val;
        cout<<"\nElement is inserted successfully.";
    }
}
int queue::remove(queue* p){
    if(p->front==p->rear){
        cout<<"\nQueue Underflows.";
        return(-1);
    }
    else{
        ++p->front;
        return(p->item[p->front]);
    }
}
void queue::display(queue * p){
    int i;
    cout<<"\nElements of queue are:";
    for(i=p->front+1;i<=p->rear;i++){
        cout<<"\t"<<p->item[i];
    }
}
int main(){
    int ch,val,re;
    queue obj,ad,*q;
    q=&ad;
    do{
        cout<<"\n\n1:Create\n2:Isempty\n3:Isfull\n4:Insert\n5:Remove\n6:Display\n7:Exit";
        cout<<"\nEnter your choise from above menu:";
        cin>>ch;
        switch (ch){
            case 1:
                obj.create(q);
                break;
            case 2:
                obj.isempty(q);
                break;
            case 3:
                obj.isfull(q);
                break;
            case 4:
                cout<<"\nEnter element:";
                cin>>val;
                obj.insert(q,val);
                break;
            case 5:
                re=obj.remove(q);
                cout<<"\nRemoved element: "<<re;
                break;
            case 6:
                obj.display(q);
                break;
            case 7:
                exit(11234);
            default:
                cout<<"\nInvalid choise.";
        }
    }while(ch!=7);
}