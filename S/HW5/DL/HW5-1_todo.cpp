#include <iostream>
#include <string>

using namespace std;

class CloudInstance;
class CloudStorage;


// TODO 1: 完成 UserAccount (使用者帳戶) 類別
class UserAccount {
private:
    string username;
    int balance;

public:
    UserAccount(string name, int b) : username(name), balance(b) {}

    // 請在此宣告兩個計費函式為 friend
    
    
};

// TODO 2: 完成 CloudInstance (雲端主機) 類別
class CloudInstance {
private:
    string instanceName;
    int hourlyRate;
    int usageHours;

public:
    CloudInstance(string name, int rate, int hours) : instanceName(name), hourlyRate(rate), usageHours(hours) {}

    // 請在此宣告主機計費函式 billInstance 為 friend
    
};

// TODO 3: 完成 CloudStorage (雲端儲存空間) 類別
class CloudStorage {
private:
    string storageName;
    int pricePerGB;
    int usedGB;

public:
    CloudStorage(string name, int price, int gb) : storageName(name), pricePerGB(price), usedGB(gb) {}

    // 請在此宣告儲存計費函式 billStorage 為 friend
    
};

// TODO 4: 實作 friend 函式：結算主機費用
void billInstance(UserAccount& user, CloudInstance& instance) {
    
}

// TODO 5: 實作 friend 函式：結算儲存空間費用
void billStorage(UserAccount& user, CloudStorage& storage) {
    
}

//不需要修改以下的 main 函式
int main() {
    string userName, instanceName, storageName;
    int balance, rate, hours, price, gb;
    
    cin >> userName >> balance;
    cin >> instanceName >> rate >> hours;
    cin >> storageName >> price >> gb;

    // 建立物件
    UserAccount myAccount(userName, balance);
    CloudInstance myInstance(instanceName, rate, hours);
    CloudStorage myStorage(storageName, price, gb);

    // 執行結算函式
    billInstance(myAccount, myInstance);
    billStorage(myAccount, myStorage);

    return 0;
}