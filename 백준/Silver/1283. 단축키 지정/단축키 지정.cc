#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <cctype>

using namespace std;

static bool alphabet_check[26];

int main() {
    int N;
    cin >> N;
    cin.ignore();
    vector<vector<string>> command(N);

    for (int i = 0; i < N; i++) {
        string line;
        getline(cin, line); 
        istringstream iss(line);
        string word;
        while (iss >> word) { 
            command[i].push_back(word);
        }
    }
    

    for(int i=0;i<N;i++){
        bool find = false;
        for(int j=0;j<command[i].size();j++){
            if(isupper(command[i][j][0])) {
                if(alphabet_check[command[i][j][0] - 'A']) {
                    continue;
                } else {
                    find = true;
                    alphabet_check[command[i][j][0] - 'A'] = true;
                    command[i][j].insert(0, "[");
                    command[i][j].insert(2, "]");
                    break;
                }
            } else {
                if(alphabet_check[command[i][j][0] - 'a']) {
                    continue;
                } else {
                    find = true;
                    alphabet_check[command[i][j][0] - 'a'] = true;
                    command[i][j].insert(0, "[");
                    command[i][j].insert(2, "]");
                    break;
                }    
            }
        }
        
        if(find == false) { // 단어들 첫 문자에서 단축어를 못 찾았으면 
            // 앞에서 부터 순서대로 단축어 찾기
            for(int j=0;j<command[i].size();j++){
                if(find) break;
                for(int k=1;k<command[i][j].length();k++) {
                    if(isupper(command[i][j][k])) {
                        if(alphabet_check[command[i][j][k] - 'A']) {
                            continue;
                        } else {
                            find = true;
                            alphabet_check[command[i][j][k]- 'A'] = true;
                            command[i][j].insert(k, "[");
                            command[i][j].insert(k+2, "]");
                            break;
                        }
                    } else {
                        if(alphabet_check[command[i][j][k] - 'a']) {
                            continue;
                        } else {
                            find = true;
                            alphabet_check[command[i][j][k] - 'a'] = true;
                            command[i][j].insert(k, "[");
                            command[i][j].insert(k+2, "]");
                            break;
                        }    
                    }                    
                }
            }
        }
    }
    
    for(int i=0;i<N;i++){
        for(auto w: command[i]) {
            cout << w << " ";
        }
        cout << "\n";
    }
}
