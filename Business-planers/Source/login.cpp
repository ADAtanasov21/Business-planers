#include "../Header Files/login.h"
#include "../Header Files/user_id.h"

void login(string username, string password, string passwordVer, bool haveAccount, char loginOrSignup, pqxx::connection* conn)
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
        pqxx::work worker(*conn);
        pqxx::result res = worker.exec("SELECT id FROM users WHERE username = '" + username + "' AND password = '" + password + "'");
        if (!res.empty()) {
            // Извличане на стойности от първия намерен ред
            pqxx::result::const_iterator row = res.begin();
            int user_id = row["id"].as<int>();
            id = user_id;

            std::cout << id << endl;
            std::cout << "User ID: " << user_id << std::endl;
        }
        else {

            std::cout << "No such an acount" << std::endl;
        }

    }
    else if (loginOrSignup == '2')
    {
        cout << "Enter your username: ";
        cin >> username;
        unsigned int lenUser = password.length();
        if (lenUser < 4)
            while (lenUser < 4)
            {
                cout << "Username must be at least 4 charecters long!" << endl;
                cout << "Enter your username: ";
                cin >> password;
                unsigned int lenTest = password.length();
                lenUser = lenTest;
            }
        cout << endl;
        cout << "Enter your password: ";
        cin >> password;
        unsigned int lenPass = password.length();
        if(lenPass < 8)
            while (lenPass < 8)
            {
                cout << "Password must be at least 8 charecters long!" << endl;
                cout << "Enter your password: ";
                cin >> password;
                unsigned int lenTest = password.length();
                lenPass = lenTest;
            }
        cout << endl;
        cout << "Confirm your password: ";
        cin >> passwordVer;
        cout << endl;
        if (password == passwordVer)
        {
            pqxx::work worker(*conn);
            pqxx::result res = worker.exec("INSERT INTO users(username, password) VALUES('" + username + "','" + password + "')");
            worker.commit();
            cout << "Account created successfully! Welcome!" << endl;
        }
        else
        {
            system("cls");
            cout << "Passwords don't match! Try again!" << endl;
            
            string passwordTries[5];
            for (int i = 0; i < 5; i++)
            {
                cout << "Confirm your password: ";
                cin >> passwordTries[i];
                system("cls");

                if (5 - i - 1 == 0) {
                    cout << "Your remaining tries expired. PLease come back when you remember you password!";
                    break;
                    exit(10000000000);
                }
                if (passwordTries[i] == password)
                {
                    pqxx::work worker(*conn);
                    pqxx::result res = worker.exec("INSERT INTO users(username, password) VALUES('" + username + "','" + password + "')");
                    worker.commit();
                    cout << "Account created successfully! Welcome!" << endl;
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


