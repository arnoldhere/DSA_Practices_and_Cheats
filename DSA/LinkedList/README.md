# Linked Lists

- linear data structure where its elements are called nodes which stores data
- introduced to over come the limitation of arrays which is continous memory location
- Array needs the fixed or continous memory to store its element meanwhile linkedlist allows to store data in separate memory locations

## Node structure

```
[head(optional) | data | tail ] -> [data | tail] -> [data | null]
```

- head = stores metadata of the whole linked list
- data = stores the actual value of element
- tail = stores the memory address of very next node
- null = stores the null pointer which represents end of linkedlist

## Pros

- Dynamic memory allocation
- Efficient insertion and deletion
- More flexible than array

## Cons

- No direct access by index like arrays
- Needs more memory to stores pointers
- Slower to access

## Applications of Linkedlist

- Music playlists
- file or directory system
- Dynamic memory allocation and so on.

## Types

1. Singly
   - simple and most widely used
   - only moves forward
   - unable to move backward
   - Structure
     [As discussed above](#node-structure)
2. Doubly

   - can move in both direction
   - easier operation of insert and delete
   - use extra pointer
   - last node
   - structure

   ```
   [head|data|tail] ⇄ [head|data|tail] ⇄ [head|data|null]
   ```

3. Circular
   - Not more used practicaly
   - can loop infinitely
   - great for round-robin cpu process
   - tricky and complex to implement
   - structure
   ```
       [head|data|tail] ⇄ [head|data|tail] ⇄ [head|data|tail ] -> back to 1st node
   ```

## Basic operations with algorithm for Linked lists

- Creation
  [Add a new node at the end of the list (standard creation flow).]

```
CreateNode(data)
START
    allocate new memory -> new_node
    new_node.data = data
    new_node.next = null

    IF head is NULL
        head =new_node       // first node
    ELSE
        tmp<-head
            while tmp.next != NULL
                tmp=tmp.next
            ENDWHILE
        tmp.next = new_node // attach at end
    ENDIF
END
```

- Creation of node at start

```
CreateNodeAtstart(data)
START
    allocate new memory -> new_node
    new_node.data = data
    new_node.next = null

    IF head is NULL
        head =new_node       // first node
    ELSE
        // attach new node at head and give memory address of old head to new head
        new_node.nxt <-head
        head.nxt <- new_node
   ENDIF

END
```

- Display

```

DisplayLL
START
IF head is NULL
Linked list is empty
ENDIF
tmp = head
while tmp!= null
print -> tmp.data
ENDWHILE
END

```

```

```
