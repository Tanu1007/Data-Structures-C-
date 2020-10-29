//Doubly Linked List
/*

*/

#include <iostream>

using namespace std;

class Node{
	public:
		int data;
		int key;
		Node* previous;
		Node* next;
		
		Node(){
			key=0;
			data=0;
			previous=NULL;
			next=NULL;
		}
		
		Node(int k,int d){
			key=k;
			data=d;
		}
};

class DoublyLinkedList{
	
	public:
		Node* head;
		DoublyLinkedList(){
			head=NULL;
		}
		DoublyLinkedList(Node* n){
			head=n;
		}
		
		//Check if a node exist
		Node* checkIfExists(int k){
			Node* temp=NULL;
			Node* ptr=head;
			
			while(ptr!=NULL){
				if(ptr->key==k){
					temp=ptr;
				}
				ptr=ptr->next;
			}
			return temp;
		}
		
		//appending
		void appendNode(Node* n){
			
			if(checkIfExists(n->key)!=NULL){
				cout << "Node already exist!!";
			}else{
				if(head==NULL){
					head=n;
					cout << "Head Node Appended !!";
				}else{
					Node *ptr=head;
					while(ptr->next!=NULL){
						ptr=ptr->next;
					}
					ptr->next=n;
					n->previous=ptr;
					cout << "Node appended !!";   
				}
			}
			cout << endl;
		}
		
		void prependNode(Node* n){
			if(checkIfExists(n->key)!=NULL){
				cout << "Node already exist!!";
			}else{
				if(head==NULL){
					head=n;
					cout << "Head Node prepended !!";
				}else{
					Node *ptr=head;
					head->previous=n;
					n->next=head;
					
					head=n;
					cout << "Node prepended !!";    
				}	
			}
			cout << endl;
		}
		
		void insertNode(int k,Node* n){
			Node*ptr=checkIfExists(k);
			if(ptr==NULL){
				cout << "No such key exists!!";
			}else{
				if(checkIfExists(n->key)!=NULL){
					cout << "Node already exist with this key !!";
				}
				else{
					Node* nextnode = ptr->next;
					
					if(nextnode==NULL){
						//appendNode(n);
						ptr->next = n;
						n->previous = ptr;
						cout << "Node inserted !!";
					}else{
						ptr->next = n;
						n->previous=ptr;
						n->next=nextnode;
						nextnode->previous=n;
						cout << "Node inserted !!";
					} 
				}
			}
			cout << endl;
		}
		
		void deleteNode(int k){
			Node *ptr = checkIfExists(k);
			if(ptr==NULL){
				cout << "No such node exists to delete";
			}
			else{
				if(head->key == k){
					head = head->next;
					cout << "Head node unlinked";
				}else{
					Node *nextNode=ptr->next,*preNode=ptr->previous;
					if(nextNode==NULL){
						preNode->next=NULL;
						cout << "Tail node unlinked";
					}else{
						preNode->next = nextNode;
						nextNode->previous = preNode;
						
						cout << "Node unlinked";
					}
				}
			}
			cout << endl;
		}
		
		void updateNode(int k,int d){
			Node *ptr = checkIfExists(k);
			if(ptr==NULL){
				cout << "No such node exists!!";
			}else{
				ptr->data = d;
				cout << "Value updated";
			}
			cout << endl;
		}
		
		void display(){
			if(head==NULL) cout << "Doubly Linked list is empty!!";
			else{
				Node *ptr = head;
				cout << "VALUES: ";
				while(ptr->next!=NULL){
					cout << "(" << ptr->key << "," << ptr->data << ")" << " <---> ";
					ptr=ptr->next;
				}
				cout << "(" << ptr->key << "," << ptr->data << ")";
			}
			cout << endl;
		}
};

int main(){
	DoublyLinkedList d1;
	int n=0;
	cin >> n;
	int i=0,d=0;
	for(int i=0;i<n;i++){
		Node* n1 = new Node();
		cin >> n1->data;
		n1->key=i;
		d1.appendNode(n1);
	}
	//d1.reverseLinkList();
	d1.display();
	
}
