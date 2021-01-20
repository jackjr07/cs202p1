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

        char * user_name;
        char * user_city;
        char * user_state;
        char * user_status;
    private:
        int add_user_p(char * name, char * city, char * state, char * status);
        
};
struct node{
    user user_obj;
    node * next;
};

class database:public user{
    public:
        database();
        ~database();
        int add_database(user & user_obj_a);
        int display_database();
        int find_user(char * f_name);
    private:
        int display_database_p(node * curr);
        node * head;

};
