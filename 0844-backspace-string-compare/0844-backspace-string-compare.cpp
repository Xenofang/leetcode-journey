class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<string>st;
        stack<string>tt;

        for(char i : s)
        {
            if(i == '#')
            {
                if(!st.empty()) st.pop();
                continue;

            }
            else{
                st.push(string(1,i));
            }
        }

        for(char j : t)
        {
            if(j == '#')
            {
                if(!tt.empty())tt.pop();
                continue;
            }
            else{
                tt.push(string(1,j));
            }
        }

        if(st.size() == tt.size())
        {
            while(!st.empty())
            {
                if(st.top() != tt.top()) return false;
                else{
                    st.pop() ;tt.pop();
                }
            }
           
        }
        else{
            return false;
        }
        return true;
    }
};