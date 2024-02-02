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
                                // Temporary variables to store modified data
                                string new_name;
                                string temp_line;  // Temporary variable to store the entire line

                                // Create a temporary file to store modified data
                                ofstream tempFile("temp_user_database.txt");

                                // Loop through the userdb file
                                while (userdb >> stored_id >> stored_name >> stored_surname >> stored_address >> stored_password) {
                                    if (stored_id == id) {
                                        cout << "Enter a new name: "; cin >> new_name;
                                        // Update only the name
                                        tempFile << stored_id << " " << new_name << " " << stored_surname << " " << stored_address << " " << stored_password << endl;
                                    } else {
                                        // Write unchanged data to the temporary file
                                        tempFile << stored_id << " " << stored_name << " " << stored_surname << " " << stored_address << " " << stored_password << endl;
                                    }
                                }

                                // Close the original file
                                userdb.close();
                                
                                // Close the temporary file
                                tempFile.close();

                                // Remove the original file
                                remove("User_database.txt");

                                // Rename the temporary file to the original file
                                rename("temp_user_database.txt", "User_database.txt");
                            } else if(mchoice == 2) {
                                // Temporary variables to store modified data
                                string new_surname;
                                string temp_line;  // Temporary variable to store the entire line

                                // Create a temporary file to store modified data
                                ofstream tempFile("temp_user_database.txt");

                                // Loop through the userdb file
                                while (userdb >> stored_id >> stored_name >> stored_surname >> stored_address >> stored_password) {
                                    if (stored_id == id) {
                                        cout << "Enter a new name: "; cin >> new_surname;
                                        // Update only the name
                                        tempFile << stored_id << " " << stored_name << " " << new_surname << " " << stored_address << " " << stored_password << endl;
                                    } else {
                                        // Write unchanged data to the temporary file
                                        tempFile << stored_id << " " << stored_name << " " << stored_surname << " " << stored_address << " " << stored_password << endl;
                                    }
                                }

                                // Close the original file
                                userdb.close();
                                
                                // Close the temporary file
                                tempFile.close();

                                // Remove the original file
                                remove("User_database.txt");

                                // Rename the temporary file to the original file
                                rename("temp_user_database.txt", "User_database.txt");
                            } else if(mchoice == 3) {
                                // Temporary variables to store modified data
                                string new_address;
                                string temp_line;  // Temporary variable to store the entire line

                                // Create a temporary file to store modified data
                                ofstream tempFile("temp_user_database.txt");

                                // Loop through the userdb file
                                while (userdb >> stored_id >> stored_name >> stored_surname >> stored_address >> stored_password) {
                                    if (stored_id == id) {
                                        cout << "Enter a new address: "; cin >> new_address;
                                        // Update only the name
                                        tempFile << stored_id << " " << stored_name << " " << stored_surname << " " << new_address << " " << stored_password << endl;
                                    } else {
                                        // Write unchanged data to the temporary file
                                        tempFile << stored_id << " " << stored_name << " " << stored_surname << " " << stored_address << " " << stored_password << endl;
                                    }
                                }

                                // Close the original file
                                userdb.close();
                                
                                // Close the temporary file
                                tempFile.close();

                                // Remove the original file
                                remove("User_database.txt");

                                // Rename the temporary file to the original file
                                rename("temp_user_database.txt", "User_database.txt");
                            } else if(mchoice == 4) {
                                // Temporary variables to store modified data
                                string new_password;
                                string temp_line;  // Temporary variable to store the entire line

                                // Create a temporary file to store modified data
                                ofstream tempFile("temp_user_database.txt");

                                // Loop through the userdb file
                                while (userdb >> stored_id >> stored_name >> stored_surname >> stored_address >> stored_password) {
                                    if (stored_id == id) {
                                        cout << "Enter a new name: "; cin >> new_password;
                                        // Update only the name
                                        tempFile << stored_id << " " << stored_name << " " << stored_surname << " " << stored_address << " " << new_password << endl;
                                    } else {
                                        // Write unchanged data to the temporary file
                                        tempFile << stored_id << " " << stored_name << " " << stored_surname << " " << stored_address << " " << stored_password << endl;
                                    }
                                }

                                // Close the original file
                                userdb.close();
                                
                                // Close the temporary file
                                tempFile.close();

                                // Remove the original file
                                remove("User_database.txt");

                                // Rename the temporary file to the original file
                                rename("temp_user_database.txt", "User_database.txt");
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
