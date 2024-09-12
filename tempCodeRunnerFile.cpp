        case 2:
            if (cart.getCartQty() == 0) {
                cout << "No products added to the cart." << endl;
                break;  // Return to menu after displaying the message
            } else {
                cart.viewCart();
                cout << endl << "Do you want to checkout all the products? (Y/N): ";
                cin >> procToCheckout;

                if (toupper(procToCheckout) == 'Y') {
                    cart.checkout();
                }
            }
            break;