#include <iostream>
#include <unordered_map>

using namespace std;

const int q = 101; // Prime number used to calculate hash value
const int d = 256; // Integer value to prevent overflow

int rabinKarp(string s, string pattern) {
    int n = s.size();
    int m = pattern.size();
    int h = 1; // Initialize rolling hash calculation

    for (int i = 0; i < m - 1; i++) {
        h = (h * d) % q;
    }

    int pHash = 0; // Hash for pattern
    int sHash = 0; // Hash for string s

    for (int i = 0; i < m; i++) {
        pHash = (d * pHash + pattern[i]) % q; // Calculate hash for pattern
        sHash = (d * sHash + s[i]) % q; // Calculate hash for substring s
    }

    unordered_map<int, int> hashMap; // Map to store substring initial value
    hashMap[sHash] = 0; // Store the initial substring hash value in the map

    // Loop through text to find pattern
    for (int i = 0; i <= n - m; i++) { // Changed '<' to '<=' to check the last substring
        if (pHash == sHash) { // Compare hashes
            if (pattern == s.substr(i, m)) { // If they match, check the substring and pattern values
                return i;
            }
        }
        // Update the hash value of subsequent substrings using rolling hash technique
        if (i < n - m) {
            // Update sHash for the next substring
            sHash = (d * (sHash - s[i] * h) + s[i + m]) % q;

            if (sHash < 0) { // Check if hash val is not negative
                sHash += q;
            }
        }
    }
    return -1; // If not found
}

int main() {
    string s;
    string pattern;

    cin >> s;
    cin >> pattern;

    int index = rabinKarp(s, pattern);

    cout << index;
}
