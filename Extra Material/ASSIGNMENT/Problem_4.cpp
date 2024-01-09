#include <iostream>
#include <string>

using namespace std;

class Node
{
public:
    int id;
    string name;
    string designation;
    Node *left;
    Node *right;
    int height;

    Node(int id, string name, string designation)
    {
        this->id = id;
        this->name = name;
        this->designation = designation;
        this->left = nullptr;
        this->right = nullptr;
        this->height = 1;
    }
};

class Tree
{
public:
    Node *root;

    Tree()
    {
        root = nullptr;
    }

    int getHeight(Node *node)
    {
        if (node == nullptr)
            return 0;
        return node->height;
    }

    int getBalanceFactor(Node *node)
    {
        if (node == nullptr)
            return 0;
        return getHeight(node->left) - getHeight(node->right);
    }

    Node *rotateLeft(Node *node)
    {
        Node *newRoot = node->right;
        Node *temp = newRoot->left;

        newRoot->left = node;
        node->right = temp;

        node->height = 1 + max(getHeight(node->left), getHeight(node->right));
        newRoot->height = 1 + max(getHeight(newRoot->left), getHeight(newRoot->right));

        return newRoot;
    }

    Node *rotateRight(Node *node)
    {
        Node *newRoot = node->left;
        Node *temp = newRoot->right;

        newRoot->right = node;
        node->left = temp;

        node->height = 1 + max(getHeight(node->left), getHeight(node->right));
        newRoot->height = 1 + max(getHeight(newRoot->left), getHeight(newRoot->right));

        return newRoot;
    }

    Node *insertEmployee(Node *node, int id, const string &name, const string &designation)
    {
        if (node == nullptr)
        {
            // Create a new node with the given information
            return new Node(id, name, designation);
        }

        if (id < node->id)
        {
            // Check if ID is already present in the left subtree
            if (searchById(node->left, id) != nullptr)
            {
                cout << "Employee with ID " << id << " already exists!" << endl;
                return node;
            }
            node->left = insertEmployee(node->left, id, name, designation);
        }
        else if (id > node->id)
        {
            // Check if ID is already present in the right subtree
            if (searchById(node->right, id) != nullptr)
            {
                cout << "Employee with ID " << id << " already exists!" << endl;
                return node;
            }
            node->right = insertEmployee(node->right, id, name, designation);
        }
        else
        {
            cout << "Employee with ID " << id << " already exists!" << endl;
            return node;
        }

        node->height = 1 + max(getHeight(node->left), getHeight(node->right));

        int balanceFactor = getBalanceFactor(node);

        if (balanceFactor > 1 && id < node->left->id)
            return rotateRight(node);

        if (balanceFactor < -1 && id > node->right->id)
            return rotateLeft(node);

        if (balanceFactor > 1 && id > node->left->id)
        {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }

        if (balanceFactor < -1 && id < node->right->id)
        {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }

        return node;
    }

    Node *searchById(Node *node, int id)
    {
        if (node == nullptr || node->id == id)
            return node;

        if (id < node->id)
            return searchById(node->left, id);

        return searchById(node->right, id);
    }

    void printOrganizationalChart(Node *node, int tabs)
    {
        if (node == nullptr)
            return;

        printOrganizationalChart(node->left, tabs + 1);

        for (int i = 0; i < tabs; i++)
            cout << "\t";
        cout << node->name << " (" << node->designation << ")" << endl;

        printOrganizationalChart(node->right, tabs + 1);
    }

    Node *getMinValueNode(Node *node)
    {
        Node *current = node;
        while (current->left != nullptr)
            current = current->left;
        return current;
    }

    Node *removeEmployeeById(Node *node, int id)
    {
        if (node == nullptr)
            return node;

        if (id < node->id)
            node->left = removeEmployeeById(node->left, id);
        else if (id > node->id)
            node->right = removeEmployeeById(node->right, id);
        else
        {
            if (node->left == nullptr || node->right == nullptr)
            {
                Node *temp = node->left ? node->left : node->right;

                if (temp == nullptr)
                {
                    temp = node;
                    node = nullptr;
                }
                else
                    *node = *temp;

                delete temp;
            }
            else
            {
                Node *temp = getMinValueNode(node->right);

                node->id = temp->id;
                node->name = temp->name;
                node->designation = temp->designation;

                node->right = removeEmployeeById(node->right, temp->id);
            }
        }

        if (node == nullptr)
            return node;

        node->height = 1 + max(getHeight(node->left), getHeight(node->right));

        int balanceFactor = getBalanceFactor(node);

        if (balanceFactor > 1 && getBalanceFactor(node->left) >= 0)
            return rotateRight(node);

        if (balanceFactor > 1 && getBalanceFactor(node->left) < 0)
        {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }

        if (balanceFactor < -1 && getBalanceFactor(node->right) <= 0)
            return rotateLeft(node);

        if (balanceFactor < -1 && getBalanceFactor(node->right) > 0)
        {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }

        return node;
    }
};

int main()
{
    Tree tree;

    int choice;
    int id;
    string name;
    string designation;

    Node *foundEmployee = nullptr;
    Node *employeeToModify = nullptr;

    while (true)
    {
        cout << "Menu Options:" << endl;
        cout << "1. Add Employee" << endl;
        cout << "2. Search for Employee" << endl;
        cout << "3. Generate Organizational Chart" << endl;
        cout << "4. Modify Employee Information" << endl;
        cout << "5. Remove Employee" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter employee ID: ";
            cin >> id;
            cout << "Enter employee name: ";
            cin >> name;
            cout << "Enter employee designation: ";
            cin >> designation;
            tree.root = tree.insertEmployee(tree.root, id, name, designation);
            break;

        case 2:
            cout << "Enter employee ID to search: ";
            cin >> id;
            foundEmployee = tree.searchById(tree.root, id);
            if (foundEmployee != nullptr)
            {
                cout << "Employee Details:" << endl;
                cout << "ID: " << foundEmployee->id << endl;
                cout << "Name: " << foundEmployee->name << endl;
                cout << "Designation: " << foundEmployee->designation << endl;
            }
            else
            {
                cout << "Employee not found!" << endl;
            }
            break;

        case 3:
            cout << "Organizational Chart:" << endl;
            tree.printOrganizationalChart(tree.root, 0);
            break;

        case 4:
            cout << "Enter employee ID to modify: ";
            cin >> id;
            employeeToModify = tree.searchById(tree.root, id);
            if (employeeToModify != nullptr)
            {
                cout << "Enter new employee name: ";
                cin >> name;
                cout << "Enter new employee designation: ";
                cin >> designation;
                employeeToModify->name = name;
                employeeToModify->designation = designation;
                cout << "Employee information updated!" << endl;
            }
            else
            {
                cout << "Employee not found!" << endl;
            }
            break;

        case 5:
            cout << "Enter employee ID to remove: ";
            cin >> id;
            tree.root = tree.removeEmployeeById(tree.root, id);
            cout << "Employee removed successfully!" << endl;
            break;

        case 6:
            exit(0);

        default:
            cout << "Invalid choice! Please try again." << endl;
        }

        cout << endl;
    }

    return 0;
}