/* Jack Wanitkun
 *This contains all the functionalities for order system
 *
 * */
#include "order.h"

using namespace std;

product::product(){
    top = NULL;
};
product::~product(){
    if(top){
        stack_p * temp = new stack_p;
        delete top;
        top = temp;
    }
};

int product::add_product_p(char * product_a, char * seller_a){
    product_name = new char[strlen(product_a) + 1];
    strcpy(product_name, product_a);
    seller = new char[strlen(seller_a) + 1];
    strcpy(seller, seller_a);
    return stack_push();
}

int product::stack_push(){
    if(!top){
        stack_p * temp = new stack_p();
        temp -> product_obj.product_name = product_name;
        temp -> product_obj.seller = seller;
        temp -> next = NULL;
        top = temp;
       return 1;
    }
    stack_p * temp = new stack_p();
    temp -> product_obj.product_name = product_name;
    temp -> product_obj.seller = seller;
    temp ->next = top;
    top = temp;
    return 1;
};

int product::display_product(){
    return display_product_p(top);
};

int product::display_product_p(stack_p * curr){
    if(!curr){
        cout << "Nothing in the product" << endl;
        return 0;
    }
    while(curr){
        cout << "Product name: " <<  curr->product_obj.product_name << endl;
        cout << "Seller is: " << curr->product_obj.seller << endl;
        curr = curr->next;
    }
    return 1;
};

int product::check_product(order order_obj,char * product_n){
    if(!product_n) return 3;
    stack_p * curr = top;
    if(!curr){
        cout << "No product in database" << endl;
        return 0;
    }
    while(curr){
        if(strcmp(product_n, curr->product_obj.product_name) != 0) return order_obj.putin_order(curr);
        else{
        curr = curr -> next;
        }
    }
    cout << "No match" << endl;
    return 0;
};
/*
        order();
        ~order();
        int putin_order();
        int display_order();
        int shipping(); 
    private:
        int order_status;
        char * order_name;
        char * order_seller;
        char * order_method;
*/

order::order(){
    order_status = 0;
    order_name = order_seller = order_method = NULL;
};
order::~order(){
    if(order_name) delete [] order_name;
    if(order_seller) delete [] order_seller;
    if(order_method) delete [] order_method;
    order_status = 0;
};

int order::putin_order(stack_p * match){
     //cout << "Passed" << endl; 
     char u_name[20];
     cout << "Ordered: " << match->product_obj.product_name << endl;
     cout << "By seller: " << match->product_obj.seller << endl;
    cout << "What is your name: ";
    cin.get(u_name, 20);

     

};

