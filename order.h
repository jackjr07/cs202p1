/*Jack Wanitkun
 * This is a structure of ordering system. Now I have user. 
 * Next step is to make the ordering system.
 * Plan: users can add product, order, and display for both end
*/

#include "user.h"

class product{
    public:
        product();
        ~product();
        int add_product();
        int display_product();
        int add_product_p(char * product_a);

    private:
        char * pro_name;
        int display_product_p(node * curr);

};
