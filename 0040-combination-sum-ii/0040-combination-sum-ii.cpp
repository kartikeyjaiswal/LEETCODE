class Solution {
public:
    void subseq( int ind, int target, vector<int>& ds, vector<int>& candidates, vector<vector<int>>& ans  ){
        if( target == 0 ){
            ans.push_back(ds);
            return;
        }

        for( int i = ind; i<candidates.size(); i++ ){
            // not take
            if( i>ind && candidates[i-1]==candidates[i] ){
                continue;
            }

            if( candidates[i] > target ){
                break;
            }

            // take
            ds.push_back( candidates[i] );
            subseq( i+1, target - candidates[i], ds, candidates, ans );
            ds.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> ds;
        vector<vector<int>> ans;
        sort( candidates.begin(), candidates.end() );

        subseq( 0, target, ds, candidates,ans );

        return ans;
    }
};