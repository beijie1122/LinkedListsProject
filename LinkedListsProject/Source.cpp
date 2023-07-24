#include <iostream>
#include "Node.h"

void print(Node* head, int &Counter)
{
	//Helps so the head is constantly at the begining of the linked list 
	Node* temp = head;

	while (temp != NULL)
	{
		std::cout << temp->data << "\n";
		temp = temp->next;
		Counter++;
	}
}

Node* TakeInput()
{
	int UserData;
	std::cin >> UserData;
	Node* head = NULL; //LL is empty RN
	Node* tail = NULL; //Cause LL is not yet created

	while (UserData != -1)
	{
		Node *n = new Node(UserData);
		//This Code makes linklist 
		//MUST use dynamic memory to make sure nodes are not deleted 
		//Check if node is first 
		if (head == NULL)
		{
			head = n;
			tail = n;
		}
		else
		{
			tail->next = n; //Updates the memory for next 
			tail = n;
		}
		
		std::cin >> UserData;
	}
	return head;
}

Node* TakeInput2()
{
	int UserData;
	std::cin >> UserData;
	Node* head = NULL; //LL is empty RN
	Node* tail = NULL; //Cause LL is not yet created

	while (UserData != -1)
	{
		Node* n = new Node(UserData);
		//This Code makes linklist 
		//MUST use dynamic memory to make sure nodes are not deleted 
		//Check if node is first 
		if (head == NULL)
		{
			head = n;
			tail = n;
		}
		else
		{
			n->next = head; //Updates at head
			head = n;
		}

		std::cin >> UserData;
	}
	return head;
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

	//print(Nexthead);

	int counter = 0;

	Node* DynamicHead = TakeInput();
	print(DynamicHead, counter);
	std::cout << "The LL length is: " << counter << "\n";
//	Node* HeadUpdate = TakeInput2();
//	print(HeadUpdate, counter);

	

	return 0;
}