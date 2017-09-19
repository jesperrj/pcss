#include <iostream>

using namespace std;

// function declarations
struct Node{
    int data;
    Node *link;
};
typedef Node* NodePtr;

void head_insert(NodePtr& head, int the_number);

int main()
{
    // initialize temporary number and node pointers
    int temp_number=0;
    NodePtr linklist_ptr, search_ptr;

    // create the first node of the linked list
    linklist_ptr = new Node;

    // fill linked list
    for(int i=0;i<10;i++){
        // get user input for linked list
        cout<< "Enter integer for entry "<<i+1<<" (of 10) in the linked list:\n";
        cin >> temp_number;
        cout<< "\n";

        // store input in linked list
        if(i==0){
            linklist_ptr->data = temp_number;
            linklist_ptr->link = NULL;
        }else{
            head_insert(linklist_ptr, temp_number);
        }
    }

    // start reading entries from the head of the linked list
    search_ptr=linklist_ptr;
    cout<<"The entries stored in the linked list are (number, pointer):\n";
    // print numbers stored in the linked list
    for(int i=0;i<10;i++){
        cout<<search_ptr->data<<", "<<search_ptr->link<<"\n";
        search_ptr=search_ptr->link;
    }

    // return from main function
    return 0;
}

// function definitions
void head_insert(NodePtr& head, int the_number){
    NodePtr temp_ptr;
    temp_ptr = new Node;

    temp_ptr->data = the_number;

    temp_ptr->link = head;
    head = temp_ptr;
}

