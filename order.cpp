/* Jack Wanitkun
 *This contains all the functionalities for order system
 *
 * */
#include "order.h"
using namespace std;
product::product(){
    pro_name = NULL;
};
product::~product(){
    if(pro_name) delete [] pro_name;
};

int product::add_product(){
    char product_a[20];
    cout << "Product name: ";
    cin.get(product_a, 20); cin.ignore(100,'\n');
    return add_product_p(product_a);
};

int product::add_product_p(char * product_a){
    


}
