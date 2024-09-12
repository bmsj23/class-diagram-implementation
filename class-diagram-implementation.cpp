#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Order {
private:
    string orders[100];
    string orderName, orderAddress, orderStatus;
    int orderQty;
    double orderPrice; 

public:
    Order() : orderStatus("Pending") {}

    void setOrderDetails(string name, string address, int qty, double price) {
        orderName = name;
        orderAddress = address;
        orderQty = qty;
        orderPrice = price;
    }

    string placeOrder() {
        return "\nOrder placed for " + to_string(orderQty) + " item(s) at a total price of " + to_string(orderPrice);
    }

    string cancelOrder() {
        orderStatus = "Canceled";
        return "Order canceled";
    }

    string completeOrder() {
        orderStatus = "Completed";
        return "Order completed";
    }

    string getOrderStatus() {
        return orderStatus;
    }
};

class Product {
private:
    char choice;
    string productIDChosen;
    string products[10][3];
    string productInCart[100];
    int productQtyListed[100];
    int productCount;
    int numOfProdInCart;
    bool validProductID;

public:
    Product() : productCount(10), numOfProdInCart(0), validProductID(false) {
        products[0][0] = "ID001"; products[0][1] = "Nike Vomero 5"; products[0][2] = "7500";
        products[1][0] = "ID002"; products[1][1] = "Adidas NMD R1"; products[1][2] = "8500";
        products[2][0] = "ID003"; products[2][1] = "Puma RS-X"; products[2][2] = "6200";
        products[3][0] = "ID004"; products[3][1] = "Reebok Classic"; products[3][2] = "5000";
        products[4][0] = "ID005"; products[4][1] = "Converse Chuck"; products[4][2] = "4500";
        products[5][0] = "ID006"; products[5][1] = "Vans Old Skool"; products[5][2] = "4000";
        products[6][0] = "ID007"; products[6][1] = "New Balance 530"; products[6][2] = "7000";
        products[7][0] = "ID008"; products[7][1] = "Asics Quantum"; products[7][2] = "6800";
        products[8][0] = "ID009"; products[8][1] = "Fila Disruptor"; products[8][2] = "5200";
        products[9][0] = "ID010"; products[9][1] = "Adidas Handball Spezial"; products[9][2] = "9000";
    }

    void displayProductHeader() {
        cout << endl << left << setw(12) << "Product ID" 
             << left << setw(35) << "Name" 
             << left << setw(10) << "Price" << endl;
        cout << string(57, '-') << endl;
    }

    void getProductDetails(int index) {
        if (index >= 0 && index < productCount) {
            cout << left << setw(12) << products[index][0]
                 << left << setw(35) << products[index][1]
                 << left << setw(10) << products[index][2] << endl;
        } else {
            cout << "Product not found!" << endl;
        }
    }

    void displayProducts() {
        for (int i = 0; i < productCount; i++) {
            getProductDetails(i);
        }
        cout << endl << string(57, '-');
    }

void addToCart() {
    int counter = numOfProdInCart;
    char addProdsInCart;
    char choice;

    do {
        // Initial prompt if no products in cart
        if (counter == 0) {
            do {
                cout << endl << "Do you want to add products to your shopping cart? (Y/N): ";
                cin >> addProdsInCart;
                addProdsInCart = toupper(addProdsInCart);

                // Check if the input is valid
                if (addProdsInCart != 'Y' && addProdsInCart != 'N') {
                    cout << "Invalid input. Please enter 'Y' or 'N' only." << endl;
                }
            } while (addProdsInCart != 'Y' && addProdsInCart != 'N');
        }

        // If the user chooses to add products to the cart
        if (addProdsInCart == 'Y') {
            do {
                cout << endl << "Enter the ID of the product you want to add to the shopping cart: ";
                cin >> productIDChosen;

                // Convert the entered product ID to uppercase for case-insensitive comparison
                for (int i = 0; i < productIDChosen.length(); i++) {
                    productIDChosen[i] = toupper(productIDChosen[i]);
                }

                validProductID = false;
                // Check if the product ID exists
                for (int i = 0; i < productCount; i++) {
                    if (products[i][0] == productIDChosen) {
                        cout << "Selected Product: " << endl;
                        displayProductHeader();
                        cout << left << setw(12) << products[i][0]
                             << left << setw(35) << products[i][1]
                             << left << setw(10) << products[i][2] << endl;
                        cout << string(57, '-') << endl;

                        productInCart[counter] = products[i][0];

                        cout << "Enter quantity: ";
                        cin >> productQtyListed[counter];

                        cout << endl << "Product added to cart successfully!" << endl << endl;
                        validProductID = true;
                        counter++;
                        numOfProdInCart = counter;
                        break;
                    }
                }

                // If the product ID is invalid, prompt the user to try again
                if (!validProductID) {
                    cout << "Invalid product ID! Please try again." << endl;
                }
            } while (!validProductID);  // Loop until a valid product ID is entered

            // Ask if the user wants to add another product to the cart
            do {
                cout << "Do you want to add another product to the shopping cart? (Y/N): ";
                cin >> choice;
                choice = toupper(choice);

                // Check if the input is valid
                if (choice != 'Y' && choice != 'N') {
                    cout << "Invalid input. Please enter 'Y' or 'N' only." << endl;
                }
            } while (choice != 'Y' && choice != 'N');
        } else {
            break;  // Exit the loop if the user does not want to add products
        }

    } while (choice != 'N');  // Continue the loop if the user wants to add another product
}


    int getNumOfProdInCart() {
        return numOfProdInCart;
    }

    string getNameOfProdInCart(int index) {
        for (int i = 0; i < productCount; i++) {
            if (products[i][0] == productInCart[index]) {
                return products[i][1];
            }
        }
        return "";
    }

    double getPriceOfProdInCart(int index) {
        for (int i = 0; i < productCount; i++) {
            if (products[i][0] == productInCart[index]) {
                return stod(products[i][2]);
            }
        }
        return 0.0;
    }

    string getProductIDFromCart(int index) {
        return productInCart[index];
    }

    int getProductQtyFromCart(int index) {
        return productQtyListed[index];
    }

    void setProductInCart(){
        productInCart[100] = "";
    }
};

class ShoppingCart {
private:
    char checkoutChoice;
    double totalPrice;

public:
    ShoppingCart() : totalPrice(0.00) {}

    void displayProductHeader() {
        cout << endl << left << setw(12) << "Product ID" 
             << left << setw(35) << "Name" 
             << left << setw(10) << "Price" 
             << left << setw(10) << "Quantity" << endl;
        cout << string(67, '-') << endl;
    }


    void displayCart(Product &product) {
        totalPrice = 0; // Reset totalPrice to 0

        int numOfProdInCart = product.getNumOfProdInCart();
        
        if (numOfProdInCart == 0) {
            cout << endl << "No product(s) in cart!" << endl;
            return;
        }

        displayProductHeader();

        for (int i = 0; i < numOfProdInCart; i++) {
            cout << left << setw(12) << product.getProductIDFromCart(i) 
                << left << setw(10) << product.getPriceOfProdInCart(i) 
                << left << setw(10) << product.getProductQtyFromCart(i) << endl;

            totalPrice += product.getPriceOfProdInCart(i) * product.getProductQtyFromCart(i);
        }

        cout << string(67, '-') << endl;
        cout << endl << "Total: " << totalPrice << endl;

        askCheckout(product);
    }


    void askCheckout(Product &product) {
        char choice;
        int numOfProdInCart = product.getNumOfProdInCart();

        if (numOfProdInCart > 0) {
            cout << "Do you want to checkout all the products? (Y/N): ";
            cin >> choice;

            if (toupper(choice) == 'Y') {
                Order order;
                checkoutOption(product, order);
            }
        } else {
            cout << "No product(s) in cart! Cannot proceed to checkout." << endl;
        }
    }

    void checkoutOption(Product &product, Order &order) {
        int numOfProdInCart = product.getNumOfProdInCart();
        if (numOfProdInCart == 0) {
            cout << "No product(s) in cart! Cannot checkout." << endl;
            return;
        }

        string name, address;

        displayCheckoutProducts(product);

        cout << "Total: " << getTotalPrice() << endl << endl;
        cout << string(67, '-') << endl;

        cout << "Please enter your information needed for checkout" << endl << endl;
        cout << "Enter your name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter your address: ";
        getline(cin, address);

        for (int i = 0; i < numOfProdInCart; i++) {
            order.setOrderDetails(name, address, product.getProductQtyFromCart(i), product.getPriceOfProdInCart(i));
            cout << order.placeOrder() << " for product: " << product.getNameOfProdInCart(i) << endl;
        }
        cout << "Total price for your order: " << getTotalPrice() << endl;

        totalPrice = 0;
    }

    void displayCheckoutProducts(Product &product) {
        displayProductHeader();
        int numOfProdInCart = product.getNumOfProdInCart();
        for (int i = 0; i < numOfProdInCart; i++) {
            cout << left << setw(12) << product.getProductIDFromCart(i) 
                 << left << setw(35) << product.getNameOfProdInCart(i) 
                 << left << setw(10) << product.getPriceOfProdInCart(i) 
                 << left << setw(10) << product.getProductQtyFromCart(i) << endl;
        }
        cout << string(67, '-') << endl;
    }

    double getTotalPrice() {
        return totalPrice;
    }
};

int main() {
    int choice;
    Product product;
    ShoppingCart cart;
    Order order;

    do {
        cout << string(25, '-') << endl;
        cout << "        Main Menu" << endl;
        cout << string(25, '-') << endl;
        cout << "1 - View Products" << endl;
        cout << "2 - View Shopping Cart" << endl;
        cout << "3 - Checkout" << endl;
        cout << "4 - Exit" << endl;
        cout << string(25, '-') << endl;

        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << string(57, '-') << endl << "                        Products" << endl << string(57, '-');
                product.displayProductHeader();
                product.displayProducts();
                product.addToCart();
                break;
            case 2:

                if (product.getNumOfProdInCart() > 0){

                    cout << string(67, '-') << endl << "                     Shopping Cart" << endl  << string(67, '-');
                }

                cart.displayCart(product);
                break;
            case 3:
                cout << string(67, '-') << endl << "                          Checkout" << endl << string(67, '-');
                cart.checkoutOption(product, order);
                break;
            case 4:
                cout << endl << "Thank you!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
        cout << endl;

    } while (choice != 4);

    return 0;
}
