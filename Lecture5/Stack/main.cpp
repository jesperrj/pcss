#include <iostream>

using namespace std;

// function declarations
struct Node{
    int data;
    Node *link;
};
typedef Node* NodePtr;

void push_stack(NodePtr& stack_top, int the_number);

void pop_stack(NodePtr& stack_top);

int main()
{
    int stack_size=5;
    int pop_number=3;
    int temp_number;
    NodePtr stack_top;

    // create new stack
    stack_top = new Node;

    // fill stack
    for(int i=0;i<stack_size;i++){
        // get user input for stack
        cout<< "Enter integer for node "<<i+1<<" (of "<<stack_size<<") on the stack:\n";
        cin >> temp_number;
        cout<< "\n";

        // push input on the stack
        if(i==0){
            stack_top->data = temp_number;
            stack_top->link = NULL;
        }else{
            push_stack(stack_top, temp_number);
        }
    }

    // start popping from top of the stack
    cout<<"Popping "<<pop_number<<" values from the stack:\n";
    // print numbers stored in the queue (using iterator)
    for(int i=0; i<pop_number; i++){
        cout<<stack_top->data<<" ";

        pop_stack(stack_top);
    }

    return 0;
}

// function definitions
void push_stack(NodePtr& stack_top, int the_number){
    NodePtr temp_ptr;
    temp_ptr = new Node;

    temp_ptr->data=the_number;
    temp_ptr->link=stack_top;

    stack_top=temp_ptr;
}

void pop_stack(NodePtr& stack_top){
    NodePtr temp_ptr;

    temp_ptr=stack_top->link;

    delete stack_top;

    stack_top=temp_ptr;
}
