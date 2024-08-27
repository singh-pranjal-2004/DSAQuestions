class Solution {
public:
    string frequencySort(string s) {
        map<char, int>mp;
        for(auto i: s){
            mp[i]++;
        }

        for(auto i: mp){
            cout<<i.second<<endl;
        }

        priority_queue<pair<int, char>>q;
        for(auto i: mp){
            q.push({i.second, i.first});
        }

        string ans = "";
        while(!q.empty()){
            int cnt = q.top().first;
            char c = q.top().second;
            q.pop();

            for(int i = 0; i < cnt; i++){
                ans += c;
            }
        }

        return ans;
        
    }
};

const static auto fast = []
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();