#include <iostream>
#include <string>
#include <set>

using namespace std;

int main(){
    int N;
    char G;
    
    cin >> N >> G;
    
    set<string> player_set;
    string player_name;
    for(int i=0;i<N;i++){
        cin >> player_name;
        player_set.insert(player_name);
    }
    
    if(G == 'Y') {
        cout << player_set.size();
    } else if(G == 'F') {
        cout << player_set.size() / 2;
    } else if(G == 'O') {
        cout << player_set.size()/ 3;
    }
}