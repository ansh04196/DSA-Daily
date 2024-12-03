#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool KMPSearch(string pat, string txt) {
        int M = pat.size();
        int N = txt.size();

        // create lps[] that will hold the longest prefix suffix
        // values for pattern
        int lps[M];

        // Preprocess the pattern (calculate lps[] array)
        computeLPSArray(pat, M, lps);

        int i = 0; // index for txt[]
        int j = 0; // index for pat[]
        while ((N - i) >= (M - j)) {
            if (pat[j] == txt[i]) {
                j++;
                i++;
            }

            if (j == M) {
                return true;

            }

            // mismatch after j matches
            else if (i < N && pat[j] != txt[i]) {
                // Do not match lps[0..lps[j-1]] characters,
                // they will match anyway
                if (j != 0)
                    j = lps[j - 1];
                else
                    i = i + 1;
            }
        }
        return false;
    }

    // Fills lps[] for given pattern pat[0..M-1]
    void computeLPSArray(string pat, int M, int *lps) {
        // length of the previous longest prefix suffix
        int len = 0;

        lps[0] = 0; // lps[0] is always 0

        // the loop calculates lps[i] for i = 1 to M-1
        int i = 1;
        while (i < M) {
            if (pat[i] == pat[len]) {
                len++;
                lps[i] = len;
                i++;
            } else // (pat[i] != pat[len])
            {

                if (len != 0) {
                    len = lps[len - 1];

                    // Also, note that we do not increment
                    // i here
                } else // if (len == 0)
                {
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }

    // Function to check if two strings are rotations of each other or not.
    bool areRotations(string &s1, string &s2) {
        if (s1.length() != s2.length())
            return false;
        else {
            // we concatenate first string to itself and check if other
            // string occurs in it as substring. If yes, then it
            // is rotated version and we return true else false.
            string concated = s1 + s1;
            if (KMPSearch(s2, concated))
                return true;
            else
                return false;
        }
    }
};
