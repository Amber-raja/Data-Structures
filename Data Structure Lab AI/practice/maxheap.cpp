#include<iostream>
#include <vector>
using namespace std;
class heap {
public:
vector <int> htree;
  int getParent(int child) {
        if (child == 0) {
            return -1;
        }
        return (child - 1) / 2;
    }

    int getLeft(int parent) {
        if ((2 * parent) + 1 >= htree.size()) {
            return -1;
        }
        return (2 * parent) + 1;
    }

    int getRight(int parent) {
        if ((2 * parent) + 2 >= htree.size()) {
            return -1;
        }
        return (2 * parent) + 2;
    }


void swap(int *a, int *b) {
    int temp=*a;
*a=*b;
*b=temp;
}
void heapifyUp(int node) {
int parent=getParent(node);
if(node >=0 && parent >=0 && htree[parent] < htree[node])
{
swap(&htree[node], &htree[parent]);
heapifyUp(getParent(node));
}
}
void heapifyDown(int node)
{
int lchild= getLeft(node);
int rchild= getRight(node);
int largest;
if(lchild >=0 && rchild>=0)
{
if(htree[lchild] > htree[rchild])
{
largest=lchild;
}
else if(htree[rchild] > htree[lchild])
{
largest=rchild;
}
if(largest>0)
{
swap(&htree[largest], &htree[node]);
heapifyDown(largest);
}
}
}
void insert(int value) {
int size= htree.size();
if(size==0) {
htree.push_back(value);
} else {
htree.push_back(value);
heapifyUp(htree.size()-1);
}
}
void del(int value) {
int index=-1;
for(int i=0; i<htree.size(); i++)
{
if(htree[i]==value)
{
index=i;
break;
}
}
if(index!=-1)
{
swap(&htree[index], &htree[htree.size()-1]);
htree.pop_back();
heapifyDown(index);
}
}
void display() {
for(int i=0; i<htree.size(); i++) {
cout<<htree[i]<<" ";
}
cout<<endl;
}

};
int main() {
    heap h;
h.insert(5);
h.insert(3);
h.insert(8);
h.insert(9);
h.insert(2);
h.insert(7);
h.insert(9);
h.display();
h.del(5);
h.del(3);
h.display();
}