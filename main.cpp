/*Jack Wanitkun CS202
 Program#1 || Distribution System
This is the user interface for program#1
*/ 

#include"user.h"

using namespace std;

int menu(int &answer);

int main (){
    user user_obj;
    database database_obj;
    int answer = 0;
    cout << "Welcome to Jack's distribution system" << endl;
    //Start the program
    do{
        menu(answer);
        if(answer == 1){
            user_obj.add_user();
            database_obj.add_database(user_obj);
        }
        else if(answer == 4){
            database_obj.display_database();
        }
    }while(answer != 9);
    cout << "Thank you !!!" << endl;
return 0;
}

int menu(int &answer){
    cout << "Choose the options" << endl;
    cout << "[1] Create your account \n";
    cout << "[2] Update your account \n";
    cout << "[3] Remove your account \n";
    cout << "[4] Display all users \n";
    cout << "[9] Exit the program\n";
    cin >> answer;
    cin.ignore(100,'\n');
    return answer;

return 0;
}

