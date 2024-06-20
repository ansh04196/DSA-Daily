class Solution {
  public:
    string compareFrac(string& s) {
        // Code here
        int n = s.length();
        int a=0,b=0,c=0,d=0;
        int i=0;
        while(i<n and s[i]!='/') {
            a = a*10+s[i]-'0';
            i++;
        }
        i++;
        while(i<n and s[i]!=',') {
            b = b*10+s[i]-'0';
            i++;
        }
        i++;
        i++;
        while(i<n and s[i]!='/') {
            c = c*10+s[i]-'0';
            i++;
        }
        i++;
        while(i<n) {
            d = d*10+s[i]-'0';
            i++;
        }
        if ((a/(1.0*b)) > (c/(1.0*d)))
            return to_string(a)+"/"+to_string(b);
        else if((a/(1.0*b)) < (c/(1.0*d)))
            return to_string(c)+"/"+to_string(d);
        return "equal";
    }
};
