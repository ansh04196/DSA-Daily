class Solution
{
  public:
    // a,b : the arrays
    // Function to return a list containing the union of the two arrays.
    vector<int> findUnion(vector<int> &a, vector<int> &b)
    {
        int i, j, x, y;
        vector<int> ans;

        for (i = 0, j = 0;   ;  )
        {
            if (i >= (int)a.size()) break;
            if (j >= (int)b.size()) break;
            x = a[i];
            y = b[j];
            if (x == y)
            {
                ans.push_back(x);
                i++;
                j++;
                continue;
            }
            if (x < y)
            {
                ans.push_back(x);
                i++;
                continue;
            }
            ans.push_back(y);
            j++;
        }

        for (   ;  i < (int)a.size(); i++)
        {
            x = a[i];
            ans.push_back(x);
        }

        for (  ;  j < (int)b.size(); j++)
        {
            y = b[j];
            ans.push_back(y);
        }

        return ans;
        
    }
};
