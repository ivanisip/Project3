//Ivan Isip
//6-22-24
//Project 3

#ifndef GROCERYITEM_H
#define GROCERYITEM_H

#include <string>

class GroceryItem {
private:
    std::string name;
    int quantity;
public:
    GroceryItem();
    GroceryItem(const std::string& name);
    GroceryItem(const std::string& name, int quantity);

    /**
     * @return The name of the grocery item.
     */
    std::string getName() const;

    /**
     * @return The quantity of the grocery item.
     */
    int getQuantity() const;

    /**
     * Increments the quantity of the grocery item by one.
     */
    void addItem();

    /**
     * Decrements the quantity of the grocery item by one.
     */
    void removeItem();

    /**
     * Compares this grocery item with another for sorting.
     * @param other The other grocery item to compare with.
     * @return True if this item's name is lexicographically less than the other's name, false otherwise.
     */
    bool operator<(const GroceryItem& other) const;
};

#endif // GROCERYITEM_H


