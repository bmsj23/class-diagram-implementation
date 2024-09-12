#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
using namespace std;

class Order
{
private:
    string orderName, orderAddress, orderStatus;
    int orderQty;
    double orderPrice;

    struct OrderDetail
    {
        string name;
        string address;
        double totalPrice;
        string productIDs[100];
        string products[100];
        double prices[100];
        int quantities[100];
        int productCount;
    };

    OrderDetail orders[100];
    int orderCount;

public:
    Order() : orderCount(0) {}

    void setOrderDetails(string name, string address, double price, string product[], string productIDs[], double productPrices[], int quantity[], int productCount)
    {
        orders[orderCount].name = name;
        orders[orderCount].address = address;
        orders[orderCount].totalPrice = price;
        orders[orderCount].productCount = productCount;

        for (int i = 0; i < productCount; ++i)
        {
            orders[orderCount].products[i] = product[i];
            orders[orderCount].productIDs[i] = productIDs[i];
            orders[orderCount].prices[i] = productPrices[i];
            orders[orderCount].quantities[i] = quantity[i];
        }

        orderQty = 0;
        orderPrice = price;

        for (int i = 0; i < productCount; ++i)
        {
            orderQty += quantity[i];
        }

        orderCount++;
    }

    string placeOrder()
    {
        return "\nCheckout for " + to_string(orderQty) + " item(s) successful!";
    }

    void displayOrders()
    {
        if (orderCount == 0)
        {
            cout << "No Orders yet!" << endl;
            return;
        }

        for (int i = 0; i < orderCount; i++)
        {
            cout << endl << "Order ID: " << (i + 1) << endl;
            cout << "Total Amount: " << fixed << setprecision(2) << orders[i].totalPrice << endl;
            cout << "Order Details:" << endl;
            cout << string(67, '-') << endl;
            cout << left << setw(13) << "Product ID" << left << setw(35) << "Product Name" << left << setw(10) << "Price" << left << setw(10) << "Quantity" << endl;
            cout << string(67, '-') << endl;

            for (int j = 0; j < orders[i].productCount; j++)
            {
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
        do
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
                    int quantity;

                    char addMore;
                    
                    for (int j = 0; j < numOfProdInCart; j++)
                    {
                        if (productInCart[j] == products[i][0])
                        {
                            productExists = true;
                            cout << "This product is already in your cart." << endl << endl;

                            do
                            {
                                cout << endl << "Do you want to add this product in your cart again? (Y/N): ";
                                cin >> addMore;
                                addMore = toupper(addMore);

                                if (addMore != 'Y' && addMore != 'N')
                                {
                                    cout << "Invalid input. Please enter 'Y' or 'N' only." << endl;
                                    cin.clear();
                                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                }

                            } while (addMore != 'Y' && addMore != 'N');

                            if (addMore == 'N')
                            {
                                cout << endl;
                                validProductID = true;
                                break;
                            }
                            break;
                        }
                    }

                    if (!productExists || addMore == 'Y')
                    {
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
                                if (productExists)
                                {
                                    for (int j = 0; j < numOfProdInCart; j++)
                                    {
                                        if (productInCart[j] == products[i][0])
                                        {
                                            productQtyListed[j] += quantity;
                                            cout << endl
                                                 << "Product quantity updated successfully!" << endl
                                                 << endl;
                                            break;
                                        }
                                    }
                                }
                                else
                                {
                                    productInCart[numOfProdInCart] = products[i][0];
                                    productQtyListed[numOfProdInCart] = quantity;
                                    numOfProdInCart++;
                                    cout << endl
                                         << "Product added to cart successfully!" << endl
                                         << endl;
                                }
                                break;
                            }
                        }
                    }

                    validProductID = true;
                    break;
                }
            }

            if (!validProductID)
            {
                cout << "Invalid product ID! Please try again." << endl;
            }
        } while (!validProductID);

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

        if (addProdsInCart == 'Y')
        {
            system("cls");

            cout << endl
                 << string(57, '-') << endl
                 << "                        Products" << endl
                 << string(57, '-');

            displayProductHeader();
            displayProducts();
        }
    }
    cout << endl
         << "Returning to Main Menu." << endl;
    system("pause");
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
        cout
            << left << setw(12) << "Product ID"
            << left << setw(35) << "Name"
            << left << setw(10) << "Price"
            << left << setw(10) << "Quantity" << endl;
        cout << string(67, '-') << endl;
    }

    void willCheckout(Product &product, Order &order)
    {

        char choice;

        do
        {
            cout << "Do you want to checkout all the products? (Y/N): ";
            cin >> choice;

            choice = toupper(choice);

            if (choice != 'Y' && choice != 'N')
            {
                cout << endl
                     << "Invalid input. Please enter 'Y' or 'N' only." << endl
                     << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

        } while (choice != 'Y' && choice != 'N');

        if (choice == 'Y')
        {
            system("cls");
            checkoutOption(product, order);
        }
    }

    void displayCart(Product &product, Order &order)
    {
        totalPrice = 0;
        int numOfProdInCart = product.getNumOfProdInCart();

        if (numOfProdInCart == 0)
        {
            cout << endl
                 << "\t\t     No product(s) in cart!" << endl
                 << endl;
            cout << "Returning to Main Menu." << endl;
            system("pause");
            return;
        }
        else
        {
            cout << endl;
            displayProductHeader();

        for (int i = 0; i < numOfProdInCart; i++)
        {
            string prodID = product.getProductIDFromCart(i);
            string prodName = product.getNameOfProdInCart(i);
            double prodPrice = product.getPriceOfProdInCart(i);
            int prodQty = product.getProductQtyFromCart(i);

            if (!prodID.empty() && prodPrice > 0 && prodQty > 0)
            {
                cout << left << setw(12) << prodID
                     << left << setw(35) << prodName
                     << left << setw(10) << fixed << setprecision(2) << prodPrice
                     << left << setw(10) << prodQty << endl;

                totalPrice += prodPrice * prodQty;
            }
        }
            cout << string(67, '-') << endl;
            cout << "Total: " << totalPrice << endl
                 << endl;

            willCheckout(product, order);
        }
        cout << endl << "Returning to Main Menu." << endl;
        system("pause");
    }

void displayCheckoutProducts(Product &product)
{
    int numOfProdInCart = product.getNumOfProdInCart();

    cout << string(67, '-') << endl
         << "                          Checkout" << endl
         << string(67, '-') << endl;
    displayProductHeader();

    for (int i = 0; i < numOfProdInCart; i++)
    {
        cout << left << setw(12) << product.getProductIDFromCart(i)
             << left << setw(35) << product.getNameOfProdInCart(i)
             << left << setw(10) << fixed << setprecision(2) << product.getPriceOfProdInCart(i)
             << left << setw(10) << product.getProductQtyFromCart(i) << endl;
    }

    cout << string(67, '-') << endl;
}

    double getTotalPrice()
    {
        return totalPrice;
    }

void checkoutOption(Product &product, Order &order)
{
    int numOfProdInCart = product.getNumOfProdInCart();

    if (numOfProdInCart == 0)
    {
        cout << endl
             << "No product(s) in cart! Cannot checkout." << endl
             << endl;
        return;
    }

    string name, address;

    displayCheckoutProducts(product);

    totalPrice = 0;
    for (int i = 0; i < numOfProdInCart; i++)
    {
        // Calculate the total price correctly
        totalPrice += product.getPriceOfProdInCart(i) * product.getProductQtyFromCart(i);
    }

    // Display the final total price
    cout << "Total: " << fixed << setprecision(2) << totalPrice << endl;

    cout << endl
         << "Please enter your information needed for checkout" << endl
         << endl;
    cout << "Enter your Name: ";
    cin.ignore();  // Flush out any new line characters left in the input buffer
    getline(cin, name);  // Take the full name input
    cout << "Enter your Address: ";
    getline(cin, address);  // Take the full address input

    // Initialize the arrays to hold product details
    string productNames[100];
    string productIDs[100];
    double productPrices[100];
    int quantities[100];

    // Populate the arrays with product details in the cart
    for (int i = 0; i < numOfProdInCart; i++)
    {
        productNames[i] = product.getNameOfProdInCart(i);
        productIDs[i] = product.getProductIDFromCart(i);
        productPrices[i] = product.getPriceOfProdInCart(i);
        quantities[i] = product.getProductQtyFromCart(i);
    }

    // Set order details using the order object
    order.setOrderDetails(name, address, totalPrice, productNames, productIDs, productPrices, quantities, numOfProdInCart);

    lastOrder = order;  // Store the order as the last one

    // Place order and display confirmation message
    cout << fixed << setprecision(2) << order.placeOrder() << " for product(s): ";
    for (int i = 0; i < numOfProdInCart; i++)
    {
        cout << product.getNameOfProdInCart(i) << " (Qty: " << product.getProductQtyFromCart(i) << "), ";
    }
    cout << endl;

    // Display the total price
    cout << endl
         << "Total price for your order: " << fixed << setprecision(2) << totalPrice << endl
         << endl;

    orderID++;  // Increment order ID for future orders

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

        do
        {

            cout << "Enter choice: ";
            cin >> choice;

            if (choice < 1 || choice > 4)
            {
                cout << "Invalid choice. Please enter a number between 1 and 4.";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

        } while (choice < 1 || choice > 4);

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
                cout << string(67, '-') << endl
                     << "                           Checkout" << endl
                     << string(67, '-') << endl;
                cout << "No Orders yet!" << endl
                     << endl;
            }
            cout << endl
                 << "Returning to Main Menu" << endl;
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