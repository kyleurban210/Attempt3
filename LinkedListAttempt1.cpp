
#include <iostream>
#include <ctime>



class Node
{

public: 

	 Node(); 
	 Node(int n); 
	 Node(int n, Node* ptr); 
	 int data;
	 Node* next; 

};

Node::Node()
{

	data = 0;
	next = nullptr; 


}

Node::Node(int n)
{

	data = n; 

}

Node ::Node(int n, Node* ptr)
{

	data = n; 
	next = ptr; 


}


//function prototypes
Node* connector(Node* nodeptr, int input); 
Node* newNode(int input); 
void traverse(Node* nodeptr);
void test(int input); 



Node* connector(Node* nodeptr, int input)
{
	bool makenew = 0;
	
	if (nodeptr == NULL)
	{
		
			return newNode(input); 

		
		

	}
	else
	{

		nodeptr->next = connector(nodeptr->next, input);

	}



	return nodeptr;

	

}

Node* newNode(int input)
{

	Node* node = new Node(input); 
	return node; 


}

void traverse(Node* nodeptr)
{
	//anchor; keeps going till one of the pointers doesn't go to anything
	if (nodeptr == NULL)
	{
		return;
	}
	else
	{

		std::cout << nodeptr->data << " , ";

		traverse(nodeptr->next); //moves us over to the next datapoint
	}


}

void test(int input)
{




}


int main()
{

	srand(time(0)); 

	Node* start = new Node(1, nullptr); 
	start = connector(start, 8); 
	start = connector(start, 9); 

	traverse(start);

	std::cout << "\n"; 

	for (int i = 0; i < rand() % 20; i++)
	{

		start = connector(start, rand() % 20); 

	}

	traverse(start); 
	test(4); 



}