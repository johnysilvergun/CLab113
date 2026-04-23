
// Implementation ของ Class Weapon

// Weapon ประกอบด้วย attributes ดังนี้:

//     durability คือ ความทนทาน มีค่าตั้งแต่ 0 ถึง 100
//     damage คือ ค่าความเสียหาย มีค่าไม่ต่ำกว่า 0
//     weaponType คือ ประเภทของอาวุธ (เช่น "Sword", "Bow", "Axe")

// Weapon มี methods ต่อไปนี้:

//     Constructor รับค่า durability, damage และ weaponType ตามลำดับ

//             ถ้า durability < 0 ให้กำหนดเป็น 0
//             ถ้า durability > 100 ให้กำหนดเป็น 100
//             ถ้า damage < 0 ให้กำหนดเป็น 0

//     getter ของ attributes ทั้งสาม
//     attack() คืนค่าความเสียหายที่อาวุธสามารถทำได้

//             ถ้า durability เป็น 0 จะโจมตีไม่ได้ (คืนค่า 0)
//             ถ้าโจมตีได้ จะลด durability ลง 2 หน่วย

//     upgrade(Material) อัพเกรดอาวุธด้วย Material

//             ถ้า Material สามารถใช้กับ weaponType ได้ จะเพิ่ม damage ตามค่า getUpgradeValue() ของ Material
//             ถ้าใช้ไม่ได้ จะคืนค่า false
//             ถ้าใช้ได้ จะคืนค่า true

//     repair() ซ่อมแซมอาวุธให้ durability กลับไปเป็น 100
//     showStatus() แสดงสถานะปัจจุบันของอาวุธทั้ง durability, damage และ weaponType ตามลำดับ คั่นแต่ละค่าด้วยช่องว่าง



#include <iostream>
#include <vector>
using namespace std;
class Material {
private:
    string name;
    int quality;
    vector<string> compatibleTypes;

public:
    Material(string name, int quality);
    string getName();
    int getQuality();
    void addCompatibleType(string type);
    bool isCompatibleWith(string weaponType);
    int getUpgradeValue();
};
Material::Material(string name,int quality) {
    this->name = name;
    if (quality < 1) {
        this->quality = 1;
    }
    else if (quality > 5) {
        this->quality = 5;
    }
    else {
        this->quality = quality;
    }
}
string Material::getName() {
    return name;
}

int Material::getQuality() {
    return quality;
}
void Material::addCompatibleType(string type) {
    compatibleTypes.push_back(type);
}
bool Material::isCompatibleWith(string weaponType) {
    for (string type : compatibleTypes) {
        if (type == weaponType) {
            return true;
        }
    }
    return false;
}
int Material::getUpgradeValue() {
    return quality * 5;
}


class Weapon {
private:
    int durability;
    int damage;
    string weaponType;

public:
    Weapon(int durability, int damage, string weaponType);
    int getDurability();
    int getDamage();
    string getWeaponType();
    int attack();
    bool upgrade(Material material);
    void repair();
    void showStatus();
};
//constructor
Weapon::Weapon (int durability, int damage, string weaponType) {
    if (durability < 0) {
        this->durability = 0;
    }
    else if (durability > 100) {
        this->durability = 100;
    }
    else {
        this->durability = durability;
    }
    if (damage < 0) {
        this->damage = 0;
    }
    else {
        this->damage = damage;
    }
    this->weaponType = weaponType;
}
//getter
int Weapon::getDurability() {
    return durability;
}
int Weapon::getDamage() {
    return damage;
}

string Weapon::getWeaponType() {
    return weaponType;
}
//misc
int Weapon::attack() {
    if (durability == 0) {
        return 0;
    }
    else {
        durability -= 2;
        if (durability < 0) {
            durability = 0;
        }
        return damage;
    }
}
bool Weapon::upgrade(Material material) {
    if (material.isCompatibleWith(weaponType)) {
        damage += material.getUpgradeValue();
        return true;
    }
    else {
        return false;
    }
}
void Weapon::repair() {
    durability = 100;
}
void Weapon::showStatus() {
    cout << durability << " " << damage << " " << weaponType << endl;
}

int main() {
    string name;
    int lvl;
    string type;
    cout << "enter materiel name : ";
    cin >> name;
    cout << "enter materiel quality : ";
    cin >> lvl;
    cout << "enter materiel type : ";
    cin >> type;
    Material materiel(name,lvl);
    materiel.addCompatibleType(type);
    cout << "this material name is :" << materiel.getName() << endl;
    cout << "this material quality is :" << materiel.getQuality() << endl; 
    cout << "is this material compatiable with :" << type << endl;
    cout << materiel.isCompatibleWith(type) << endl;   

}
