#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class Warehouse {
    public:
        // all aboard the breakage-mobile
         vector<Product> products;

        void update_warehouse(Product product) {products.push_back(product);}
};

class Admin: public User {
    public:
        void manage_products() {
            // broken (for now)
        }
        void manage_users() {
            fstream userdb("User_database.txt");
            if(userdb.is_open()){
                int choice;
                cout << "1. Add user\n2. Modify user\n3. Delete user\nPlease enter your choice: "; cin >> choice;
                if(choice == 1) {
                    register_user();
                } else if(choice == 2) {
                    int id;
                    cout << "Enter ID of user: "; cin >> id;
                    int stored_id;
                    while (userdb >> stored_id ) {
                        if (stored_id == id) {
                            int mchoice;
                            cout << "1. Modify name\n2. Modify surname\n3. Modify address\n4. Modify password\nPlease enter your choice: "; cin >> mchoice;
                            if(mchoice == 1) {
                                
                            }
                        }
                    }
                }
            }
        }
        void view_orders() {
            // also borked for now
            for(int i = 0; i < olen; i++)
                cout << orderlist[i] << endl;
        }
        void update_warehouse() {
            Warehouse::update_warehouse();
        }
};

class Payment {
    public:
        string payment_type;
        int amount;

        Payment(string pt, int a) : payment_type(pt), amount(a){}

        void process_payment() {

        }
        void validate_transaction() {

        }
        void issue_reciept() {
            cout << "Payment type: " << payment_type << "\nAmount" << amount << endl;
        }
};
