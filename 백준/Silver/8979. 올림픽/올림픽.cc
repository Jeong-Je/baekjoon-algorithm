#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>

using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;
    
    vector<tuple<int, int, int>> v(1001);
    
    for(int i=1;i<=N;i++)
    {
        int country, gold, silver, bronze;
        cin >> country >> gold >> silver >> bronze;
        
        v[country] = {gold, silver, bronze};
    }
    
    
    int rank = 1;
    auto [gold_k, silver_k, bronze_k] = v[K];
    for(int i=1;i<=N;i++)
    {
        if(i == K) continue;
        
        auto [gold_i, silver_i, bronze_i] = v[i];
        
        if(gold_i > gold_k) {
            rank ++;
        } else if(gold_i == gold_k && silver_i > silver_k) {
            rank++;
        } else if(gold_i == gold_k && silver_i == silver_k && bronze_i > bronze_k) {
            rank++;
        }
    }
    
    
    cout << rank;
}