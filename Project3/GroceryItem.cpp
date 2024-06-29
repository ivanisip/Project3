//Ivan Isip
//6-22-24
//Project 3

#include "GroceryItem.h"

// Default constructor
GroceryItem::GroceryItem() : name(""), quantity(0) {}

// Constructor with name
GroceryItem::GroceryItem(const std::string& name) : name(name), quantity(0) {}

// Constructor with name and quantity
GroceryItem::GroceryItem(const std::string& name, int quantity) : name(name), quantity(quantity) {}

// Getter for name
std::string GroceryItem::getName() const { return name; }

// Getter for quantity
int GroceryItem::getQuantity() const { return quantity; }

// Increment quantity
void GroceryItem::addItem() { quantity++; }

// Decrement quantity
void GroceryItem::removeItem() { if (quantity > 0) quantity--; }

// Overload the < operator for set
bool GroceryItem::operator<(const GroceryItem& other) const {
    return name < other.name;

}
