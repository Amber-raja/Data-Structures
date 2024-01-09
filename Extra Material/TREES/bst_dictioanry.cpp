#include <iostream>
#include <cmath>
#include <string.h>
using namespace std;

class Node
{
public:
    string words;
    string meanings;
    Node *left;
    Node *right;
    Node(string w, string m)
    {
        this->words = w;
        this->meanings = m;
        left = NULL;
        right = NULL;
    }
};

class Dictionary
{
public:
    Node *root;

    Dictionary()
    {
        root = NULL;
    }

    void insert(string lfaz, string mtlb)
    {
        Node *newNode = new Node(lfaz, mtlb);

        if (root == NULL)
        {
            root = newNode;
        }

        else
        {

            Node *curr = root;
            while (curr != NULL)
            {
                if (newNode->words < curr->words && curr->left == NULL)
                {
                    curr->left = newNode;
                    break;
                }
                else if (newNode->words < curr->words)
                {
                    curr = curr->left;
                }
                else if (newNode->words > curr->words && curr->right == NULL)
                {
                    curr->right = newNode;
                    break;
                }
                else if (newNode->words > curr->words)
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

    void display(Node *currentNode)
    {
        if (currentNode != nullptr)
        {
            display(currentNode->left);
            cout << "Word: " << currentNode->words << ", Meaning: " << currentNode->meanings << endl;
            display(currentNode->right);
        }
    }

    Node *Search(Node *thisNode, string word)
    {

        if (thisNode == NULL)
        {
            return NULL;
        }
        if (thisNode->words == word)
        {

            return thisNode;
        }

        if (word < thisNode->words)
        {
            return Search(thisNode->left, word);
        }
        else
        {
            return Search(thisNode->right, word);
        }
    }

    void Update(Node *thisNode, string oldMeaning, string newMeaning)
    {

        if (thisNode == NULL)
        {
            return;
        }

        if (oldMeaning == thisNode->meanings)
        {
            thisNode->meanings = newMeaning;
            return;
        }

        if (oldMeaning < thisNode->meanings)
        {
            Update(thisNode->left, oldMeaning, newMeaning);
        }
        else
        {
            Update(thisNode->right, oldMeaning, newMeaning);
        }
    }

    Node *findMin(Node *thisNode)
    {
        if (thisNode == NULL)
        {
            return NULL;
        }
        if (thisNode->left == NULL)
        {
            return thisNode;
        }
        return findMin(thisNode->left);
    }
    Node *findMax(Node *thisNode)
    {
        if (thisNode == NULL)
        {
            return NULL;
        }
        if (thisNode->right == NULL)
        {
            return thisNode;
        }
        return findMin(thisNode->right);
    }

    void remove(int value)
    {
    }
};

int main()
{
    Dictionary dictionary;
    dictionary.insert("2010", "Edition0");
    dictionary.insert("2011", "Edition1");
    dictionary.insert("2013", "Edition3");
    dictionary.insert("2012", "Edition3");

    dictionary.display(dictionary.root);

    dictionary.Update(dictionary.root, "Edition3", "Edition2");
    string word;
    cout << "Enter a word to search for its meaning: ";
    cin >> word;

    Node *temp = dictionary.Search(dictionary.root, word);
    if (temp == NULL)
    {
        cout << "No meaning found for the word." << endl;
    }
    else
    {
        cout << temp->words << ": " << temp->meanings << endl;
    }

    dictionary.display(dictionary.root);

    return 0;
}