class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>>pq;
        if(a > 0) pq.push({a, 'a'});
        if(b > 0) pq.push({b, 'b'});
        if(c > 0) pq.push({c, 'c'});

        string result = "";

        while(!pq.empty()){
            int count1 = pq.top().first;
            char c1 = pq.top().second;
            pq.pop();

            if(result.size() >= 2 && result.back() == c1 && result[result.size()-2] == c1){
                if(pq.empty()) break;

                int count2 = pq.top().first;
                int c2 = pq.top().second;
                pq.pop();

                result += c2;
                count2--;
                if(count2 > 0) pq.push({count2, c2});
                if(count1 > 0) pq.push({count1, c1});
            }else{
                result += c1;
                count1--;

                if(count1 > 0) pq.push({count1, c1});
            }
        }
        return result;
    }
};

const static auto fast = []
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();