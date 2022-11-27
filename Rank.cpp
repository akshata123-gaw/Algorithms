#include <bits/stdc++.h>
using namespace std;
class BST
{
public:
int data;
BST *left, *right;
int size;
BST(int data)
{
this->data = data;
left = NULL;
right = NULL;
size = 0;
}
BST *insert(BST *root, int data)
{
if (root == NULL)
return new BST(data);
if (data <= root->data)
{
root->left = insert(root->left, data);
root->size++;
}
else
root->right = insert(root->right, data);
return root;
}
int getRank(BST *root, int num)
{
if (root->data == num)
return root->size;
if (num < root->data)
{
if (root->left == NULL)
return -1;
else
return getRank(root->left, num);
}
else
{
if (root->right == NULL)
return -1;
else
{
int rsize = getRank(root->right, num);
if (rsize == -1)
return -1;
return rsize + root->size + 1;
}
}
return -1;
}
};
int main()
{
BST *root = new BST(5);
root->insert(root, 1);
cout << "Rank of 1: " << root->getRank(root, 1) << endl;
root->insert(root, 4);
root->insert(root, 9);
root->insert(root, 7);
cout << "Rank of 7: " << root->getRank(root, 7) << endl;
root->insert(root, 13);
root->insert(root, 3);
cout << "Rank of 3: " << root->getRank(root, 3) << endl;
}
