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
    cout << "Your name: " <<user_name << endl;
    cout << "Your address: " << user_city << ", "<< user_state << endl;
    cout << "Your status: " << user_status << endl;
    return 1;   
};

//DATABASE SECTION
database::database(){
   head = NULL; 
};

database::~database(){
    if(head){
        node * temp = new node;
        delete head;
        head = temp;
    }
};

int database::add_database(user & user_obj_a){
    node * add = new node;
    add -> user_obj = user_obj_a;
    add -> next = NULL;

    if(!head){
        head = add;
        cout << "Added to head" <<endl;
        return 1;
    }
    node * curr =   head;
    while(curr->next){
            curr = curr->next;
    }
    curr->next = add;
    cout << "Add success" << endl;
   return 1;
}
int database::display_database(){
   return display_database_p(head);
}

int database::display_database_p(node * curr){
   if(!curr){
        cout << "Nothing is in the system" << endl;
        return 0;
   }
   while(curr){
        curr->user_obj.display_user();
        curr = curr->next;
   }
    return 1;
}

int database::find_user(char * f_name){
    char * u_name = new char[strlen(u_name) + 1];
    strcpy(u_name, f_name);
    if(!head){
        cout << "No user in database" << endl;
        return 0;
    };
    //cout << u_name << "\\" << f_name << endl;
    node * curr = head;
    while(curr){
        if(strcmp(u_name, curr->user_obj.user_name) != 0){
            cout << "passed" << endl;
            cout << "Your city: " << curr->user_obj.user_city << endl;
            cout << "Your state: " << curr->user_obj.user_state << endl;
            cout << "Your status: " << curr->user_obj.user_status << endl;
        }
        curr = curr -> next;
    };
    return 3;
}
