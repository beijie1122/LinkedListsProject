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
}

int LengthofLL(Node* head)
{
	Node* temp = head;
	int Counter = 0;

	while (temp != NULL)
	{
		Counter++;
		temp = temp->next;
	}

	return Counter;
}

void PrintIthNode(Node* head, int i)
{
	if (i < 0)
	{
		std::cout << "-1" << "\n";
		return;
	}
	Node* temp = head;
	int Counter = 1;

	while (Counter <= i && head!=NULL)
	{
		temp = temp->next;
		Counter++;
	}
	if (head)
	{
		std::cout << temp->data << "\n";
	}
	else
	{
		std::cout << "-1" << "\n";
	}
	
}

Node* InsertElementatLocation(Node* head, int Data, int i)
{
	if (i < 0)
	{
		return head;
	}
	if (i == 0)
	{
		Node* n = new Node(Data);
		n->next = head;
		head = n;
		return head;
	}

	Node* copyHead = head;

	int Insertcounter = 1;

	while (Insertcounter <= i - 1 && head != NULL)
	{
		head = head->next;
		Insertcounter++;

	}
	if (head)
	{
		Node* n = new Node(Data); //Generate new node with data 
		n->next = head->next; //Connects next of head to the front of the new node 
		head->next = n; //updates next of head, hooks up to the back of new node n 
		return copyHead;
	}
	return copyHead;

}

Node* InsertMethodTwo(Node* head, int Data, int i)
{
	if (i <= 0)
	{
		return head;
	}
	if (i == 0)
	{
		Node* n = new Node(Data);
		n->next = head;
		head = n;
		return head;
	}

	int Counter = 1;

	Node* CopyHead = head;

	while (head != NULL && Counter <= i - 1)
	{
		head = head->next;
		Counter++;
	}
	if (head)
	{
		Node* TempNext = head->next;
		Node* n = new Node(Data);
		head->next = n;
		n->next = TempNext;
		return CopyHead;
	}
	return CopyHead;
}

Node* DeleteIthNode(Node* head, int i)
{
	if (i < 0)
	{
		return head;
	}
	if (i == 0 && head) //or else runtime error if we do not include head check
	{
		Node* newHead = head->next;
		head = head->next;
		delete head;
		return newHead;
	}

	int DeleteCounter = 1;

	Node* Current = head;

	while (head != NULL && DeleteCounter <= i-1)
	{
		Current = Current->next;
		DeleteCounter++;
	}

	if (Current && Current->next) // Check Current->next to avoid runtime error or when n is more than the length of the LL 
	{
		//Node* TempNext = head->next;
		//TempNext = TempNext->next;
		//head->next = TempNext;
		Node* TempHead = Current->next;
		Current->next = Current->next->next;
		TempHead->next = NULL;
		delete TempHead;
		return head;
	}
	return head;

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
	int PositionToPrint;

	Node* DynamicHead = TakeInput();
	print(DynamicHead);
	//counter = LengthofLL(DynamicHead);
	//std::cout << "The LL length is: " << counter << "\n";
	//std::cout << "What element do you want to print: ";
	//std::cin >> PositionToPrint;
	//PrintIthNode(DynamicHead, PositionToPrint);

	int Placement = 2;

	//DynamicHead = InsertElementatLocation(DynamicHead, 15, Placement);
	DynamicHead = InsertMethodTwo(DynamicHead, 15, Placement);
	print(DynamicHead);

	DynamicHead = DeleteIthNode(DynamicHead, 4);
	print(DynamicHead);

//	Node* HeadUpdate = TakeInput2();
//	print(HeadUpdate, counter);

	

	return 0;
}