// Login Page

#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

void login();
void registration();
void forgot();

int main()
{
    int choice;
    cout << "\t___________________________________________________\n\n";
    cout << "\t             Welcome to the Login Page          \n\n";
    cout << "\t_________________      MENU       _________________\n\n";
    cout << "                                                              \n";
    cout << "\t| 1. LOGIN                                         |" << endl;
    cout << "\t| 2. REGISTER                                      |" << endl;
    cout << "\t| 3. FORGOT PASSWORD                               |" << endl;
    cout << "\t| 4. EXIT                                          |" << endl;
    cout << "\n\t     Enter your choice: ";
    cin >> choice;
    cout << endl;

    // Choose option
    switch (choice)
    {
    case 1:
        login();
        break;
    case 2:
        registration();
        break;
    case 3:
        forgot();
        break;
    case 4:
        cout << "\t\t____________THANK YOU!_____________\n\n";
        exit(1);
        break;
    default:
        system("cls");
        cout << "\t\t Select option from the given above \n";
        main();
    }

    return 0;
}

// Login System
void login()
{
    int count;
    string userId, password, id, pass;
    system("cls");
    // Take Username and password from user
    cout << "\t Enter Username and Password " << endl;
    cout << "\t USERNAME: ";
    cin >> userId;
    cout << "\t PASSWORD: ";
    cin >> password;

    // Store username and password in records.txt file
    ifstream in("records.txt");
    while (in >> id >> pass)
    {
        // Check your entered username and password from records.txt file
        if (id == userId && pass == password)
        {
            // If it will return 1 means username and password is ture
            count = 1;
            system("cls");
        }
    }
    in.close();

    // for print login massage
    if (count == 1)
    {
        cout << "\n\t\t    Your LOGIN is successfull \n\t\t     Thanks for logging in! \n";
        main();
    }
    else
    {
        cout << "\n LOGIN ERROR \n Please check your username and password\n";
    }
}

// Registration function
void registration()
{
    string regUserId, regPassword, regId, regPass;
    system("cls");
    // Taking username and password
    cout << "\t Enter the username: ";
    cin >> regUserId;
    cout << "\t Enter the password: ";
    cin >> regPassword;

    // Check your entered username and password from records.txt file
    ofstream out("records.txt", ios::app);
    out << regUserId << ' ' << regPassword << endl;
    system("cls");

    // Print after registration massage
    cout << "\n\t\t   Registration is successfull! \n";
    main();
}

// Forgot function
void forgot()
{
    int option;
    system("cls");
    cout << "\t\t\t You forgot the password? No worries \n";
    // Select the option for fogot
    cout << "\n1. Search your id by Username" << endl;
    cout << "2. Go back to the Main menu" << endl;
    cout << "\n\t Enter your choice: ";
    cin >> option;

    switch (option)
    {
    case 1:
    {
        int count;
        string searchUserId, SearchId, SearchPass;
        // Taking username from user for forget
        cout << "\t Enter the username: ";
        cin >> searchUserId;

        // Check username in records.txt
        ifstream in2("records.txt");
        while (in2 >> SearchId >> SearchPass)
        {
            // If username found it will return 1 otherwise 0
            if (searchUserId == SearchId)
            {
                count == 1;
            }
        }
        in2.close();
        if (count == 0)
        {
            cout << "\n\t Your account is not found! \n";
            main();
        }
        else
        {
            cout << "\n\t\t    Your account is found!";
            cout << "\n\t\t    Your password is: " << SearchPass << endl;
            main();
        }
        break;
    }

    case 2:
    {
        main();
    }

    default:
    {
        cout << "\t\t You are enterd invalid key! Please try again";
        forgot();
    }
    }
}
