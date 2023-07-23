#include <iostream>
#include "Node.h"

void print(Node* head)
{
	//Helps so the head is constantly at the begining of the linked list 
	Node* temp = head;

	while (temp != NULL)
	{
		std::cout << temp->data << "\n";
		temp = temp->next;
	}

	temp = head;
	while (temp != NULL)
	{
		std::cout << temp->data << "\n";
		temp = temp->next;
	}
}

int main()
{

	//Exercise 1 

	//Creating an object statically 

	Node n1(1);
	Node n2(2);

	n1.next = &n2;

	std::cout << n1.data << " " << n2.data << "\n";

	Node* head = &n1;

	std::cout << head->data << "\n";

	//Creating nodes dynamically 

	Node* n3 = new Node(3);
	Node* n4 = new Node(4);

	n3->next = n4; //not *n4 because n4 is pointing to data, it is already an address 


	//Exercise 2 

	Node Node1(1);
	
	Node Node2(2);
	
	Node Node3(3);
	
	Node Node4(4);
	
	Node Node5(5);
	Node* Nexthead = &Node1;
	Node1.next = &Node2;
	Node2.next = &Node3;
	Node3.next = &Node4;
	Node4.next = &Node5;

	print(Nexthead);

	return 0;
}