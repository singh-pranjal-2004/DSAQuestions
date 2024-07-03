class Solution {
public:
    class node{
        public:
        int data;
        int i;
        int j;

        node(int data, int row, int col){
            this->data = data;
            i = row;
            j = col;
        }
    };

    class compare1{
        public:
        bool operator()(node* a, node* b){
            return a->data > b->data;
        }
    };

    class compare2{
        public:
        bool operator()(node* a, node* b){
            return a->data < b->data;
        }
    };
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<int> ans;
        int minAns = INT_MAX;
        // priority_queue<node*, vector<node*>, compare2> maxHeap;
        priority_queue<node*, vector<node*>, compare1> minHeap;
        int n = nums.size();
        int maxi = INT_MIN;

        for(int i = 0; i < n; i++){
            node* temp = new node(nums[i][0], i, 0);
            minHeap.push(temp);
            maxi = max(maxi, nums[i][0]);
            // maxHeap.push(temp);
        }

        while(minHeap.size()==n){
            node* t1 = minHeap.top();
            // node* t2 = maxHeap.top();
            minHeap.pop();

            int t1d = t1->data;
            int row = t1->i;
            int col = t1->j;
            // int t2d = t2->data;

            if(maxi-t1d < minAns){
                minAns = maxi-t1d;
                ans.clear();
                ans.push_back(t1d);
                ans.push_back(maxi);
            }

            if(col+1 < nums[row].size()){
                node* next = new node(nums[row][col+1], row, col+1);
                minHeap.push(next);
                // maxHeap.push(next);
                maxi = max(maxi, nums[row][col+1]);
            }
        }

        return ans;
    }
};