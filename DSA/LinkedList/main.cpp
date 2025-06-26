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

void display()
{
    if (head == nullptr)
        cout << "Linked List is empty..." << endl;
    else
    {
        Node *current = head;
        while (current != nullptr)
        {
            cout << current->data << "->";
            current = current->nxt;
        }
        cout << "null" << endl;
    }
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
            display();
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
                cout << "choose option : ";
                cin >> ich;
                if (ich == 1) // add node at the end
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
                        Node *current = head;
                        while (current->nxt != nullptr)
                        {
                            current = current->nxt;
                        }
                        current->nxt = n;
                    }
                    count++;
                    break;
                }
                else if (ich == 2) // add node at the start
                {
                    int x;
                    cout << "Enter the value to be inserted :";
                    cin >> x;
                    Node *n = new Node(x);
                    if (head == nullptr)
                        cout << "Linked List is empty....";
                    else
                    {
                        // attach new node at head and give memory address of old head to new head
                        n->nxt = head;
                        head = n;
                    }
                    count++;
                    break;
                }
                else if (ich == 3) // add the node at specific location
                {
                    int pos, x;
                    display();
                    cout << "Enter the value to be inserted :";
                    cin >> x;
                    cout << "Enter the position :";
                    cin >> pos;
                    Node *n = new Node(x);
                    if (pos < 1 || pos > count + 1)
                    {
                        cout << "❌ Invalid position! Out of bounds.\n";
                        break;
                    }

                    // If inserting at the head
                    if (pos == 1)
                    {
                        n->nxt = head;
                        head = n;
                        count++;
                        break;
                    }

                    Node *current = head;

                    // Traverse to node at pos - 1
                    for (int i = 1; i < pos - 1; i++)
                    {
                        if (current == nullptr)
                        {
                            cout << "invalid postion";
                            break;
                        }
                        current = current->nxt;
                    }
                    n->nxt = current->nxt; // Link new node to next node
                    current->nxt = n;      // Link previous node to new node
                    count++;
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
            cout << "Total nodes in the LinkedList is " << count << endl;
            display();
            break;
        case 6:
            break;
        default:
            cout << "Invalid input try again.....";
        }
    }

    return 0;
}