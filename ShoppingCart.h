#ifndef SHOPPING_CART_H
#define SHOPPING_CART_H

#include <vector>
#include <iostream>
#include "Product.h"

using namespace std;

/**
 * @class CartItem
 * @brief Merepresentasikan item dalam keranjang belanja
 */
class CartItem {
public:
    Product product;
    int quantity;

    CartItem(Product p, int q) : product(p), quantity(q) {}

    double getSubtotal() const {
        return product.getPrice() * quantity;
    }

    void display() const {
        cout << product.getName() << " x " << quantity 
             << " = Rp" << getSubtotal() << endl;
    }
};

/**
 * @class ShoppingCart
 * @brief Keranjang belanja menggunakan vector (Array)
 * 
 * Menggunakan dynamic array (vector) untuk menyimpan item-item belanja
 * dengan operasi:
 * - Tambah item
 * - Hapus item
 * - Lihat total
 */
class ShoppingCart {
private:
    vector<CartItem> items;

public:
    // Add item to cart
    void addItem(Product product, int quantity) {
        // Check if product already exists in cart
        for (auto& item : items) {
            if (item.product.getID() == product.getID()) {
                item.quantity += quantity;
                return;
            }
        }
        // If not found, add new item
        items.push_back(CartItem(product, quantity));
    }

    // Remove item by product ID
    void removeItem(int productID) {
        for (auto it = items.begin(); it != items.end(); ++it) {
            if (it->product.getID() == productID) {
                items.erase(it);
                return;
            }
        }
        cout << "Produk tidak ditemukan di keranjang!" << endl;
    }

    // Get total price
    double getTotalPrice() const {
        double total = 0;
        for (const auto& item : items) {
            total += item.getSubtotal();
        }
        return total;
    }

    // Display cart contents
    void display() const {
        if (items.empty()) {
            cout << "Keranjang kosong!" << endl;
            return;
        }
        cout << "\n========== KERANJANG BELANJA ==========" << endl;
        for (const auto& item : items) {
            item.display();
        }
        cout << "Total: Rp" << getTotalPrice() << endl;
        cout << "======================================" << endl;
    }

    // Clear cart
    void clear() {
        items.clear();
    }

    // Get number of items
    int getItemCount() const {
        return items.size();
    }

    // Get all items (for checkout)
    const vector<CartItem>& getItems() const {
        return items;
    }

    // Check if cart is empty
    bool isEmpty() const {
        return items.empty();
    }
};

#endif // SHOPPING_CART_H
