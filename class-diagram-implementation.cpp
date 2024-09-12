#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
using namespace std;

class Order {
private:
    string orderName, orderAddress, orderStatus;
    int orderQty;
    double orderPrice; 

    struct OrderDetail {
        string name;
        string address;
        double totalPrice;
        string productIDs[100];   // Store product IDs
        string products[100];     // Store product names
        double prices[100];       // Store corresponding prices
        int quantities[100];      // Store corresponding quantities
        int productCount;         // Count of products in the order
    };

    OrderDetail orders[100]; // Array to store multiple orders
    int orderCount; // Number of orders placed

public:
    Order() : orderCount(0) {}

void setOrderDetails(string name, string address, double price, string product[], string productIDs[], double productPrices[], int quantity[], int productCount) {
    orders[orderCount].name = name;
    orders[orderCount].address = address;
    orders[orderCount].totalPrice = price;
    orders[orderCount].productCount = productCount;

    for (int i = 0; i < productCount; ++i) {
        orders[orderCount].products[i] = product[i];
        orders[orderCount].productIDs[i] = productIDs[i];    // Store product IDs
        orders[orderCount].prices[i] = productPrices[i];      // Store product prices
        orders[orderCount].quantities[i] = quantity[i];
    }

    orderQty = 0;
    orderPrice = price;

    for (int i = 0; i < productCount; ++i) {
        orderQty += quantity[i];
    }

    orderCount++;
}

    string placeOrder() {
        return "\nOrder placed for " + to_string(orderQty) + " item(s) at a total price of " + to_string(orderPrice);
    }

    void displayOrders() {
        if (orderCount == 0) {
            cout << "No Orders yet!" << endl;
            return;
        }

        for (int i = 0; i < orderCount; i++) {
            cout << "Order ID: " << (i + 1) << endl;
            cout << "Total Amount: " << fixed << setprecision(2) << orders[i].totalPrice << endl;
            cout << "Order Details:" << endl;
            cout << string(67, '-') << endl;
            cout << left << setw(13) << "Product ID" << left << setw(35) << "Product Name" << left << setw(10) << "Price" << left << setw(10) << "Quantity" << endl;
            cout << string(67, '-') << endl;

            for (int j = 0; j < orders[i].productCount; j++) {
                cout << left << setw(13) << orders[i].productIDs[j] << left << setw(35) << orders[i].products[j] << left << setw(10) << orders[i].prices[j] << left << setw(10) << orders[i].quantities[j] << endl;
            }

            cout << string(67, '-') << endl;
        }
    }
};

class Product
{
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
    Product() : productCount(10), numOfProdInCart(0), validProductID(false)
    {
        products[0][0] = "ID001";
        products[0][1] = "Nike Vomero 5";
        products[0][2] = "7500";
        products[1][0] = "ID002";
        products[1][1] = "Adidas NMD R1";
        products[1][2] = "8500";
        products[2][0] = "ID003";
        products[2][1] = "Puma RS-X";
        products[2][2] = "6200";
        products[3][0] = "ID004";
        products[3][1] = "Reebok Classic";
        products[3][2] = "5000";
        products[4][0] = "ID005";
        products[4][1] = "Converse Chuck";
        products[4][2] = "4500";
        products[5][0] = "ID006";
        products[5][1] = "Vans Old Skool";
        products[5][2] = "4000";
        products[6][0] = "ID007";
        products[6][1] = "New Balance 530";
        products[6][2] = "7000";
        products[7][0] = "ID008";
        products[7][1] = "Asics Quantum";
        products[7][2] = "6800";
        products[8][0] = "ID009";
        products[8][1] = "Fila Disruptor";
        products[8][2] = "5200";
        products[9][0] = "ID010";
        products[9][1] = "Adidas Handball Spezial";
        products[9][2] = "9000";
    }

    void displayProductHeader()
    {
        cout << endl
             << left << setw(12) << "Product ID"
             << left << setw(35) << "Name"
             << left << setw(10) << "Price" << endl;
        cout << string(57, '-') << endl;
    }

    void getProductDetails(int index)
    {
        if (index >= 0 && index < productCount)
        {
            cout << left << setw(12) << products[index][0]
                 << left << setw(35) << products[index][1]
                 << left << setw(10) << fixed << setprecision(2) << stod(products[index][2]) << endl;
        }
        else
        {
            cout << "Product not found!" << endl;
        }
    }

    void displayProducts()
    {
        for (int i = 0; i < productCount; i++)
        {
            getProductDetails(i);
        }
        cout << endl
             << string(57, '-');
    }

    void addToCart()
    {
        char addProdsInCart;

        do
        {
            cout << endl
                 << "Do you want to add products to your shopping cart? (Y/N): ";
            cin >> addProdsInCart;

            if (toupper(addProdsInCart) != 'Y' && toupper(addProdsInCart) != 'N')
            {
                cout << "Invalid input. Please enter 'Y' or 'N' only." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                addProdsInCart = ' ';
            }
            else
            {
                addProdsInCart = toupper(addProdsInCart);
            }

        } while (addProdsInCart != 'Y' && addProdsInCart != 'N');

        while (addProdsInCart == 'Y')
        {
            cout << endl
                 << "Enter the ID of the product you want to add to the shopping cart: ";
            cin >> productIDChosen;

            for (int i = 0; i < productIDChosen.length(); i++)
            {
                productIDChosen[i] = toupper(productIDChosen[i]);
            }

            validProductID = false;
            for (int i = 0; i < productCount; i++)
            {
                if (products[i][0] == productIDChosen)
                {
                    cout << endl
                         << "Selected Product: " << endl;
                    displayProductHeader();
                    cout << left << setw(12) << products[i][0]
                         << left << setw(35) << products[i][1]
                         << left << setw(10) << products[i][2] << endl;
                    cout << string(57, '-') << endl;

                    bool productExists = false;
                    for (int j = 0; j <= numOfProdInCart; j++)
                    {
                        if (productInCart[j] == products[i][0])
                        {
                            productQtyListed[j] += 1;
                            productExists = true;
                            break;
                        }
                    }

                    if (!productExists)
                    {
                        productInCart[numOfProdInCart] = products[i][0];

                        int quantity;
                        while (true)
                        {
                            cout << endl
                                 << "Enter quantity (1-100): ";
                            cin >> quantity;

                            if (quantity < 1 || quantity > 100)
                            {
                                cout << endl
                                     << "Invalid quantity! Please enter a number between 1 and 100." << endl;
                                cin.clear();
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            }
                            else
                            {
                                productQtyListed[numOfProdInCart] = quantity;
                                break;
                            }
                        }

                        cout << endl
                             << "Product added to cart successfully!" << endl
                             << endl;
                    }

                    numOfProdInCart++;
                    validProductID = true;
                    break;
                }
            }

            if (!validProductID)
            {
                cout << "Invalid product ID! Please try again." << endl;
            }
            else
            {   
                do
                {
                    cout << "Do you want to add another product to the shopping cart? (Y/N): ";
                    cin >> addProdsInCart;
                    addProdsInCart = toupper(addProdsInCart);

                    if (addProdsInCart != 'Y' && addProdsInCart != 'N')
                    {
                        cout << endl
                             << "Invalid input. Please enter 'Y' or 'N' only." << endl;
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }

                } while (addProdsInCart != 'Y' && addProdsInCart != 'N');
            }
            cout << string(57, '-') << endl
            << "                        Products" << endl
            << string(57, '-');

            displayProductHeader();
            displayProducts();
        }
    }

    int getNumOfProdInCart()
    {
        return numOfProdInCart;
    }

    string getNameOfProdInCart(int index)
    {
        for (int i = 0; i < productCount; i++)
        {
            if (products[i][0] == productInCart[index])
            {
                return products[i][1];
            }
        }
        return "";
    }

    double getPriceOfProdInCart(int index)
    {
        for (int i = 0; i < productCount; i++)
        {
            if (products[i][0] == productInCart[index])
            {
                return stod(products[i][2]);
            }
        }
        return 0.0;
    }

    void clearCart()
    {
        for (int i = 0; i < numOfProdInCart; i++)
        {
            productInCart[i] = "";
            productQtyListed[i] = 0;
        }
        numOfProdInCart = 0;
    }

    string getProductIDFromCart(int index)
    {
        return productInCart[index];
    }

    int getProductQtyFromCart(int index)
    {
        return productQtyListed[index];
    }

    void setProductInCart()
    {
        productInCart[100] = "";
    }
};

class ShoppingCart
{
private:
    char checkoutChoice;
    double totalPrice;
    int orderID = 0;
    int orderNumber = 0;
    Order lastOrder;

public:
    ShoppingCart() : totalPrice(0.00) {}

    void displayProductHeader()
    {
        cout << endl
             << left << setw(12) << "Product ID"
             << left << setw(35) << "Name"
             << left << setw(10) << "Price"
             << left << setw(10) << "Quantity" << endl;
        cout << string(67, '-') << endl;
    }

void willCheckout(Product &product, Order &order){

    char choice;

    do {
        cout << "Do you want to checkout all the products? (Y/N): ";
        cin >> choice;

        choice = toupper(choice);

        if (choice != 'Y' && choice != 'N') {
            cout << endl
            << "Invalid input. Please enter 'Y' or 'N' only." << endl
            << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

    } while (choice != 'Y' && choice != 'N');

    system("cls");
    if (choice == 'Y'){
        //displayCheckoutProducts(product);
        checkoutOption(product, order);
    }

}

void displayCart(Product &product, Order &order) {
    totalPrice = 0;
    int numOfProdInCart = product.getNumOfProdInCart();

    if (numOfProdInCart == 0) {
        cout << endl << "\t\t No product(s) in cart!" << endl << endl;
        system("pause");  // Pause after displaying the empty cart message
        return;
    }
    else{

    displayProductHeader();

    for (int i = 0; i < numOfProdInCart; i++) {
        cout << left << setw(12) << product.getProductIDFromCart(i)
             << left << setw(35) << product.getNameOfProdInCart(i)
             << left << setw(10) << fixed << setprecision(2) << product.getPriceOfProdInCart(i)
             << left << setw(10) << product.getProductQtyFromCart(i) << endl;

        totalPrice += product.getPriceOfProdInCart(i) * product.getProductQtyFromCart(i);
    }

    cout << string(67, '-') << endl;
    cout << "Total: " << totalPrice << endl << endl;


    willCheckout(product, order);
    }

    system("pause"); 
}

    void displayCheckoutProducts(Product &product)
    {

        cout << string(67, '-') << endl
             << "                          Checkout" << endl
             << string(67, '-');
        displayProductHeader();
        int numOfProdInCart = product.getNumOfProdInCart();
        for (int i = 0; i < numOfProdInCart; i++)
        {
            cout << left << setw(12) << product.getProductIDFromCart(i)
                 << left << setw(35) << product.getNameOfProdInCart(i)
                 << left << setw(10) << product.getPriceOfProdInCart(i)
                 << left << setw(10) << product.getProductQtyFromCart(i) << endl;
        }
        cout << string(67, '-') << endl;
    }

    double getTotalPrice()
    {
        return totalPrice;
    }

void checkoutOption(Product &product, Order &order) {
    int numOfProdInCart = product.getNumOfProdInCart();
    if (numOfProdInCart == 0) {
        cout << endl << "No product(s) in cart! Cannot checkout." << endl << endl;
        return;
    }

    string name, address;

    displayCheckoutProducts(product);

    totalPrice = 0;
    for (int i = 0; i < numOfProdInCart; i++) {
        totalPrice += product.getPriceOfProdInCart(i) * product.getProductQtyFromCart(i);
    }

    cout << "Total: " << fixed << setprecision(2) << totalPrice << endl;

    cout << endl << "Please enter your information needed for checkout" << endl << endl;
    cout << "Enter your Name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter your Address: ";
    getline(cin, address);

    // Create arrays to hold product names, IDs, prices, and quantities
    string productNames[100];  // Assuming max 100 products
    string productIDs[100];    // Store product IDs
    double productPrices[100];  // Store product prices
    int quantities[100];        // Store quantities

    for (int i = 0; i < numOfProdInCart; i++) {
        productNames[i] = product.getNameOfProdInCart(i); // Store product names
        productIDs[i] = product.getProductIDFromCart(i);   // Store product IDs
        productPrices[i] = product.getPriceOfProdInCart(i); // Store product prices
        quantities[i] = product.getProductQtyFromCart(i);    // Store quantities
    }

    // Pass correct parameters to setOrderDetails
    order.setOrderDetails(name, address, totalPrice, productNames, productIDs, productPrices, quantities, numOfProdInCart);

    // Store last order details in ShoppingCart
    lastOrder = order;

    // Output the order confirmation message
    cout << fixed << setprecision(2) << order.placeOrder() << " for product(s): ";
    for (int i = 0; i < numOfProdInCart; i++) {
        cout << product.getNameOfProdInCart(i) << " (Qty: " << product.getProductQtyFromCart(i) << "), ";
    }
    cout << endl;

    cout << endl << "Total price for your order: " << fixed << setprecision(2) << totalPrice << endl << endl;

    // Increment order ID after a successful checkout
    orderID++;

    // Clear the cart after successful checkout
    product.clearCart();
}

    void displayOrderProducts(Product &product)
    {
        lastOrder.displayOrders();
    }

    int getOrderID()
    {
        return orderID;
    }
};

int main()
{
    int choice;
    Product product;
    ShoppingCart cart;
    Order order;

    do
    {
        system("cls");
        cout << string(25, '-') << endl;
        cout << "        Main Menu" << endl;
        cout << string(25, '-') << endl;
        cout << "1 - View Products" << endl;
        cout << "2 - View Shopping Cart" << endl;
        cout << "3 - Order" << endl;
        cout << "4 - Exit" << endl;
        cout << string(25, '-') << endl;

        cout << "Enter choice: ";
        cin >> choice;

        if (choice < 1 || choice > 4)
        {
            cout << "Invalid choice. Please enter a number between 1 and 4. Press any key to continue. ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        switch (choice)
        {
        case 1:
            system("cls");
            cout << string(57, '-') << endl
                 << "                        Products" << endl
                 << string(57, '-');
            product.displayProductHeader();
            product.displayProducts();
            product.addToCart();
            break;
        case 2:
            system("cls");
            
            cout << string(67, '-') << endl
                 << "                         Shopping Cart" << endl
                 << string(67, '-');
            cart.displayCart(product, order);
            break;
        case 3:
            system("cls");
            if (cart.getOrderID() > 0)
            {
                order.displayOrders();
            }
            else
            {
                cout << "No Orders yet!" << endl
                     << endl;
            }
            system("pause");
            break;
        case 4:
            cout << endl
                 << "Thank you!" << endl;
            break;
        default:
            cin.get();
        }
        cout << endl;

    } while (choice != 4);

    return 0;
}