#include <iostream>

struct Node {
	int data;
	Node* next;
};

class LinkedList {

private:
	Node* head = nullptr;

public:

	void printList() {
		Node* tmp = head;
		
		if (head == nullptr)
		{
			std::cout << "[Empty]\n";
			return;
		}

		int i = 0;
		while (tmp != nullptr)
		{
			std::cout << "[" << i << "]" << "(" << tmp->data << ")" << std::endl;
			tmp = tmp->next;
			i++;
		}
		
	}

	void addNode(int n)
	{
		Node* new_node = new Node();
		new_node->data = n;
		new_node->next = nullptr;
		Node* last = getlastEl();
		if (last == nullptr)
		{
			head = new_node;
			return;
		}
		else {
			last->next = new_node;
		}


	}

	Node* getlastEl()
	{
		Node* tmp = head;

		if (tmp == nullptr)
		{
			return tmp;
		}

		while (tmp->next != nullptr)
		{
			tmp = tmp->next;
		}
		return tmp;
	}

	void insert_node_at_beginning(int x)
	{
		Node* first_node = new Node();
		first_node->data = x;
		first_node->next = head;
		head = first_node;
	}

};

int main()
{
	LinkedList newlist;
	newlist.addNode(4);
	newlist.addNode(6);
	newlist.addNode(8);
	newlist.printList();

	std::cout << "---------------------------------------\n\n";

	newlist.insert_node_at_beginning(2);
	newlist.printList();

}
