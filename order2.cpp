/* Jack Wanitkun
 *This contains all the functionalities for order system
 *
 * */
#include "order2.h"

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
    cout << "=================================" <<endl;
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
       return curr->prod_obj.seller;
    } 
    if(!curr->next){
        return 0;
    }
    return check_product(curr->next, prod_n);

};

stack_p * product::get_next(){
  return top_prod;
};

stack_p * product::get_next(stack_p * curr){
  if(curr->next){
    return get_next(curr->next); 
  }
  return curr;
};

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

order::order(){
    order_buyer = order_name = order_seller = order_method = NULL;
};
order::~order(){
    if(order_name) delete [] order_name;
    if(order_buyer) delete [] order_buyer;
    if(order_seller) delete [] order_seller;
    if(order_method) delete [] order_method;
};

int order::display_order(){
  if(order_name){
    cout << "Product name: " << order_name << endl;
  }
  if(order_buyer){
    cout << "ordered by: " << order_buyer << endl;
  }
  if(order_seller){
    cout << "Sell by: " << order_seller << endl;
  }
  if(order_method){
    cout << "Shipping: " << order_method << endl;
    cout << "=============================" << endl;
  }
  
  return 1;
}

int order::shipping(char * product_n, user * buyer, user * seller){
    char * method_n;

    if(!buyer || !seller) return 0;
    if(strcmp(buyer->user_city, seller->user_city) == 0){
        cout << "Shipping by Truck " << endl;
        method_n = new char[strlen("Truck") + 1];
        strcpy(method_n, "Truck");
    }
    else if(strcmp(buyer->user_state, seller->user_state) == 0){
        cout << "Shipping by Train " << endl;
        method_n = new char[strlen("Train") + 1];
        strcpy(method_n, "Train");
    }
    else{
        cout << "Shipping by air " << endl;
        method_n = new char[strlen("Air") + 1];
        strcpy(method_n, "Air");
    }
    return order_push(product_n,buyer,seller,method_n);
};

int order::order_push(char * product_n, user * buyer, user * seller, char * method_n){
    cout << "Confirmation \n";
    cout << product_n << endl;
    cout << buyer->user_name << endl;
    cout << seller->user_name <<endl;
    cout << method_n << endl;
    cout << "==================================" << endl;
    
    order_name = new char[strlen(product_n) + 1];
    strcpy(order_name, product_n);
    order_buyer = new char[strlen(buyer->user_name) + 1];
    strcpy(order_buyer, buyer->user_name);
    order_seller = new char[strlen(seller->user_name) + 1];
    strcpy(order_seller, seller->user_name);
    order_method = new char[strlen(method_n)+1];
    strcpy(order_method, method_n);
    
    return 1;
};

order * order::get_next(order * curr){
   if(curr->next) {
      return get_next(curr->next);
   };
   return curr;
};

order_list::order_list(){
  head = NULL;

};
order_list::~order_list(){
  if(head){
    order * temp = new order;
    delete head;
    head = temp;
  }

};
int order_list::add_order(order & order_obj){
    order * add = new order();
    add->order_name = order_obj.order_name;
    add->order_buyer = order_obj.order_buyer;
    add->order_seller = order_obj.order_seller;
    add->order_method = order_obj.order_method;
    add -> next = NULL;
    if(!head){
      head = add;
      return 2;
    };
    order * curr = get_next(head);
    curr->next = add;
    cout << "Add order success" << endl;
    return 1;
};

int order_list::display_list(){
    return display_list(head);
};

int order_list::display_list(order * curr){
    if(!curr){
      cout << "No order in database" << endl;
    };
    curr->display_order();
    if(!curr) return 0;
    return display_list(curr->next);
};
