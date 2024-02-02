#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "alan.cpp"

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
                    registerUser();
                } else if(choice == 2) {
                    int id;
                    cout << "Enter ID of user: "; cin >> id;
                    int stored_id;
                    string stored_name, stored_surname, stored_address, stored_password;
                    while (userdb >> stored_id ) {
                        if (stored_id == id) {
                            int mchoice;
                            cout << "1. Modify name\n2. Modify surname\n3. Modify address\n4. Modify password\nPlease enter your choice: "; cin >> mchoice;
                            if(mchoice == 1) {
                                while (userdb >> stored_id >> stored_name) {
                                    string new_name;
                                    cout << "Enter a new name: "; cin >> new_name;
                                    stored_name = new_name;
                                }
                            } else if(mchoice == 2) {
                                while(userdb >> stored_id >> stored_name >> stored_surname) {
                                    string new_surname;
                                    cout << "Enter a new surname: "; cin >> new_surname;
                                    stored_surname = new_surname;
                                }
                            } else if(mchoice == 3) {
                                while(userdb >> stored_id >> stored_name >> stored_surname >> stored_address) {
                                    string new_address;
                                    cout << "Enter a new address: "; cin >> new_address;
                                    stored_address == new_address;
                                }
                            } else if(mchoice == 4) {
                                while(userdb >> stored_id >> stored_name >> stored_surname >> stored_address >> stored_password) {
                                    string new_password;
                                    cout << "Enter a new password: "; cin >> new_password;
                                    stored_password == new_password;
                                }
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
