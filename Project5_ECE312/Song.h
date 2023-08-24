/* This is Song.h written by Fahim Imtiaz
Professor: Dr. Vivek Telang
ECE 312 Summer 2023
TA: Saher Elsayed, Hamza Masood
Author: Fahim Imtiaz
Date: 7/19/2023
 UT EID: fmi89
*/

#ifndef SONG_H
#define SONG_H

#include <string>

class Song {
private:
    std::string title;
    std::string artist;
    int size; // in MB

public:

    Song();
    Song(std::string _title, std::string _artist, int _size);

    bool operator==(const Song &rhs) const;
    bool operator<(const Song &rhs) const;
    bool operator>(const Song &rhs) const;

    std::string getTitle() const;
    std::string getArtist() const;
    int getSize() const;


};

#endif  // SONG_H
