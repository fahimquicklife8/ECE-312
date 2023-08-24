/* This is UTPod.cpp written by Fahim Imtiaz
Professor: Dr. Vivek Telang
ECE 312 Summer 2023
TA: Saher Elsayed, Hamza Masood
Author: Fahim Imtiaz
Date: 7/19/2023
 UT EID: fmi89
*/
#include <cstdlib>
#include <iostream>
#include "UTPod.h"


using namespace std;

UTPod::UTPod() {
    memSize = MAX_MEMORY;
    songs = nullptr;
}

UTPod::UTPod(int size) {
    if (size > MAX_MEMORY || size <= 0) {
        memSize = MAX_MEMORY;
    } else {
        memSize = size;
    }
    songs = nullptr;
}

UTPod::~UTPod() {
    clearMemory();
}

int UTPod::addSong(const Song &s) {
    if (s.getTitle() == "" || s.getArtist() == "" || s.getSize() <= 0) {
        return NO_MEMORY;
    }
    if (getRemainingMemory() >= s.getSize()) {
        SongNode *newSong = new SongNode;
        newSong->s = s;
        newSong->next = songs;
        songs = newSong;
        return SUCCESS;
    } else {
        return NO_MEMORY;
    }
}

int UTPod::removeSong(const Song &s) {
    SongNode *curr = songs;
    SongNode *prev = nullptr;
    while (curr != nullptr) {
        if (curr->s == s) {
            if (prev == nullptr) {
                songs = curr->next;
            } else {
                prev->next = curr->next;
            }
            delete curr;
            return SUCCESS;
        }
        prev = curr;
        curr = curr->next;
    }
    return NOT_FOUND;
}

void UTPod::shuffle() {
    if (songs == nullptr || songs->next == nullptr) {
        return;
    }

    int numSongs = 0;
    SongNode *curr = songs;
    while (curr != nullptr) {
        numSongs++;
        curr = curr->next;
    }

    for (int i = 0; i < numSongs; i++) {
        int pos1 = rand() % numSongs;
        int pos2 = rand() % numSongs;

        SongNode *node1 = songs;
        SongNode *node2 = songs;
        for (int j = 0; j < pos1; j++) {
            node1 = node1->next;
        }
        for (int j = 0; j < pos2; j++) {
            node2 = node2->next;
        }

        Song temp = node1->s;
        node1->s = node2->s;
        node2->s = temp;
    }
}

void UTPod::showSongList() {
    if (songs == nullptr) {
        cout << "The song list is empty." << endl;
        return;
    }

    SongNode *curr = songs;
    while (curr != nullptr) {
        cout << "Title: " << curr->s.getTitle() << ", Artist: " << curr->s.getArtist() << ", Size: " << curr->s.getSize() << " MB" << endl;
        curr = curr->next;
    }
}

void UTPod::sortSongList() {
    if (songs == nullptr || songs->next == nullptr) {
        return;
    }

    SongNode *curr = songs;
    SongNode *sortedList = nullptr;

    while (curr != nullptr) {
        SongNode *nextNode = curr->next;
        SongNode *sortedCurr = sortedList;
        SongNode *sortedPrev = nullptr;

        while (sortedCurr != nullptr && curr->s > sortedCurr->s) {
            sortedPrev = sortedCurr;
            sortedCurr = sortedCurr->next;
        }

        if (sortedPrev == nullptr) {
            curr->next = sortedList;
            sortedList = curr;
        } else {
            curr->next = sortedCurr;
            sortedPrev->next = curr;
        }

        curr = nextNode;
    }

    songs = sortedList;
}

void UTPod::clearMemory() {
    SongNode *curr = songs;
    while (curr != nullptr) {
        SongNode *nextNode = curr->next;
        delete curr;
        curr = nextNode;
    }
    songs = nullptr;
}

int UTPod::getRemainingMemory() {
   int usedMemory = 0;
    SongNode *curr = songs;
    while (curr != nullptr) {
        usedMemory += curr->s.getSize();
        curr = curr->next;
    }
    return memSize - usedMemory;
}
