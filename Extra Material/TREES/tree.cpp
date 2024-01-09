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

class binaryTree
{

public:
    Node *root;
    binaryTree()
    {
        root = NULL;
    }

    Node *Parent(Node *curr, Node *thisNode, Node *parent)
    {

        if (curr == NULL)
        {
            return NULL;
        }

        if (curr == thisNode)
        {
            return parent;
        }

        else
        {

            Node *temp = NULL;
            temp = Parent(curr->left, thisNode, curr);
            if (temp != NULL)
            {
                return temp;
            }

            else
            {
                temp = Parent(curr->right, thisNode, curr);
                return temp;
            }
        }
    }

    Node *Sibling(Node *curr, Node *thisNode)
    {

        Node *parent = Parent(curr, thisNode, NULL);

        if (parent->left = thisNode)
        {
            return parent->right;
        }
        else
        {
            return parent->left;
        }
    }

    int getLevel(Node *curr, Node *thisNode, int level)
    {

        if (curr == NULL)
        {
            return 0;
        }

        if (curr == thisNode)
        {
            return level;
        }

        int LEFT = getLevel(curr->left, thisNode, level + 1);
        int RIGHT = getLevel(curr->right, thisNode, level + 1);

        if (LEFT == 0)
        {
            return RIGHT;
        }
        else if (RIGHT == 0)
        {
            return LEFT;
        }
        else
        {
            return 0;
        }
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
                return (leftHeight + 1);
            }
            else
                return (rightHeight + 1);
        }
    }

    void deleteTree(Node *thisNode)
    {
        if (thisNode != NULL)
        {
            deleteTree(thisNode->left);
            deleteTree(thisNode->right);
            delete thisNode;
        }
    }
};

int main()
{
    binaryTree tree;
    Node *root = new Node(5);
    root->left = new Node(2);
    root->right = new Node(7);
    root->right->right = new Node(22);
    root->right->left = new Node(44);



    return 0;
}