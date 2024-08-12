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

    void Delete(int key) {

        Node* t, * t0;
        int i = 0;
        t = root_;
        t0 = root_;

        while (t != nullptr) {
            if (i == key) {
                if (key == 0) {
                    root_ = t->next;
                    delete t;
                    return;
                }
               
                // we found it delete here
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

    void InsertAtBeginning(int data) {
        Node* new_node = new Node();
        new_node->data = data;
        new_node->next = root_;
        root_ = new_node;

    } 
#
    void InsertAtPosition(int position, int data) {
        Node* new_node = new Node();
        new_node->data = data;

        if (position == 0) {            
           InsertAtBeginning(data);
        }

        Node* tmp = root_;
        int i = 0;

        while (tmp != nullptr && i < position - 1) {
            tmp = tmp->next;
            i++;
        } 

        if (i == position - 1 && tmp != nullptr) {
            new_node->next = tmp->next;
            tmp->next = new_node;
            return;
           
        }
        else {
            delete new_node;
            return;
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

    LinkedList New;
    New.Add(0);
    New.Add(5);
    New.Add(10);
    New.Add(15);
    New.Add(20);
    New.Add(25);
    New.InsertAtPosition(2, 50);
    New.PrintList();
 }



