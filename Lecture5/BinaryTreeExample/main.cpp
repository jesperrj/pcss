#include <iostream>

using namespace std;

struct TreeNode{
    int data;
    TreeNode *left_link;
    TreeNode *right_link;
};
typedef TreeNode* TreeNodePtr;

void add_leaf(TreeNodePtr parent_ptr, int the_number);

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}

void add_leaf(TreeNodePtr root_ptr, int the_number){
    if(root_ptr->left_link==NULL&&root_ptr->right_link==NULL){
        root_ptr
    }
}
