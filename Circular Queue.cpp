//Queue
/*
	Queue is a linear DS operates in FIFO or LILO
	like line of cars =+ | =+ | =+ 
	its an Abstarct data type with bounded capacity
		 Front                 Rear
		[    ]|[    ]|[    ]|[    ]
		_____________________________7
	elements added at one end is called enqueue
	elements removed from the other end is called dequeue
*/

#include <iostream>
using namespace std;

class CircularQueue{
	private:
		int front;
		int rear;
		int arr[5];
		int itemcount;
	
	public:
		CircularQueue(){
			front = rear = -1;
			for(int i=0;i<5;i++){
				arr[i]=0;
			}
		}
		
		bool isEmpty(){
			if (front==-1 && rear==-1){
				//cout << "Queue is empty !!";
				return true;
			}
			return false;
		}
		
		bool isFull(){
			if((rear+1)%5==front){     //for circular queue 
			//if(rear==4){
				//cout << "Queue is full !!";
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
				rear = (rear+1)%5; //for circular queue
			}
			arr[rear]=val;
			itemcount++;
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
				front = (front+1)%5;   //for circular queue
			}
			itemcount--;
			return x;
		}
		
		int count(){
			return (rear-front+1);
		}	
		
		void display(){
			cout << "QUEUE:" << endl;
			for(int i=0;i<5;i++){
				cout << arr[i] << " ";
			}
			cout << endl;
		}
};

int main(){
	CircularQueue q;
	//q.isEmpty();
	q.enqueue(1);
	q.display();
	q.enqueue(2);
	q.display();
	q.enqueue(3);
	q.display();
	q.enqueue(4);
	q.display();
	q.enqueue(5);
	q.display();
	q.dequeue();
	q.display();
	q.enqueue(6);
	q.display();
	q.dequeue();
	q.display();
	q.enqueue(7);
	q.display();
	q.dequeue();
	q.display();
	q.enqueue(8);
	q.display();
	q.dequeue();
	q.display();
	q.enqueue(9);
	q.display();
	
	
}
