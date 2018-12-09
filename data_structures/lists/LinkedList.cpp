#include <cstdlib>
#include <iostream>
#include "LinkedList.h"


using namespace std;


LinkedList::LinkedList(int data)
{
    this->data = data;
    this->next = nullptr;
}


LinkedList::~LinkedList()
{
    if (this->next != nullptr)
        delete this->next;
}


void LinkedList::add(int data)
{
    if (this->next != nullptr)
        this->next->add(data);
    else
        this->next = new LinkedList(data);
}


void LinkedList::remove(int data)
{
    if (this->data == data && this->next == nullptr)
        delete this;
    else
    {
        LinkedList* current_node = this;
        LinkedList* next_node = current_node->next;  // This can't be nullptr because of the previous if statement

        // Search the node to delete
        if (current_node->data == data)
        {

        }
        while (next_node->data != data)
        {
            current_node = next_node;
            next_node = next_node->next;

            if (next_node == nullptr) // End of list: the data wasn't found. Just return
                return;
        }

        // From here, the node to delete is next_node, and its parent is current_node
        while (next_node->next != nullptr)
        {
            next_node->data = next_node->next->data;
            current_node = next_node;
            next_node = next_node->next;
        }

        // From here, next_node is the last node, and its parent is current_node
        current_node->next = nullptr;
        delete next_node;

    }
}


void LinkedList::print()
{
    //TODO
    cout << this->data;
    LinkedList* node = this->next;

    while (node != nullptr)
    {
        cout << " -> " << node->data;
        node = node->next;
    }

    cout << endl;
}


int main()
{
    LinkedList *list;
    LinkedList *list_2;

    list = new LinkedList(2);
    list->add(2);
    list->add(1);
    delete list;

    list = new LinkedList(1);
    list->add(2);
    list->add(3);
    list->add(4);
    list->print();
    list->remove(1);
    list->print();
    list->remove(3);
    list->print();
    list->remove(4);
    list->print();
    list->remove(2);
    delete list;

    /*
    list = new LinkedList(0);
    list.add(1);
    list.add(2);
    list.add(3);
    list.remove_by_index(0);
    list.remove_by_index(2);
    list.remove_by_index(3);
    list.remove_by_index(1);
    delete list;
     */

    return EXIT_SUCCESS;
}