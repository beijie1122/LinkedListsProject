#include <iostream>
#include "Node.h"
#include <vector>

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

int LengthofLLRecursive(Node* head)
{
	Node* temp = head;
	
	if (temp == NULL)
	{
		return 0;
	}
	int smallAnswer = LengthofLLRecursive(temp->next);

	return 1 + smallAnswer;
	
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

bool IsElementPresent(Node* head, int Value)
{
	Node* temp = head;

	while (temp)
	{
		if (temp->data == Value)
		{
			return true;
		}
		temp = temp->next;	
	}
	return false;

}

bool IsElementPresentRec(Node* head, int Value)
{
	Node* temp = head;

	if (temp == NULL)
	{
		return false;
	}
	if (temp->data == Value)
	{
		return true;
	}

	return IsElementPresentRec(temp->next, Value);
}

Node* FindMiddleElementData(Node* head)
{
	//Node* temp = head;

	Node* SlowPtr = head;

	Node* FastPtr = head->next;

	while (FastPtr && FastPtr->next)
	{
		SlowPtr = SlowPtr->next;
		FastPtr = FastPtr->next->next;
	}
	if (FastPtr) // EVEN Length 
	{
		return SlowPtr->next;
	}
	return SlowPtr;
}

Node* ReverseLL(Node* head)
{
	Node* Current = head;
	Node* Previous = NULL;

	while (Current)
	{
		Node* n = Current->next;
		Current->next = Previous;

		Previous = Current;
		Current = n;
	}

	return Previous;

}

Node* DeleteIthNodeFromEnd(Node* head, int RemovedSpace)
{
	Node* FirstPtr = head;
	Node* SecondPtr = head;

	while (RemovedSpace--)
	{
		SecondPtr = SecondPtr->next;
	}

	if (SecondPtr == NULL) // For if RemovedSpace = LL Length 
	{
		return FirstPtr->next;
	}

	while (SecondPtr->next != NULL)
	{
		SecondPtr = SecondPtr->next;
		FirstPtr = FirstPtr->next;
	}

	FirstPtr->next = FirstPtr->next->next;

	return head;

}

//Node* MergeTwoSortedLL(Node* Head1, Node* Head2)
//{

//}

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

Node* TakeInputFromVector(std::vector<int> Values)
{
	Node* head = NULL;
	Node* tail = NULL;

	for (int i = 0; i < Values.size(); i++)
	{
		Node* n = new Node(Values.at(i));

		if (head == NULL)
		{
			head = n;
			tail = n;
		}
		else
		{
			tail->next = n;
			tail = n;
		}

	}
	return head;

}

Node* MergeTwoLists(Node* LL1, Node* LL2)
{
	if (LL1 == NULL)
	{
		return LL2;
	}
	if (LL2 == NULL)
	{
		return LL1;
	}

	Node* FinalHead = NULL; // Head of the list we want to return 
	

	if (LL1->data < LL2->data)
	{
		FinalHead = LL1;
		LL1 = LL1->next;
	}
	else
	{
		FinalHead = LL2;
		LL2 = LL2->next;
	}
	Node* FinalTail = FinalHead; //Used to establish links, useless for other usage 

	while (LL1 && LL2)
	{
		if (LL1->data < LL2->data)
		{
			FinalTail->next = LL1;
			LL1 = LL1->next;
		}
		else
		{
			FinalTail->next = LL2;
			LL2 = LL2->next;
		}
		FinalTail = FinalTail->next;
	}
	if (LL1)
	{
		FinalTail->next = LL1;
	}
	else
	{
		FinalTail->next = LL2;
	}

	return FinalHead;


}

Node* SortedMerge(Node* a, Node* b)
{
	Node* result = NULL;

	if (a == NULL)
	{
		return b;
	}
	else if (b == NULL)
	{
		return a;
	}

	if (a->data < b->data)
	{
		result = a;
		result->next = SortedMerge(a->next, b);
	}
	else
	{
		result = b;
		result->next = SortedMerge(a, b->next);
	}

	return result;

}

Node* SortLL(Node* head)
{

	if (head == NULL || head->next == NULL)
	{
		return head;
	}
	///break list into two halves 

	Node* SlowPtr = head;
	Node* FastPtr = head->next;

	while (FastPtr && FastPtr->next)
	{
		SlowPtr = SlowPtr->next;
		FastPtr = FastPtr->next->next;
	}

	//Now SlowPtr is at middle node 
	Node* SecondHalf = SlowPtr->next; //make this to avoid missing the link when breaking

	SlowPtr->next = NULL; //Now Broken 

	std::cout << "Printing: ";

	print(head);

	Node* a = SortLL(head);
	Node* b = SortLL(SecondHalf);

	head = SortedMerge(a, b);

	return head;
}

void FrontBackSplit(Node* source, Node** frontRef, Node** backRef)
{
	Node* fast;
	Node* slow;
	slow = source;
	fast = source->next;

	while (fast != NULL)
	{
		fast = fast->next;
		if (fast != NULL)
		{
			slow = slow->next;
			fast = fast->next;
		}
	}

	*frontRef = source;
	*backRef = slow->next;
	slow->next = NULL;
}

Node* SortedMergeOnline(Node* a, Node* b)
{
	Node* result = NULL;

	if (a == NULL)
	{
		return b;
	}
	else if (b == NULL)
	{
		return a;
	}

	if (a->data <= b->data)
	{
		result = a;
		result->next = SortedMergeOnline(a->next, b);
	}
	else
	{
		result = b;
		result->next = SortedMergeOnline(a, b->next);
	}
	return result;
}

void MergeSortOnline(Node** headRef)
{
	Node* head = *headRef;
	Node* a;
	Node* b;

	if (head == NULL || head->next == NULL)
	{
		return;
	}

	FrontBackSplit(head, &a, &b);

	MergeSortOnline(&a);
	MergeSortOnline(&b);

	*headRef = SortedMergeOnline(a, b);

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

	Node* TestLL;

	Node* TestLL2;

	Node* TestLL3;

	std::vector<int> TestLLValues = { 10, 20, 30, 40, 50 };

	std::vector<int> TestLL2Values = { 1, 21, 29, 42, 47 };

	std::vector<int> TestLL3Values = {1, 30, 15, 2, 12, 3, 10, 5};

	TestLL = TakeInputFromVector(TestLLValues);

	TestLL2 = TakeInputFromVector(TestLL2Values);

	TestLL3 = TakeInputFromVector(TestLL3Values);

	print(TestLL);

	print(TestLL2);

	print(TestLL3);

	//SortLL(TestLL3);

	MergeSortOnline(&TestLL3);

	std::cout << "Merge Sort Attempted!" << "\n";

	print(TestLL3);

	TestLL = MergeTwoLists(TestLL, TestLL2);

	std::cout << "Listed Merged Successfully!" << "\n";

	print(TestLL);

	Node* DynamicHead = TakeInput();
	print(DynamicHead);
	//counter = LengthofLL(DynamicHead);
	//std::cout << "The LL length is: " << counter << "\n";
	//std::cout << "What element do you want to print: ";
	//std::cin >> PositionToPrint;
	//PrintIthNode(DynamicHead, PositionToPrint);

	int Length = 0;

	Length = LengthofLLRecursive(DynamicHead);

	bool IsPresent = false;

	IsPresent = IsElementPresent(DynamicHead, 0);

	std::cout << IsPresent << "\n";

	std::cout << "The LL Length is: " << Length << "\n";

	int Placement = 2;

	Node* MidPoint;

	MidPoint = FindMiddleElementData(DynamicHead);

	std::cout << "The Value of the MidPoint is: " << MidPoint->data << "\n";

	DynamicHead = DeleteIthNodeFromEnd(DynamicHead, 2);

	std::cout << "Deleted an element" << "\n";

	print(DynamicHead);

	DynamicHead = ReverseLL(DynamicHead);

	print(DynamicHead);

	//DynamicHead = InsertElementatLocation(DynamicHead, 15, Placement);
	DynamicHead = InsertMethodTwo(DynamicHead, 15, Placement);
	print(DynamicHead);

	DynamicHead = DeleteIthNode(DynamicHead, 4);
	print(DynamicHead);

//	Node* HeadUpdate = TakeInput2();
//	print(HeadUpdate, counter);

	

	return 0;
}