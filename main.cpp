#include <iostream>
#include <cassert>
using namespace std;

struct tree
{
    int num = 0;
    tree* left = nullptr;
    tree* right = nullptr;
};

void pushTree (tree* (&root), string number, int start, int finish)
{
    int mid = (start+finish)/2;
    root->num = int(number[mid])-48;
    if ((((mid-2)+start)/2) >= start)
    {
        finish = mid-1;
        root->left = new tree;
        pushTree(root, number, start, finish);
    }
    if ((((mid+2)+finish)/2) <= finish)
    {
        start = mid+1;
        root->right = new tree;
        pushTree(root, number, start, finish);
    }
}

void bstUA (tree* root)
{
    if (root->left)
        bstUA(root->left);
    cout << root->num;
    if (root->right)
        bstUA(root->right);
}

int main()
{
    tree* root = new tree;
    tree* leaf = root;
    string number;
    cout << "please enter an infix expression > ";
    cin >> number;
    int start = 0;
    int finish = number.size()-1;
    pushTree (leaf, number, start, finish);
    bstUA (root);
    return 0;
}
