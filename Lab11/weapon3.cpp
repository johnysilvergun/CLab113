// Implementation ของ Class Sword ที่สืบทอดจาก Weapon

// Sword เป็นอาวุธประเภทดาบที่มีความสามารถพิเศษในการโจมตีแบบ Critical Hit นอกเหนือจากความสามารถพื้นฐานที่สืบทอดมาจาก Weapon

// Sword มี attribute เพิ่มเติมดังนี้:

//     criticalMultiplier คือ ตัวคูณความเสียหายเมื่อเกิด Critical Hit มีค่าไม่ต่ำกว่า 1.0

// Sword มี methods ต่อไปนี้:

//     Constructor รับค่า durability, damage และ criticalMultiplier ตามลำดับ

//             ส่งค่า durability และ damage ไปให้ Constructor ของ Weapon โดยกำหนด weaponType เป็น "Sword"
//             ถ้า criticalMultiplier < 1.0 ให้กำหนดเป็น 1.0

//     getter ของ attribute criticalMultiplier
//     setCriticalMultiplier(double) กำหนดค่าตัวคูณ Critical Hit

//             ถ้าค่าที่รับมาน้อยกว่า 1.0 ให้กำหนดเป็น 1.0

//     attack() override method attack() จาก Weapon

//             คำนวณ damage คูณด้วย criticalMultiplier
//             ลด durability ลง 2 หน่วยเหมือนเดิม
//             ถ้า durability เป็น 0 จะโจมตีไม่ได้ (คืนค่า 0)

//     showStatus() override method showStatus() จาก Weapon

//             แสดงข้อมูลเหมือนเดิมและเพิ่ม criticalMultiplier ต่อท้าย (แต่ละค่าคั่นด้วยช่องว่าง)


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


class Sword : public Weapon {
private:
    double criticalMultiplier;

public:
    Sword(int durability, int damage, double criticalMultiplier);
    double getCriticalMultiplier();
    void setCriticalMultiplier(double multiplier);
    int attack();
    void showStatus();
};

Sword::Sword(int durability, int damage, double criticalMultiplier) : Weapon(durability, damage, "Sword") {
    if (criticalMultiplier < 1.0) {
        this->criticalMultiplier = 1.0;
    }
    else {
        this->criticalMultiplier = criticalMultiplier;
    }
}
double Sword::getCriticalMultiplier() {
    return criticalMultiplier;
}
void Sword::setCriticalMultiplier(double multiplier) {
    if (multiplier < 1.0) {
        this->criticalMultiplier = 1.0;
    }
    else {
        this->criticalMultiplier = multiplier;
    }
}
int Sword::attack() {
    int baseDamage = Weapon::attack();
    return (int)(baseDamage * criticalMultiplier);
}
void Sword::showStatus() {
    Weapon::showStatus();
    cout << " " << criticalMultiplier << endl;
}
int main() {

}