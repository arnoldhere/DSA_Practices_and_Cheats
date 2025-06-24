#include <iostream>
using namespace std;

// node structure of the linked list
struct Node
{
    int data;  // value to be stored
    Node *nxt; // address of next node
    // constructor to store automatic data while creating a node
    Node(int val)
    {
        data = val;
        nxt = nullptr;
    }
};

// global  head pointer that indicates the start of linkedlist
Node *head = nullptr;
int count = 0; // no. of elements in LL
void menu()
{
    cout << "\t\t====Linked Lists====" << endl;
    cout << "[1] Display " << endl;
    cout << "[2] Insert Element" << endl;
    cout << "[3] Delete Element" << endl;
    cout << "[4] Search Element" << endl;
    cout << "[5] Length of Linked List" << endl;
    cout << "[6] EXIT... " << endl;
    cout << "================================\n";
}

int main()
{
    int ch;

    while (ch != 6)
    {
        menu();
        cout << "Choose option :";
        cin >> ch;
        switch (ch)
        {
        case 1: // display the LL
            if (head == nullptr)
                cout << "Linked List is empty..." << endl;
            else
            {
                Node *tmp = head;
                while (tmp != nullptr)
                {
                    cout << tmp->data << "->";
                    tmp = tmp->nxt;
                }
                cout << "null"<<endl;
            }
            break;
        case 2:
            int ich;
            while (ich != 4)
            {
                cout << "Select where do you want to add the node" << endl;
                cout << "[1] insert at end " << endl;
                cout << "[2] insert at start " << endl;
                cout << "[3] insert at choice" << endl;
                cout << "[4] EXIT" << endl;
                cout << "==================" << endl;
                cout << "choose option";
                cin >> ich;
                if (ich == 1)
                {
                    int x;
                    cout << "Enter the value here :";
                    cin >> x;
                    // set value in node
                    Node *n = new Node(x); // create a new node with value x
                    // set the node in LL
                    if (head == nullptr)
                    {
                        head = n; // first node becomes head
                    }
                    else
                    {
                        Node *t = head;
                        while (t->nxt != nullptr)
                        {
                            t = t->nxt;
                        }
                        t->nxt = n;
                    }
                    count++;
                    break;
                }
                else if (ich == 2)
                {
                    break;
                }
                else if (ich == 3)
                {
                    break;
                }
                else if (ich == 4)
                {
                    break;
                }
                else
                {
                    cout << "Invalid input...";
                    break;
                }
            }
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        default:
            cout << "Invalid input try again.....";
        }
    }

    return 0;
}