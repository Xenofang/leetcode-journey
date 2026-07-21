class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>m ;

        for(int ele : nums)
        {
            m[ele]++;
        }

        struct comp{
            bool operator()(const pair<int,int> &a ,const pair<int,int> &b)
            {
                if(a.second == b.second)
                {
                    return a.first < b.first;
                }
                return a.second > b.second;
            }

        };

        priority_queue<pair<int,int> , vector<pair<int,int>> , comp> minh;

        for(auto i : m)
        {
            minh.push({i.first , i.second});

            if(minh.size() > k)
            {
                minh.pop();
            }
        }

        vector<int>ans;
        while(!minh.empty())
        {
            ans.push_back(minh.top().first);
            minh.pop();
        }

        return ans;
    }
};