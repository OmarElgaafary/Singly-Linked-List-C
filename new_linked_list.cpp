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

		while (tmp != nullptr)
		{
			std::cout << tmp->data << ", ";
			tmp = tmp->next;
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

};

int main()
{
	LinkedList newlist;
	newlist.addNode(5);
	newlist.addNode(10);
	newlist.addNode(20);
	newlist.addNode(30);
	newlist.addNode(40);
	newlist.addNode(50);
	newlist.printList();

}
