#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class MedianFinder {
    priority_queue<int> left; 
    priority_queue<int, vector<int>, greater<int>> right; 
public:
    
    MedianFinder() {}
    

    void addNum(int num) {

        
        if(left.size()==0){
            left.push(num);
            return;
        }

        if(num<= left.top())
            left.push(num);
        else
            right.push(num);

        int diff = left.size() - right.size();

        if(diff > 1){
            int n = left.top();
            left.pop();
            right.push(n);
        }
        else if(diff<0){
            int n = right.top();
            right.pop();
            left.push(n);
        }

    }
    
    double findMedian() {

        if(left.size() == 0 && right.size()==0)
            return 0.0;

        if (left.size() > right.size()) 
            return left.top();  
        else 
            return (left.top() + right.top()) / 2.0;  

    }
};

int main() {
    MedianFinder mf;

    // Sequence of operations: [[],[-1],[],[-2],[],[-3],[],[-4],[],[-5],[]]
    cout << mf.findMedian() << endl; // []

    mf.addNum(-1);
    cout << mf.findMedian() << endl; // [-1]

    mf.addNum(-2);
    cout << mf.findMedian() << endl; // [-2]

    mf.addNum(-3);
    cout << mf.findMedian() << endl; // [-3]

    mf.addNum(-4);
    cout << mf.findMedian() << endl; // [-4]

    mf.addNum(-5);
    cout << mf.findMedian() << endl; // [-5]

    return 0;
}