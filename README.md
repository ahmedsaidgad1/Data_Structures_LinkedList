# Linked Lists in C++

Implementations of the two core linked list structures, written from scratch in C++ with heavy inline comments (in Arabic) explaining the logic step by step.

## Contents

| File | Description |
|---|---|
| `Singly_Linked_List.cpp` | Singly linked list — insert at beginning/end/after a node, search, delete first/last/by value, print |
| `Doubly_Linked_List.cpp` | Doubly linked list — insert at beginning/end/after a node, search, delete (generic + first/last), print |

## Operations Implemented

**Singly Linked List**
- `Insert_At_Beginning`
- `Insert_At_End`
- `Insert_After`
- `find`
- `Delete_first`
- `Delete_last`
- `Delete_Node` (by value)
- `Print_List`

**Doubly Linked List**
- `Insert_At_Beginning`
- `Insert_At_End`
- `Insert_After`
- `Find_Node`
- `Delete_Node` (by node pointer)
- `Delete_First_Node`
- `Delete_Last_Node`
- `Print_List`

## Build & Run

```bash
g++ -std=c++17 -Wall -o singly Singly_Linked_List.cpp
./singly

g++ -std=c++17 -Wall -o doubly Doubly_Linked_List.cpp
./doubly
```

## Notes

- Each function is commented in Arabic to explain the reasoning behind every step, useful as a learning reference.
- Memory is managed manually with `new`/`delete`, following raw pointer semantics (no smart pointers), to keep the focus on understanding the data structure mechanics.

## Author

Ahmed Said — [GitHub](https://github.com/ahmedsaidgad1)
