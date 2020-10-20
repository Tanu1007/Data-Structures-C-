//Queue
/*
	Queue is a linear DS operates in FIFO or LILO
	like line of cars =+ | =+ | =+ 
	its an Abstarct data type with bounded capacity
		 Front                 Rear
		[    ]|[    ]|[    ]|[    ]
	elements added at one end is called enqueue
	elements removed from the other end is called dequeue
*/

#include <iostream>
using namespace std;

class Queue{
	private:
		int front;
		int rear;
		int arr[4];
	
	public:
		Queue(){
			front = rear = -1;
			for(int i=0;i<4;i++){
				arr[i]=0;
			}
		}
		
		bool isEmpty(){
			if (front==-1 && rear==-1){
				cout << "Queue is empty !!";
				return true;
			}
			return false;
		}
		
		bool isFull(){
			//if((rear+1)%4==front){     ///for circular queue 
			if(rear==4){
				cout << "Queue is full !!";
				return true;
			}
			return false;
		}
		
		void enqueue(int val){
			if(isFull()){
				cout << "Queue is full!!";	
				return;
			}else if(isEmpty()){
				rear=front =0;
			}else{
				rear++;
				//rear = (rear+1)%4; //for circular queue
			}
			arr[rear]=val;
		}
		
		int dequeue(){
			int x=0;
			if(isEmpty()){
				cout << "Queue is Empty";
				return 0;
			}else if(front == rear){
				x = arr[front];
				front=rear=-1;
			}else{
				x = arr[front];
				arr[front]=0;
				front++;
				//front = (front+1)%4;   //fpr circular queue
			}
			return x;
		}
		
		int count(){
			return (rear-front+1);
		}	
		
		void display(){
			cout << "QUEUE:" << endl;
			for(int i=0;i<4;i++){
				cout << arr[i] << " ";
			}
		}
};

int main(){
	Queue q;
	//q.isEmpty();
	q.enqueue(4);
	q.enqueue(56);
	q.enqueue(3);
	cout << q.dequeue() << endl;
	q.display();
	
	
}
