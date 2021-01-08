//Liam Howes 5880331

#include <iostream>
#include <string>
#include "PriorityQueue.h"
using namespace std;

int main(){
    bool running = true;
    PriorityQueue<string> PQ; // priority queue to hold strings as items
    cout<<"Hey, I made a priority queue to hold strings\n";
    cout<<"1 = enqueue, 2 = dequeue, 3 = peek, 4 = count, 0 = quit.\n";

    while(running){
        cout<<"\nenter choice: ";
        int choice;
        cin>>choice;
        if(choice==1){ // enqueue
            string item;
            long prio;
            cout<<"     enter string to be stored in node: ";
            cin>>item;
            cout<<"     enter priority for the node (lower number = higher priority): ";
            cin>>prio;
            PQ.enqueue(item, prio);
            continue;
        }
        if(choice==2){ // dequeue
            try{
                cout<<"     removed: "<<PQ.dequeue()<<endl;
                continue;
            }
            catch(int e){
                cout<<"Error "<<e<<": empty queue.\n";
                continue;
            }
        }
        if(choice==3){ // peek
            try{
                cout<<"     next dequeue will return: "<<PQ.peek()<<endl;
                continue;
            }
            catch(int e){
                cout<<"Error "<<e<<": empty queue.\n";
                continue;
            }
        }
        if(choice==4){ // count
            cout<<"     priority queue length is currently: "<<PQ.count()<<endl;
            continue;
        }
        if(choice==0){ // quit
            running = false;
            continue;
        }
        else{
            cout<<"please enter a valid choice (1 = enqueue, 2 = dequeue, 3 = peek, 0 = quit).\n";
        }
    }
    return 0;
}