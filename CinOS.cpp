#include <iostream>
#include <fstream>
#include <conio.h>
#include <string>
#include <vector>
using namespace std;

struct account{
        int id;
        string username;
        string password;
        bool admin;
};

class CinOS{

        private:

                bool LoginSuccess = false;
                account CurrentUser;

                void clearScreen() {
                        system("cls");
                        return;
                }
                void line0() {
                        cout << "========================================================================" << endl;
                        return;
                }

                void line1() {
                        cout << "===[CinOS]==============================================================" << endl;
                        return;
                }

                char keyPress() {
        		char key = _getch(); // Get the key pressed
                        return key;
                }

                int checkUser(string user, string password) {      // Check if provided info is correct

                        ifstream userBase("Data/user.txt");
                        ifstream adminBase("Data/admin.txt");

                        string line;
                        int count = 0;
                        while (getline(userBase, line)) {
                                if (line == user) {
                                        getline(userBase, line);
                                        if (line == password) {
                                                CurrentUser.id = (count - 1) / 3;
                                                CurrentUser.username = user;
                                                CurrentUser.password = password;
                                                CurrentUser.admin = false;
                                                return 0;
                                        }
                                }
                                count++;
                        }
                        count = 0;
                        while (getline(adminBase, line)) {
                                if (line == user) {
                                        getline(adminBase, line);
                                        if (line == password) {
                                                CurrentUser.id = (count - 1) / 3;
                                                CurrentUser.username = user;
                                                CurrentUser.password = password;
                                                CurrentUser.admin = true;
                                                return 1;
                                        }
                                }
                                count++;
                        }

                        return -1;
                        
                }

                bool logIn() {          // Login user account
                        char key;
                        vector<char> name;
                        vector<char> pass;
                        int nameCount = 0;
                        int passCount = 0;

                        clearScreen();
                        line1();
                        cout << endl << "Username: _" << endl << endl;
                        cout << "Password: " << endl << endl;
                        line0();
                        while ((key = keyPress())) {
                                if (key != 8 and key != 13 and key != 27) {
                                        nameCount++;
                                        name.push_back(key);
                                } else {
                                        if (key == 8) {
                                                if (nameCount > 0) {
                                                        nameCount--;
                                                        name.pop_back();
                                                }
                                        }
                                        if (key == 13) {
                                                break;
                                        }
                                        if (key == 27) {
                                                return false;
                                        }
                                }

                                clearScreen();
                                line1();
                                string str(name.begin(), name.end());
                                cout << endl << "Username: " << str << "_" << endl << endl;
                                cout << "Password: " << endl << endl;
                                line0();
                        }

                        clearScreen();
                        line1();
                        string str(name.begin(), name.end());
                        cout << endl << "Username: " << str << endl << endl;
                        cout << "Password: _" << endl << endl;
                        line0();

                        while ((key = keyPress())) {
                                if (key != 8 and key != 13 and key != 27) {
                                        passCount++;
                                        pass.push_back(key);
                                } else {
                                        if (key == 8) {
                                                if (passCount >0) {
                                                        passCount--;
                                                        pass.pop_back();
                                                }
                                        }
                                        if (key == 13) {
                                                break;
                                        }
                                        if (key == 27) {
                                                return false;
                                        }
                                }

                                clearScreen();
                                line1();
                                string str(name.begin(), name.end());
                                cout << endl << "Username: " << str << endl << endl;
                                cout << "Password: ";
                                string temp = "";
                                for (int i = 0; i < passCount; i++) {
                                        temp += "*";
                                }
                                temp += "_";
                                cout << temp << endl << endl;
                                line0();
                        }

                        string n(name.begin(), name.end());
                        string p(pass.begin(), pass.end());

                        if (checkUser(n, p) == 0 or checkUser(n, p) == 1) {
                                LoginSuccess = true;
                                return true;
                        }

                        return false;
                        
                }

                void createAccount(string u, string p, int type) {
                        
                }

                bool signUp() {
                        char key;
                        vector<char> name;
                        vector<char> pass;
                        vector<char> conPass;
                        int nameCount = 0;
                        int passCount = 0;
                        int conPassCount = 0;

                        clearScreen();
                        line1();
                        cout << endl << "Username: _" << endl << endl;
                        cout << "Password: " << endl << endl;
                        cout << "Confirm Password: " << endl << endl;
                        line0();

                        vector<char>* currentVector = &name;
                        int* currentCount = &nameCount;

                        string username;
                        string password;
                        string confirmPassword;

                        while ((key = keyPress())) {
                                if (key != 8 && key != 13 && key != 27) {
                                        (*currentCount)++;
                                        currentVector->push_back(key);
                                } else {
                                        if (key == 8) {
                                                if (*currentCount > 0) {
                                                        (*currentCount)--;
                                                        currentVector->pop_back();
                                                }
                                        }
                                        if (key == 13) {
                                                if (currentVector == &name) {
                                                        currentVector = &pass;
                                                        currentCount = &passCount;

                                                        clearScreen();
                                                        line1();
                                                        username = string(name.begin(), name.end());
                                                        cout << endl << "Username: " << username << endl << endl;
                                                        cout << "Password: _" << endl << endl;
                                                        cout << "Confirm Password: " << endl << endl;
                                                        line0();
                                                } else if (currentVector == &pass) {
                                                        currentVector = &conPass;
                                                        currentCount = &conPassCount;

                                                        clearScreen();
                                                        line1();
                                                        username = string(name.begin(), name.end());
                                                        password = string(pass.begin(), pass.end());
                                                        cout << endl << "Username: " << username << endl << endl;
                                                        cout << "Password: " << string(passCount, '*') << endl << endl;
                                                        cout << "Confirm Password: _" << endl << endl;
                                                        line0();
                                                } else {
                                                        break;
                                                }
                                        }
                                        if (key == 27) {
                                                return false;
                                        }
                                }

                                clearScreen();
                                line1();
                                username = string(name.begin(), name.end());

                                if (currentVector == &name) {
                                        cout << endl << "Username: " << username << "_";
                                } else if (currentVector == &pass) {
                                        cout << endl << "Username: " << username << endl << endl;
                                        cout << "Password: " << string(passCount, '*') << "_";
                                } else {
                                        cout << endl << "Username: " << username << endl << endl;
                                        cout << "Password: " << string(passCount, '*') << endl << endl;
                                        cout << "Confirm Password: " << string(conPassCount, '*') << "_";
                                }

                                cout << endl << endl;
                                line0();
                        }

                        username = string(name.begin(), name.end());
                        password = string(pass.begin(), pass.end());
                        confirmPassword = string(conPass.begin(), conPass.end());

                        if (password == confirmPassword && checkUser(username, password) == -1) {
                                createAccount(username, password, 0);
                                return true;
                        }

                        return false;
                        
                }

                int choose(int count, string question, vector<string> options) {        // Create selection menu

                        int choice = 0;
                        char key;       // Input char
                        string l;       // Output string

                        clearScreen();
                        line1();
                        cout << endl << " " << question << endl << endl;

                        for (int i = 0; i < count; i++) {
                                l = "";

                                if (choice == i) l += " > ";
                                else l += "   ";
                                                
                                l += options[i];

                                if (choice == i) l += " < ";
                                else l += "   ";

                                cout << l << endl;
                        }

                        cout << endl << "(Use arrow keys to navigate, Enter to confirm, Esc to quit.)" << endl;
                        line0();

                        while (true) {
                                
                                if (_kbhit()) {

                                        key = _getch();

                                        if (key == 72) {                // Up Arrow is pressed
                                                if (choice > 0) choice--;
                                        } else if (key == 80) {         // Down Arrow is pressed
                                                if (choice < (count - 1)) choice++;
                                        } else if (key == 13) {         // Enter is pressed
                                                break;
                                        } else if (key == 27) {         // Escape is pressed
                                                choice = -1;
                                                break;
                                        }

                                        clearScreen();
                                        line1();
                                        cout << endl << " " << question << endl << endl;

                                        for (int i = 0; i < count; i++) {
                                                l = "";

                                                if (choice == i) l += " > ";
                                                else l += "   ";
                                                                
                                                l += options[i];

                                                if (choice == i) l += " < ";
                                                else l += "   ";

                                                cout << l << endl;
                                        }

                                        cout << endl << "(Use arrow keys to navigate, Enter to confirm, Esc to quit.)" << endl;
                                        line0();

                                }
                                
                        }

                        return choice;

                }

        public:

                void UserInterface() {

                        while(not(LoginSuccess)) {

                                int action;
                                action = choose(2, "Login or Register?", {"Login","Register"});

                                if (action == 0) {
                                        logIn();
                                } else if (action == 1) {
                                        signUp();
                                } else if (action == -1) return;

                        }


                        cout << endl << CurrentUser.id << endl;
                        cout << CurrentUser.username << endl;
                        cout << CurrentUser.password << endl;
                        cout << CurrentUser.admin << endl;
                        return;

                }

};

int main() {

        CinOS CinOS;

        CinOS.UserInterface();

        return 0;

}
