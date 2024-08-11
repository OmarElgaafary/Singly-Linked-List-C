#include <iostream>
#include <chrono>

struct Node {
    int data;
    Node* next;
    Node* previous;
};

class LinkedList {
public:

    LinkedList() : root_(nullptr) {}
    ~LinkedList() {}

    void Add(int data) {
        Node* new_node = new Node();
        new_node->data = data;
        new_node->next = nullptr;

        Node* last_el = get_last_element();
        if (last_el == nullptr) {
            root_ = new_node;
            return;
        }

        last_el->next = new_node;
    }

    void InsertionatBeginning(int data) {

        Node* new_node = new Node();
        new_node->data = data;
        new_node->next = root_;
        root_ = new_node;

    }

    void insertionposition(int position, int data) {
        Node* new_node = new Node();
        new_node->data = data;
        Node* tmp = root_;
        int i = 0;

        if (position == 0) {
            new_node->next = root_;
            root_ = new_node;
            return;
        }

        while (tmp != nullptr && i < position - 1) {
            tmp = tmp->next;
            i++;
        }


        if (i == position - 1)
        {
            new_node->next = tmp->next;
            tmp->next = new_node;
            return;
        }


    }

    void Delete(int key) {

        Node* t, * t0;
        int i = 0;
        t = root_;
        t0 = root_;

        while (t != nullptr) {
            if (i == key) {
                // we found it delete here
                if (key == 0) {
                    root_ = t->next;
                    delete t;
                    break;
                }

                t0->next = t->next;
                delete t;
                break;
            }
            t0 = t;
            t = t->next;
            i++;
        }

        if (i != key) {
            std::cout << "Not Found" << std::endl;
        }


    }

    Node* get_last_element() {
        Node* tmp = root_;
        while (tmp && tmp->next != nullptr) {
            tmp = tmp->next;
        }
        return tmp;
    }

    void PrintList() {

        if (root_ == nullptr) {
            std::cout << "[Empty]" << std::endl;
            return;
        }

        Node* tmp = root_;
        int i = 0;
        while (tmp != nullptr) {
            std::cout << "[" << i << "](" << tmp->data << ")" << std::endl;
            tmp = tmp->next;
            i++;
        }
    }



private:
    Node* root_;
};

int main()
{

    // HOME WORKY
    // 1- FIX DELETE FUNCTION done
    // 2- ADD InsertAtBeginning done
    // 3- Add InsertAtPosition(int position, int data) done

    LinkedList l1;
    l1.Add(2006);
    l1.Add(2005);
    l1.Add(2004);
    l1.Add(2003);
    l1.Add(2002);
    l1.Add(2001);
    l1.Add(2000);
    l1.InsertionatBeginning(5);
    l1.insertionposition(6, 10);
    l1.PrintList();

    return 0;
}



