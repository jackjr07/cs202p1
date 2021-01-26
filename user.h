/*Jack Wanitkun CS202
 Program#1 
This is the struture for the user section. 
This will contain user base, the buy and seller
*/

#include<iostream>
#include<cstring>
#include<cctype>
class user{
    public:
        user();
        ~user();
        int add_user();
        int display_user();
        user * get_next(user * head);


        char * user_name;
        char * user_city;
        char * user_state;
        char * user_status;
        user * next;
    private:
        int add_user_p(char * name, char * city, char * state, char * status);
        
};

class database:public user{
    public:
        database();
        ~database();
        int add_database(user & user_obj_a);
        int display_database();
        user * find_user(char * f_name);
        user * prod_find_user(char * f_name);

    private:
        int display_database_p(user * curr);
        user * find_user(user * curr, char * u_name);
        user * prod_find_user(user * curr, char * f_name);
        user * head;

};
