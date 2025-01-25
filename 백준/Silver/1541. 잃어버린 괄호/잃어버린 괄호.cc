// https://www.acmicpc.net/problem/1541

#include <string>
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

vector<string> split(string input, char delimiter);
int sum(string s);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    string input;
    cin >> input;
    
    vector<string> str = split(input, '-');
    
    int result = 0;
    
    for(int i=0; i<str.size(); i++){
        if(i==0) {
            result += sum(str[i]);
        } else {
            result -= sum(str[i]);
        }
    }
    
    cout << result;

    return 0;
}


vector<string> split(string input, char delimiter) {
    vector<string> result;
    stringstream mystream(input);
    string splitdata;
    
    while(getline(mystream, splitdata, delimiter)) {
        result.push_back(splitdata);
    }
    
    return result;
}

int sum(string s) {
    vector<string> nums = split(s, '+');
    
    int sum = 0;
    
    for(int i=0;i<nums.size();i++){
        sum += stoi(nums[i]);
    }
    
    return sum;
}

