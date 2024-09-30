class CustomStack {
public:
    vector<int>stack;
    int maxSize;
    CustomStack(int maxSize) {
        this->maxSize = maxSize;
    }
    
    void push(int x) {
        if(stack.size() == maxSize) return;
        stack.push_back(x);
    }
    
    int pop() {
        if(stack.size()==0) return -1;
        int s = stack[stack.size()-1];
        stack.pop_back();
        return s;
    }
    
    void increment(int k, int val) {
        int n = stack.size();
        for(int i = 0; i < k && i < n; i++){
            stack[i] += val;
        }
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
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */