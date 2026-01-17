
class Solution {
public:
    vector<vector<int>> result;
    vector<int> current;

    void solve(int index, int target, vector<int>& candidates) {
        
        if (target == 0) {
            result.push_back(current);
            return;
        }

        if (target < 0 || index == candidates.size()) {
            return;
        }

        current.push_back(candidates[index]);
        solve(index, target - candidates[index], candidates);
        current.pop_back();


        solve(index + 1, target, candidates);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        solve(0, target, candidates);
        return result;
    }
};