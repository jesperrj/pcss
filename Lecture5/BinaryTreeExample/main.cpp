#include <iostream>

using namespace std;

struct TreeNode{
    int data;
    TreeNode *left_link=NULL;
    TreeNode *right_link=NULL;
};
typedef TreeNode* TreeNodePtr;

void add_leaf(TreeNodePtr& parent_ptr, int the_number);

int walk_tree(TreeNodePtr root_ptr, int* arr, int ndx){
    TreeNodePtr temp_ptr=root_ptr;

    if(temp_ptr->left_link!=NULL){
        ndx=walk_tree(temp_ptr->left_link, arr, ndx);
    }

    arr[ndx]=temp_ptr->data;
    ndx++;

    if(temp_ptr->right_link!=NULL){
        ndx=walk_tree(temp_ptr->right_link, arr, ndx);
    }

    return ndx;
}

int main()
{
    TreeNodePtr root_ptr = NULL;
    int number_array[] = {6,1,7,2,6,8,7};
    int array_length=sizeof(number_array)/sizeof(number_array[0]);
    int sorted_array[array_length];
    int ndx=0;

    for(int i=0; i<array_length; i++){
        add_leaf(root_ptr, number_array[i]);
    }

    // walk the tree to sort array
    ndx=walk_tree(root_ptr, sorted_array, ndx);

    // print arrays
    cout<<"Array before sorting:\n";
    for(int i=0; i<array_length; i++){
        cout<<number_array[i]<<" ";
    }
    cout<<"\n\nArray after sorting:\n";
    for(int i=0; i<array_length; i++){
        cout<<sorted_array[i]<<" ";
    }

}

void add_leaf(TreeNodePtr& root_ptr, int the_number){
    TreeNodePtr temp_ptr=new TreeNode;
    temp_ptr->data=the_number;

    if(root_ptr==NULL){
        root_ptr = temp_ptr;
    }else{
        if(the_number<=root_ptr->data){
            if(root_ptr->left_link==NULL){
                root_ptr->left_link = temp_ptr;
            }else{
                add_leaf(root_ptr->left_link, the_number);
            }
        }else{
            if(root_ptr->right_link==NULL){
                root_ptr->right_link=temp_ptr;
            }else{
                add_leaf(root_ptr->right_link, the_number);
            }
        }
    }
}
