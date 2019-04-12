#include <iostream>

using namespace std;

struct intNode
{
    int item;
    intNode * next = nullptr;
    intNode(int x):item(x){}
};
//template <typename T>
class myVector
{
private:
    intNode * head = nullptr;
    intNode * tail = nullptr;
public:
    void push_back(int item);
    void pop_back();
    void display();

};

//template <typename T>
void myVector::push_back(int item)
{
    /// TO DO: Add your code here
    return;
}

void myVector::pop_back()
{
    /// TO DO: Add your code here
    return;
}
void myVector::display()
{
    intNode *p = head;
    while (p != nullptr)
    {
        cout << p->item << " ";
        p = p ->next;
    }

}
int main()
{
    myVector myVect;

    myVect.push_back(3);
    myVect.push_back(5);
    myVect.display();

    myVect.pop_back();
    myVect.display();

    return 0;
}
