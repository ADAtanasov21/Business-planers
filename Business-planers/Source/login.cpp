#include "../Header Files/login.h"

void login(string username, string password, string passwordVer, bool haveAccount, char loginOrSignup)
{
    string temp = " ";
    cout << "1. LOGIN" << endl << "2. SIGNUP" << endl << "Press one if you want to log in to an existing account or press two if you want to create an account" << endl;
    cin >> loginOrSignup;
    if (loginOrSignup == '1')
    {

        cout << "Enter your username: ";
        cin >> username;
        cout << endl;
        cout << "Enter your password: ";
        cin >> password;
        system("cls");
        cout << "Welcome back!" << username << " What do you want to do?";
    }
    else if (loginOrSignup == '2')
    {
        cout << "Enter your username: ";
        cin >> username;
        cout << endl;
        cout << "Enter your password: ";
        cin >> password;
        cout << endl;
        cout << "Confirm your password: ";
        cin >> passwordVer;
        cout << endl;
        if (password == passwordVer)
        {
            system("cls");
            cout << "Account created successfully! Welcome!" << endl;
        }
        else
        {
            system("cls");
            cout << "Passwords don't match! Try again!" << endl;
            sleep(5);
            system("cls");
            string passwordTries[5];
            for (int i = 0; i < 5; i++)
            {
                cout << "Confirm your password: ";
                cin >> passwordTries[i];
                system("cls");
                if (passwordTries[i] == password)
                {
                    cout << "Account created successfully! Welcome!" << endl;
                    sleep(5);
                    system("cls");
                    break;
                }
                else
                {
                    cout << "Passwords don't match! Try again!" << endl;
                    cout << "You have " << 5 - i - 1 << " more tries";
                    sleep(5);
                    system("cls");
                }
            }
        }
        ofstream loginFile("data.csv");
        if (loginFile.is_open()) {
            // Write the variables to the file in CSV format
            loginFile << "Username, Passowrd" << endl; // Column headers
            loginFile << username << "," << password <<  ", " << passwordVer << endl;

            // Close the file
            
        }
        
    }
}
        
    
       
void sendToEcxcel(string username, string passowd)
{
    
    


}
