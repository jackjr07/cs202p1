/*Jack Wanitkun
 * This is a structure of ordering system. Now I have user. 
 * Next step is to make the ordering system.
 * Plan: users can add product, order, and display for both end
*/
#include "user.h"
class stack_p;
class order;

class product: public database{
    public:
        product();
        ~product();
        int display_product();
        int add_product_p(char * product_a, char * seller_a);
        char * product_name;
        char * seller;
        char *  check_product(char * product_n);
        char * check_product(stack_p * curr, char * product_n);
        stack_p * get_next();
    private:
        stack_p * top_prod;
        int display_product_p(stack_p * curr);
        int stack_push();
        stack_p * get_next(stack_p * curr);

};

class stack_p: public product{
    public: 
        stack_p();
        ~stack_p();
        int stack_push();
        product prod_obj;
        stack_p * next;
    private:
};

class order: public product{
    public:
        order();
        ~order();
        int display_order();
        int shipping(char * product_n, user * buyer, user * seller); 
        int order_push(char * product_n, user * buyer, user * seller, char * method_n);
        order * get_next(order * curr);
        order * next;
        char * order_name;
        char * order_seller;
        char * order_buyer;
        char * order_method;
    private:
};


class order_list: public order{
  public:
      order_list();
      ~order_list();
      int add_order(order & order_obj);
      int display_list();

  private:
      int display_list(order * curr);
      order * head;
};
