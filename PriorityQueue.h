//Liam Howes 5880331

#include <iostream>
using namespace std;

template<typename T>
struct node {
	T item;
    long priority;
	node<T> *link;
};

template<typename T>
class PriorityQueue {
    private:
        node<T> *head = NULL; // initialize head and tail to NULL (empty queue)
        node<T> *tail = NULL;
    public:
        bool isEmpty(){ // check if the queue is empty
            if(head==NULL && tail==NULL)
            return true;
            else return false;
        }

        void recursiveCheck(node<T> *newnode, node<T> *next, node<T> *prev){
            if(next->link!=NULL){
                if(newnode->priority < next->priority){
                    newnode->link = next;
                    prev->link = newnode;
                }
                else{
                    recursiveCheck(newnode, next->link, next);
                }
            }
            else{ // is the new node higher priority than the last node?
                if(newnode->priority < next->priority){ // yes.
                    newnode->link = next;
                    prev->link = newnode;
                }
                else{ // no.
                    tail->link = newnode;
                    tail = newnode;
                }
            }
        }

        int recursiveCount(node<T> *next, int count){
            if(next == NULL){
                return count;
            }
            else if(next->link!=NULL){
                count++;
                recursiveCount(next->link, count);
            }
            else{
                count++;
                return count;
            }
        }

        void enqueue(const T &i, const long &p) {
            node<T> *nn = new node<T>;
            nn->item=i;
            nn->priority=p;
            nn->link=NULL;
            
            if(head == NULL){ //(if queue is empty)
                head = nn;
                tail = nn;
            }
            else {  
                if(nn->priority < head->priority){ // if new node has higher priority than the head node
                    nn->link = head;
                    head = nn;
                }
                else if(head->link == NULL){ //only one existing node
                    tail->link = nn;
                    tail = nn;
                }
                else recursiveCheck(nn, head->link, head); // recursively check for where the new node fits into queue
            }
        }

        T dequeue() {
            if(isEmpty()){
                throw 21;
            }
            else
            if(head==tail){
                T fr;
                node<T> *ptr = head;
                fr = ptr->item;
                delete ptr;
                head = NULL;
                tail = NULL;
                return fr;
            }
            else{
                T fr;
                node<T> *ptr = head;
                head = head->link;
                fr = ptr->item;
                delete ptr;
                return fr;	
            }
        }

        T peek() {
            if(isEmpty()){
                throw 21;
            }
            else{
                T fr;
                node<T> *ptr = head;
                fr = ptr->item;
                return fr;
            }
        }

        int count(){
            int count = 0;
            return recursiveCount(head, count);
        }
};