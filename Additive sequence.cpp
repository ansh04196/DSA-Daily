//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
 
 
 class Solution {
  public:
    bool isValid(string num) {
        // check if the number is valid, i.e., not starting with 0 if it has more than 1
        // digit
        if (num.size() > 1 && num[0] == '0')
            return false;
        return true;
    }

    int val(string a, int pos) {
        // get the integer representation of the character at a specific position in a
        // string
        if (pos >= a.length())
            return 0;
        return (a[pos] - '0');
    }

    string addString(string a, string b) {
        // function to add two strings representing numbers
        string sum = "";
        int i = a.length() - 1;
        int j = b.length() - 1;
        int carry = 0;

        while (i >= 0 || j >= 0) {
            // calculate the sum of two digits and the carry
            int t = val(a, i) + val(b, j) + carry;

            // append the digit to the sum string
            sum += (t % 10 + '0');

            // update the carry for the next iteration
            carry = t / 10;
            i--;
            j--;
        }

        // if there is still a carry left, append it to the sum string
        if (carry)
            sum += (carry + '0');

        // reverse the sum string and return it
        reverse(sum.begin(), sum.end());
        return sum;
    }

    bool checkAddition(list<string>& res, string a, string b, string c) {
        // check if the addition of two strings is valid
        if (!isValid(a) || !isValid(b))
            return false;
        string sum = addString(a, b);

        // check if the sum is equal to the target string
        if (sum == c) {
            res.push_back(sum);
            return true;
        }

        // check if the target string starts with the sum string
        if (c.size() <= sum.size() || sum != c.substr(0, sum.size()))
            return false;
        else {
            res.push_back(sum);

            // recursively check the addition of the previous sum and the next string in
            // the sequence
            return checkAddition(res, b, sum, c.substr(sum.size()));
        }
    }

    list<string> additiveSequence(string num) {
        // find the additive sequence for a given number
        list<string> res;
        int l = num.length();

        for (int i = 1; i <= l / 2; i++) {
            for (int j = 1; j <= (l - i) / 2; j++) {
                // check if the addition of the first two substrings leads to the target
                // string
                if (checkAddition(res, num.substr(0, i), num.substr(i, j),
                                  num.substr(i + j))) {
                    // add the substrings to the result list and return it
                    res.push_front(num.substr(i, j));
                    res.push_front(num.substr(0, i));
                    return res;
                }
            }
        }

        // if no additive sequence is found, clear the result list and return it
        res.clear();
        return res;
    }

    bool isAdditiveSequence(string n) {
        // check if a number has an additive sequence
        list<string> res = additiveSequence(n);
        if (res.size() == 0)
            return 0;
        else
            return 1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;

    Solution sol;

    while (t--) {
        string s;
        cin >> s;

        bool result = sol.isAdditiveSequence(s);
        cout << result << endl;
    }

    return 0;
}

// } Driver Code Ends
