#include <iostream>
#include <cmath>
#include <string.h>
using namespace std;

class Node
{

public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

class BST
{

public:
    Node *root;
    BST()
    {
        root = NULL;
    }

    void insert(int value)
    {
        Node *newNode = new Node(value);

        if (root == NULL)
        {
            root = newNode;
        }

        else
        {

            Node *curr = root;
            while (curr != NULL)
            {
                if (newNode->data < curr->data && curr->left == NULL)
                {
                    curr->left = newNode;
                    break;
                }
                else if (newNode->data < curr->data)
                {
                    curr = curr->left;
                }
                else if (newNode->data > curr->data && curr->right == NULL)
                {
                    curr->right = newNode;
                    break;
                }
                else if (newNode->data > curr->data)
                {
                    curr = curr->right;
                }
                else
                {
                    cout << "Duplicate Value" << endl;
                    return;
                }
            }
        }
    }

    void preOrder(Node *thisNode)
    {
        if (thisNode == NULL)
        {
            return;
        }
        cout << thisNode->data << " ";
        preOrder(thisNode->left);
        preOrder(thisNode->right);
    }
    void inOrder(Node *thisNode)
    {
        if (thisNode == NULL)
        {
            return;
        }
        inOrder(thisNode->left);
        cout << thisNode->data << " ";
        inOrder(thisNode->right);
    }

    void postOrder(Node *thisNode)
    {

        if (thisNode == NULL)
        {
            return;
        }
        postOrder(thisNode->left);
        postOrder(thisNode->right);
        cout << thisNode->data << " ";
    }

    int getHeight(Node *thisNode)
    {

        if (thisNode == NULL)
        {
            return -1;
        }
        else
        {

            int leftHeight = getHeight(thisNode->left);
            int rightHeight = getHeight(thisNode->right);

            if (leftHeight > rightHeight)
            {
                return leftHeight + 1;
            }
            else
            {
                return rightHeight + 1;
            }
        }
    }

    void levelOrder(Node *node)
    {
        int h = getHeight(node);
        for (int i = 0; i <= h; i++)
        {
            helperLevelOrder(node, i);
        }
    }

    void helperLevelOrder(Node *node, int level)
    {

        if (node == NULL)
        {
            return;
        }

        else if (level == 0)
        {
            cout << node->data << " ";
        }
        else
        {
            helperLevelOrder(node->left, level - 1);
            helperLevelOrder(node->right, level - 1);
        }
    }

    Node *Search(Node *thisNode, int value)
    {

        if (thisNode == NULL)
        {
            return NULL;
        }
        if (value == thisNode->data)
        {
            return thisNode;
        }

        if (value < thisNode->data)
        {
            return Search(thisNode->left, value);
        }

        else
        {
            return Search(thisNode->right, value);
        }
    }
};

int main()
{
    BST tree;
    tree.insert(5);
    tree.insert(11);
    tree.insert(12);
    tree.insert(8);
    tree.insert(9);
    tree.insert(3);
    tree.insert(2);
    tree.insert(4);
    cout << "\nPreorder:";
    tree.preOrder(tree.root);
    cout << "\nInorder:";
    tree.inOrder(tree.root);
    cout << "\nPostorder:";
    tree.postOrder(tree.root);
    cout << "\nLevelorder:";
    tree.levelOrder(tree.root);
    cout << endl;
    int value;
    cout << "Enter Value to Search: ";
    cin >> value;

    Node *myPower = tree.Search(tree.root, value);
    if (myPower != NULL)
    {
        cout << myPower->data << endl;
    }
    else
    {
        cout << "Not found!" << endl;
    }
    return 0;
}