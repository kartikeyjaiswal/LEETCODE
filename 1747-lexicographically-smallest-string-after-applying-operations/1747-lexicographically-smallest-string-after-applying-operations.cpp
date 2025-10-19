class Solution {
    string addOperation(string curr, int a){
        for(int i=1; i<curr.size(); i+=2){
            curr[i] = ((curr[i] - '0' + a)%10) + '0';
        }

        return curr;
    }

    string rotateOperation(string curr, int b){
        b = b%(curr.size());
        return curr.substr(curr.size() - b) + curr.substr(0, curr.size() - b);
    }

public:
    string findLexSmallestString(string s, int a, int b) {
        queue<string> q;
        unordered_set<string> visited;

        string ans = s;
        q.push(s);
        visited.insert(s);

        while(!q.empty()){
            string curr = q.front();
            q.pop();

            ans = min(ans, curr);

            string added = addOperation(curr, a);
            if(!visited.count(added)){
                visited.insert(added);
                q.push(added);
            }

            string rotated = rotateOperation(curr, b);
            if(!visited.count(rotated)){
                visited.insert(rotated);
                q.push(rotated);
            }
        }

        return ans;
    }
};