/* UTPodDriver.cpp
Demo Driver for the UTPod.
Professor: Vivek Telang
Roger Priebe
EE 312 10/16/18
UT EID: fmi89
This is a basic driver for the UTPod.
You will want to do more complete testing.
Name: Fahim Imtiaz
*/

#include <cstdlib>
#include <iostream>
#include "Song.h"
#include "UTPod.h"

using namespace std;

int main(int argc, char *argv[])
{
    int size = 512;


    UTPod t(size);

    // This is the code that adds songs
    cout << "\nTesting addSong function..." << endl;
    Song s1("Here comes the sun", "Beatles", 4);
    int result = t.addSong(s1);
    cout << "Adding song: " << s1.getTitle() << ", result = " << result << endl;

    Song s2("Blank Space", "Taylor Swift", 5);
    result = t.addSong(s2);
    cout << "Adding song: " << s2.getTitle() << ", result = " << result << endl;

    Song s3("Beatles", "Beatles", 6);
    result = t.addSong(s3);
    cout << "Adding song: " << s3.getTitle() << ", result = " << result << endl;

    Song s4("Treat You Better", "Shawn Mendes", 7);
    result = t.addSong(s4);
    cout << "Adding song: " << s4.getTitle() << ", result = " << result << endl;

    Song s5("Florist girl", "Anna LaPrade", 7);
    result = t.addSong(s5);
    cout << "Adding song: " << s5.getTitle() << ", result = " << result << endl;

    Song s6("Beat it", "Michael Jackson", 7);
    result = t.addSong(s6);
    cout << "Adding song: " << s6.getTitle() << ", result = " << result << endl;

    Song s7("Rock and Hard place", "Bailey Zimmerman", 7);
    result = t.addSong(s7);
    cout << "Adding song: " << s7.getTitle() << ", result = " << result << endl;


    Song s8("Hot girl bummer", "Blackbear", 241);
    result = t.addSong(s8);


    cout << "Adding song: " << s8.getTitle() << ", result = " << result << endl;

    cout << "\nShowing Song List..." << endl;
    t.showSongList();


    // The line below Remove songs
    cout << "\nTesting removeSong function..." << endl;
    result = t.removeSong(s8);
    cout << "Removing song: " << s8.getTitle() << ", result = " << result << endl;

    result = t.removeSong(s3);
    cout << "Removing song: " << s3.getTitle() << ", result = " << result << endl;

    cout << "\nShowing Song List..." << endl;
    t.showSongList();


    // Shuffle songs for playlist
    cout << "\nTesting shuffle function..." << endl;
    t.shuffle();
    cout << "After shuffling..." << endl;
    t.showSongList();

    // Sort songs in UTPod by Artist name
    cout << "\nTesting sortSongList function..." << endl;
    t.sortSongList();
    cout << "After sorting..." << endl;
    t.showSongList();

    // Get total memory and print it
    cout << "\nTesting getTotalMemory function..." << endl;
    int totalMemory = t.getTotalMemory();
    cout << "Total Memory = " << totalMemory << endl;

    // Remaining memory gets printed out
    cout << "\nTesting getRemainingMemory function..." << endl;
    int remainingMemory = t.getRemainingMemory();
    cout << "Remaining Memory = " << remainingMemory << endl;
}
