/*Jack Wanitkun
 * This is a structure of ordering system. Now I have user. 
 * Next step is to make the ordering system.
 * Plan: users can add product, order, and display for both end
*/
#include "user.h"
struct stack_p;
class order;
class product: public user{
    public:
        product();
        ~product();
        int display_product();
        int add_product_p(char * product_a, char * seller_a);
        char * product_name;
        char * seller;
        int check_product(order order_obj,char * product_n);
    private:
        stack_p * top;
        int display_product_p(stack_p * curr);
        int stack_push();

};

class order: public product{
    public:
        order();
        ~order();
        int putin_order(stack_p * match);
        int display_order();
        int shipping(); 
    private:
        int order_status;
        char * order_name;
        char * order_seller;
        char * order_method;
};

struct stack_p{
    product product_obj;
    stack_p * next;
};
