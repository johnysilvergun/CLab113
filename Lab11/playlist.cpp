#include <iostream>
#include <string>
using namespace std;
class MusicPlaylist {
    private:
    string songs[20];
    int trackNumber;
    public:
    void add(string song) {
        int i;
        for(i = 0 ; songs[i] != "";i++);
        this->songs[i] = song;
    }

    int setCurrentTrack(int trackNumber) {
        this->trackNumber = trackNumber;
        return trackNumber - 1;
    }

    string play() {
        return songs[setCurrentTrack(trackNumber)];
    }

};



int main()
{
    MusicPlaylist mp;
    mp.add("Shape of You");
    mp.add("That's What I Like");
    mp.add("Humble");
    mp.setCurrentTrack(1);
    cout << mp.play() << endl; // แสดงเพลงลำดับที่ 1 คือ Shape of You
}