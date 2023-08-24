/* This is Song.cpp written by Fahim Imtiaz
Professor: Dr. Vivek Telang
ECE 312 Summer 2023
TA: Saher Elsayed, Hamza Masood
Author: Fahim Imtiaz
Date: 7/19/2023
 UT EID: fmi89
*/
#include "Song.h"
#include <iostream>
#include <cstdlib>


Song::Song(std::string _title, std::string _artist, int _size) {
    title = _title;
    artist = _artist;
    if (_size > 0) {
        size = _size;
    } else {
        size = 0;
    }
}

Song::Song() {
    title = "  ";
    artist = " ";
    size = 0;
}

std::string Song::getTitle() const {
    return title;
}

std::string Song::getArtist() const {
    return artist;
}

int Song::getSize() const {
    return size;
}


bool Song::operator==(const Song &rhs) const {
    return (title == rhs.title) && (artist == rhs.artist) && (size == rhs.size);
}

bool Song::operator<(const Song &rhs) const {
    if (artist != rhs.artist) {
        return artist < rhs.artist;
    } else if (title != rhs.title) {
        return title < rhs.title;
    } else {
        return size < rhs.size;
    }
}

bool Song::operator>(const Song &rhs) const {
    if (artist != rhs.artist) {
        return artist > rhs.artist;
    } else if (title != rhs.title) {
        return title > rhs.title;
    } else {
        return size > rhs.size;
    }
}
