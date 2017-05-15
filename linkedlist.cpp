#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <climits>

using namespace std;

struct Node {
	
	int data;
	struct Node* next;
};

class Linkedlist{
	private:
		int length = 0;
		Node* head = NULL;
		
	public:
		int* getLength(void);
		Linkedlist();
		Node* getHead(void);
		int getDataAtHead(void);
		void addNode(int data);
		void removeNode(int index);
		Node* findNodeAt(int index);
		void print(void);
		void sortAscending(void);
		void sortDescending(void);
		
};

Linkedlist::Linkedlist(void){
	cout<<"linkedlist created"<<endl;
}

int* Linkedlist::getLength(void){
	return  &length;
}

Node* Linkedlist::getHead(void){
	return head;
}

int Linkedlist::getDataAtHead(void){
	return head->data;
}

void Linkedlist::print(void){
	Node* node = new Node();
	node = getHead();
	cout<<endl;
	for(int i = 0; node != 0; i++){
		cout<<"Position "<<i<<" contains " << node->data<<endl;
		node = node->next;
		if (node == NULL){
			return;
		}

	}
}
void Linkedlist::addNode(int data){
	Node* node = new Node();
	node->data = data;
	node->next = head;
	head = node;
	
	cout<<"Node "<< data << " added to the queue."<<endl;
	int* length = getLength();
	*length += 1;
	cout<<*length;
	print();
}

void Linkedlist::removeNode(int index){
	Node* node = new Node();
	node = head;
	Node* temp = new Node();
	temp = head;
	for(int i = 0; i < index; i ++){
		node = node->next;
	}
	for(int j = 0; j < index+1; j++){
		temp = temp->next;
	}
	node->next = temp->next;
	temp = NULL;
	
}

Node* Linkedlist::findNodeAt(int index){
	
	
	Node* runner = new Node();
	runner = getHead();
	int* length = getLength();
	int l = *length;
	if(index+1>l){
		
		return NULL;
	}

	if (runner == NULL){
		return NULL;
	}
	
	for (int i=0; i < index; i++){
		
		runner = runner->next;
	}
	
	return runner;
	
}
void Linkedlist::sortAscending(void){
	

	
}

int main(){
	
	Linkedlist list;
	
	bool done = false;

	int data;
	
	while(!done){
	
		cout<<"Enter -1 to end queueing."<<endl<<"Enter data of node: ";
		while(!(cin >> data)){
			cout << "Bad value!"<<endl;
			cin.clear();
			cin.ignore();
		}
		if(data == -1){
			done = true;
			continue;
		}
		list.addNode(data);
		cout<<endl;
		
	}
	done = false;
	
	int index;
	cout<<endl<<endl;
	while(!done){
		
		cout<<"Enter -1 to end index search."<<endl<<"Enter index of node: ";
		while(!(cin >> index)){
			cout << "Bad value!"<<endl;
			cin.clear();
			cin.ignore();
		}
		if(index == -1){
			done = true;
			continue;
		}
		Node* node = new Node();
		if (list.findNodeAt(index) != NULL){
			node = list.findNodeAt(index);
			cout<<endl<<"Node at index " <<index<<" contains data - "<<node->data<<endl<<endl;
		}
		else{
			cerr<< "Error: Index out of range"<<endl<<endl;
		}
	}
	done = false;
	
	while(!done){
		
		cout<<"Enter -1 to end node remove."<<endl<<"Enter index of node to remove: ";
		while(!(cin >> index)){
			cout << "Bad value!"<<endl;
			cin.clear();
			cin.ignore();
		}
		
		if(index == -1){
			done = true;
			continue;
		}
		Node* node = new Node();
		if (list.findNodeAt(index) != NULL){
			list.removeNode(index);
			cout<<endl<<"Node at index " <<index<<" contains data - "<<node->data<<endl<<endl;
		}
		else{
			cerr<< "Error: Index out of range"<<endl<<endl;
		}
	}
	
	list.print();
	
	return 1;

}
