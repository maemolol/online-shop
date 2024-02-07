#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <chrono>
#include <thread>

using namespace std;
using namespace std::this_thread;

class Warehouse {
    public:
        // all aboard the breakage-mobile
         vector<Product> products;

         Warehouse();

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
                switch (choice) {
                    case 1:
                        registerUser();
                    case 2:
                        modifyUser();
                }   
            }
        }

        void modifyUser() {
            fstream userdb("User_database.txt");
            int id;
            cout << "Enter ID of user: "; cin >> id;
            int stored_id;
            string stored_name, stored_surname, stored_address, stored_password;
            while (userdb >> stored_id ) {
                if (stored_id == id) {
                    int mchoice;
                    cout << "1. Modify name\n2. Modify surname\n3. Modify address\n4. Modify password\n5. Exit\nPlease enter your choice: "; cin >> mchoice;
                    switch(mchoice) {
                        case 1: {
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
                        } case 2: {
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
                        } case 3: {
                            
                            string new_address; //temporary variables to store modified data
                            string temp_line;  //temporary variable to store the entire line

                            
                            ofstream tempFile("temp_user_database.txt"); //create a temporary file to store modified data

                            
                            while (userdb >> stored_id >> stored_name >> stored_surname >> stored_address >> stored_password) { //loop through the userdb file
                                if (stored_id == id) {
                                    cout << "Enter a new address: "; cin >> new_address;
                                    //update only the name
                                    tempFile << stored_id << " " << stored_name << " " << stored_surname << " " << new_address << " " << stored_password << endl;
                                } else {
                                    //write unchanged data to the temporary file
                                    tempFile << stored_id << " " << stored_name << " " << stored_surname << " " << stored_address << " " << stored_password << endl;
                                }
                            }

                            
                            userdb.close(); //close the original file
                            tempFile.close(); //close the temporary file

                            
                            remove("User_database.txt"); //remove the original file

                            
                            rename("temp_user_database.txt", "User_database.txt"); //rename the temporary file to the original file
                        } case 4: {
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
                        } case 5:
                            break;
                    }
                }
            }
        }

        void view_orders() {
            // also borked for now
            for(int i = 0; i < olen; i++) {
                cout << orderlist[i] << endl;
            }
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
            cout << "Processing payment...";
            sleep_for(3s);
        }
        void validate_transaction() {

        }
        void issue_reciept() {
            cout << "Payment type: " << payment_type << "\nAmount" << amount << endl;
        }
};

// Useful commands for makefile:
// make(to compille)
// make run, make push