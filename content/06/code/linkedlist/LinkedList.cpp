#include <iostream>
#include "LinkedList.hpp"

using namespace std;

LinkedList::LinkedList()
{
    head = NULL;
}

LinkedList::~LinkedList()
{
    Node* temp = head;

    if(Length()) {
        while(head) {
            // delete head
            temp = head;
            head = head->next;
            delete temp;
        }
    }

}

Node* LinkedList::CreateNode(int id, string name, float gpa)
{
    Node* temp = new Node({id, name, gpa, NULL});
    return temp;
}

void LinkedList::PrintNode(Node* n)
{
    if(n) {
        cout << "[ID] " << n->id << ", [NAME] " << n->name << ", [GPA] " <<  n->gpa << endl;
    }
}

void LinkedList::PrintList()
{
    int n = Length();
    Node* temp = head;
    for(int i = 0; i < n; i++) {
        PrintNode(temp);
        temp = temp->next;
    }
}

Node* LinkedList::Tail()
{
    Node* temp = head;
    while(temp && temp->next != NULL) {
        temp = temp->next;
    }
    return temp;
}

Node* LinkedList::Search(string name)
{
    Node* temp = head;
    while(temp && temp->name != name) {
        temp = temp->next;
    }
    return temp;
}

Node* LinkedList::Search(int ix)
{
    int len = Length();
    if(ix >= len - 1) {
        return Tail();
    }
    else if(ix <= 0) {
        return head;
    }
    
    Node* temp = head;
    for(int i = 0; i < ix; i++) {
        temp = temp->next;
    }
    return temp;
}

int LinkedList::Index(Node* n)
{
    Node* temp = head;
    int counter = 0;
    while(temp && temp != n) {
        temp = temp->next;
        counter++;
    }
    return counter;
}

void LinkedList::Filter(float low, float high)
{
    Node* temp = head;
    while(temp) {
        if (temp->gpa >= low && temp->gpa <= high) {
            PrintNode(temp);
        }
        temp = temp->next;
    }
}

Node* LinkedList::CreateLoop(string name)
{
    Node* tail = Tail();
    Node* temp = Search(name);

    tail->next = temp;
    return tail;
}

void LinkedList::Insert(Node* p, int ix)
{
    int pos = 0;
    if(ix > Length()) {
        ix = Length(); 
    }

    if(ix == 0) {
        // Insert at head
        p->next = head;
        head = p;
    }
    else {
        // Insert somewhere else
        Node* q = Search(ix - 1);
        p->next = q->next;
        q->next = p;
    }
}

void LinkedList::Delete(int ix)
{
    if(head) {

        if(ix >= Length()) {
            // delete tail
            ix = Length() - 1;
        }
        
        if (ix <= 0 || head->next == NULL) {
            // delete head 
            delete head;
            head = NULL;
        }
        else {
            // intermediate node
            Node* prev = Search(ix - 1);
            Node* pres = Search(ix);

            prev->next = pres->next;
            delete pres;
        }
    }
}

int LinkedList::Length()
{
    Node* temp = head;
    int counter = 0;
    while(temp) {
        temp = temp->next;
        counter++;
    }
    return counter;
}