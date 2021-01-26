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
    private:
        stack_p * top_prod;
        int display_product_p(stack_p * curr);
        int stack_push();

};

class order: public product{
    public:
        order();
        ~order();
        char * putin_order(stack_p * match);
        int display_order();
        int shipping(user * buyer, user * seller); 
        int cal_shipping(char * lo_seller, char * lo_buyer);
        int order_push();

    private:
        int display_order(stack_p * curr);
        stack_p * top_order;
        int order_status;
        char * order_name;
        char * order_seller;
        char * order_buyer;
        char * order_method;
};

class stack_p: public order{
    public: 
        stack_p();
        ~stack_p();
        int stack_push();
        product prod_obj;
        order order_obj;
        stack_p * next;
    private:
};

