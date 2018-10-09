#include <iostream>

using namespace std;

// function declarations
struct Node{
    int data;
    Node *link;
};
typedef Node* NodePtr;

void head_insert(NodePtr& head, int the_number);

void tail_insert(NodePtr& tail, int the_number);

int main()
{
    // initialize temporary number and node pointers
    int temp_number=0;
    int linklist_length=3;
    NodePtr linklist_ptr, tail_ptr, iter;

    // create the first node of the linked list
    linklist_ptr = new Node;
    tail_ptr=linklist_ptr;

    // fill linked list
    for(int i=0;i<linklist_length;i++){
        // get user input for linked list
        cout<< "Enter integer for entry "<<i+1<<" (of "<<linklist_length<<") in the linked list:\n";
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
    cout<<"The entries stored in the linked list are (number, pointer):\n";
    // print numbers stored in the linked list (using iterator)
    for(iter=linklist_ptr; iter!=NULL; iter=iter->link){
        cout<<iter->data<<", "<<iter->link<<"\n";
    }

    // insert from tail
    cout<< "\n Enter integer for new tail entry:\n";
    cin >> temp_number;
    cout<< "\n";

    tail_insert(tail_ptr, temp_number);

    // print numbers stored in the linked list
    for(iter=linklist_ptr; iter!=NULL; iter=iter->link){
        cout<<iter->data<<", "<<iter->link<<"\n";
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

void tail_insert(NodePtr& tail, int the_number){
    NodePtr temp_ptr;
    temp_ptr = new Node;

    temp_ptr->data = the_number;
    temp_ptr->link = NULL;

    tail->link = temp_ptr;
    tail = temp_ptr;
}

