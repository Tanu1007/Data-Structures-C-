//Stack and it's operation
#include <iostream>
#include <string>

using namespace std;

class Stack{
	private:
		int top;
		int arr[5];
		
	public:
		Stack(){
			top = -1;
			for(int i=0;i<5;i++){
				arr[i]=0;
			}
		}
		
		bool isEmpty(){
			if(top==-1){
				return true;
			}else{
				return false;
			}
		} 
		
		bool isFull(){
			if(top==4){
				return true;
			}else{
				return false;
			}
		}
		
		void push(int val){
			if(isFull())
				cout << "Stack OverFlow!!";
			else{
				top++;
				arr[top] = val;
			}
		}
		
		int pop(){
			if(isEmpty())
				cout << "Stack UnderFlow!!";
			else{
				int x = arr[top];
				arr[top]=0;
				top--;
				return x;	
			}	
		}
		
		int count(){
			return(top+1);
		}
		
		int peek(int pos){
			if(isEmpty())
				cout << "Stack Empty!!";
			else{
				return arr[pos];
			}
		}
		
		void change(int pos,int val){
			if(isEmpty())
				cout << "Stack Empty!!";
			else{
				arr[pos]=val;
				cout<<"Item channged";
			}
		}
		
		void display(){
			cout << "STACK:" << endl;
			for(int i=4;i>=0;i--){
				cout << arr[i] << "\n";
			}
		}
};

int main(){
	Stack s;
	s.push(2);
	s.push(13);
	s.push(100);
	s.count();
	int x=s.pop();
	cout << x<< endl;
	s.push(101);
	s.display();
	return 0;
}

