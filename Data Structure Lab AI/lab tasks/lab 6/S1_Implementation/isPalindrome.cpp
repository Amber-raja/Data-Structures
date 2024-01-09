#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;

    node(int val)
    {
        data = val;
        next = NULL;
    }
};

class Cir_list
{
    node *head;
    int length;

public:
    Cir_list()
    {
        head = NULL;
        length = 0;
    }
    ~Cir_list()
    {
        while (head != NULL)
        {
            node *curr = head;
            head = head->next;

            if (head == curr)
            {
                head = NULL;
            }
            else
            {
                node *tail = head;
                while (tail->next != curr)
                {
                    tail = tail->next;
                }
                tail->next = head;
            }

            delete curr;
            length--;
        }
    }

    void insert(char val, int pos)
    {
        if (pos < 1 || pos > length + 1)
        {
            cout << "Invalid position" << endl;
            return;
        }
        node *n = new node(val);
        node *curr = head;
        if (head == NULL)
        {
            head = n;
            head->next = head;
        }

        else if (pos == 1)
        {
            n->next = head;
            while (curr->next != head)
            {
                curr = curr->next;
            }
            curr->next = n;
            head = n;
        }
        else
        {
            node *curr = head;
            for (int i = 1; i < pos - 1; i++)
            {
                curr = curr->next;
            }
            n->next = curr->next;
            curr->next = n;
        }
        length++;
    }

    void remove(int pos)
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
            return;
        }
        if (pos < 1 || pos > length)
        {
            cout << "Invalid position" << endl;
            return;
        }
        node *curr = head;
        node *tail = head;
        if (pos == 1)
        {
            while (tail->next != head)
            {
                tail = tail->next;
            }
            head = head->next;
            tail->next = head;
            if (head == head->next)
            {
                head = NULL;
            }
            delete curr;
        }
        else
        {
            node *slow = NULL;
            for (int i = 1; i < pos; i++)
            {
                slow = curr;
                curr = curr->next;
            }
            slow->next = curr->next;
            delete curr;
        }
        length--;
    }
    int find(int val)
    {
        node *curr = head;
        for (int i = 1; i <= length; i++)
        {
            if (curr->data == val)
            {
                return i;
            }
            curr = curr->next;
        }
        return -1;
    }
    void rem_val(int val)
    {
        int pos = find(val);
        if (pos == -1)
        {
            cout << "Value not found" << endl;
            return;
        }
        remove(pos);
    }

    void display()
    {
        node *curr = NULL;
        while (curr != head)
        {
            if (curr == NULL)
            {
                curr = head;
            }
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    }

    void clear()
    {
        while (head != NULL)
        {
            remove(1);
        }
    }

    int len()
    {
        return length;
    }

    bool isPalindrome()
{
    int len = this->len();
    if (len <= 1)
    {
        
        return true;
    }

    
    int *values = new int[len];
    node *current = head;
    for (int i = 0; i < len; i++)
    {
        values[i] = current->data;
        current = current->next;
    }

    
    int left = 0;
    int right = len - 1;
    while (left < right)
    {
        if (values[left] != values[right])
        {
            
            delete[] values;
            return false;
        }
        left++;
        right--;
    }

    
    delete[] values;
    return true;
}

};

int main()
{
    Cir_list c;
    c.insert(1, 1);
    c.insert(1, 2);
    c.insert(2, 3);
    c.insert(2, 4);
    c.insert(1, 5);
    c.insert(1, 6);

    c.display();

    if (c.isPalindrome()) {
        cout << "The list is a palindrome." << endl;
    } else {
        cout << "The  list isn't a palindrome." << endl;
    }

    return 0;
}