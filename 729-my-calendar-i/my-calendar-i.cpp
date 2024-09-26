class MyCalendar {
public:
    MyCalendar() {}

    vector<pair<int, int>>main;
    
    bool book(int start, int end) {
        for(auto i: main){
            int vStart = i.first;
            int vEnd = i.second;

            if(start < vEnd && end > vStart) return false;
        }

        main.push_back({start, end});
        return true;

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
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */