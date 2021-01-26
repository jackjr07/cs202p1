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

char * product::check_product(char * product_n){
    if(!product_n) return 0;
    char * prod_n = new char[strlen(product_n)+1];
    strcpy(prod_n, product_n);
    stack_p * curr = top_prod;
    if(!curr){
        cout << "No product in database" << endl;
        return 0;
    }
    return check_product(curr, prod_n);
};

char * product::check_product(stack_p * curr, char * prod_n){
    
    if(strcmp(prod_n, curr->prod_obj.product_name) == 0){
        order order_obj;
       return order_obj.putin_order(curr); 
    } 
    if(!curr->next){
        return 0;
    }
    return check_product(curr->next, prod_n);

};

order::order(){
    top_order = NULL;
    order_status = 0;
    order_name = order_seller = order_method = NULL;
};
order::~order(){
    if(top_order){
        stack_p * temp = new stack_p();
        delete top_order;
        top_order = temp;
    }
    if(order_name) delete [] order_name;
    if(order_seller) delete [] order_seller;
    if(order_method) delete [] order_method;
    order_status = 0;
};


int order::display_order(){
    return display_order(top_order);
}

int order::display_order(stack_p * curr){
    if(!curr){
        cout << "No order in line" << endl;
        return 0;
    }
    cout << "Ordered: " << curr->order_obj.order_name << endl;
    cout << "By seller: " << curr->order_obj.order_seller << endl;
    cout << "By buyer: " << curr->order_obj.order_buyer << endl;
    cout << "Shipping Method: " << curr->order_obj.order_method << endl;
    cout << "==================================" << endl;
    if(!curr->next) return 0;
    return display_order(curr->next);

}


char * order::putin_order(stack_p * match){
     cout << "Ordered: " << match->prod_obj.product_name << endl;
     cout << "By seller: " << match->prod_obj.seller << endl;
    cout << "==================================" << endl;
    order_name = match->prod_obj.product_name;
    order_seller = match->prod_obj.seller;
    return match->prod_obj.seller;
     
};

int order::shipping(user * buyer, user * seller){
    if(!buyer || !seller) return 0;
    if(strcmp(buyer->user_city, seller->user_city) == 0){
        cout << "Shipping by Truck " << endl;
        order_method = "Truck";
    }
    else if(strcmp(buyer->user_state, seller->user_state) == 0){
        cout << "Shipping by Train " << endl;
        order_method = "Train";
    }
    else{
        cout << "Shipping by air " << endl;
        order_method = "air";
    }
    return order_push();
};

int order::order_push(){
    if(!top_order){
        stack_p * temp = new stack_p;
        temp->order_obj.order_name = order_name;
        temp->order_obj.order_seller = order_seller;
        temp->order_obj.order_method = order_method;
        temp -> next = NULL;
        top_order = temp;
    }
        stack_p * temp = new stack_p;
        temp->order_obj.order_name = order_name;
        temp->order_obj.order_seller = order_seller;
        temp->order_obj.order_method = order_method;
        temp -> next = top_order;
        top_order = temp;
    return 1;
}

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

