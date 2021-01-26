/* Jack Wanitkun
 *This contains all the functionalities for order system
 *
 * */
#include "order.h"

using namespace std;

product::product(){
    top_prod = NULL;
};
product::~product(){
    if(top_prod){
        stack_p * temp = new stack_p;
        delete top_prod;
        top_prod = temp;
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
    if(!top_prod){
        stack_p * temp = new stack_p();
        temp -> prod_obj.product_name = product_name;
        temp -> prod_obj.seller = seller;
        temp -> next = NULL;
        top_prod= temp;
       return 1;
    }
    stack_p * temp = new stack_p();
    temp -> prod_obj.product_name = product_name;
    temp -> prod_obj.seller = seller;
    temp ->next = top_prod;
    top_prod = temp;
    return 1;
};

int product::display_product(){
    return display_product_p(top_prod);
};

int product::display_product_p(stack_p * curr){
    if(!curr){
        cout << "Nothing in the product" << endl;
        return 0;
    }
    cout << "Product name: " <<  curr->prod_obj.product_name << endl;
    cout << "Seller is: " << curr->prod_obj.seller << endl;
    if(!curr->next) return 0;
    return display_product_p(curr->next);
};

int product::check_product(char * product_n){
    if(!product_n) return 3;
    char * prod_n = new char[strlen(product_n)+1];
    strcpy(prod_n, product_n);
    stack_p * curr = top_prod;
    if(!curr){
        cout << "No product in database" << endl;
        return 0;
    }
    return check_product(curr, prod_n);
};
int product::check_product(stack_p * curr, char * prod_n){
    
    if(strcmp(prod_n, curr->prod_obj.product_name) == 0){
        order order_obj;
       return order_obj.putin_order(curr); 
    } 
    if(!curr->next){
        return 0;
    }
    return check_product(curr->next, prod_n);

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
     char u_name[20];
     cout << "Ordered: " << match->prod_obj.product_name << endl;
     cout << "By seller: " << match->prod_obj.seller << endl;
     cout << "What's your name: ";
     cin.get(u_name,20); cin.ignore(100,'\n');
    
     char * buyer = new char[strlen(u_name)+1];
     strcpy(buyer, u_name);

     stack_p * ordered = new stack_p();
     ordered->order_obj.order_name = new char [strlen(match->prod_obj.product_name) +1];
     strcpy(ordered->order_obj.order_name, match->prod_obj.product_name);

     ordered->order_obj.order_seller = new char [strlen(match->prod_obj.seller) +1];
     strcpy(ordered->order_obj.order_seller, match->prod_obj.seller);
    
     ordered->order_obj.order_buyer = new char [strlen(u_name) +1];
     strcpy(ordered->order_obj.order_buyer, buyer);
     return shipping(ordered);
};

int order::shipping(stack_p * ordered){
   if(!ordered) return 0;
   user * buyer;
   user * seller;
   database user_db;
   cout << ordered->order_obj.order_buyer << endl;
   cout << ordered->order_obj.order_seller << endl;
   buyer = prod_find_user(ordered->order_obj.order_buyer);
   cout << buyer->display_user() << endl;
  /* 
   buyer = user_db.find_user(ordered->order_obj.order_buyer);
   cout << "Buyer's city: " << buyer->user_city << endl;
   cout << "Buyer's state: " << buyer->user_state << endl;

   seller = user_db.find_user(ordered->order_obj.order_seller);
   cout << "Seller's city: " << seller->user_city << endl;
   cout << "Seller's state: " << seller->user_state << endl;
  */ 

   return 1;
};

int cal_shipping(char * lo_seller, char * lo_buyer){

    return 0;    
}

stack_p::stack_p(){
    next = NULL;
};
stack_p::~stack_p(){
    if(next){
        stack_p * temp = new stack_p();
        temp->next = NULL;
        next = temp;
    }
};

