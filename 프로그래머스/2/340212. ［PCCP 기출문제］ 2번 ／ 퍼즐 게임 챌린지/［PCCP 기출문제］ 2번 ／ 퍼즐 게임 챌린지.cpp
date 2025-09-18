#include <string>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int solution(vector<int> diffs, vector<int> times, long long limit) {
    int left = 1;
    int right = *max_element(diffs.begin(), diffs.end());
    int answer = right;
    
    int mid;
    while(left <= right)
    {
        mid = (left + right) / 2;
        
        long long total_time = 0;
        for(int i=0;i<diffs.size();i++)
        {
            int diff = diffs[i];
            if(mid >= diff) 
            {
                total_time += times[i];
            }
            else
            {
                total_time += ((diff - mid) * (times[i-1] + times[i])) + times[i];
            }
        }
        
        
        if(total_time <= limit)
        {
            right = mid - 1;
            answer = mid;
            if(total_time == limit) break;
        }
        else left = mid + 1;
    }
    
    return answer;
}