#include <bits/stdc++.h>
#include <fstream>
using namespace std;
void printIntroMenu()
{

    cout << "\nl -> Login" << endl;
    cout << "c -> Create New Account" << endl;
    cout << "q -> Quit\n" << endl;
}
class Bank
{
public:
    int money;
    float total = 0;


    void deposit()
    {
        float mon;
        cout << "\nAmount of Deposit " ;
        cin >> mon;
        ofstream out("balance.txt");
        out << mon;
        float money =mon;
        
    }
    
    void request()
    {   float bal,ball;
        ifstream in("balance.txt");
        in >> bal;
        cout<<"Your balance is "<<bal<<endl;
        
    }
    void withdraw()
    {
        float withd, balance;
        cout << "\nAmount Withdrawn ";
        cin>>withd;
        ofstream out("withdraw.txt");
        out<<withd;
        float bal;
        ifstream in("balance.txt");
        in >> bal;
        if (bal < withd)
        {
            cout << "Current amount in account " << bal << endl;
        }
        else
        {
            bal=bal-withd;
            ofstream outt("balance.txt");
            outt<<bal;
            // cout << "\nAvailable Balance " << bal << endl;
        }
    }
};

void printMainMenu()
{
    
    cout << "d -> Deposit Money" << endl;
    cout << "w -> Withdraw Money" << endl;
    cout << "r -> Request Balance" << endl;
    cout << "q -> Quit\n" << endl;

    char ch;
    cin >> ch;
    Bank b;
    switch (ch)
    {
    case 'd':
        b.deposit();
        break;

    case 'w':
        b.withdraw();
        break;

    case 'r':
        b.request();
        break;

    case 'q':
        cout << "Thanks for stopping by!\n " << endl;
        exit(0);
        break;

    default:
        cout << "Please enter correct choice " << endl;
        break;
    }
    printMainMenu();
}

void login()
{
    int userid, password;
    int euser, epass;
    cout << "Please enter your user id: " << endl;
    cin >> userid;
    ifstream in("userid.txt");
    cout << "Please enter your password: " << endl;
    cin >> password;
    ifstream inn("password.txt");
    in >> euser;
    inn >> epass;
    if (euser == userid && epass == password)
    {
        cout << "Access Granted" << endl;
        printMainMenu();
    }
    else
    {
        cout << "************LOGIN FAILED************" << endl;
        printIntroMenu();
    }
}
void createAccount()
{
    int userid, password;
    cout << "Please enter your user id: " << endl;
    cin >> userid;
    ofstream out("userid.txt");
    out << userid;
    cout << "Please enter your password: " << endl;
    cin >> password;
    ofstream outt("password.txt");
    outt << password;
    try
    {
        throw userid;
    }
    catch (int x)
    {
        cout << "Thank You! Your account has been created!" << endl;
        printIntroMenu();
    }
    catch (...)
    {
        cout << "Retry" << endl;
        printIntroMenu();
    }
}

void start()
{
    cout << "Please select an option from the menu below: " << endl;
    printIntroMenu();
}

int main()
{
    char ch;

    cout << "Hi! Welcome to Mr. Zamar’s ATM Machine!" << endl;
    start();

    while (1)
    {
        cin >> ch;
        switch (ch)
        {
        case 'l':
            login();
            break;
        case 'c':
            createAccount();
            break;
        case 'q':
            exit(0);
            break;
        }
    }

    return 0;
}