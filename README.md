# Virtual Memory Simulator (FIFO Algorithm)  

## Overview  
This C++ program simulates the **FIFO (First-In-First-Out) page replacement algorithm**, a fundamental concept in operating system memory management. It demonstrates how virtual memory handles page faults when requested pages are not in physical memory, tracking cumulative page faults across multiple simulations.

## Key Features  
- **Interactive Menu**: Choose between running simulations or exiting.  
- **Visual Memory Display**: Shows current page allocations in a formatted table.  
- **FIFO Implementation**: Replaces the oldest page when memory is full.  
- **Page Fault Tracking**: Logs page faults per simulation and cumulatively.  
- **Dynamic Input**: Users specify frame count and custom page request sequences.  

## How It Works  
1. **Initialization**:  
   - Set up empty memory frames.  
2. **Page Requests**:  
   - Check if requested page exists in memory.  
   - If not (page fault), load it into an empty frame or replace the oldest page.  
3. **Visualization**:  
   - Displays memory state after each request.  
   - Reports page faults at the end of each simulation.  

## Code Structure  
- **`isPageInMemory()`**: Checks if a page exists in physical memory.  
- **`displayMemory()`**: Prints the current memory state with borders.  
- **`simulateFIFO()`**: Core logic for FIFO page replacement.  
- **`main()`**: Handles user input and menu navigation.  

## Example Usage  
```plaintext
Requesting page: 3  
Page fault! Loaded page 3 into memory.  

Current Memory State:  
+---------------------+  
|   3   |   -   |   -   |  
+---------------------+  
```

## Compilation & Execution  
1. Compile:  
   ```bash  
   g++ OS_Final_Project.cpp -o memory_simulator  
   ```  
2. Run:  
   ```bash  
   ./memory_simulator  
   ```  

## Future Enhancements  
- Add **LRU (Least Recently Used)** and **Optimal** algorithms.  
- Support for **predefined page request sequences** (e.g., from files).  
- Graphical visualization (e.g., using SFML).  

Developed as a final project for an Operating Systems course. 🖥️  

--- 
