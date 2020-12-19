/* name : mohammed kabashi hammad
class :second 
department: computer */

#include <iostream>
#include <string>
using namespace std;
const int maxSize = 10;
/*=<<<<<<<<<<<<<<<<<<<<<<<<<<<linked list>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
class Linked_List
{
private:
    struct Node
    {
        int item;
        Node*next;
    };
    Node*first;
    Node*last;
    int length;
public:
    Linked_List(){
    first = last = NULL;
    length = 0;
    }

    bool isEmpty() // الدله لتفقد اذا ما كانت فارغه ام لا 
    {
        return length == 0;
    }

    void addFirst(int num) //لاضافه عنصر في بدابه القائمه واستبداله
    {
     
     Node*newNode = new Node;
     newNode->item = num;
     if (length==0)
     {
         first = last = newNode;
         newNode->next = NULL;
     }   
     else {
         newNode->next=first;
         first = newNode;
     }
     length++;
    }

    void addLast(int num) //لاضافه عنصر في اخر القائمه
    {
        
        Node *newNode = new Node;
        newNode->item = num;
        if (length == 0)
        {
            first = last = newNode;
            newNode->next = NULL;
        }
        else{
            last->next = newNode;
            newNode->next = NULL;
            last = newNode;
        }
        length++;
    }

    void addAtpos(int pos, int num) //لاضافه عنصر في موقع في القائمه
    {

        if(pos < 0 || pos > length)
        cout<<"Out of Range\n";
        else
        {
            Node*newNode = new Node;
            newNode->item = num;
            if(pos==0)
                addFirst(num);
            else if(pos == length)
                addLast(num);
            else
            {
                Node * cur = first;
                for (int i = 1; i < pos; i++)
                {
                    cur = cur->next;
                }
                newNode->next = cur->next;
                cur->next = newNode;
                length++;
            }
        }
         
    }

    void remove(int num) //داله لحزف العنصر في القائمه
    {
        if (isEmpty()) //للتحقق من ان القائمه ليست فارغه
        {
            cout << "Empty List can't Remove\n";
            return;
        }
        Node *curr, *prev;
        if (first->item == num)
        {
            curr = first;
            first = first->next;
            delete curr;
            length--;
            if (length==0)
            {
                last = NULL;
            }
        }
        else
        {
                curr = first->next;
                prev = first;
            
            
            while (curr != NULL)
            {
               if (curr->item == num)
               break;
               prev = curr;
               curr = curr->next;
            }

            if (curr == NULL)
               cout <<"NOT FOUND!\n";
            
            else
            {
                prev->next = curr->next;
                if (last == curr)
                {
                    last = prev;
                    delete curr;
                    length--;
                }
                
            }
        }
        
    }

    void print() //داله لطباعه عناصر القائمه
    {
        cout << "<<<<<<<<<<<<<THE LINKED LIST>>>>>>>>>>>>\n";
        Node*cur = first;
        cout << "[ ";
        while (cur != NULL)
        {
            cout << cur->item << " ";
            cur=cur->next;
        }
        cout << "]\n";
    }
};

/*>>>>>>>>>>>>stack<<<<<<<<<<<<<<<<<<<<<*/
class Stack
{
    private:
        int stackArray [maxSize];
        int Top;

    public:
       Stack():Top (-1){}

       void push(int element) //داله لاضافه عناصر الى المكدسه
       {
           if (Top >= maxSize - 1)
           {
               cout << "Stack is Full! \n";
           }
           else
           {
               Top++;
               stackArray[Top] = element;
           }
        }

        bool isEmpty() //للتحقق اذا ما كانت فارغه
        {
            return Top < 0;
        }

        void pop() //دداله لحزف عنصر من المكدسه
        {
            if (isEmpty())
            {
                cout << "Stack is Empty !\n";
            }
            else
            {
                Top--;
            }
        }

        void print() //داله لطباعه عناصر المكدس
        {
            cout<<"<==========STACK=========>"<<endl;
            cout <<"---\n";
            for (int i = Top; i >= 0; i--)
            {
                cout << stackArray[i] << endl;
            }
            cout << "---";
        }
    
};
/*<<<<<<<<<<<<<<<<<<<queue>>>>>>>>>>>>>>>>>>*/
class Queue
{
    int front, end, length, queueArray[maxSize];
public:
    Queue(){
        front = 0;
        end = maxSize - 1;
        length = 0;
    }

    bool isEmpty()//لتتحقق ماااذا كان الصف فارغا
    {
        return length == 0;
    }

    bool isFull()
    {
        return length == maxSize;
    }

    void addQ(int num) //لاضافه عنصر الى الصف
    {
        if (isFull()) //لتتحق من ما اذا كان الصف ممتلئ
        {
            cout << "Queue is Full can't ADD\n";
        }
        else
        {
            end = (end + 1) % maxSize;
            queueArray[end] = num;
            length++;
        }
    }

    void deleteQ() //لحذف عناصر من الصف
    {
        if (isEmpty()) //لتحقق من ما اذا كان الصف فارغا
        {
            cout << "Queue is Empty can't DELETE\n";
        }
        else
        {
            front = (front+1) % maxSize ;
            length--;
        }  
    }

    void printQ() //داله لطباعه عناصر الصف
    {
        cout << "[ ";
        for (int i = front; i != end+1; i = (i+1) % maxSize)
        {
            cout << queueArray[i] << " ";
        }
        cout << "]";
    }   
};

int main()
{
Linked_List l; Stack s; Queue q; //objects
int choice, pos, element, Choice;
string Exit;
cout << "Choose the NUMBER of What do you want to work with | 1-linked list| 2-stack | 3-queue: ";
cin >> choice;

    switch (choice)
{
case 1:
    cout << "at first Add 3 Element to Linked List: "<<endl;
    for (int i = 1; i < 4; i++)
    {
        cout << "Enter The Element number "<<i<<": ";
        cin >> element;
        l.addLast(element);
    }
    l.print();

    do
    {
        cout << "\nnow To add more Element|\npress 1 and the Element will be the FIRST one \n";
        cout << "press 2 and the Element will be the LAST one \n";
        cout << "press 3 to ADD AT POSITION --Enter the POSITION and then Enter the ELEMENT-- \n";
        cout << "press 4 To REMOVE Element : ";
        try
        {
            cin >> Choice;
            if (Choice == 1)
            {
                cout << "The Element = ";
                cin >> element;
                l.addFirst(element);
            }
            else if (Choice == 2)
            {
                cout << "The Element = ";
                cin >> element;
                l.addLast(element);
            }
            else if (Choice == 3)
            {
                cout  << "The Position = ";
                cin >> pos;
                cout << "The Element = ";
                cin >> element;
                l.addAtpos(pos,element);
            }
            else if (Choice == 4)
            {
                cout << "The Element = ";
                cin >> element;
                l.remove(element);
                cout << element << " Have been Deleted!\n";
            }
            
            
            else
            {
                throw "Something went wrong!"; 
            }
                
        }
        catch(char const*e)
        {
            cerr <<"ERROR : "<< e << '\n';
        }
    
        l.print();
        cout<< "\nDo you want to Exit? | type (yes) to exit or (no) to continue : ";
        cin >> Exit;
    } while (Exit != "yes");

break;

case 2:
    cout << "Firstly Add 3 Element to Stack: " << endl;
    for (int i = 1; i < 4; i++)
    {
        cout << "Enter The Element number " << i << ": ";
        cin >> element;
        s.push(element);
    }
    s.print();

    do
    {
        cout << "\npress 1 To Push Element on TOP || 2 To Pop Element from TOP: ";
        try
        {
            cin >> Choice;
            if (Choice == 1)
            {
                cout << "The Element = ";
                cin >> element;
                s.push(element);
            }
            else if (Choice == 2)
            {
                s.pop();
            }
            else
            {
                throw "Out of Range!\n"; 
            }            
        }
        catch(char const*e)
        {
            cerr << "\nERROR : " << e << '\n';
        }
        s.print();
    cout << "\nDo you want to Exit? | type (yes) to exit or (no) to continue : ";
    cin >> Exit;
    } while (Exit != "yes");

break;

case 3:
    cout << "Firstly Add 3 Element to Queue: " << endl;
    for (int i = 1; i < 4; i++)
    {
        cout << "Enter The Element number " << i << ": ";
        cin >> element;
       q.addQ(element);
    }
    q.printQ();
    
    do
    {
        cout << "\npress 1 To Add Element to Queue || 2 To delete Element from Queue: ";
        try
        {
            cin >> Choice;
            if (Choice == 1)
            {
                cout << "The Element = ";
                cin >> element;
                q.addQ(element);
            }
            else if (Choice == 2)
            {
                q.deleteQ();
            }
            else
            {
                throw "Out of Range!\n"; 
            }
        }
        catch (char const *e)
            {
                cerr << "\nERROR : " << e << '\n';
            }
           q.printQ();

    cout << "\nDo you want to Exit? | type (yes) to exit or (no) to continue : ";
    cin >> Exit;
    } while (Exit != "yes");

break;

default:
    cout << "Something went wrong!";
    break;
}

return 0;
}