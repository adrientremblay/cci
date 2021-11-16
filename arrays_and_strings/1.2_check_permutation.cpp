#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

/**
Check Permutation: Given two strings, write a method to decide if one is a permutation of the other

Example:

"sadeas" and "dassea"

Solutions:
- sort both and compare, see if they are equal
- hash map and check if they are equal 

**/

bool hash_map(string a, string b) {
    unordered_map<char, int> map;
    
    for (char c : a)
        if (!map.contains(c))
            map[c] = 1;
        else
            map[c]++;

    for (char c : b)
        if (!map.contains(c))
            return false;
        else
            map[c]--;

    for (pair<char, int> element : map) 
        if (element.second != 0)
            return false;
    
    return true;
}

int main() {
    string tests[][2] = { {"sadeas", "dassea"} };
    
    for (auto& test : tests) {
        cout << test[0] << " " << test[1] << endl;
        cout << hash_map("sadeas", "dassea") << endl;
    }
}