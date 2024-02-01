#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Warehouse {
    public:
        vector<Product> products;

        void update_warehouse(Product product) {products.push_back(product);}
};

class Admin: public User {
    public:
        void manage_products() {
            
        }
        void manage_users() {
            void udelete() {
                userlist.erase(userlist.begin() + index);
            }
        }
        void view_orders() {
            for(int i = 0; i < olen; i++)
                cout << orderlist[i] << endl;
        }
        void update_warehouse() {
            Warehouse::update_warehouse();
        }
};
