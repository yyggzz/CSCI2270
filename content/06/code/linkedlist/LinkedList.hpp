#pragma once 
#include <iostream>

using namespace std;

struct Node {
    int id;
    string name;
    float gpa;
    Node* next;
};

class LinkedList
{
    private:
        Node* head;

    public:
        LinkedList();
        ~LinkedList();
        Node* CreateNode(int id, string name, float gpa);
        void PrintNode(Node* n);
        void PrintList();
        Node* Tail();
        Node* Search(string name);
        Node* Search(int ix);
        int Index(Node* n);
        void Filter(float low, float high);
        Node* CreateLoop(string name);
        void Insert(Node* p, int ix);
        void Delete(int ix);
        int Length();
};
