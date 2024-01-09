#include <iostream>
using namespace std;
class node
{
public:
    int value;
    node *right;
    node *left;
    node(int val)
    {
        value = val;
        right = NULL;
        left = NULL;
    }
};
class BST
{
public:
    node *root;
    
    BST()
    {
        root = NULL;
    }
    node *insert(node *current, int val)
    {
       // cout << "INsert FUnction" << endl;

        if (current == NULL)
        {
            return new node(val);
        }
        if (val == current->value)
        {
            cout << "value already presend in the tree" << endl;
        }
        if (val > current->value)
        {
            current->right = insert(current->right, val);
            // return current;
        }
        if (val < current->value)
        {
            current->left = insert(current->left, val);
        }

        return current;
    }

    node* search(node *current, int val)
    {
        //cout << "Search function" << endl;
        if (current == NULL)
        {
            cout << "Tree is empty" << endl;
            return current;
        }

        if (current->value == val)
        {
            cout << "value found " << endl;
            return current;
        }
        if (val > current->value)
        {
            return search(current->right, val);
        }
        else if (val < current->value)
        {
            return search(current->left, val);
        }
        return current;
    }
    
    bool isempty(node *r)
    {
       // cout << " IS EMPTY FUNCTION" << endl;
        if (r == NULL)
        {
            cout << " BST is empty " << endl;
            return true;
        }
        else
        {
            cout << "BST is  not empty" << endl;
            return false;
        }
    }
      
    node *find_successor(node *val1)
    {
        if (val1->left == NULL)
        {
            return val1;
        }
        root = val1;
        return find_successor(val1->left);
    }

    void preOrder(node *n)
    {
        if (n == NULL)
        {
            return;
        }
        cout << n->value << "\t";
        preOrder(n->left);
        preOrder(n->right);
    }
    void inOrder(node *n)
    {
        if (n == NULL)
        {
            return;
        }
        inOrder(n->left);
        cout << n->value << "\t";
        inOrder(n->right);
    }
    void postOrder(node *n)
    {
        if (n == NULL)
        {
            return;
        }
        postOrder(n->left);
        postOrder(n->right);
        cout << n->value << "\t";
    }



    void deleteNode(int val, node * &current)
    {
        //cout << "Delete Function" << endl;
        if (current == NULL)
        {
            cout << " value you want to delete doesnt exist" << endl;
            return;
        }
      
        if (current->value == val)
        {
            if (current->left && current->right == NULL)
            {


                delete current;
                current = NULL;
                return;

               
            }
            else if (current->left == NULL)
            {
                node *temp = current;
                current = current->right;
                delete temp;
                
            }
            else if (current->right == NULL)
            {
                node *temp = current;
                current = current->left;
                delete temp;
                
            }
            else
            {
                node *successor = find_successor(current->right);
                current->value = successor->value;
                deleteNode(successor->value, current->right);
                
            }
        }
        else if (val < current->value)
        {
            deleteNode(val, current->left);
        }
        else
        {
            deleteNode(val, current->right);
        }
    }
    


};

int main()
{
    BST tree;
    tree.root = tree.insert(tree.root, 10);
    //tree.insert(tree.root, 5);
    tree.insert(tree.root, 4);
    tree.insert(tree.root, 7);
    tree.insert(tree.root, 12);
    tree.insert(tree.root, 3);
    tree.insert(tree.root, 9);
    tree.insert(tree.root, 23);
    tree.insert(tree.root, 6);
    tree.insert(tree.root, 2);
    //tree.insert(tree.root, 3.5);
    tree.inOrder(tree.root);
    tree.search(tree.root, 3);
    tree.isempty(tree.root);
    cout<<endl;
    tree.deleteNode(10, tree.root);
    tree.inOrder(tree.root);
}