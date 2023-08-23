/*Author: Fahim Imtiaz
 * EID:fmi89
 * Course: ECE 312 summer 2023
 * Vivek Telang
 * TA: Saher Elsayed, Hamza Masood
 */
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <map>
#include <algorithm>
#include <sstream>

using namespace std;

// Function declarations
string preprocess(const string& filepath);
vector<string> extractSequences(const string& text, int p);
map<pair<string, string>, int> compareSequences(const vector<vector<string>>& allSequences, const vector<string>& filenames);
void printResults(const map<pair<string, string>, int>& results, int m);

int getdir (string dir, vector<string> &files) {
    DIR *dp;
    struct dirent *dirp;
    if((dp = opendir(dir.c_str())) == NULL) {
        cout << "Error(" << errno << ") opening " << dir << endl;
        return errno;
    }

    while ((dirp = readdir(dp)) != NULL) {
        string filename = string(dirp->d_name);
        if(filename != "." && filename != "..") { // ignore . and ..
            files.push_back(filename);
        }
    }
    closedir(dp);
    return 0;
}

int main(int argc, char *argv[]) {
    if(argc != 4) {
        cout << "Usage: ./plagiarismCatcher directory p m" << endl;
        return 1;
    }

    // Extract command line arguments
    string directory = argv[1];
    int p = stoi(argv[2]);
    int m = stoi(argv[3]);

    vector<string> filenames;
    getdir(directory, filenames);

    // Preprocess and extract sequences from each essay
    vector<vector<string>> allSequences;
    for(const auto& filename : filenames) {
        string fullpath = directory + "/" + filename;
        string text = preprocess(fullpath);
        allSequences.push_back(extractSequences(text, p));
    }

    // Compare sequences between essays
    auto results = compareSequences(allSequences, filenames);

    // Print results based on the threshold m
    printResults(results, m);

    return 0;
}

string preprocess(const string& filepath) {
    ifstream file(filepath);
    if(!file.is_open()) {
        cerr << "Failed to open " << filepath << endl;
        return "";
    }

    string text, line;
    while(getline(file, line)) {
        transform(line.begin(), line.end(), line.begin(), ::tolower);
        line.erase(remove_if(line.begin(), line.end(),
                             [](char c) { return !isalnum(c) && c != ' ' && c != '\''; }), line.end());
        text += line + " ";
    }

    file.close();
    return text;
}

vector<string> extractSequences(const string& text, int p) {
    vector<string> sequences;
    vector<string> words;

    istringstream iss(text);
    string word;
    while (iss >> word) {
        words.push_back(word);
    }

    if (words.size() < p) {
        return sequences;
    }

    for (size_t i = 0; i <= words.size() - p; ++i) {
        string sequence;
        for (int j = 0; j < p; ++j) {
            sequence += words[i + j] + " ";
        }
        sequences.push_back(sequence);
    }

    return sequences;
}

map<pair<string, string>, int> compareSequences(const vector<vector<string>>& allSequences, const vector<string>& filenames) {
    map<pair<string, string>, int> results;
    for (size_t i = 0; i < allSequences.size(); ++i) {
        for (size_t j = i + 1; j < allSequences.size(); ++j) {
            int count = 0;
            for (const auto& seq1 : allSequences[i]) {
                for (const auto& seq2 : allSequences[j]) {
                    if (seq1 == seq2) {
                        count++;
                    }
                }
            }
            results[make_pair(filenames[i], filenames[j])] = count;
        }
    }

    return results;
}

void printResults(const map<pair<string, string>, int>& results, int m) {
    for (const auto& pair : results) {
        if (pair.second > m) {
            cout << pair.second << ": " << pair.first.first << ", " << pair.first.second << endl;
        }
    }
}
