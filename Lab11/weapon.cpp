//  Implementation ของ Class Material

// Material ประกอบด้วย attributes ดังนี้:

//     name คือ ชื่อของวัสดุ
//     quality คือ คุณภาพของวัสดุ มีค่าตั้งแต่ 1 ถึง 5 (ถ้ากำหนดค่าคุณภาพต่ำกว่า 1 ให้ปรับเป็น 1, ถ้ากำหนดค่าคุณภาพสูงกว่า 5 ให้ปรับเป็น 5)
//     compatibleTypes คือ array ของประเภทอาวุธที่สามารถใช้วัสดุนี้ได้

// Material มี methods ต่อไปนี้:

//     Constructor รับค่า name และ quality
//     getter ของ attributes name และ quality
//     addCompatibleType(string) เพิ่มประเภทอาวุธที่สามารถใช้วัสดุนี้ได้
//     isCompatibleWith(string) ตรวจสอบว่าวัสดุนี้ใช้กับอาวุธประเภทที่ระบุได้หรือไม่
//     getUpgradeValue() คำนวณค่า damage ที่จะเพิ่มขึ้นเมื่อใช้วัสดุนี้ ซึ่งมีค่าเป็น 5 เท่าของค่า quality




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
