# 🧠 C Mastery Roadmap & Practice Checklist

A curated list of progressively challenging C problems to build true low-level mastery — from pointers and arrays to dynamic memory, data structures, and system programming.

---

## 🧩 Phase 1: Fundamentals of Memory & Pointers
**Goal:** Understand arrays, pointers, and basic string manipulation.

- [X] Implement `strlen` manually  
- [X] Implement `strcpy` manually  
- [X] Reverse a string in place  
- [X] Swap array of integers using pointers  
- [X] Find max/min in an integer array using pointers  
- [X] Implement `strcmp` manually  
- [X] Implement your own `strchr` (find first char in string)  
- [X] Reverse an integer array in place  
- [X] Implement `memcpy` manually  
- [X] Count vowels and consonants in a string  

---

## ⚙️ Phase 2: Dynamic Memory Management
**Goal:** Learn heap allocation, resizing, and memory safety.

- [ ] Dynamically allocate an integer array and fill it  
- [ ] Implement your own `strdup`  
- [ ] Concatenate two strings using `malloc`  
- [ ] Resize an integer array using `realloc`  
- [ ] Build a dynamic array (push/pop/resize)  
- [ ] Demonstrate shallow vs deep copy of a struct  
- [ ] Free all allocated memory and test with Valgrind  

---

## 🧱 Phase 3: Structs & Basic Data Structures
**Goal:** Model data in memory with structs and pointers.

### 🧩 Struct Practice
- [ ] Define a `struct Point { int x, y; }` and compute distance  
- [ ] Create a `struct Person` with dynamically allocated `char* name`  

### 🔗 Linked Lists
- [ ] Implement a singly linked list (insert/delete/print)  
- [ ] Reverse a linked list iteratively  
- [ ] Implement a doubly linked list  
- [ ] Detect a cycle in a linked list (Floyd’s algorithm)  
- [ ] Merge two sorted linked lists  

### 🌳 Trees
- [ ] Define a `struct Node` for a binary tree (`data`, `left`, `right`)  
- [ ] Implement preorder, inorder, and postorder traversals (recursive)  
- [ ] Implement level-order traversal (using a queue)  
- [ ] Find height and number of nodes in a binary tree  
- [ ] Insert and search in a Binary Search Tree (BST)  
- [ ] Delete a node in a BST  

### 🕸 Graphs
- [ ] Represent a graph using adjacency list  
- [ ] Implement Breadth-First Search (BFS)  
- [ ] Implement Depth-First Search (DFS)  
- [ ] Detect a cycle in a directed graph  
- [ ] Find connected components in an undirected graph  
- [ ] Implement Dijkstra’s shortest path algorithm  

---

## 💾 Phase 4: Files & I/O
**Goal:** Handle persistent data and understand file buffers.

- [ ] Count lines, words, and characters in a file  
- [ ] Copy one file into another (byte by byte)  
- [ ] Recreate the `cat` command (print file contents)  
- [ ] Append text to a file using `fopen` in append mode  
- [ ] Read a file into a dynamically allocated string buffer  

---

## ⚡ Phase 5: Bitwise & Low-Level Manipulation
**Goal:** Think in bits and bytes like hardware.

- [ ] Check if a number is odd or even using bitwise AND  
- [ ] Count number of set bits in an integer  
- [ ] Swap two numbers without a temp variable  
- [ ] Extract specific bits from a byte  
- [ ] Reverse the bits of a byte  
- [ ] Pack four bytes into one 32-bit integer, then unpack them  

---

## 🚀 Phase 6: Systems-Level & Advanced C
**Goal:** Combine all knowledge into real programs.

- [ ] Implement `atoi` (string to int)  
- [ ] Implement `itoa` (int to string)  
- [ ] Build a mini command-line calculator  
- [ ] Implement a hash table with collision handling  
- [ ] Create your own simplified `printf` for strings/ints  
- [ ] Implement a memory pool allocator  
- [ ] Build a ring buffer for UART-like data  
- [ ] Use function pointers to build a callback system  
- [ ] Simulate a basic shell (parse + execute commands)  

---

## 💣 Bonus: Embedded / Real-Time / Hardware Simulation
**Goal:** Practice concepts crucial for embedded and systems interviews.

- [ ] Implement a finite state machine (traffic light controller)  
- [ ] Simulate GPIO register toggling using bit manipulation  
- [ ] Create a mock UART ring buffer with push/pop  
- [ ] Debounce a button press in software  
- [ ] Simulate an interrupt-safe queue with atomic flag handling  

---

## 🧭 Notes
- 🧩 Start with **Phase 1**, do 2–3 problems per session.  
- 💾 Use `valgrind` to check for memory leaks in dynamic problems.  
- 🧱 Print pointer addresses and array indices often — understand *why* data sits where it does.  
- 💬 Adapt and extend the problems — try different data types, edge cases, and constraints.  

---
✅ *By the end of this list, you’ll have implemented strings, memory allocators, linked lists, trees, graphs, and system-level utilities — the full toolset of a real C engineer.*
