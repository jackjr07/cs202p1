/*Jack Wanitkun CS202
 Program#1 
This is the functionalities of the user section
*/

#include"user.h"

using namespace std;

user::user(){
    user_name = user_city = user_state = NULL;
    user_status = 0;
};

user::~user(){
    if(user_name) delete [] user_name;
    if(user_city) delete [] user_city;
    if(user_state) delete [] user_state;
    user_status = 0;
};
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
    return 1;   
};

user * user::get_next(user * curr){
    if(curr->next){
        return get_next(curr->next);
    }
    return curr;
};

//DATABASE SECTION
database::database(){
   head = NULL; 
};

database::~database(){
    if(head){
        user * temp = new user;
        delete head;
        head = temp;
    }
};

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

user * database::find_user(char * f_name){
    char * u_name = new char[strlen(f_name) + 1];
    strcpy(u_name, f_name);
    return find_user(head, u_name);
};

user * database::prod_find_user(char * f_name){
    if(f_name){
        cout << "passed to prod" <<f_name << endl;
    }
    return prod_find_user(head,f_name);
};

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

