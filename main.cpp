/*Jack Wanitkun CS202
 Program#1 || Distribution System
This is the user interface for program#1
*/ 

#include"order.h"

using namespace std;

int menu(int &answer);

int main (){
    user user_obj;
    database database_obj;
    product product_obj;
    order order_obj;
    int answer = 0;
    cout << "Welcome to Jack's distribution system" << endl;
    //Start the program
    do{
        menu(answer);
        if(answer == 1){
            user_obj.add_user();
            database_obj.add_database(user_obj);
        }
        else if(answer == 2){
            database_obj.display_database();
        }
        else if(answer == 3){
            char product_a[20];
            char seller_a[20];
            cout << "What is product name: " ;
            cin.get(product_a, 20);
            cin.ignore(100,'\n');
            cout << "What is your name: ";
            cin.get(seller_a, 20);
            cin.ignore(100, '\n');
            product_obj.add_product_p(product_a, seller_a);
        }
        else if(answer == 4){
            product_obj.display_product();
        }
        else if(answer == 5){
            char product_n[20];
            cout << "Product name: " ;
            cin.get(product_n,20); cin.ignore(100,'\n');
            product_obj.check_product(order_obj,product_n);

        }
        else if(answer == 8){
            char u_name[20];
            cout << "What is your name: ";
            cin.get(u_name,20); cin.ignore(100,'\n');
            database_obj.find_user(u_name);

        }
    }while(answer != 9);
    cout << "Thank you !!!" << endl;
return 0;
}

int menu(int &answer){
    cout << "Choose the options" << endl;
    cout << "[1] Create your account \n";
    cout << "[2] Display all users \n";
    cout << "[3] Add your Product \n";
    cout << "[4] Display all products \n";
    cout << "[5] Put in order \n";
    cout << "[8] See your account \n";
    cout << "[9] Exit the program\n";
    cin >> answer;
    cin.ignore(100,'\n');
    return answer;

return 0;
}

