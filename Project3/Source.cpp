//Ivan Isip
//6-22-24
//Project 3

#include <iostream>
#include <fstream>
#include <set>
#include <limits>
#include <memory>
#include "GroceryItem.h"

/**
 * Reads the inventory from a file and returns a set of GroceryItems.
 * @param filename The name of the file to read from.
 * @return A set of GroceryItems read from the file.
 */
std::set<GroceryItem> readInventory(const std::string& filename) {
    std::set<GroceryItem> items;
    std::ifstream file(filename);

    if (!file) {
        std::cerr << "Error: Could not open the file " << filename << std::endl;
        return items;
    }

    std::string itemName;
    while (file >> itemName) {
        auto tempItem = std::make_unique<GroceryItem>(itemName);
        auto it = items.find(*tempItem);
        if (it != items.end()) {
            GroceryItem existingItem = *it;
            items.erase(it);
            existingItem.addItem();
            items.insert(existingItem);
        }
        else {
            tempItem->addItem();
            items.insert(*tempItem);
        }
    }

    // Close the input file before writing to the output file
    file.close();

    // Back up the data to frequency.dat
    std::ofstream backup("frequency.dat");
    for (const auto& item : items) {
        backup << item.getName() << " " << item.getQuantity() << std::endl;
    }

    return items;
}

/**
 * Searches for an item and displays its frequency.
 * @param items The set of GroceryItems to search within.
 */
void searchItem(const std::set<GroceryItem>& items) {
    std::string itemName;
    std::cout << "Enter the item name: ";
    std::cin >> itemName;

    auto tempItem = std::make_unique<GroceryItem>(itemName);
    auto it = items.find(*tempItem);
    if (it != items.end()) {
        std::cout << itemName << " frequency: " << it->getQuantity() << std::endl;
    }
    else {
        std::cout << "Item not currently in inventory." << std::endl;
    }
}

/**
 * Displays the frequencies of all items.
 * @param items The set of GroceryItems to display.
 */
void displayFrequencies(const std::set<GroceryItem>& items) {
    for (const auto& item : items) {
        std::cout << item.getName() << ": " << item.getQuantity() << std::endl;
    }
}

/**
 * Prints a histogram of item frequencies.
 * @param items The set of GroceryItems to print.
 */
void printHistogram(const std::set<GroceryItem>& items) {
    for (const auto& item : items) {
        std::cout << item.getName() << " ";
        for (int i = 0; i < item.getQuantity(); ++i) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
}

/**
 * Gets a validated menu choice from the user.
 * @return The validated menu choice.
 */
int getValidatedChoice() {
    int choice;
    while (true) {
        std::cin >> choice;
        if (std::cin.fail() || choice < 1 || choice > 4) {
            std::cin.clear(); // Clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
            std::cout << "Invalid choice. Please enter a number between 1 and 4: ";
        }
        else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard any extra input
            break;
        }
    }
    return choice;
}

int main() {
    std::set<GroceryItem> items;

    int choice;
    do {
        // Display the menu
        std::cout << "1. Search for an item" << std::endl;
        std::cout << "2. Display all item frequencies" << std::endl;
        std::cout << "3. Print histogram" << std::endl;
        std::cout << "4. Exit" << std::endl;
        std::cout << "Enter your choice: ";

        // Get and validate the user's menu choice
        choice = getValidatedChoice();

        // Ensure the inventory is read from the file each time to get the latest data
        items = readInventory("inventory.txt");

        switch (choice) {
        case 1:
            searchItem(items);
            break;
        case 2:
            displayFrequencies(items);
            break;
        case 3:
            printHistogram(items);
            break;
        case 4:
            std::cout << "Exiting program." << std::endl;
            break;
        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while (choice != 4);

    return 0;
}
