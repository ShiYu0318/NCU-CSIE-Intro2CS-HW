#include <iostream>
#include <string>

using namespace std;

class Vehicle 
{
    protected:
        string vehicleId;
        int minutes, baseFee, multiplier;

    public:
        Vehicle(string &vehicleId, int minutes, int baseFee, int multiplier) :
            vehicleId(vehicleId), minutes(minutes), baseFee(baseFee), multiplier(multiplier) {}
        
        string getId() { return vehicleId; }
        
        int calculateFee()
        {
            return minutes ? (baseFee + (minutes > 5 ? multiplier * minutes : 0)) : 0;
        }
};

class Bike : public Vehicle
{
    public:
        Bike(string &id, int mins) : Vehicle(id, mins, 10, 1) {}
};

class Scooter : public Vehicle
{
    public:
        Scooter(string &id, int mins) : Vehicle(id, mins, 25, 3) {}
};

int main()
{
    int N, mins, sum = 0;
    char type;
    string id;
    
    cin >> N;
    while(N--)
    {
        cin >> type >> id >> mins;
        int fee;
        switch(type)
        {
            case 'B': fee = bike(id, mins).calculateFee(); break;
            case 'S': fee = scooter(id, mins).calculateFee(); break;
        }   
        sum += fee;
        cout << id << " Fee: " << fee << "\n";
    }
    cout << "Total Revenue: " << sum << "\n";
}