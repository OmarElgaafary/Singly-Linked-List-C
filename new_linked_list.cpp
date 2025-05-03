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

	Node* find_position(int position)
	{
		Node* tmp = new Node();
		tmp = head;
		int i = 0;

		while (i != position && tmp->next != nullptr)
		{
			tmp = tmp->next;
			i++;

		}
		std::cout << tmp->data << std::endl;
		return tmp;
	}

	int linked_length()
	{
		Node* tmp = head;
		int i = 0;
		while (tmp != nullptr)
		{
			tmp = tmp->next;
			i++;
		}
		return i;
	}

	void insert_at_position(int pos, int x)
	{
		Node* new_node = new Node();
		new_node->data = x;
		Node* tmp = head;

		if (pos > linked_length() || pos < 0)
		{
			std::cout << "Position out of bounds." << std::endl;
			return;
		}
		
		int i = 0;
		while (i != pos - 1 && tmp->next != nullptr)
		{
			tmp = tmp->next;
			i++;
		}
		new_node->next = tmp->next;
		tmp->next = new_node;

	}

};

int main()
{
	LinkedList newlist;
	newlist.addNode(0);
	newlist.addNode(2);
	newlist.addNode(4);
	newlist.addNode(6);
	newlist.addNode(8);
	newlist.addNode(10);
	newlist.addNode(12);



	newlist.printList();

	std::cout << "---------------------------------------\n\n";
	
	newlist.insert_at_position(5, 9);
	newlist.printList();


}
