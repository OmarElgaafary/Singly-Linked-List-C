#include <iostream>

struct Node {
	int value;
	Node* next;
};

class linked_list
{
private:
	Node* root = nullptr;

public:

	int getLength()
	{
		Node* new_node = new Node();
		new_node = root;
		int count = 0;
		while (new_node != nullptr)
		{
			new_node = new_node->next;
			count++;
		}
		return count;
	}

	Node* getlast()
	{
		Node* tmp = new Node();
		tmp = root;

		while (tmp->next != nullptr)
		{
			tmp = tmp->next;
		}

		return tmp;
	}

	void createNode(int data)
	{
		Node* new_node = new Node();
		new_node->value = data;
		new_node->next = nullptr;

		if (root == nullptr)
		{
			root = new_node;
			return;
		}
		Node* last = getlast();
		last->next = new_node;
	}

	void printList()
	{
		Node* tmp = new Node();
		tmp = root;
		if (root == nullptr)
		{
			std::cout << "[Empty]\n";
			return;
		}

		int i = 0;
		while (tmp != nullptr)
		{
			std::cout << "[" << i << "] " << "(" << tmp->value << ")\n";
			tmp = tmp->next;
			i++;
		}

		
	}

	void insert_at_position(int data, int position)
	{
		if (position > getLength() || position < 0 || root == nullptr)
		{
			std::cout << "[Invalid Position]\n";
			return;
		}

		// find the nth position
		Node* tmp = new Node();
		Node* new_node = new Node();
		new_node->value = data;

		if (position == 0)
		{
			new_node->next = root;
			root = new_node;
			return;
		}

		tmp = root;

		int current = 0;
		while (current != position - 1 && tmp->next != nullptr)
		{
			tmp = tmp->next;
			current++;
		}
		new_node->next = tmp->next;
		tmp->next = new_node;

	}

	void delete_at_position(int position)
	{
		if (root == nullptr || position < 0 || position > getLength())
			return;
		// initalizing temporary variable
		Node* tmp = new Node();
		tmp = root;

		//deleteing first node
		if (position == 0)
		{
			root = tmp->next;
			delete tmp;
			return;
		}

		// find deleting position
		int i = 0;
		while (i != position - 1 && tmp->next != nullptr)
		{
			tmp = tmp->next;
			i++;
		}

		Node* tmp2 = tmp->next;
		tmp->next = tmp2->next;
		delete tmp2;
	}

	void reverse_linked()
	{
		Node* curr = root;
		Node* tmp = curr->next;
		Node* tmp2 = tmp->next;

		root->next = nullptr;

		while (tmp2 != nullptr)
		{
			tmp->next = curr;
			curr = tmp;
			tmp = tmp2;
			tmp2 = tmp2->next;
		}

		tmp->next = curr;
		root = tmp;
	}

	void print_recursion(Node* node)
	{
		if (node == nullptr)
			return;

		std::cout << node->value << " ";
		print_recursion(node->next);
	}

	void print_reverse_recursion(Node* node)
	{
		if (node == nullptr)
			return;
		print_reverse_recursion(node->next);
		std::cout << node->value << " ";
	}

	Node* getRoot()
	{
		return root;
	}

	void reverse_recursion(Node* node)
	{

		if (node->next == nullptr)
		{
			root = node;
			return;
		}

		reverse_recursion(node->next);

		node->next->next = node;
		node->next = nullptr;
	}

};



int main()
{
	linked_list list;
	list.createNode(1);
	list.createNode(2);
	list.createNode(3);
	list.createNode(4);
	list.createNode(5);
	list.createNode(6);
	list.createNode(7);
	list.printList();
	std::cout << "-----------------------\n\n";

	list.reverse_linked();
	list.printList();

	std::cout << "-------------------------\n\n";
	list.reverse_recursion(list.getRoot());
	list.printList();
}
