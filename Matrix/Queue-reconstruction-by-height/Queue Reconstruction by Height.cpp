class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(),people.end(), [](vector<int> a,vector<int> b)->bool{
           if(a[0]>b[0]) return true; 
           else if(a[0]==b[0]) return a[1]<b[1];
           else return false;
        });
        vector<vector<int>> ans;
        
        for(auto person:people)
        {
            ans.insert(ans.begin()+person[1],person);
        }
        return ans;
    }
};
