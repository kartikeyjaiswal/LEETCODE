class Solution {
public:
    bool isValid(string s) {
        stack<char> al;
        for(char ch: s){
            if(ch=='(' || ch=='{' || ch=='['){
                al.push(ch);

            }else {
            if (al.empty())
            return false;
            char top = al.top();
            al.pop();

            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '[')) {
                return false;
            }
        }
    }

    return al.empty();
}
};

