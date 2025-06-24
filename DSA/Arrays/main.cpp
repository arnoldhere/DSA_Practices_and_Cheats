#include <iostream>
using namespace std;

int *arr = nullptr;
int n = 0;

void show_menu()
{
    cout << " [1] Array IO\n";  // Input/Output for the array
    cout << " [2] Insertion\n"; // Insertion at a specific position
    cout << " [3] Deletion\n";  // Deletion of an element
    cout << " [4] Search\n";    // Search for an element using different methods
    cout << " [5] Sort \n";     // Sort the array using QuickSort
    cout << " [6] EXIT \n";     // Exit the program
}

void show_array()
{
    cout << "=======================================" << endl;
    cout << "<< YOUR ARRAY IS >>" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "\t";
    }
    cout << endl;
}

void search_menu()
{
    cout << "====Search methods====" << endl;
    cout << "[1] Linear search\n";
    cout << "[2] Binary search\n";
    cout << "[3] EXIT\n";
    cout << "========================" << endl;
}

void show_sorting_menu()
{
    cout << "====Sorting methods====" << endl;
    cout << "[1] QuickSort\n";
    cout << "[2] MergeSort\n";
    cout << "[3] EXIT\n";
    cout << "========================" << endl;
}

int linear(int k)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == k)
            return i + 1; // return position (1-based index)
    }
    return -1; // not found
}

int binary(int k)
{
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2; // Avoid integer overflow
        if (arr[mid] == k)
            return mid + 1; // 1-based index
        if (arr[mid] > k)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

void QuickSort(int low, int high)
{
    // Only organize if there's more than one person (base case)
    if (low < high)
    {
        // Pick Priya as the VIP (pivot = arr[low])
        int key = arr[low];
        int i = low;  // Start at the left end of the line
        int j = high; // Start at the right end of the line
        int c = 1;    // Count passes for debugging (like numbering party rounds)

        // Partition: Move shorties left, tall folks right
        while (i < j)
        {
            // Find the first person on the left who's taller than Priya (key)
            while (i <= high && arr[i] <= key)
            {
                i++;
            }
            // Find the first person on the right who's shorter than or equal to Priya
            while (j >= low && arr[j] > key)
            {
                j--;
            }
            // If we found a tall person on the left and a short person on the right, swap them
            if (i < j)
            {
                int tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }

        // Place Priya in her final spot (swap arr[low] with arr[j])
        int tmp = arr[low];
        arr[low] = arr[j];
        arr[j] = tmp;

        // Show the party line after this round
        cout << "\nPASS - " << c << ": ";
        c++;
        show_array();

        // Organize the shorties (left group)
        QuickSort(low, j - 1);
        // Organize the tall folks (right group)
        QuickSort(j + 1, high);
    }
}

void merge_sort()
{
    
}

void ArrayIO()
{
    if (arr != nullptr)
    {
        delete[] arr;
    }

    cout << "Enter the number of elements for array: ";
    cin >> n;
    arr = new int[n];

    for (int i = 0; i < n; i++)
    {
        cout << "Enter the value of Array[" << i + 1 << "] : ";
        cin >> arr[i];
    }

    show_array();
}

void insert_array(int x, int pos)
{
    if (pos < 1 || pos > n + 1)
    {
        cout << "Invalid position... try again." << endl;
        return;
    }

    int *t = new int[n + 1];

    for (int i = 0; i < pos - 1; i++)
    {
        t[i] = arr[i];
    }

    t[pos - 1] = x;

    for (int i = pos - 1; i < n; i++)
    {
        t[i + 1] = arr[i];
    }

    delete[] arr;
    arr = t;
    n++;

    show_array();
}

void delete_arr(int x)
{
    int index;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == x)
        {
            index = i;
            break;
        }
    }
    if (index == -1)
    {
        cout << "Element not found....";
    }
    for (int i = index; i < n; i++)
    {
        arr[i] = arr[i + 1];
    }
    n--;
    cout << "Deletion successful. ";
    show_array();
}

int main()
{
    int ch = 0;
    while (ch < 6)
    {
        cout << "\n====== Array DSA Problems ======" << endl;
        show_menu();
        cout << "Choose your option : ";
        cin >> ch;

        switch (ch)
        {
        case 1: // Array IO
            ArrayIO();
            break;

        case 2: // array insertion
            if (arr == nullptr)
            {
                cout << "Please input the array first using option 1." << endl;
                break;
            }
            int x, pos;
            cout << "Enter the value to be inserted : ";
            cin >> x;
            cout << "Enter the position for insertion : ";
            cin >> pos;
            insert_array(x, pos);
            break;

        case 3: // deletion
            if (arr == nullptr)
            {
                cout << "Please input the array first using option 1." << endl;
                break;
            }
            int val;
            show_array();
            cout << "Enter the position to be deleted : ";
            cin >> val;
            delete_arr(val);
            break;

        case 4: // search
            if (arr == nullptr)
            {
                cout << "Please input the array first using option 1." << endl;
                break;
            }

            while (true)
            {
                int sch;
                search_menu();
                cout << "Choose method to search : ";
                cin >> sch;

                if (sch == 3) // Exit search menu
                {
                    cout << "Returning to main menu..." << endl;
                    break;
                }
                switch (sch)
                {
                case 1: // linear search
                {
                    int k, res;
                    cout << "Enter the element : ";
                    cin >> k;
                    res = linear(k);
                    if (res != -1)
                        cout << "Element " << k << " found at position " << res << " in the array." << endl;
                    else
                        cout << "Element " << k << " not found in the array." << endl;
                    break;
                }
                case 2: // binary search
                {
                    int k, res;
                    cout << "Enter the element : ";
                    cin >> k;
                    QuickSort(0, n - 1);
                    res = binary(k);
                    if (res != -1)
                        cout << "Element " << k << " found at position " << res << " in the array." << endl;
                    else
                        cout << "Element " << k << " not found in the array." << endl;
                    break;
                }
                default:
                    cout << "Invalid input.. try again." << endl;
                    break;
                }
            }

        case 5: // sort
            if (arr == nullptr)
            {
                cout << "Please input the array first using option 1." << endl;
                break;
            }
            cout << "Original array: ";
            show_array();
            int sort_choice;
            while (true)
            {
                show_sorting_menu();
                cout << "Choose sorting method: ";
                cin >> sort_choice;
                if (sort_choice == 3) // Exit sorting menu
                {
                    cout << "Returning to main menu..." << endl;
                    break;
                }
                switch (sort_choice)
                {
                case 1: // QuickSort
                    cout << "Sorting the array using QuickSort..." << endl;
                    QuickSort(0, n - 1);
                    show_array();
                    break;
                case 2:
                    merge_sort();
                    break;
                default:
                    cout << "Invalid choice... try again." << endl;
                    break;
                }
            }
            cout << "Sorting the array using QuickSort..." << endl;
            QuickSort(0, n - 1);
            break;

        case 6:
            cout << "Exiting program..." << endl;
            break;

        default:
            cout << "Invalid choice... try again." << endl;
            break;
        }
    }

    delete[] arr;
    return 0;
}