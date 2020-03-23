#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node* next;
};

void printList(Node* head)
{
    Node * tmp = head;
    while(tmp) {
        cout << tmp->data << " -> ";
        tmp = tmp -> next;
    }
    cout << "NULL"<<endl;
}

int main(int argc, char* argv[])
{
    // build the list
    Node * head = new Node({10, NULL});
    head->next = new Node({4, NULL});
    head->next->next = new Node({13, NULL});
    head->next->next->next = new Node({2, NULL});
    head->next->next->next->next = new Node({22, NULL});
    head->next->next->next->next->next = new Node({9, NULL});

    // print the list
    printList(head);

    // load the inputs
    if(argc != 2) {
        cout << "Invalid key (command line argument)" << endl;
        return 0;
    }
    else if (!head) {
        cout << "Empty List!" << endl;
        return 0;
    }

    // setup pointers
    int key = atoi(argv[1]);
    Node* prev = head;

    if(prev->data == key) {
        // found the item at head node
        // rewiring and deleting
        Node* tmp = head;
        head = head->next;
        delete tmp;
    }
    else {
        Node* curr = head->next; // to hold current node pointer

        // traverse until current.data == key
        while(curr && curr->data != key) {
            prev = prev->next;
            curr = curr->next;
        }

        // check if curr is not NULL
        if(!curr) {
            cout << endl << "Did not find key in the list" << endl;
        }
        else {
            // rewiring and deleting
            prev->next = curr->next;
            delete curr;
        }

    }

    // printing out changes
    cout << endl << "After Deleting " << key << endl;
    printList(head);

    return 0;
}