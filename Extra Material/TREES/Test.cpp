#include <iostream>

class Node
{
public:
    std::string word;
    std::string meaning;
    Node *left;
    Node *right;

    Node(std::string word, std::string meaning);
};

Node::Node(std::string word, std::string meaning)
{
    this->word = word;
    this->meaning = meaning;
    left = nullptr;
    right = nullptr;
}

class BST
{
private:
    Node *root;

public:
    BST();
    void insert(std::string word, std::string meaning);
    void display();
    std::string search(std::string word);

private:
    void insert(Node *currentNode, std::string word, std::string meaning);
    void display(Node *currentNode);
    std::string search(Node *currentNode, std::string word);
};

BST::BST()
{
    root = nullptr;
}

void BST::insert(std::string word, std::string meaning)
{
    if (root == nullptr)
    {
        root = new Node(word, meaning);
    }
    else
    {
        insert(root, word, meaning);
    }
}

void BST::insert(Node *currentNode, std::string word, std::string meaning)
{
    if (word < currentNode->word)
    {
        if (currentNode->left != nullptr)
        {
            insert(currentNode->left, word, meaning);
        }
        else
        {
            currentNode->left = new Node(word, meaning);
        }
    }
    else if (word > currentNode->word)
    {
        if (currentNode->right != nullptr)
        {
            insert(currentNode->right, word, meaning);
        }
        else
        {
            currentNode->right = new Node(word, meaning);
        }
    }
    // Handle case when word already exists in the tree (duplicate)
    else
    {
        // Update the meaning of the existing word
        currentNode->meaning = meaning;
    }
}

void BST::display()
{
    display(root);
}

void BST::display(Node *currentNode)
{
    if (currentNode != nullptr)
    {
        display(currentNode->left);
        std::cout << "Word: " << currentNode->word << ", Meaning: " << currentNode->meaning << std::endl;
        display(currentNode->right);
    }
}

std::string BST::search(std::string word)
{
    return search(root, word);
}

std::string BST::search(Node *currentNode, std::string word)
{
    if (currentNode == nullptr)
    {
        return "";
    }

    if (currentNode->word == word)
    {
        return currentNode->meaning;
    }

    if (word < currentNode->word)
    {
        return search(currentNode->left, word);
    }
    else
    {
        return search(currentNode->right, word);
    }
}

int main()
{
    BST dictionary;
    dictionary.insert("ABC", "A programming language");
    dictionary.insert("ABCD", "A numeral system");
    dictionary.insert("ABCDE", "To look for something");
    dictionary.insert("F", "A data structure");
    dictionary.insert("G", "A data structure");
    dictionary.insert("H", "A data structure");
    dictionary.insert("Z", "A data structure");
    dictionary.insert("I", "A data structure");

    dictionary.display();

    std::string word;
    std::cout << "Enter a word to search for its meaning: ";
    std::cin >> word;

    std::string meaning = dictionary.search(word);
    if (meaning.empty())
    {
        std::cout << "No meaning found for the word." << std::endl;
    }
    else
    {
        std::cout << "Meaning: " << meaning << std::endl;
    }

    return 0;
}