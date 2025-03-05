#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <cmath>

using namespace std;

static int parent[101];

void munion(int a,int b);
int find(int a);

int main(){
    int N;
    cin >> N;
    
    for(int i=1;i<=N;i++){
        parent[i] = i;
    }
    
    typedef pair<double, double> position;
    typedef tuple<double, int, int> relation;
    
    vector<position> starts(N+1);
    priority_queue<relation, vector<relation>, greater<relation>> pq;
    
    
    for(int i=1;i<=N;i++){
        double x, y;
        cin >> x >> y;
        starts[i] = {x, y};
    }
    
    for(int i=1;i<N;i++){
        for(int j=i+1;j<=N;j++){
            double a_x = starts[i].first;
            double a_y = starts[i].second;
            double b_x = starts[j].first;
            double b_y = starts[j].second;
            
            //cout << a_x << " " << a_y << " "<< b_x<<" "<<b_y << endl;
            double dis = sqrt(pow(a_x-b_x,2) + pow(a_y-b_y,2));
            //cout << dis << endl;
            pq.push({dis, i, j});
        }
    }
    
    double result = 0.0;
    while(!pq.empty()){
        tuple<double, int, int> now = pq.top();
        pq.pop();
        
        double w = get<0>(now);
        int a = get<1>(now);
        int b = get<2>(now);
        
        if(find(a) != find(b)) {
            munion(a, b);
            result += w;
        }
    }
    
    cout << fixed;
    cout.precision(2);
    cout << result;
}


void munion(int a,int b) {
    a = find(a);
    b = find(b);
    if(a != b) {
        parent[b] = a;
    }
}
int find(int a) {
    if(a == parent[a]) return a;
    else return a = find(parent[a]);
}