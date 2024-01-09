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

class List
{
    node* head;
    int length;
    public:
      List()
      {
          head = NULL;
          length = 0;
      }
      ~List()
      {
         node* curr = NULL;
         while(head != NULL)
         {  curr = head;
             head = head->next;
             delete curr;
            
         }
      }

      void insert(int val,int pos)
      {
        if(pos < 1 || pos > length+1)
        {
            cout<<"Invalid position"<<endl;
            return;
        }
        node*  n = new node(val);

        if(pos == 1)
        {
            n->next = head;
            head = n;
        }
        else
        {
            node* curr = head;
            for(int i = 1 ; i < pos - 1 ; i++)
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
            if(head == NULL)
            {
                cout<<"List is empty"<<endl;
                return;
            }
            if(pos < 1 || pos > length)
            {
                cout<<"Invalid position"<<endl;
                return;
            }
            node* curr = head;
            if(pos == 1)
            {
                head = head->next;
                delete curr;
            }
            else
            {
                node* slow = NULL;
                for(int i = 1 ; i < pos ; i++)
                {
                    slow = curr;
                    curr = curr->next;
                }
                slow->next = curr->next;
                delete curr;

            }
            length--;
        }

        node* get_head()
        {
            return head;
        }
    int find(int val)
        {
            node* curr = head;
            for(int i = 1 ; i <= length ; i++)
             {
                    if(curr->data == val)
                    {
                        return  i;
                    }
                    curr = curr->next;


             }
                return -1;
        }
    void rem_val(int val)
    { 
        int pos = find(val);
        if(pos == -1)
        {
            cout<<"Value not found"<<endl;
            return;
        }
        remove(pos);
    }

    void display()
    {
        node* curr = head;
        while(curr != NULL)
        {
            cout<<curr->data<<" ";
            curr = curr->next;
        }
        cout<<endl;
    }
    void clear()
    {
        while(head != NULL)
        {
           remove(1);

        }
    }
    int len()
    {
        return length;
    }
   
     void copy(List& l)
    {
        node* curr = l.head;
        while(curr != NULL)
        {
            insert(curr->data,length+1);
            curr = curr->next;
        }
    }
    
    node* reverse(node* head, int k)
{   
	if (!head)
		return NULL;
	node* current = head;
	node* next = NULL;
	node* prev = NULL;
	int count = 0;

	/*reverse first k nodes of the linked list */
	while (current != NULL && count < k) {
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
		count++;
	}

	/* next is now a pointer to (k+1)th node
	Recursively call for the list starting from current.
	And make rest of the list as next of first node */
    for(int i = 0 ; i < length ; i++)
    {
      count = i;
    { 
        if(count%2 == 0)
    {
	if (next != NULL)
		head->next = reverse(next, k);
    }
    else
    { 
       //move the pointers skipping k nodes
        for(int j = 0 ; j < k ; j++)
        {
            prev = current;
            current = current->next;
            next = current->next;
        }
        



        
        
    }
    }
    }
	/* prev is new head of the input list */
	return prev;
}

  void reversekNodes(int k)
    {
        head = reverse(head,k);
    }

      };



 int main()
 {
        List l;
        l.insert(10,1);
        l.insert(20,2);
        l.insert(30,3);
        l.insert(40,4);
        l.insert(50,5);
        l.insert(60,6);
        l.insert(70,7);
        l.insert(80,8);
        l.insert(90,9);
        l.insert(100,10);
        l.display(); 
        l.reversekNodes(3);

        l.display();
        return 0;
 } 
 