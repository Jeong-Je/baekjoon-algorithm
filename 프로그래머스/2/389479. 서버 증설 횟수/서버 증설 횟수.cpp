#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> players, int m, int k) {
    int answer = 0;
    queue<int> server; // 서버의 개설 시간을 담는 큐 
    
    for(int i=0;i<players.size();i++)
    {

        while(server.empty() == false && i - server.front() == k)
        {
            server.pop(); // 이용 시간 끝 
        }
 

        int player = players[i]; // 게임 이용자의 수 
        
        int need_server = player / m;
        int server_cnt = server.size();
        if(server_cnt < need_server)
        {
            for(int j=0;j<need_server - server_cnt; j++)
            {
                server.push(i);
                answer++;
            }
        }
        
    }
    
    return answer;
}


