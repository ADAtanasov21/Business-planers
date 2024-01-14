#include "../Header Files/login.h"

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

            // Обработка на user_id
            // Например, извеждане на стойността
            std::cout << "User ID: " << user_id << std::endl;
        }
        else {
            // Няма намерени резултати
            std::cout << "No" << std::endl;
        }

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
                if (i == 0) {
                    cout << "Seems that you don't have more tries. Please remember your password and come back!";
                }

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
        ofstream loginFile("data.csv");
        if (loginFile.is_open()) {
            // Write the variables to the file in CSV format
            loginFile << "Username, Password" << endl; // Column headers
            sendToExcel(username, password);
            loginFile << username << "," << password <<  ", " << passwordVer << endl;

            // Close the file
            
        }
        
    }
}

void sendToExcel(const std::string& username, const std::string& password)
{
    Excel::Book book;
    Excel::Sheet* sheet = book.sheet(1);

    sheet->cell("A1")->set(username);
    sheet->cell("B1")->set(password);

    book.save("example.xlsx");
}

