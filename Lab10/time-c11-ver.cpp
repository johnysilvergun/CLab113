#include <iostream>
#include <cmath>
#include <string>
using namespace std;

class Time {
    private:
    int hours;
    int minutes;
    int seconds;
    public:
    Time(int hour,int minute, int second) {
        this->hours = hour;
        this->minutes = minute;
        this->seconds = second;
    }
    Time(int duration) {
        this->hours = duration / 3600;
        this->minutes = (duration % 3600) / 60;
        this->seconds = duration % 60;
    }
    int getHour() {
        return hours; 
    }

    int getMinute() {
        return minutes;
    }

    int getSecond() {
        return seconds;
    }

    void setHour(int h) {
        this->hours = h;
    }

    void setMinute(int m) {
        this->minutes = m;
    }

    void setSecond(int s) {
        this->seconds = s;
    }
    int getDuration() {
        return hours * 3600 + minutes * 60 + seconds;
    }
    Time add(Time other) {
        Time temp (getDuration() + other.getDuration());
        if (temp.getDuration() > 86400) {
            return temp.getDuration() - 86400;
        }
        else {
            return temp.getDuration();
        }
    }

    int subtract(Time other) {
        Time temp (getDuration() - other.getDuration());
        if (temp.getDuration() < 0) {
            return temp.getDuration() + 86400;
        }
        else {
            return temp.getDuration();
        }
    }
    int equals(Time other) {
        if (getDuration() == other.getDuration()){
            return 1;
        }
        else{
            return 0;
        }
    }
    string toString() {
        string hour;
        string minute;
        string second;
        if (hours < 10) {
            hour = "0" + to_string(hours);
        }
        else {
            hour = to_string(hours);
        }
        if (minutes < 10) {
            minute = "0" + to_string(minutes);
        }
        else {
            minute = to_string(minutes);
        }
        if (seconds < 10) {
            second = "0" + to_string(seconds);
        }
        else {
            second = to_string(seconds);
        }
        return hour + ":" + minute + ":" + second;
    }
};


int main(){
    Time t1(02, 02, 02);
    Time t2(86400);
    Time t3(0), t4(0);
    t3 = t1.add(t2);
    t4 = t2.subtract(t1);
    cout << t1.getDuration() << endl;
    cout << t2.getSecond() << endl;
    cout << t3.getDuration() << endl;
    cout << t4.getDuration() << endl;
    cout << t1.equals(t2) << endl;
    cout << t3.toString() << endl;
    cout << t4.toString() << endl;
}