
#include <iostream>

using namespace std;

class Node{
	public:
	int data;
	int key;
	Node* next;

	Node(){
		key=0;
		data=0;
		next=NULL;
	}
	Node(int k,int d){
		key=k;
		data = d;
	}
};

class SinglyLinkedList{
	public:
	Node* head;

	SinglyLinkedList(){
		head=NULL;
	}	
	SinglyLinkedList(Node *n){
		head=n;
	}
	//check
	Node* nodeExists(int k){
		Node* temp=NULL;
		Node* ptr=head;
		while(ptr != NULL){
			if(ptr->key==k){
				temp=ptr;
			}
			ptr = ptr->next;
		}
		return temp;
		cout << endl;
	}
	//append
	void appendNode(Node* n){
		if(nodeExists(n->key)!=NULL){   //if not NULL, means it exist
			cout << "Node already exist!!";
		}
		else{
			if(head==NULL){
				head=n;
				cout << "Node appended!";
			}
			else{
				Node* ptr=head;
				while(ptr->next != NULL){
					ptr = ptr->next;
				}
				ptr->next = n;
				cout<<"Node Appended!!";

			}
		}
		cout << endl;
	}

	//prepend
	void prependNode(Node* n){
		if(nodeExists(n->key)!=NULL){   //if not NULL, means it exist
			cout << "Node already exist!!";
		}
		else{
			if(head==NULL){
				head=n;
				cout << "Node appended!";
			}
			else{
				n->next=head;
				head = n;
				cout << "Node prepended!";
			}

		}
		cout << endl;
	}

	//insert a node after a specified node
	void insertNodeAfter(int k,Node* n){
		Node* ptr = nodeExists(k);
		if(ptr==NULL){
			cout << "No such node exist";
		}
		else{
			n->next=ptr->next;
			ptr->next = n;
			cout <<"Node Inserrted!";	
		}
		cout << endl;
	}
	//delete node by key
	void deleteNodeByKey(int k){
		if(head==NULL){
			cout <<"List is empty";
		}
		else if(head!=NULL){
			Node *temp=NULL,*prevptr=NULL,*currptr=NULL;
			while(currptr !=NULL){
				if(currptr->key==k){
					temp=currptr;
					currptr=NULL;
				}
				else{
					prevptr=prevptr->next;
					currptr=currptr->next;
				}
			}
			if(temp!=NULL){
				prevptr->next = temp-> next;
				cout << "Node Unlinked!";
			}
			else{
				cout << "Node doesnt exist!";
			}
		}
		cout << endl;
	}

	//update node
	void updateNodeByKey(int k,int d){
		Node* ptr=nodeExists(k);
		if(ptr!=NULL){
			ptr->data = d;
			cout << "Data updated succesfully!";
		}
		else{
			cout << "node doesnt exist!";
		}
		cout << endl;
	}

	//print
	void printList(){
		if(head==NULL){
			cout <<"Linked list is empty!";
		}
		else{
			cout << "Values: ";
			Node* temp=head;
			while(temp!=NULL){
				cout << temp->key << "|" << temp->data << " -->";
				temp=temp->next;
			}
		}
		cout << endl;
	}


};

int main(){
	SinglyLinkedList s;
	int n=0;
	cin >> n;
	int i=0,d=0;
	for(int i=0;i<n;i++){
		Node* n1 = new Node();
		cin >> n1->data;
		n1->key=i;
		s.prependNode(n1);
	}
	s.printList();
	
	return 0;
}

/*
int main() {
SinglyLinkedList s;
  int option;
  int key1, k1, data1;
  do {
    cout << "\nWhat operation do you want to perform? Select Option number. Enter 0 to exit." << endl;
    cout << "1. appendNode()" << endl;
    cout << "2. prependNode()" << endl;
    cout << "3. insertNodeAfter()" << endl;
    cout << "4. deleteNodeByKey()" << endl;
    cout << "5. updateNodeByKey()" << endl;
    cout << "6. print()" << endl;
    cout << "7. Clear Screen" << endl << endl;
 
    cin >> option;
    Node * n1 = new Node();
    //Node n1;
 
    switch (option) {
    case 0:
      break;
    case 1:
      cout << "Append Node Operation \nEnter key & data of the Node to be Appended" << endl;
      cin >> key1;
      cin >> data1;
      n1 -> key = key1;
      n1 -> data = data1;
      s.appendNode(n1);
      //cout<<n1.key<<" = "<<n1.data<<endl;
      break;
 
    case 2:
      cout << "Prepend Node Operation \nEnter key & data of the Node to be Prepended" << endl;
      cin >> key1;
      cin >> data1;
      n1 -> key = key1;
      n1 -> data = data1;
      s.prependNode(n1);
      break;
 
    case 3:
      cout << "Insert Node After Operation \nEnter key of existing Node after which you want to Insert this New node: " << endl;
      cin >> k1;
      cout << "Enter key & data of the New Node first: " << endl;
      cin >> key1;
      cin >> data1;
      n1 -> key = key1;
      n1 -> data = data1;
 
      s.insertNodeAfter(k1, n1);
      break;
 
    case 4:
 
      cout << "Delete Node By Key Operation - \nEnter key of the Node to be deleted: " << endl;
      cin >> k1;
      s.deleteNodeByKey(k1);
 
      break;
    case 5:
      cout << "Update Node By Key Operation - \nEnter key & NEW data to be updated" << endl;
      cin >> key1;
      cin >> data1;
      s.updateNodeByKey(key1, data1);
 
      break;
    case 6:
      s.printList();
 
      break;
    case 7:
      system("cls");
      break;
    default:
      cout << "Enter Proper Option number " << endl;
    }
 
  } while (option != 0);
 
  return 0;
	
}
*/

