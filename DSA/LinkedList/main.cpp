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

void menu()
{
    cout << "\t\t====Linked Lists====" << endl;
    cout << "[1] Linked List I/O " << endl;
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
        case 1:
            break;
        case 2:
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