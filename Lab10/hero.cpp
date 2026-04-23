#include <iostream>
#include <string>
using namespace std;

class Hero {
    private:
    string name;
    int level;
    public:
    Hero(string name, int level ) {
        this->name = name;
        this->level = level;
    }

    string getName() {
        return name;
    }
    int getLevel(){
        return level;
    }
};




int main()
{
    string name;
    int lvl;
    cin >> name >> lvl;
    Hero hero1(name, lvl);
    cout << hero1.getName() << " " << hero1.getLevel() << endl;
}