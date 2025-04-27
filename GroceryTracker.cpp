#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <iomanip>
#include <algorithm>
#include <limits>

// GroceryTracker class to manage item frequency tracking
class GroceryTracker {
private:
    std::map<std::string, int> itemFrequencies; // Map to store item-frequency pairs

    // Reads input file and populates itemFrequencies map
    void loadInputFile(const std::string& filename) {
        std::ifstream inFile(filename);
        std::string item;

        if (!inFile) {
            std::cerr << "Error: Unable to open input file!" << std::endl;
            return;
        }

        // Read each line (item) and increment frequency
        while (std::getline(inFile, item)) {
            if (!item.empty()) {
                // Convert to lowercase for case-insensitive handling
                std::transform(item.begin(), item.end(), item.begin(), ::tolower);
                itemFrequencies[item]++;
            }
        }

        inFile.close();
    }

    // Creates frequency.dat backup file
    void createBackupFile(const std::string& filename) {
        std::ofstream outFile(filename);

        if (!outFile) {
            std::cerr << "Error: Unable to create backup file!" << std::endl;
            return;
        }

        // Write each item and its frequency to the file
        for (const auto& pair : itemFrequencies) {
            outFile << pair.first << " " << pair.second << std::endl;
        }

        outFile.close();
    }

public:
    // Constructor: Loads input file and creates backup
    GroceryTracker(const std::string& inputFile, const std::string& backupFile) {
        loadInputFile(inputFile);
        createBackupFile(backupFile);
    }

    // Option 1: Search for an item's frequency
    void searchItemFrequency() {
        std::string item;
        std::cout << "Enter the item to search: ";
        std::cin >> item;
        std::transform(item.begin(), item.end(), item.begin(), ::tolower);

        // Validate item input (alphabetic characters only)
        bool isValid = std::all_of(item.begin(), item.end(), [](char c) { return std::isalpha(c); });
        if (!isValid) {
            std::cout << "Invalid item name. Please enter alphabetic characters only." << std::endl;
            return;
        }

        auto it = itemFrequencies.find(item);
        if (it != itemFrequencies.end()) {
            std::cout << item << " appears " << it->second << " times." << std::endl;
        }
        else {
            std::cout << item << " not found in the records." << std::endl;
        }
    }

    // Option 2: Print all items and their frequencies
    void printFrequencyList() {
        std::cout << "\nItem Frequencies:\n" << std::endl;
        for (const auto& pair : itemFrequencies) {
            std::cout << std::left << std::setw(20) << pair.first << pair.second << std::endl;
        }
    }

    // Option 3: Print histogram of item frequencies
    void printHistogram() {
        std::cout << "\nItem Frequency Histogram:\n" << std::endl;
        for (const auto& pair : itemFrequencies) {
            std::cout << std::left << std::setw(20) << pair.first;
            for (int i = 0; i < pair.second; i++) {
                std::cout << "*";
            }
            std::cout << std::endl;
        }
    }
};

// Displays the menu and returns user choice
int displayMenu() {
    int choice;
    std::cout << "\nCorner Grocer Item Tracker\n";
    std::cout << "1. Search for an item\n";
    std::cout << "2. Display all item frequencies\n";
    std::cout << "3. Display histogram\n";
    std::cout << "4. Exit\n";
    std::cout << "Enter your choice (1-4): ";
    while (!(std::cin >> choice)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please enter a number between 1 and 4: ";
    }
    return choice;
}

int main() {
    // Initialize GroceryTracker with input and backup file names
    GroceryTracker tracker("CS210_Project_Three_Input_File.txt", "frequency.dat");

    int choice;
    do {
        choice = displayMenu();

        // Handle user input with switch statement
        switch (choice) {
        case 1:
            tracker.searchItemFrequency();
            break;
        case 2:
            tracker.printFrequencyList();
            break;
        case 3:
            tracker.printHistogram();
            break;
        case 4:
            std::cout << "Exiting program. Goodbye!\n";
            break;
        default:
            std::cout << "Invalid choice. Please enter a number between 1 and 4.\n";
        }
    } while (choice != 4);

    return 0;
}