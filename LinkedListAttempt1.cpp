
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
Node* connector(Node* nodeptr, int input, bool make_new); 
Node* newNode(int input); 
int traverse(Node* nodeptr, bool display, int num_nodes);
 
Node* partial_traverse(Node* nodeptr, int num_nodes, int desired_node, int iterator); 
Node* insert_at_node(Node* nodeptr, int desired_node); 

 



Node* connector(Node* nodeptr, int input, bool make_new)
{
	bool makenew = 0;
	
	if (nodeptr == NULL)
	{
		if (make_new)
		{
			return newNode(input);

		}
		else
		{

			return nullptr; 

		}
		

	}
	else
	{

		nodeptr->next = connector(nodeptr->next, input, make_new);
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

Node* partial_traverse(Node* nodeptr, int num_nodes, int desired_node, int iterator)
{

	if (desired_node > num_nodes)
	{
		std::cout << "\n**DESIRED NODE DOES NOT EXIST**\n"; 

		return nullptr; 

	}

	if (iterator >= desired_node)
	{

		return nodeptr; //returns the current node 

	}
	else
	{

		std::cout << nodeptr->data << " , ";
		iterator++; 
		partial_traverse(nodeptr->next, num_nodes, desired_node, iterator); 

	}

	




}

Node* insert_at_node(Node* nodeptr, int desired_node)
{

	Node* temp; 
	
	int input; 

	temp = nodeptr->next;

	std::cout << "\nWhat is the data for this new node? ";
	std::cin >> input;

	nodeptr->next = newNode(input); 

	return nodeptr; 



}


int main()
{
	bool display = 0;
	srand(time(0)); 
	int num_nodes = 0;
	int iterator = 0;
	int desired_node = 0; 

	Node* start = new Node(1, nullptr); 
	Node* desired; //stores the desired node. 
	Node* temp; 
	start = connector(start, 8, 1); 
	
	start = connector(start, 9, 1); 

	std :: cout << "\n Number of nodes here: " << traverse(start, 1, num_nodes);
	
	std::cout << "\n"; 

	for (int i = 0; i < rand() % 20; i++)
	{

		start = connector(start, rand() % 20, 1); 

	}

	std::cout << "wanna display? 1 for Yes, 0 for no? ";
	std::cin >> display; 


	num_nodes =  traverse(start, display, num_nodes);
	std::cout << "\n Number of nodes here: " << num_nodes; 
	

	std::cout << "\nHow many nodes to you want to traverse? ";
	std::cin >> desired_node; 

	desired = partial_traverse(start, num_nodes, desired_node, iterator);

	if (desired == nullptr)
	{
		std::cout << "\n you went to the final node"; 
	}
	else
	{
		std::cout << "\n the contents of the node you stopped on is: " << desired->data;

	}


	 

	temp = insert_at_node(desired, desired_node); 
	temp = connector(temp, temp->data, 0); //hope this works

	traverse(start, 1, num_nodes);

	//std::cout << " \n The data of the final node is: " << end->data;

}