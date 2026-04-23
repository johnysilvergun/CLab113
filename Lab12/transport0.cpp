#include <iostream>
using namespace std;

class Transportation
{
    public:
    virtual double fare() = 0;
};

class Taxi : public Transportation
{
    private:
    double price = 35;
    public:
    Taxi(){
    }
    void setDistance(double km){
        price += km*2;
    }
    double fare(){
        return price;
    }
};

int main()
{
    int tc;
    cin >> tc;
    if (tc == 1) {
        double distance;
        cin >> distance;
        Taxi taxi;
        taxi.setDistance(distance);
        cout << "Taxi fare: "
             << taxi.fare() << endl;
    } else if(tc == 2) {
        double distance;
        cin >> distance;
        Taxi taxi;
        taxi.setDistance(distance);
        Transportation *transport = &taxi;
        cout << "Transporataion fare: "
             << transport->fare() << endl;
    }
}