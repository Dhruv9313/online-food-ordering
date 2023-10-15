#include <iostream>
#include <string>
using namespace std;

struct Menu_item {
    string list;
    int price_item;
    Menu_item(string name, int price) : list(name), price_item(price) {}
};

class Ordering {
    int total = 0;

public:
    void add_item(Menu_item& item, int a);
    void delete_item(Menu_item& item, int a);
    friend void display(const Ordering& order);
};

void Ordering::add_item(Menu_item& item, int a) {
    total = total + a * item.price_item;
}

void Ordering::delete_item(Menu_item& item, int a) {
    total = total - a * item.price_item;
}

void display(const Ordering& order) {
    cout << "Your total is: " << order.total << endl;
}

int main() {
    Ordering order;
    Menu_item burger("Burger", 200);
    Menu_item pizza("Pizza", 500);
    Menu_item french_fries("French Fries", 100);

    while (true) {
        int choice;
        cout << "Enter 1 for adding Burger of ₹200" << endl;
        cout << "Enter 2 for adding Pizza of ₹500" << endl;
        cout << "Enter 3 for adding French Fries of ₹100" << endl;
        cout << "Enter 4 for deleting Burger" << endl;
        cout << "Enter 5 for deleting Pizza" << endl;
        cout << "Enter 6 for deleting French Fries" << endl;
        cout << "Enter 7 to Exit with bill" << endl;
        cin >> choice;

        switch (choice) {
            case 1:
                int a;
                cout << "Enter the number of pieces" << endl;
                cin >> a;
                order.add_item(burger, a);
                break;
            case 2:
                int b;
                cout << "Enter the number of pieces" << endl;
                cin >> b;
                order.add_item(pizza, b);
                break;
            case 3:
                int c;
                cout << "Enter the number of pieces" << endl;
                cin >> c;
                order.add_item(french_fries, c);
                break;
            case 4:
                int d;
                cout << "Enter the number of pieces you want to delete" << endl;
                cin >> d;
                order.delete_item(burger, d);
                break;
            case 5:
                int e;
                cout << "Enter the number of pieces you want to delete" << endl;
                cin >> e;
                order.delete_item(pizza, e);
                break;
            case 6:
                int f;
                cout << "Enter the number of pieces you want to delete" << endl;
                cin >> f;
                order.delete_item(french_fries, f);
                break;
            case 7:
                display(order);
                return 0;
            default:
                cout << "Wrong input" << endl;
        }
    }

    return 0;
}
