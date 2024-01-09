#include <iostream>
#include <string>

using namespace std;

class node
{
public:
    int ID;
    node *left;
    node *right;
    int height;

    string name;
    string designation;

    node(int val, string n, string d)
    {
        ID = val;
        left = NULL;
        right = NULL;
        height = 1;
        name = n;
        designation = d;
    }
};

class Tree
{
public:
    int length;
    node *root;

    Tree()
    {
        length = 0;
        root = NULL;
    }

    ~Tree()
    {
        deleteTree(root);
    }

    int getbalance(node *n)
    {
        if (n == NULL)
            return 0;
        return height(n->left) - height(n->right);
    }

    void deleteTree(node *leaf)
    {
        if (leaf != NULL)
        {
            deleteTree(leaf->left);
            deleteTree(leaf->right);
            delete leaf;
        }
    }

    int height(node *N)
    {
        if (N == NULL)
            return 0;
        return N->height;
    }

    int max(int a, int b)
    {
        if (a > b)
        {
            return a;
        }
        else
            return b;
    }

    node *leftRotate(node *x)
    {
        node *y = x->right;
        node *t = y->left;

        y->left = x;
        x->right = t;

        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;

        return y;
    }

    node *rightRotate(node *y)
    {
        node *x = y->left;
        node *t = x->right;

        x->right = y;
        y->left = t;

        y->height = max(height(y->left), height(y->right)) + 1;
        x->height = max(height(x->left), height(x->right)) + 1;

        return x;
    }

    node *insert(node *curr, int val, string name, string d)
    {
        if (curr == NULL)
        {
            return new node(val, name, d);
        }

        if (val < curr->ID)
        {
            curr->left = insert(curr->left, val, name, d);
        }
        else if (val > curr->ID)
        {
            curr->right = insert(curr->right, val, name, d);
        }
        else
            return curr;

        curr->height = 1 + max(height(curr->left), height(curr->right));
        int balance = getbalance(curr);

        if (balance < -1 && val > curr->right->ID)
        {
            return leftRotate(curr);
        }
        if (balance > 1 && val < curr->left->ID)
        {
            return rightRotate(curr);
        }
        if (balance < -1 && val < curr->right->ID)
        {
            curr->right = rightRotate(curr->right);
            return leftRotate(curr);
        }
        if (balance > 1 && val > curr->left->ID)
        {
            curr->left = leftRotate(curr->left);
            return rightRotate(curr);
        }

        return curr;
    }

    void preOrder(node *n)
    {
        if (n == NULL)
            return;

        cout << n->ID << "\t";

        preOrder(n->left);
        preOrder(n->right);
    }

    void inOrder(node *n)
    {
        if (n == NULL)
            return;

        inOrder(n->left);

        cout << n->ID << "\t";

        inOrder(n->right);
    }

    void postOrder(node *n)
    {
        if (n == NULL)
            return;

        postOrder(n->left);
        postOrder(n->right);

        cout << n->ID << "\t";
    }

    node *search(node *curr, int val)
    {
        if (curr == NULL)
            return NULL;
        if (curr->ID == val)
        {
            cout << " Employee found" << endl;
            cout << "Name:  " << curr->name << endl;
            cout << "ID:  " << curr->ID << endl;
            cout << "Designation: " << curr->designation << endl;
            return curr;
        }
        else if (val < curr->ID){
            return search(curr->left, val);
        }
        else if(val>curr->ID){
            return search(curr->right, val);
        }
        else
        cout<<"Employee Id not found"<<endl;
    }

    node *findMax(node *n)
    {
        if (n == NULL)
            return NULL;
        if (n->right == NULL)
            return n;
        else
            return findMax(n->right);
    }

    node *findMin(node *n)
    {
        if (n == NULL)
            return NULL;
        if (n->left == NULL)
            return n;
        else
            return findMin(n->left);
    }

    node *deleteNode(int val, node *root)
    {
        if (root == NULL)
        cout<<" ID to be deleted not found "<<endl;
            return NULL;
        if (val < root->ID)
            root->left = deleteNode(val, root->left);
        else if (val > root->ID)
            root->right = deleteNode(val, root->right);
        else
        {
            if (root->left == NULL && root->right == NULL)
            {
                delete root;
                root = NULL;
            }
            else if (root->left == NULL)
            {
                node *t = root;
                root = root->right;
                delete t;
            }
            else if (root->right == NULL)
            {
                node *t = root;
                root = root->left;
                delete t;
            }
            else
            {
                node *t = findMin(root->right);
                root->ID = t->ID;
                root->right = deleteNode(t->ID, root->right);
            }
        }
        if (root == NULL)
            return root;

        root->height = 1 + max(height(root->left), height(root->right));
        int balance = getbalance(root);
        // case1
        if (balance < -1 && getbalance(root->right) <= 0)
        {
            return leftRotate(root);
        }
        // case2
        if (balance > 1 && getbalance(root->left) >= 0)
        {
            return rightRotate(root);
        }
        // case3
        if (balance < -1 && getbalance(root->right) > 0)
        {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }
        // case4
        if (balance > 1 && getbalance(root->left) < 0)
        {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }

        return root;
    }

    void updateValue(int id, string n1, string n2)
    {
    
        root = deleteNode(id, root);
        root = insert(root, id, n1, n2);
    }

    void printTree(node *root)
    {
        if (root == NULL)
            return;

        printTree(root->left);
        cout << root->ID << '\t';
        printTree(root->right);
    }
};

int main()
{
    Tree t;

    while (true)
    {
        cout << "1. Add Employee" << endl;
        cout << "2. Search for an employee" << endl;
        cout << "3. Generate organizational chart" << endl;
        cout << "4. Modify Employee Information" << endl;
        cout << "5. Remove Employee" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        if (choice == 1)
        {
            cout << "Enter Employee ID: ";
            int id;
            cin >> id;
            cout << "Enter Employee Name: ";
            string name;
            cin >> name;
            cout << "Enter Employee designation: ";
            string designation;
            cin >> designation;
            t.root = t.insert(t.root, id, name, designation);
            cout << "Employee added" << endl;
        }
        else if (choice == 2)
        {
            cout << "Enter Employee ID: ";
            int id;
            cin >> id;
            t.search(t.root, id);
        }
        else if (choice == 3)
        {
            t.printTree(t.root);
            cout << endl;
        }
        else if (choice == 4)
        {
            cout << "Enter Employee ID to be modified: ";
            int id;
            cin >> id;
            cout << "Enter new name: ";
            string newN;
            cin >> newN;
            cout << "Enter new designation: ";
            string nDesign;
            cin >> nDesign;
            t.updateValue(id, newN, nDesign);
        }
        else if (choice == 5)
        {
            cout << "Enter Employee ID to remove: ";
            int id;
            cin >> id;
            t.root = t.deleteNode(id, t.root);
        }
        else if (choice == 6)
        {
            break;
        }
        else
        {
            cout << "Invalid choice. Please enter a valid option." << endl;
        }
    }

    return 0;
}