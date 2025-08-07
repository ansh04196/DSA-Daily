class Solution {
  public:
    void print(auto it){
        for(auto i:it){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    int Normal_Form(string s,string r){
        //Normal turn
        int hours1=stoi(s.substr(0,2));
        int minutes1=stoi(s.substr(3,5));
        int seconds1=stoi(s.substr(6));
        //cout<<hours1<<" "<<minutes1<<" "<<seconds1<<endl;
        int hours2=stoi(r.substr(0,2));
        int minutes2=stoi(r.substr(3,5));
        int seconds2=stoi(r.substr(6));
        //cout<<hours2<<" "<<minutes2<<" "<<seconds2<<endl;
        int cnt2=0;
        while(true){
            if(hours1==hours2 && minutes1==minutes2 && seconds1==seconds2){
                break;
            }
            cnt2++;
            seconds1++;
            if(seconds1==60){
                minutes1++;
                seconds1=0;
                if(minutes1==60){
                    hours1++;
                    minutes1=0;
                    if(hours1==24){
                        hours1=0;
                    }
                }
            }
        }
        return cnt2;
    }
    int Circular_Form(string s,string r){
        //Circular turn
        int hours1=stoi(s.substr(0,2));
        int minutes1=stoi(s.substr(3,5));
        int seconds1=stoi(s.substr(6));
        //cout<<hours1<<" "<<minutes1<<" "<<seconds1<<endl;
        int hours2=stoi(r.substr(0,2));
        int minutes2=stoi(r.substr(3,5));
        int seconds2=stoi(r.substr(6));
        //cout<<hours2<<" "<<minutes2<<" "<<seconds2<<endl;
        int cnt2=0;
        while(true){
            if(hours1==hours2 && minutes1==minutes2 && seconds1==seconds2){
                break;
            }
            cnt2++;
            seconds2++;
            if(seconds2==60){
                minutes2++;
                seconds2=0;
                if(minutes2==60){
                    hours2++;
                    minutes2=0;
                    if(hours2==24){
                        hours2=0;
                    }
                }
            }
        }
        return cnt2;
    }
    int minDifference(vector<string> &a){
        unordered_set<string>set;
        for(auto &it:a){
            if(set.count(it)){
                return 0;
            }
            set.insert(it);
        }
        vector<string>arr(set.begin(),set.end());
        sort(arr.begin(),arr.end());
        arr.push_back(arr[0]);
        int n=arr.size();
        //print(arr);
        int mini=INT_MAX;
        for(int i=0;i+1<n;i++){
            auto s=arr[i];
            auto r=arr[i+1];
            int cnt1=Normal_Form(s,r);
            int cnt2=Circular_Form(s,r);
            mini=min({mini,cnt1,cnt2});
        }
        return mini;
    }
};
//GFG POTD solution for 07 August
