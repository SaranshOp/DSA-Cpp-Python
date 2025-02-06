class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        vector<int>ans;

        for(int i=0 ; i<arr.size() ; i++)
        {
        int count = 0;
            for(int j = i ; j< arr.size() ; j++ )
            {
                if (arr[j] == arr[i])
                count++;
                if (arr[j] != arr[i])
                break;
                
               
            }
            // did misatake here put that inside loop which they did not allow, although logic was right 
            ans.push_back(count);
            i = i + count - 1;
               
        } 
        // this(below)  logic of sorting And checking unique elements in array is nice
        sort(ans.begin(),ans.end());
        for (int i = 0; i < ans.size() - 1; i++){
           if (ans[i] == ans [i+1])
                return false;
        }
    return true;
    }
};