#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node* next;
};

void print_forward(Node* head)
{
    Node * tmp = head;
    while(tmp) {
        cout << tmp->data << " -> ";
        tmp = tmp -> next;
    }
    cout << "NULL" << endl;
}

void print_backward(Node* head)
{
    // base case
    if (!head) {
        cout << "NULL";
        return;
    }

    // recursion: process next node
    print_backward(head->next);

    // process self
    cout <<  " -> " << head->data;

}


int main()
{
    // build the list
    Node * head = new Node({10, NULL});
    head->next = new Node({4, NULL});
    head->next->next = new Node({13, NULL});
    head->next->next->next = new Node({2, NULL});
    head->next->next->next->next = new Node({22, NULL});
    head->next->next->next->next->next = new Node({9, NULL});

    // print the list along with node position
    cout << "FORWARD: ";
    print_forward(head);

    cout << "REVERSE: ";
    print_backward(head);
    cout << endl;

    return 0;
}