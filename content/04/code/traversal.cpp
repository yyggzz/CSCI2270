#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node* next;
};

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
    int counter = 0;
    Node * tmp = head;
    while(tmp) {
        cout << tmp->data;
        cout << " [" << counter++ << "]" << " -> ";

        tmp = tmp -> next;
    }
    cout << "NULL" << endl;

    return 0;
}