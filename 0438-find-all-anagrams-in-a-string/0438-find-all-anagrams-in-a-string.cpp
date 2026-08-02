class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char,int>m;

        for(char i : p)
        {
            m[i]++;
        }

        vector<int>ans;

        int i = 0 , j = i , count = m.size(), k  = p.size();

        while(j < s.size() )
        {
            if(m.find(s[j]) != m.end())
            {
                m[s[j]]--;

                if(m[s[j]] == 0) count--;
            }
            if(j-i+1 < k) j++;

            else if(j-i+1 == k)
            {
                if(count == 0 ) ans.push_back(i);

                if(m.find(s[i]) != m.end())
                {
                    if(m[s[i]] == 0) count++;
                    
                    m[s[i]]++;
                    
                }
                j++;
                i++;
            }

            
        }
        return ans;

    }
};