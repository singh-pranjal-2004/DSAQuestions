class MyCalendarTwo {
public:
    MyCalendarTwo() {}
    vector<pair<int, int>> single;
    vector<pair<int, int>> dble;

    bool book(int start, int end) {
        for (auto i : dble) {
            int s = i.first;
            int e = i.second;

            if (max(start, s) < min(end, e))
                return false;
        }

        for(auto i: single){
            int s = i.first;
            int e = i.second;
            if(max(start, s) < min(end, e)) dble.push_back({max(start, s), min(end, e)});
        }

        single.push_back({start, end});
        return true;
    }
};

const static auto fast = []
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */