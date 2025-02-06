// #include <iostream>
// #include <vector>

// using namespace std;

// vector<string> longestUnequalAdjacentGroupsSubsequence(int n, vector<string>& words, vector<int>& groups) {
//     vector<int> changes;
//     int last_group = -1;
// //
//     for (int i = 0; i < n; i++) {
//         // cout << " i: " << i <<" " <<  groups[i] << endl  ; 
//         //   cout << "last " << last_group << endl  ;
//         if (groups[i] != last_group) {
//             changes.push_back(i);
//             last_group = groups[i];
//             // cout << "change: " << changes[i] << endl  ; 
//         } 
//     }
//     if (changes.size() == 1) {
//         return {words[changes[0]]};
//     }

//     vector<string> longest_subsequence;
//     for (int i = 0; i < changes.size() - 1; i++) {
//             longest_subsequence.push_back(words[i]);
//             cout << "lsb: " << longest_subsequence[i] << endl  ; 
//     }

//     return longest_subsequence;
// }

// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif

//     int n;
//     cin >> n;
//     vector<string> words(n);
//     vector<int> groups(n);
//     for (int i = 0; i < n; i++) {
//         cin >> words[i];
//     }
//     for (int i = 0; i < n; i++) {
//         cin >> groups[i];
//         cout << "i : grp: " << i << groups[i] << endl  ; 
//     }
//     vector<string> longest_subsequence = longestUnequalAdjacentGroupsSubsequence(n, words, groups);
//     for (string word : longest_subsequence) {
//         cout << word << " ";
//     }
//     cout << endl;

//     return 0;
// }