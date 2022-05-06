#include <iostream>
#include <vector>

using namespace std; 

class Interval {
    public:
        int start = 0; 
        int end = 0; 

    Interval(int start, int end) {
        this->start = start; 
        this->end = end; 
    }     
};

vector<Interval> merge(vector<Interval> intervals) {

    if (intervals.size() <= 1)
        return intervals; 

    vector<Interval> res; 

    // sort the intervals by start time
    sort(intervals.begin(), intervals.end(),
        [](Interval x, Interval y){ return x.start < y.start;}); 
    
    int start = intervals[0].start; 
    int end = intervals[0].end; 

    for (int i=1; i < intervals.size(); i++) {
        Interval interval = intervals[i]; 

        if (interval.start <= end) {
            end = max(end, interval.end);
        }  else {
            res.push_back({start, end}); 
            start = interval.start; 
            end = interval.end; 
        }
    }

    res.push_back({start, end}); 

    return res; 
}

int main() {
    vector<Interval> input = {{1, 3}, {2, 5}, {7, 9}, {6, 11}}; 

    sort(input.begin(), input.end(), [](Interval x, Interval y){ return x.start < y.start;}); 

    vector<Interval> res = merge(input);

    for (auto interval : res) {
        cout << interval.start << " " << interval.end << endl;
    }
}