#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <climits>

using namespace std;

struct Node {
	
	int data;
	struct Node* next;
};

Node* head  = NULL;

bool enqueue(const int index){

	Node* temp1 = new Node();
	temp1->data = index;
	temp1->next = NULL;
	
	if (head == NULL){
		temp1->next = NULL;
		head = temp1;
		return 1;
	}
	Node* temp2 = head; 
	
	if( index < temp2->data){
		temp1->next = head;
		head = temp1;
		return 1;
	}
	
	for(int i = 0; index >= temp2->data; i++){
		
		if(temp2->next == NULL){
			temp1->next = NULL;
			temp2->next = temp1;
			return 1;
		}
		if (temp2->next->data > index){
			break;
		}
		else{
			temp2 = temp2->next;
		}
	}
	temp1->next = temp2->next;
	temp2->next = temp1;
	
	
	return 1;
}

const int dequeue(){
	
	Node* temp1 = new Node();
	if(head == NULL){
		return 0;
	}
	else{
		temp1 = head;
		head = temp1->next;
		return temp1->data;
	}
}

Node* findNodeat(int index){
	
	Node* runner = new Node();
	runner = head;
	
	if (runner == NULL){
		return NULL;
	}
	
	
	for (int i=0; i < index; i++){
		
		if(runner == NULL){
			cout<<"end";
			return NULL;
		}
		runner = runner->next;
	}
	
	return runner;
}
/*
void queue(int data){
	
	Node* node = new Node();
	node-> data = data;
	
	Node* temp = new Node();
	node->next = findNodeat(index);
	if (index > 0){
		temp = findNodeat(index-1);
		temp->next = node;
	}
}*/

void print(){
	Node* node = new Node();
	node = head;
	cout<<endl;
	for(int i = 0; node != 0; i++){
		cout<<"Position "<<i<<" contains " << node->data<<endl;
		//cout<<i<<endl;
		node = node->next;
		if (node == NULL){
			return;
		}

	}
}

bool queue(int data){
	
	Node* node = new Node();
	node->data = data;
	node->next = head;
	head = node;
	
	cout<<"Node "<< data << " added to the queue."<<endl;
	
	print();
	
	return 1;
}

int main(){
	
	int input;
	
	cout<< "Enter number of nodes: ";
	cin>> input;
	
	int count = 0;
	
	while(count < input){
		int data;
		data = rand()%100 + 1;
		if (!enqueue(data)) {
			cerr << "Error: unable to enqueue.  Exiting" << endl;
			exit(-1);
		}
		cout<<data<<endl;
		count++;
	}
	
	cout<<endl<<"dequeueing..."<<endl;
	int currentdata = head->data;
	while(currentdata != 0){
		currentdata = dequeue();
		cout<<currentdata<<endl;
	}
	
	bool done = false;
	int data;
	
	while(!done){
	
		cout<<"Enter -1 to end queueing."<<endl<<"Enter data of node: ";
		cin>>data;
		if(data == -1){
			done = true;
			continue;
		}
		queue(data);
		cout<<endl;
		
	}
	done = false;
	int index;
	cout<<endl<<endl;
	while(!done){
		
		cout<<"Enter -1 to end index search."<<endl<<"Enter index of node: ";
		cin>>index;
		if(index == -1){
			done = true;
			continue;
		}
		Node* node = new Node();
		node = findNodeat(index);
		cout<<endl<<"Node at index " <<index<<" contains data - "<<node->data<<endl<<endl;
		
	}
	
	return 1;

}