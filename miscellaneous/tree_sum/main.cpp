#include <iostream>



struct TreeNode {
    TreeNode * left = nullptr;
    TreeNode * right = nullptr;
    int value = 0;
};

static unsigned long result = 0;
void prefix_sum_2(TreeNode* l, TreeNode* p = nullptr, TreeNode* g = nullptr){
    if (l && g && g->value % 2 == 0) result += l->value;
    if (l) prefix_sum_2(l->left,  l, p) , prefix_sum_2(l->right, l, p);
}

void append_leaf_to_result(TreeNode * leaf){
    if (leaf == nullptr) return;
    TreeNode * left_left = leaf->left;
    if (left_left != nullptr) result += left_left->value;
    TreeNode * left_right = leaf->right;
    if (left_right != nullptr) result += left_right->value;
}

void prefix_sum(TreeNode * root){
    if (root == nullptr) return;
    TreeNode * left = root->left;
    TreeNode * right = root->right;
    if (root->value % 2 == 0){
        append_leaf_to_result(left);
        append_leaf_to_result(right);
    }
    prefix_sum(left);
    prefix_sum(right);
}

void createLeafs(TreeNode * root, int l, int r)
{
    root->left = new TreeNode;
    root->right = new TreeNode;

    root->left->value = l;
    root->right->value = r;
}

void printLeafs(TreeNode * root)
{
    std::cout << "left = " << root->left->value << ", right = " << root->right->value << std::endl;
}

TreeNode * init()
{
    TreeNode * root = new TreeNode;
    root->value = 2;

    createLeafs(root, 4, 2);
    createLeafs(root->left, 9, 1);
    createLeafs(root->right, 4, 3);

    createLeafs(root->left->left, 4, 1);
    createLeafs(root->left->right, 2, 3);
    
    createLeafs(root->right->left, 1, 2);
    createLeafs(root->right->right, 7, 4);

    return root;
}

int main()
{

    TreeNode * root = init();
    std::cout << "root value = " << root->value <<std::endl;
    printLeafs(root);
    printLeafs(root->left);
    printLeafs(root->right);

    prefix_sum_2(root);
    std::cout << "result = " << result << std::endl;
    return 0;
}
