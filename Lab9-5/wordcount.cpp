#include <iostream>
using namespace std;

typedef struct Word_ {
    string word;
    int count;    
} Word;

int main() {
    string input;
    int i, last_word = 0, find = 0;
    Word data[20];

    while (true) {
        cin >> input;
        if (input == "exit") {
            break;
        }
        else {
            for(i = 0; i < last_word; i++) {
                if (input == data[i].word) {
                    data[i].count++;
                    break;
                }
            }
            cout << "i : "<< i << "\nword index " << last_word << endl;
            if (i == last_word) {
                data[last_word].word = input;
                data[last_word].count = 1;
                last_word++;
            }
        }
        
    }

    cout << "Output:" << endl;
    
    for(i = 0; i < last_word; i++) {
        cout << data[i].word << " = " << data[i].count << endl;
    }
    
    return 0;
}