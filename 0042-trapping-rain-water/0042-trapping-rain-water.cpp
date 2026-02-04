class Solution {
private:
    vector<int> r(vector<int> h){
        // max to the right
        int maxi=-1;
        int n=h.size();
        for(int i=n-1; i>-1; i--){
            int temp=h[i];
            if(maxi> h[i]) h[i]=maxi;
            else {h[i]=-1; maxi=temp;}
        }
        return h;
    }
    vector<int> l(vector<int> h){
    // max to the right
    int maxi=-1;
    int n=h.size();
    for(int i=0; i<n; i++){
        int temp=h[i];
        if(maxi> h[i]) h[i]=maxi;
        else {h[i]=-1; maxi=temp;}
    }
    return h;
}
public:
// Approach 2: towerwise , max to left and right
    int trap(vector<int>& h) {
        int n=h.size();
        vector<int> maxright(n,-1);
        vector<int> maxleft(n,-1);

        maxright=r(h);
        maxleft=l(h);
        int sum=0;

        for(int i=0 ; i<n; i++){
            int left=maxleft[i];
            int right=maxright[i];
            sum+= (left ==-1 || right==-1)?0: min(left,right)-h[i];
        }
        return sum;
    }
// O(n)+ O(n) [maxleft and maxright array]
};