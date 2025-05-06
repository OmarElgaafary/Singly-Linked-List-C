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

	void delete_at_pos(int n)
	{
		Node* t0 = head; //initalize node pointer

		if (head == nullptr) return;

		if (n == 0 && t0->next != nullptr)
		{
			Node* t1 = t0->next;
			head = t1;
			delete t0;
			return;

		}

		int i = 0;
		while (i < n - 1 && t0->next != nullptr) // loop through list for (n-1)th position
		{
			t0 = t0->next;
			i++;
		}

		if (t0->next == nullptr) return;

		Node* t1 = t0->next;
		t0->next = t1->next;
		delete t1;
	}

};

int main()
{

	LinkedList newlist;


	newlist.addNode(5);
	newlist.addNode(10);
	newlist.addNode(20);
	newlist.addNode(20);
	newlist.addNode(30);
	newlist.addNode(40);
	newlist.addNode(50);
	newlist.printList();
	std::cout << "---------------------------------------\n\n";
	newlist.delete_at_pos(5);
	newlist.printList();





}
