#include <iostream>
#include <iomanip>
using namespace std;

int totalPageFaults = 0;

// Function to check if a page is already in memory
int isPageInMemory(int pageTable[], int frames, int page) {
    for (int i = 0; i < frames; i++) {
        if (pageTable[i] == page) {
            return i; // Return frame index if page is found
        }
    }
    return -1; // Page not found
}

// Function to display the current state of memory
void displayMemory(int pageTable[], int frames) {
    // Dynamically adjusting the number of lines based on frames
    int displayWidth = frames * 7 + 2;  // 7 spaces per frame + 2 for borders

    cout << "\nCurrent Memory State:\n";
    cout << "+" << string(displayWidth - 2, '-') << "+\n|";  // Top border

    // Display the memory frames
    for (int i = 0; i < frames; i++) {
        if (pageTable[i] == -1) {
            cout << "   -   "; // Empty frame
        } else {
            cout << "   " << pageTable[i] << "   ";
        }
    }

    cout << "|\n+" << string(displayWidth - 2, '-') << "+\n";  // Bottom border
}

// FIFO Page Replacement Algorithm
void simulateFIFO(int pages[], int numPages, int frames, int pageTable[]) {
    int pageFaults = 0;    // Count of page faults for this run
    int currentIndex = 0;  // Tracks the next frame to replace
    bool spaceAvailable = false;  // To check if there's space in memory

    // Process each page request
    for (int i = 0; i < numPages; i++) {
        cout << "\nRequesting page: " << pages[i] << endl;

        // Check if the page is already in memory
        int pageIndex = isPageInMemory(pageTable, frames, pages[i]);
        if (pageIndex != -1) {
            cout << "Page " << pages[i] << " is already in memory at frame " << pageIndex << ".";
        } else {
            // Page fault occurs
            pageFaults++;

            // Try to find an empty frame first
            spaceAvailable = false;
            for (int j = 0; j < frames; j++) {
                if (pageTable[j] == -1) {
                    pageTable[j] = pages[i];
                    spaceAvailable = true;
                    break;
                }
            }

            // If no space available, replace the oldest page (FIFO)
            if (!spaceAvailable) {
                pageTable[currentIndex] = pages[i];
                currentIndex = (currentIndex + 1) % frames; // Update frame index
                cout << "Page fault! Replaced page " << pageTable[currentIndex] << " with page " << pages[i] << ".";
            } else {
                cout << "Page fault! Loaded page " << pages[i] << " into memory.";
            }
        }

        // Display the current memory state
        displayMemory(pageTable, frames);
    }

    // Update the global total page faults
    totalPageFaults += pageFaults;
    cout << "\n=========================================\n";
    cout << "Simulation Complete!\n";
    cout << "Page faults for this run: " << pageFaults << endl;
    cout << "Total Page Faults (Cumulative): " << totalPageFaults << endl;
    cout << "=========================================\n";
}

// Main Function with Menu
int main() {
    int choice;

    int frames = 0;
    int pageTable[100]; // Maximum frames (adjust as needed)
    for (int i = 0; i < 100; i++) {
        pageTable[i] = -1; // Initialize with empty frames
    }

    do {
        cout << "=========================================\n";
        cout << "         Virtual Memory Simulator        \n";
        cout << "=========================================\n";
        cout << "1. Run FIFO Page Replacement Simulation\n";
        cout << "2. Exit Program\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            int numPages;

            if (frames == 0) {
                cout << "\nEnter the number of memory frames: ";
                cin >> frames;
            }

            cout << "Enter the number of page requests: ";
            cin >> numPages;

            int pages[numPages];

            cout << "Enter the sequence of page requests:\n";
            for (int i = 0; i < numPages; i++) {
                cout << "Page " << i + 1 << ": ";
                cin >> pages[i];
            }

            // Start the simulation
            simulateFIFO(pages, numPages, frames, pageTable);
        } else if (choice == 2) {
            cout << "\nExiting Program. Thank you!\n";
        } else {
            cout << "\nInvalid choice. Please select 1 or 2.\n";
        }

    } while (choice != 2);

    return 0;
}
