#include "bank.h"

int PersonalAccount::nextAccountNo = 10000;
int PersonalAccount::activeAccountCount = 0;

TimeStamp::TimeStamp() {
    // TODO 1
    // Complete this constructor.
    // Goal:
    // - Get current system time
    // - Store year, month, day, hour, minute, second
    // write your code here
    time_t t = time(nullptr);
    tm* lt = localtime(&t);
    year = lt->tm_year + 1900;
    month = lt->tm_mon + 1;
    day = lt->tm_mday;
    hour = lt->tm_hour;
    minute = lt->tm_min;
    second = lt->tm_sec;
}

string TimeStamp::toString() const {
    stringstream ss;
    ss << setfill('0')
       << year << "-"
       << setw(2) << month << "-"
       << setw(2) << day << " "
       << setw(2) << hour << ":"
       << setw(2) << minute << ":"
       << setw(2) << second;
    return ss.str();
}

Transaction::Transaction(string t, double a, double b, string n) {
    type = t;
    amount = a;
    balanceAfter = b;
    note = n;
}

void Transaction::print() const {
    cout << left << setw(12) << type
         << right << setw(12) << fixed << setprecision(2) << amount
         << setw(14) << balanceAfter << "   "
         << left << setw(22) << time.toString()
         << note << "\n";
}

PersonalAccount::PersonalAccount(string owner, string group, double initialDeposit) {
    // TODO 2
    // Complete this constructor.
    // Goal:
    // - Generate account number using static nextAccountNo
    // - Save owner name and favorite group
    // - Set active = true
    // - Set initial balance
    // - Increase activeAccountCount
    // - Add one OPEN transaction into history
    // write your code here
    accountNo = ++nextAccountNo;
    ownerName = owner;
    favoriteGroup = group;
    active = true;
    balance = initialDeposit;
    ++activeAccountCount;
    history.emplace_back(Transaction("OPEN", initialDeposit, balance, "Account opened"));
}

void PersonalAccount::deposit(double amount) {
    // TODO 3
    // Complete this function.
    // Goal:
    // - Check whether account is active
    // - Check whether amount > 0
    // - Add amount to balance
    // - Record a DEPOSIT transaction
    // write your code here
    if(!active) { cout << "This account is closed.\n"; return; }
    if(amount <= 0) return;
    balance += amount;
    cout << "Deposit successful.\n";
    history.emplace_back(Transaction("DEPOSIT", amount, balance, "Deposit"));
}

bool PersonalAccount::withdraw(double amount) {
    // TODO 4
    // Complete this function.
    // Goal:
    // - Check whether account is active
    // - Check whether amount > 0
    // - Check whether balance is enough
    // - Subtract amount from balance
    // - Record a WITHDRAW transaction
    // - Return true if success, false if failed
    // write your code here
    if(!active) { cout << "This account is closed.\n"; return false; }
    if(amount <= 0) return false;
    if(balance < amount) { cout << "Insufficient balance.\n"; return false; }
    balance -= amount;
    cout << "Withdraw successful.\n";
    history.emplace_back(Transaction("WITHDRAW", amount, balance, "Withdraw"));
    return true;
}

void PersonalAccount::closeAccount() {
    // write your code here
    // TODO 5
    // Complete this function.
    // Goal:
    // - Check whether account is already closed
    // - Set active = false
    // - Decrease activeAccountCount
    // - Record a CLOSE transaction
    if(!active) { cout << "This account is closed.\n"; return; }
    active = false;
    --activeAccountCount;
    history.push_back(Transaction("CLOSE", 0.0, balance, "Account closed"));
    cout << "Account closed successfully.\n";
}

void PersonalAccount::printBasicInfo() const {
    cout << "Account No : " << accountNo << "\n";
    cout << "Owner      : " << ownerName << "\n";
    cout << "Favorite   : " << favoriteGroup << "\n";
    cout << "Balance    : " << fixed << setprecision(2) << balance << "\n";
    cout << "Status     : " << (active ? "Active" : "Closed") << "\n";
    cout << "------------------------------------------\n";
}

void PersonalAccount::printStatement() const {
    cout << "\n========== Statement ==========\n";
    cout << "Account No : " << accountNo << "\n";
    cout << "Owner      : " << ownerName << "\n";
    cout << "Favorite   : " << favoriteGroup << "\n";
    cout << "Status     : " << (active ? "Active" : "Closed") << "\n";
    cout << "Current Balance: " << fixed << setprecision(2) << balance << "\n\n";

    cout << left << setw(12) << "Type"
         << right << setw(12) << "Amount"
         << setw(14) << "Balance"
         << "   " << left << setw(22) << "Time"
         << "Note\n";

    cout << string(75, '-') << "\n";

    for (size_t i = 0; i < history.size(); i++)
        history[i].print();

    cout << string(75, '-') << "\n";
}

int PersonalAccount::getAccountNo() const {
    return accountNo;
}

string PersonalAccount::getOwnerName() const {
    return ownerName;
}

string PersonalAccount::getFavoriteGroup() const {
    return favoriteGroup;
}

double PersonalAccount::getBalance() const {
    return balance;
}

bool PersonalAccount::isActive() const {
    return active;
}

bool PersonalAccount::isLowBalance(double limit) const {
    return active && balance < limit;
}

int PersonalAccount::getActiveAccountCount() {
    return activeAccountCount;
}

BankAccountSummary::BankAccountSummary() {
    totalAccounts = 0;
    activeAccounts = 0;
    lowBalanceAccounts = 0;
    totalBalance = 0.0;
}

void BankAccountSummary::buildSummary(const vector<PersonalAccount>& accounts, double lowBalanceLimit) {
    // TODO 6
    // Complete this function.
    // Goal:
    // - Calculate totalAccounts
    // - Calculate activeAccounts
    // - Calculate lowBalanceAccounts
    // - Calculate totalBalance
    // write your code here
    totalAccounts = (int)accounts.size();
    activeAccounts = 0;
    lowBalanceAccounts = 0;
    totalBalance = 0.0;

    for(int i=0; i<totalAccounts; ++i)
    {
        if(accounts[i].isActive())
        {
            ++activeAccounts;
            totalBalance += accounts[i].getBalance();
            if(accounts[i].isLowBalance(lowBalanceLimit)) ++lowBalanceAccounts;
        }
    }

}

void BankAccountSummary::printSummary() const {
    cout << "\n========== Bank Summary ==========\n";
    cout << "Total Accounts       : " << totalAccounts << "\n";
    cout << "Active Accounts      : " << activeAccounts << "\n";
    cout << "Low Balance Accounts : " << lowBalanceAccounts << "\n";
    cout << "Total Balance        : " << fixed << setprecision(2) << totalBalance << "\n";
}

KpopBank::KpopBank(string name) {
    bankName = name;
}

PersonalAccount* KpopBank::findAccount(int accountNo) {    
    // TODO 7
    // Complete this function.
    // Goal:
    // - Search for the account by account number
    // - Return pointer to that account if found
    // - Return nullptr if not found
    // write your code here
    for(auto &i:accounts)
    {
        if(i.getAccountNo() == accountNo) return &i;
    }
    return nullptr;
}

void KpopBank::openNewAccount() {
    string ownerName;
    string favoriteGroup;
    double initialDeposit;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter owner name: ";
    getline(cin, ownerName);

    cout << "Enter favorite K-pop group: ";
    getline(cin, favoriteGroup);

    cout << "Enter initial deposit: ";
    cin >> initialDeposit;

    PersonalAccount newAccount(ownerName, favoriteGroup, initialDeposit);
    accounts.push_back(newAccount);

    cout << "\nNew account opened successfully!\n";
    cout << "New Account Number: " << accounts.back().getAccountNo() << "\n";
}

void KpopBank::closeAccount() {
    int accountNo;
    cout << "Enter account number to close: ";
    cin >> accountNo;

    PersonalAccount* acc = findAccount(accountNo);

    if (acc == nullptr) {
        cout << "Account not found.\n";
        return;
    }

    acc->closeAccount();
}

void KpopBank::viewAllAccounts() const {
    if (accounts.empty()) {
        cout << "No accounts in bank.\n";
        return;
    }

    for (size_t i = 0; i < accounts.size(); i++)
        accounts[i].printBasicInfo();
}

void KpopBank::viewLowBalanceAccounts(double limit) const {
    // TODO 8
    // Complete this function.
    // Goal:
    // - Print all active accounts with balance lower than limit
    // write your code here
    for(auto i:accounts)
    {
        if(i.isLowBalance(limit)) i.printBasicInfo();
    }
}

void KpopBank::viewBankSummary() {
    // TODO 9
    // Complete this function.
    // Goal:
    // - Call buildSummary()
    // - Call printSummary()
    // write your code here
    summary.buildSummary(accounts, 5000);
    summary.printSummary();
}

void KpopBank::generalUserMenu() {
    int accountNo;
    cout << "\nEnter your account number: ";
    cin >> accountNo;

    PersonalAccount* acc = findAccount(accountNo);

    if (acc == nullptr) {
        cout << "Account not found.\n";
        return;
    }

    int choice;

    do {

        cout << "\n1. Deposit\n2. Withdraw\n3. Check Balance\n4. Print Statement\n0. Back\n";
        cout << "Choose: ";
        cin >> choice;

        switch (choice) {

        case 1: {
            double amount;
            cout << "Enter deposit amount: ";
            cin >> amount;
            acc->deposit(amount);
            break;
        }

        case 2: {
            double amount;
            cout << "Enter withdraw amount: ";
            cin >> amount;
            acc->withdraw(amount);
            break;
        }

        case 3:
            cout << "Current balance: "<< fixed << setprecision(2)<< acc->getBalance() << "\n";
            break;

        case 4:
            acc->printStatement();
            break;

        }

    } while (choice != 0);
}

void KpopBank::bankStaffMenu() {
    int choice;

    do {

        cout << "\n1. Open New Account\n2. Close Account\n3. View All Accounts\n4. View Low Balance\n5. Bank Summary\n0. Back\n";
        cout << "Choose: ";
        cin >> choice;

        switch (choice) {

        case 1: openNewAccount(); break;
        case 2: closeAccount(); break;
        case 3: viewAllAccounts(); break;
        case 4: viewLowBalanceAccounts(5000.0); break;
        case 5: viewBankSummary(); break;

        }

    } while (choice != 0);
}

void KpopBank::mainMenu() {
    int choice;
    do {
        cout << "\n==================================\n";
        cout << " Welcome to " << bankName << "\n";
        cout << "==================================\n";
        cout << "1. General User\n";
        cout << "2. Bank Staff\n";
        cout << "0. Exit\n";
        cout << "Choose: ";
        cin >> choice;

        switch (choice) {
        case 1:
            generalUserMenu();
            break;
        case 2:
            bankStaffMenu();
            break;
        case 0:
            cout << "Thank you for using K-POP Bank!\n";
            break;
        default:
            cout << "Invalid choice.\n";
        }
    } while (choice != 0);
}