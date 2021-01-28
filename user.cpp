/*Jack Wanitkun CS202
 Program#1 
This is the functionalities of the user section
*/

#include"user.h"

using namespace std;

//Create user
//constructor
user::user(){
    user_name = user_city = user_state = NULL;
    user_status = 0;
};

//Deconstructor
user::~user(){
    if(user_name) delete [] user_name;
    if(user_city) delete [] user_city;
    if(user_state) delete [] user_state;
    user_status = 0;
};

//Add user information
int user::add_user(){
    char name[20];
    char city[10];
    char state[4];
    char status[7];

    cout << "Create an account\n Type in your name : ";
    cin.get(name,20); cin.ignore(100,'\n');
    cout << "Type in your city: " ;
    cin.get(city,10); cin.ignore(100,'\n');
    cout << "Type in your state: ";
    cin.get(state, 4); cin.ignore(100,'\n');
    cout << "Are you a buyer or seller: ";
    cin.get(status, 7); cin.ignore(100, '\n');
    
    cout << "Added your account: \n";
    cout << name << '\t' << city << ',' << state << '\n';
    cout << "You are: " << status << endl;
    return add_user_p(name,city,state,status);
};

//This one is to allocate all the information in the user object
int user::add_user_p(char * name, char * city, char * state, char * status){
    user_name = new char[strlen(name + 1)];
    strcpy(user_name,name);
    user_city = new char[strlen(city +1)];
    strcpy(user_city, city);
    user_state = new char[strlen(state + 1)];
    strcpy(user_state, state);
    user_status = new char[strlen(status + 1)];
    strcpy(user_status, status);
    return 1;
};


//Display user
int user::display_user(){
    if(user_name){
    cout << "Your name: " <<user_name << endl;
    }
    if(user_city && user_state){
    cout << "Your address: " << user_city << ", "<< user_state << endl;
    }
    if(user_status){
    cout << "Your status: " << user_status << endl;
    }
    cout << "==================================" << endl;
    return 1;   
};

//This for to get the next user
//Mainly for travese
user * user::get_next(user * curr){
    if(curr->next){
        return get_next(curr->next);
    }
    return curr;
};

//DATABASE SECTION
//constructor
database::database(){
   head = NULL; 
};

//deconstructor
database::~database(){
    if(head){
        user * temp = new user;
        delete head;
        head = temp;
    }
};

//add user object information into database
int database::add_database(user & user_obj_a){
    user * add = new user();
    add->user_name = user_obj_a.user_name;
    add->user_city = user_obj_a.user_city;
    add->user_state = user_obj_a.user_state;
    add->user_status = user_obj_a.user_status;        
    add -> next = NULL;

    if(!head){
        head = add;
        cout << "Added to head" << endl;
        return 2;
    };

    user * curr = get_next(head);
    curr -> next = add;
    cout << "Add User Succeess" << endl;
    return 1;
};

//Display all database, in database the stucture is LLL
int database::display_database(){
   return display_database_p(head);
};

int database::display_database_p(user * curr){
   if(!curr){
        cout << "Nothing is in the system" << endl;
        return 0;
   }
   curr->display_user();
   if(!curr->next) return 0;
   return display_database_p(curr->next);

};

//This one is for seek the user information
user * database::find_user(char * f_name){
    char * u_name = new char[strlen(f_name) + 1];
    strcpy(u_name, f_name);
    return find_user(head, u_name);
};
//This one is for traverse to find the match user, or prompt user that don't have this user in db
user *  database::find_user(user * curr, char * u_name){
    if(!curr){
        cout << "No user in database" << endl;
        return 0;
    };
    if(strcmp(u_name, curr->user_name) == 0){
        curr->display_user();
        return curr;
    };
    return find_user(curr->next, u_name);
};

//This one is to find the user information for the product
//and return as user * because I will user their location information later
user * database::prod_find_user(char * f_name){
    if(!f_name) return 0;

    return prod_find_user(head,f_name);
};

//This one will traverse in LLL ,to find the user 
user * database::prod_find_user(user * curr, char * f_name){
    if(!curr) {
        cout << "Can't find user" << endl;
        return 0;
    }
    
    if(strcmp(f_name, curr->user_name) == 0){
        return curr;
    };
    return prod_find_user(curr->next, f_name);
};

