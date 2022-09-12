class MedianFinder {
public:
    priority_queue<int, vector<int>, greater<int>> left;
    priority_queue<int> right;
    bool isEven = true;
    MedianFinder() {
        
    }
    
    // TC : O(logN)
    void addNum(int num) {
        if(isEven){
            left.push(num);
            right.push(left.top());
            left.pop();
        }else{
            right.push(num);
            left.push(right.top());
            right.pop();
        }
        isEven ^=1;
    }
    
    // TC : O(logN)
    double findMedian() {
        if(isEven){
            return (left.top()+right.top())/2.00;
        }else{
            return right.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */