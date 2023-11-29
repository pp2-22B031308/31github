#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> prefix_function(string s) {
    int n = s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];  // Previous prefix function value
        while (j > 0 && s[i] != s[j - 1]) { // while there is a mismatch and j is not 0
            j = pi[j - 1]; // Update j to the previous prefix value
        }
        if (s[i] == s[j]) {
            j++; // increment if characters match
            pi[i] = j; // store prefix values
        }
    }
    return pi; // return vector
}

vector<int> kmp(string s, string pattern) {
    vector<int> solve; // to store where the pattern is found
    string concat = pattern + '%' + s; // concatenate pattern unique % and string
    vector<int> pi = prefix_function(concat); // compute prefix func
    int pattern_size = pattern.size();
    for (int i = pattern_size + 1; i < concat.size(); i++) { // loop through the prefix function results
        if (pi[i] == pattern_size) { // if the prefix val matches pattern size
            solve.push_back(i - 2 * pattern_size); // push the first index of the found pattern into solve vector
        }
    }
    return solve; // return vector containing indexes where pattern is found
}

void computeLPS(string pat, int m, int* lps){ //longest prefix suffix
    int len = 0;
    lps[0] = 0; // Initialize first element of lps array
    
    int i = 1;

    while (i < m){
        if (pat[i] == pat[len]){
            len++;
            lps[i] = len; // Store the length of the current prefix that is also a suffix
            i++;
        }
        // if len isn't zero, it means there was a previous matching prefix.
        // In this case, it updates len to the value stored in lps[len - 1]
        else{
            if (len != 0){
                len = lps[len - 1];
            }
            // If len is zero, it means there was no previous matching prefix.
            // In this case, it sets the lps[i] value to 0, indicating that the current character doesn't have any proper prefix which is also a suffix, and moves to the next index.
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
}


vector<int> KMPSearch(string s, string pat) {
    vector<int> ans;// Vector to store  indexes where the pattern occurs in the string
    int n = s.size();
    int m = pat.size();
    int lps[m]; // initialize the lps array for use in computeLPS

    computeLPS(pat, m, lps);

    int j = 0, i = 0;

    while ((n - i) >= (m - j)) {// Loop through the input string while considering the pattern occurrences
        if (pat[j] == s[i]) {//if match move to next char
            j++;
            i++;
            if (j == m) {   // If the entire pattern is found in the input string
                ans.push_back(i - j);//store start index of pattern
                j = lps[j - 1];//move j to continue searching
            }
        } else {
            if (j != 0) {
                j = lps[j - 1];// Update j using the lps array to handle mismatch
            } else {
                i++;// Return the vector containing the indexes where the pattern occurs in the string
            }
        }
    }
    return ans;
}

int main() {
    string s;
    string pat;
    getline(cin, s);
    getline(cin, pat);

    vector<int> ans = KMPSearch(s, pat);

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    return 0;
}
