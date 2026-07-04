class MedianFinder {
    priority_queue<double> maxheap;
    priority_queue<double, vector<double>, greater<double>> minheap;
    double median;

    int signum(int a, int b){
        if(a == b) 
            return 0;
        else if(a > b) 
            return 1;
        else 
            return -1;
    }

public:
    MedianFinder() {
        median = 0;
    }
    
    void addNum(int num) {
        switch (signum(minheap.size(), maxheap.size())){
        case 0:

            if(num > median){
                minheap.push(num);
                median = minheap.top();
            }else{
                maxheap.push(num);
                median = maxheap.top();
            }
            break;

        case 1:
        
            if(num > median){
                double mdoubleop = minheap.top(); 
                minheap.pop();
                maxheap.push(mdoubleop);
                minheap.push(num);
                median = ( minheap.top() + maxheap.top() )/ 2;
            }else{
                maxheap.push(num);
                median = ( minheap.top() + maxheap.top() )/ 2;
            }

            break;
        case -1:
            if(num > median){
                minheap.push(num);
                median = ( minheap.top() + maxheap.top() )/ 2;
            }else{
                double maxTop = maxheap.top(); 
                maxheap.pop();
                minheap.push(maxTop);
                maxheap.push(num);
                median = ( minheap.top() + maxheap.top() )/ 2;
            }

            break;

        default:
            break;
        }
    }
    
    double findMedian() {
        return median;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */