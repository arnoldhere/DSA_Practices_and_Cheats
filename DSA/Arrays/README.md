# Arrays
- linear data structure
- stores fixed size of elements in a sequential fashion in memory
- elemenets are stored in consecutive memory location

## Pros

- efficient and fast access
- easy to understand
- versatile (used for pointers, stores various data types)

## Cons

- fixed size
- lack of flexibility
- memory allocation issues

## Various Applications and operations on arrays

- Basic I/O, Traversal
- Search (linear, binary)
- sorting (quick, merge)
- suba-array problems and so on

# Search Algorithms

Searching is a method of accessing an element inside array.

## Linear Search

A simple method for searching or finding specific value in an array. It sequentially checks all elements one by one and gets the result.

**Pseudo code**

- arr => stores n number of element
- n => determines number of element
- k => Key value to be search
- i => loop variable

```
START
REPEAT untill  i<n
    IF arr[i] == k
        RETURN "found"
    ELSE
        RETURN "not found"
    ENDIF
END
END
```

---

## Binary Search

A method to find the element by using divide and conquere approach. It is also known as "Half interval search". It divides sorted array into two intervals and repeatedly find the element.
**Pseudo code**

- arr => stores n number of element
- n => determines number of element
- k => Key value to be search
- i => loop variable
- mid => midpoint of array
- start => startpoint of array
- end => endpoint of array

## Recursive Method

```
Binary_search(start,end):
START
    IF start > end THEN
        RETURN "Not Found"
    IF key == mid
        RETURN "Found"
    IF key < mid
        return Binary_search(start,mid-1)
    IF key > mid
        return Binary_search(mid+1,end)
    END if
END
```

---

## Iterative Method

```
Binary_search(start,end):
START
    REPEAT untill start<=end
        IF key == mid
            RETURN "Found"
        IF key < mid
            end = mid-1
        IF key > mid
            low = mid+1
    END
    RETURN "not found"
END
```

---

# Sorting Algorithms

Sorting is method of managing the all elements in ordered way.

## Quick Sort

One of most efficient,Fastest and general purpose algorithm for sorting. It also follows D&C programming.  
A pivot or key element is decided and then all smaller than pivot are set to left and larger than pivot are set to right.

**Pseudo code**

- arr => stores n number of element
- n => determines number of element
- i => loop variable
- low => lowest element of array
- mid => mid element of array
- high => highest element of array
- key => Pivot element

```
QuickSort(low, high)
    If low < high then
        Set key = arr[low]   //  pivot
        Set i = low
        Set j = high

        While i < j do
            // Move i to the right until an element > key is found
            While i <= high AND arr[i] <= key do
                i = i + 1
            End While

            // Move j to the left until an element <= key is found
            While j >= low AND arr[j] > key do
                j = j - 1
            End While

            // If misplaced elements are found, swap them
            If i < j then
                Swap arr[i] with arr[j]
            End If
        End While

        // Place pivot in correct position
        Swap arr[low] with arr[j]

        // Show current state of array (optional for debugging)

        // Recursively sort the left partition
        QuickSort(low, j - 1)

        // Recursively sort the right partition
        QuickSort(j + 1, high)
    End If
End
```

## Merge Sort

One of most efficient and general purpose comparison based algorithm for sorting. Follows D&C programming to divide recusively and list of unsorted element into sublists untill the inherent element is sorted. It divides then perform sorting and merge the sublists.

**Pseudo code**

- arr => stores n number of element
- n => determines number of element
- i,j,k => loop variables
- low => lowest element of array
- mid => mid element of array
- high => highest element of array
- t => temp. array to store merged elements

```
MergeSort(low, high)
START
    IF low < high
        mid = (low+high)/2
        // recursively merge two halvs
        MergeSort(low, mid)
        MergeSort(mid+1, high)
        //merge the two divided halvs
        simpleMerge(low,mid,high)
    END IF
End
simpleMerge(low,mid,high)
START
    i=low,j=mid+1 , k=low
    // Merging the two halves
    REPEAT untill i <= mid & j<=high 
        IF arr[i] < arr[j]
            t[k] = arr[i]
            i++;
        ELSE
            t[k] = arr[j]
            j++;
        END IF
        k++;
    END

    // Copying remaining elements from the left half, if any
    REPEAT untill i <= mid
        b[k] = arr[i]
        i++
        k++
    END
    
    // Copying remaining elements from the right half, if any
    REPEAT untill  j<= high
        b[k] = arr[j]
        j++
        k++
    END
    
    //merging into original array

    REPEAT untill i < n 
        arr[i] = t[i]
    END
END
```