#include "../Header Files/login.h"

void login(string username, string password, string passwordVer, bool haveAcount, char loginOrSignup)
{
    string temp = " ";
    cout << "1. LOGIN" << endl << "2. SIGNUP" << endl << "Press one if you want to log in to an exsisting acount or press two if you want to create an acount" << endl;
    cin >> loginOrSignup;
    if (loginOrSignup == '1')
    {
        
        cout << "Enter your username: ";
        cin >> username;
        cout << "Enter your password: ";
        cin >> password;
        cout << endl << "Welcome back " << username << "! What do you want to do?";
    }
    else if (loginOrSignup == '2')
    {
        cout << "Enter your username: ";
        cin >> username;
        cout << "Enter your password: ";
        cin >> password;
        cout << "Confirm your password: ";
        cin >> passwordVer;
        if (password == passwordVer)
            cout << "Acount created succesfully! Welcome!" << endl;
        else
        {
            cout << "Passwords don't match! Try again!" << endl;
            string passwords[5];
            for (int i = 0; i < 5; i++)
            {
                cin >> passwords[i];
                if (passwords[i] == password)
                {
                    cout << "Acount created succesfully! Welcome!" << endl;
                    break;
                }
                else
                {
                    cout << "Passwords don't match! Try again!" << endl;
                    cout << "You have " << 5 - i - 1 << " more tries" << endl;
                }
            }
        }       
    }
}
        
    
       
        
        
    
    
        