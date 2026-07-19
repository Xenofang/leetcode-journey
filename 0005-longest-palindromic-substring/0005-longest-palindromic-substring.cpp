class Solution {
public:
    int max = 0 , st = 0 , end = 0; 
    bool isPalindrome(string& s , int i , int j )
    {
        while(i < j )
        {
            if(s[i] != s[j]) return false;
            i++,j--;
        }
        return true;

    }
    string longestPalindrome(string s) {
        int n = s.size();
        for(int i = 0 ; i <n ; i++)
        {
            for(int j = i ; j < n ;j++)
            {
                if(isPalindrome(s, i , j)== true)
                {
                    if((j-i+1) > max){
                        max = j-i+1;
                        st = i ;
                        end = j; 
                    }
                }
            }
        }
        string str = "";

        // for(int k = st ; k <= end ; k++)
        // {
        //     str+=s[k];
        // }
        // or
        return s.substr(st , end-st+1);
    }
};