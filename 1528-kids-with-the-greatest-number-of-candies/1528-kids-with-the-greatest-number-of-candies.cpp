class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& can, int eC) {
        
        int maxC= *max_element(can.begin(), can.end());
        vector<bool> res;
        for (int candy : can){
            res.push_back(candy+eC>= maxC);

        }
        return res;
    }
};