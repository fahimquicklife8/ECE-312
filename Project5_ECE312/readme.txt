Welcome to the UTPod program README!

This program was developed by Fahim Imtiaz (UT EID: fmi89). It is a small, music-listing and managing program, 
simulating basic functionalities of an MP3 player. 
The program handles songs, which are each represented as a distinct object, and a UTPod, which is a list of songs.

Here are the classes and their functions:

1. UTPod Class:
    - addSong(Song s): Adds the song s to the UTPod.
    - removeSong(Song s): Removes song s from the UTPod.
    - shuffle(): Rearranges the songs in the UTPod in a random order.
    - showSongList(): Prints out the list of songs currently in the UTPod.
    - sortSongList(): Sorts the songs in the UTPod in order by artist, then by song title, and then by size.
    - getTotalMemory(): Returns the total memory size of the UTPod.
    - getRemainingMemory(): Returns the remaining memory in the UTPod after adding songs.

2. Song Class:
    - The Song class has set and get methods for all instance variables (artist, title, size).
    - The Song class also overloads the ==, < and > operators for comparison between songs.

The UTPodDriver serves as the testing driver for the UTPod program. It includes at least one call to each 
of the UTPod and Song class functions, and prints statements on what functionality is being tested before displaying the output.

How to run this program in a Linux environment:
- Open a terminal.
- Navigate to the directory containing the UTPod program files.
- To compile the program, use the g++ command followed by the names of the .cpp files. 
- For example: g++ UTPod.cpp UTPodDriver.cpp Song.cpp -o UTPodDriver
- After compiling, run the program by typing './UTPodDriver'.
- Linux Command on Kamek.ece.utexas.edu: cd [directory name] -> make -> ./UTPodDriver
 