#include <iostream>
using namespace std;

class node
{
public:
    int data;
    string name;
    node *left, *right;

    node(string gemName, int gemPower)
    {
        data = gemPower;
        name = gemName;
        left = right = NULL;
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

    node *insert(node *current, string gemName, int gemPower)
    {
        if (current == NULL)
        {
            return new node(gemName, gemPower);
        }
        if (gemPower == current->data)
        {
            cout << "Value already present in the tree" << endl;
        }
        else if (gemPower > current->data)
        {
            current->right = insert(current->right, gemName, gemPower);
        }
        else
        {
            current->left = insert(current->left, gemName, gemPower);
        }
        return current;
    }

    node *search(node *current, int gemPower)
    {
        if (current == NULL)
        {
            cout << "Tree is empty" << endl;
            return NULL;
        }
        if (gemPower == current->data)
        {
            cout << "Gem found: " << current->name << " (" << current->data << ")\n";
            return current;
        }
        else if (gemPower > current->data)
        {
            return search(current->right, gemPower);
        }
        else
        {
            return search(current->left, gemPower);
        }
    }

    void inorder(node *temp)
    {
        if (temp == NULL)
            return;
        inorder(temp->left);
        cout << temp->name << " (" << temp->data << ")" << endl;
        inorder(temp->right);
    }

    void preorder(node *temp)
    {
        if (temp == NULL)
            return;
        cout << temp->name << " (" << temp->data << ")" << endl;
        preorder(temp->left);
        preorder(temp->right);
    }

    void postorder(node *temp)
    {
        if (temp == NULL)
            return;
        postorder(temp->left);
        postorder(temp->right);
        cout << temp->name << " (" << temp->data << ")" << endl;
    }

    node *FindMaxPowerGem(node *current)
    {
        if (current == NULL)
            return NULL;

        while (current->right != NULL)
        {
            current = current->right;
        }

        return current;
    }

    void remove(int gemPower, node *&current)
    {
        if (current == NULL)
        {
            cout << "Gem with power " << gemPower << " not found." << endl;
            return;
        }

        if (gemPower == current->data)
        {
            if (current->left == NULL && current->right == NULL)
            {
                delete current;
                current = NULL;
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
                node *successor = FindMaxPowerGem(current->left);
                current->data = successor->data;
                current->name = successor->name;
                remove(successor->data, current->left);
            }
        }
        else if (gemPower < current->data)
        {
            remove(gemPower, current->left);
        }
        else
        {
            remove(gemPower, current->right);
        }

        
    }
};

int main()
{
    BST t;
    int x = 100; 

    t.root = t.insert(t.root, "Diamond", 50);
    t.root = t.insert(t.root, "Ruby", 30);
    t.root = t.insert(t.root, "Sapphire", 70);
    t.root = t.insert(t.root, "Pearl", 40);
    t.root = t.insert(t.root, "Opal", 10);
    t.root = t.insert(t.root, "Garnet", 60);
    t.root = t.insert(t.root, "Zircon", 20);
    t.root = t.insert(t.root, "Jade", 5);

    int current_pow = 0;

    int choice;
    
        cout << "Enter your choices:" << endl;
        cout << "1: Traverse the BST" << endl;
        cout << "2: Delete a gem from the tree" << endl;
        cout << "3: Search for a gem" << endl;
        cout << "4: Find gem with the highest power" << endl;
        cout << "5: Quit" << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            int ch;
            cout << "1. Preorder" << endl;
            cout << "2. Inorder" << endl;
            cout << "3. Postorder" << endl;
            cin >> ch;

            switch (ch)
            {
            case 1:
                t.preorder(t.root);
                break;
            case 2:
                t.inorder(t.root);
                break;
            case 3:
                t.postorder(t.root);
                break;
            default:
                cout << "Invalid choice!" << endl;
                break;
            }
            cout << endl;
            break;

        case 2:
        {
            while(current_pow<x){
            int v;
            cout << "Enter the power of the gem you want to remove: "<<endl;
            cin >> v;
            node *gemToRemove = t.search(t.root, v);
            if (gemToRemove != NULL)
            {
                current_pow += gemToRemove->data;
                t.remove(v, t.root);
                cout << "Gem removed and added to your bag." << endl;
                
                
            }
            break;
            }
             if (current_pow >= x)
            {
                cout << "You won! Now take your bag and run from the forest" << endl;
            }
            else
            {
                cout << "You lost! Your bag burst. Now run and save yourself from the witch" << endl;
            }
            
        }

        case 3:
        {
            int s;
            cout << "Enter the power of the gem you want to search for: ";
            cin >> s;
            t.search(t.root, s);
            break;
        }

        case 4:
        {
            node *maxGem = t.FindMaxPowerGem(t.root);
            if (maxGem != NULL)
            {
                cout << "Gem with the highest power: " << maxGem->name << " (" << maxGem->data << ")\n";
            }
            else
            {
                cout << "No gems found in the enchanted forest." << endl;
            }
            break;
        }

        case 5:
            cout << "Exiting" << endl; 
            return 0;
        }
    
    return 0;
}