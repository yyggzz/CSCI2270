#include <iostream>

using namespace std;

struct Node 
{
    int data;
    Node *next;
};

Node* deleteNegatives(Node* head)
{
/*
    1. SET: pres pointer to head
    2. SET: prev pointer to NULL
    3. LOOP-WHILE: pres is not NULL
            IF pres->data < 0:
                IF pres == head:
                    head = head->next;
                    delete pres;
                    pres = head;
                ELSE:
                    prev->next = pres->next;
                    delete pres;
                    pres = prev->next;
            ELSE: 
                prev = pres;
                pres = pres->next;
    4. RETURN head;
*/
    Node* pres = head;
    Node* prev = NULL;

    while(pres) {
        if(pres->data < 0) {
            if(pres == head) {
                head = head->next;
                delete pres;
                pres = head;
            }
            else {
                prev->next = pres->next;
                delete pres;
                pres = prev->next;
            }
        }
        else {
            prev = pres;
            pres = prev->next;
        }
    }

    return head;
}

bool lengthIsEven(Node* head)
{
/*
    1. SET: temp pointer to head
    2. SET: num_nodes = 0
    3. LOOP-WHILE: temp is not NULL
            num_nodes += 1
            temp = temp->next
    4. IF num_nodes % 2 == 0: return True
    5. RETURN False
*/
    Node* temp = head;
    int num_nodes = 0;

    while(temp) {
        num_nodes += 1;
        temp = temp->next;
    }

    if(num_nodes % 2 == 0) return true;
    return false;
}

void print(Node* head)
{
    Node* temp = head;
    while(temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void deleteList(Node *&head) {
    Node *temp;
    while(head != NULL) {
        temp = head;
        head = head->next;
        delete temp;
    }
}


int main()
{
    Node* head = new Node({-3, NULL});
    head->next = new Node({-9, NULL});
    head->next->next = new Node({10, NULL});
    head->next->next->next = new Node({-11, NULL});
    head->next->next->next->next = new Node({-12, NULL});
    head->next->next->next->next->next = new Node({14, NULL});

    print(head);

    bool eo = lengthIsEven(head);
    if(eo) {
        cout << "EVEN" << endl;
    }
    else {
        cout << "ODD" << endl;
    }
    

    head = deleteNegatives(head);
    print(head);

    // avoid memory leaks
    deleteList(head);


    return 0;
}