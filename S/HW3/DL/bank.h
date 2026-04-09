#ifndef BANK_H
#define BANK_H

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <ctime>
#include <sstream>
#include <limits>

using namespace std;

class TimeStamp {
private:
    int year, month, day;
    int hour, minute, second;

public:
    TimeStamp();                  
    string toString() const;     
};

class Transaction {
private:
    string type;
    double amount;
    double balanceAfter;
    string note;
    TimeStamp time;  

public:
    Transaction(string t = "", double a = 0.0, double b = 0.0, string n = "");
    void print() const;           
};

class PersonalAccount {
private:
    int accountNo;
    string ownerName;
    string favoriteGroup;
    double balance;
    bool active;
    vector<Transaction> history;   

    static int nextAccountNo;      
    static int activeAccountCount; 

public:
    PersonalAccount(string owner = "", string group = "", double initialDeposit = 0.0);

    void deposit(double amount);
    bool withdraw(double amount);
    void closeAccount();
    void printBasicInfo() const;
    void printStatement() const;

    int getAccountNo() const;
    string getOwnerName() const;
    string getFavoriteGroup() const;
    double getBalance() const;
    bool isActive() const;
    bool isLowBalance(double limit = 5000.0) const;

    static int getActiveAccountCount();
};

class BankAccountSummary {
private:
    int totalAccounts;
    int activeAccounts;
    int lowBalanceAccounts;
    double totalBalance;

public:
    BankAccountSummary();
    void buildSummary(const vector<PersonalAccount>& accounts, double lowBalanceLimit = 5000.0);
    void printSummary() const;
};

class KpopBank {
private:
    string bankName;
    vector<PersonalAccount> accounts;
    BankAccountSummary summary;

public:
    KpopBank(string name = "K-POP Bank");

    PersonalAccount* findAccount(int accountNo);

    void openNewAccount();
    void closeAccount();
    void viewAllAccounts() const;
    void viewLowBalanceAccounts(double limit = 5000.0) const;
    void viewBankSummary();

    void generalUserMenu();
    void bankStaffMenu();
    void mainMenu();
};

#endif