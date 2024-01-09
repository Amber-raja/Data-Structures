
#include <iostream>
using namespace std;
class Stack
{
private:
    int size;  
    int top;   
    char *Arr; 
public:
    Stack(const string &str)
    {
        size = str.length();
        top = -1;
        Arr = new char[size];
    }

    ~Stack()
    {
        delete[] Arr;
    }

    
    bool isEmpty()
    {
        return top == -1;
    }

    
    bool isFull()
    {
        return top == size - 1;
    }

   
    void push(char value)
    {
        if (isFull())
        {
            cout << "Stack is full" << endl;
            return;
        }
        Arr[++top] = value;
    }

    
    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack is empty." << endl;
            return -1; 
        }
        return Arr[top--];
    }

  
    int peek()
    {
        if (isEmpty())
        {
            cout << "Stack is empty" << endl;
            return -1; 
        }
        return Arr[top];
    }

    bool ismatching(string &input)
    {
        char ch;
        for (int i = 0; i < size; i++)
        {
            if (input[i] == '(' || input[i] == '[' || input[i] == '{')
            {
                push(input[i]);
            }
            else if (input[i] == ')' || input[i] == ']' || input[i] == '}')
            {
                if (isEmpty())
                {
                    return false;
                }
                
                char topelement = peek();
                pop();
                if ((input[i] == ')' && topelement != '(') ||
                    (input[i] == '}' && topelement != '{') ||
                    (input[i] == ']' && topelement != '['))
                {
                    return false; 
                }
            }
        }
        return isEmpty();
    }

};

int main()
{
    string s;
    s= "({[]})";
    Stack stack(s); 
    if(stack.ismatching(s)){
        cout<<"Brackets matched"<<endl;
    }
    else {
        cout<<"Brackets donot matched"<<endl;
    }
    return 0;
}


