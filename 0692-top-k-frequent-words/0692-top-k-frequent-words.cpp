class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {

        struct comp{
            bool operator()(const pair<string , int>&a ,const pair<string , int>&b )
            {
                if(a.second == b.second)
                {
                    return a.first < b.first; 
                }
                return a.second > b.second;
            }
        };
        
        // store all the frequency and string in a map //O(n)
        unordered_map<string,int>m;
        for(auto str : words)
        {
            m[str]++;
        }

        // by using minh  we get the highest frequency string and store in a heap according to the size of heap //O(m log k)
        priority_queue<pair<string,int> , vector<pair<string,int>> ,comp> minh;

        for(auto p : m)
        {
            minh.push({p.first , p.second});

            if(minh.size() > k)
            {
                minh.pop();
            }
        }

        // storing all the strings  the is in heap according  to the size of heap // O(k log k)
        vector<string> ans;

        while(!minh.empty())
        {
            ans.push_back(minh.top().first);
            minh.pop();
        }

        // sorting in lexicographical order
        reverse(ans.begin() , ans.end());

        return ans;
    }
};