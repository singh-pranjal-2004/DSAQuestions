class Solution {
public:
    string simplifyPath(string path) {
        vector<string>str;

        int i = 0;
        while(i < path.length()){
            while(i < path.length() && path[i] == '/') i++;

            string s = "";
            while(i < path.length() && path[i] != '/'){
                s += path[i];
                i++;
            }

            if(s=="." || s=="") continue;
            else if(s==".."){
                if(str.size() > 0) str.pop_back();
            }else{
                str.push_back(s);
            }
        }

        string ans = "";

        for(auto dir: str){
            ans += '/' + dir;
        }

        return ans.empty()?"/":ans;
    }
};