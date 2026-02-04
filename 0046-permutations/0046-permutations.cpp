class Solution {
public:
// backtracking template
// do something
// explore
// undo the thing you did above
int n;
vector<vector<int>> result;
unordered_set<int> st; // reason -> find operation is O(1)
void solve(vector<int>& nums, vector<int>& temp)
{
    for(int i=0; i<n; i++)
    {
        // base case when we find the answer
        if(temp.size() == n)
        {
            result.push_back(temp);
            return;
        }
        if(st.find(nums[i]) == st.end())
        {
            //do something
            temp.push_back(nums[i]);
            st.insert(nums[i]);
            
            //explore
            solve(nums,temp);

            //undo the thing did above
            temp.pop_back();
            st.erase(nums[i]);
        }
    }
}
    vector<vector<int>> permute(vector<int>& nums) {
        n = nums.size();
        vector<int> temp;
        solve(nums, temp);
        return result;
}
};