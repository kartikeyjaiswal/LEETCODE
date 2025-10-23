class Solution {
public:
    bool canPlaceFlowers(vector<int>& nums, int n) {
        int count = 0;
        int a = nums.size();

        for (int i = 0; i < a; i++) {
            if (nums[i] == 0 && (i == 0 || nums[i - 1] == 0) && (i == a - 1 || nums[i + 1] == 0)) {
                nums[i] = 1;  
                count++;      

                if (count >= n) 
                    return true;
            }
        }

        return count >= n;
    }
};
