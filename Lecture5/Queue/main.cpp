#include <iostream>

using namespace std;

// function declarations
struct Node{
    int data;
    Node *link;
};
typedef Node* NodePtr;

void add_queue(NodePtr& queue_in, int the_number);

void retrieve_queue(NodePtr& queue_out);

int main()
{
    // initializations
    int queue_length = 5;
    int retrieve_number = 3;
    int temp_number;
    NodePtr queue_in, queue_out;

    // create new queue
    queue_in = new Node;
    queue_out=queue_in;

    // fill queue
    for(int i=0;i<queue_length;i++){
        // get user input for queue
        cout<< "Enter integer for entry "<<i+1<<" (of "<<queue_length<<") in the queue:\n";
        cin >> temp_number;
        cout<< "\n";

        // store input in linked list
        if(i==0){
            queue_in->data = temp_number;
            queue_in->link = NULL;
        }else{
            add_queue(queue_in, temp_number);
        }
    }

    // start reading entries from the end of the queue
    cout<<"Retrieving "<<retrieve_number<<" values from the queue:\n";
    // print numbers stored in the queue (using iterator)
    for(int i=0; i<retrieve_number; i++){
        cout<<queue_out->data<<" ";

        retrieve_queue(queue_out);
    }

    return 0;
}

// function definitions
void add_queue(NodePtr& queue_in, int the_number){
    NodePtr temp_ptr;
    temp_ptr = new Node;

    temp_ptr->data = the_number;
    temp_ptr->link = NULL;

    queue_in->link = temp_ptr;

    queue_in=temp_ptr;
}

void retrieve_queue(NodePtr& queue_out){

    NodePtr temp_ptr=queue_out->link;

    delete queue_out;
    queue_out=temp_ptr;
}
