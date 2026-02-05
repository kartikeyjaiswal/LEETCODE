class Solution {
public:
    string simplifyPath(string path) {

        string result;
        stack<string> st;
        string token = "";
        stringstream ss(path);
        while(getline(ss,token,'/'))
        {
            //skip on / and . -> nothing to be done 
            if(token == "." || token == "/" || token == "") continue;
            if(token != "..")
            {
                st.push(token);  // folder name 
            }
            else
            {
                if(!st.empty()) // otherwise runtime error, popping from an empty stack
                st.pop(); // means it is ".." so we pop one
            }
        }
        if(st.empty()) //means only the root has to be there
        {
            result = "/" ;
            return result;
        }
        while(!st.empty()) 
        { 
            result = "/" + st.top() + result;
            st.pop();
        }
        return result;
    }
};