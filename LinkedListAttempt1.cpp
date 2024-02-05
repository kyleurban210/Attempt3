
//I am going to try to an an inserter


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
	 //Node* prev; 

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
int traverse(Node* nodeptr, bool display, int num_nodes);
void test(int input); 
void partial_traverse(Node* nodeptr, int num_nodes, int desired_node, int iterator); 
 



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
		//nodeptr->prev = reverseconnector(nodeptr->prev); 
		

	}



	return nodeptr;

	

}






Node* newNode(int input)
{

	Node* node = new Node(input); 
	return node; 


}

int traverse(Node* nodeptr, bool display, int num_nodes)
{
	//anchor; keeps going till one of the pointers doesn't go to anything
	if (nodeptr == NULL)
	{
		return num_nodes ; //spits out the end node so that it can be stored
	}
	else
	{
		if (display)
		{
			std::cout << nodeptr->data << " , ";
		}

		num_nodes++; 
		traverse(nodeptr->next, display, num_nodes); //moves us over to the next datapoint
	}


}

void partial_traverse(Node* nodeptr, int num_nodes, int desired_node, int iterator)
{

	if (desired_node > num_nodes)
	{
		std::cout << "\n**DESIRED NODE DOES NOT EXIST**\n"; 

		return; 

	}

	if (iterator >= desired_node)
	{

		return; 

	}
	else
	{

		std::cout << nodeptr->data << " , ";
		iterator++; 
		partial_traverse(nodeptr->next, num_nodes, desired_node, iterator); 

	}

	




}

void test(int input)
{




}


int main()
{
	bool display = 0;
	srand(time(0)); 
	int num_nodes = 0;
	int iterator = 0;
	int desired_node = 0; 

	Node* start = new Node(1, nullptr); 
	//Node* end; //stores the end node. 
	start = connector(start, 8); 
	
	start = connector(start, 9); 

	std :: cout << "\n Number of nodes here: " << traverse(start, 1, num_nodes);
	
	std::cout << "\n"; 

	for (int i = 0; i < rand() % 20; i++)
	{

		start = connector(start, rand() % 20); 

	}

	std::cout << "wanna display? 1 for Yes, 0 for no? ";
	std::cin >> display; 


	num_nodes =  traverse(start, display, num_nodes);
	std::cout << "\n Number of nodes here: " << num_nodes; 
	test(4); 

	std::cout << "\nHow many nodes to you want to traverse? ";
	std::cin >> desired_node; 

	partial_traverse(start, num_nodes, desired_node, iterator); 




	//std::cout << " \n The data of the final node is: " << end->data;

}