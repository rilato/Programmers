// ㅁ . . .
// ㅁㅁ . .
// ㅁㅁㅁ .
// ㅁㅁㅁㅁ과 같은 형태이므로, left는 필요하지 않다.
// answer 배열에 바로 값을 넣는 방법은 어렵다. (일반적인 idx 계산 방식인 r * n + c를 적용하려 할 경우, out of bound가 발생한다. 위의 그림에서 2차원 배열에서 .과 같이 사용하지 않는 칸이 존재하기 때문)

#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

vector<int> solution(int n) {
    vector<int> answer;
    vector <vector <bool>> visited;
    vector <vector <int>> map;
    bool down = true;
    bool up = false;
    bool right = false;
    int num = 1;
    int want = n * (n + 1) / 2;
    queue <pair <int, int>> q;
    
    map.resize(n, vector <int>(n));
    visited.resize(n, vector <bool>(n));
    q.push({ 0, 0 });
    
    while (!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        
        q.pop();
        
        visited[r][c] = true;
        
        map[r][c] = num;
        
        if (num == want) {
            break;
        }
        
        num++;
        
        // down의 bool값으로 인해 right이 영향받을 수 있으므로, 그 아래의 if문은 else if문으로 바꿔준다.
        if (down) {
            if (r + 1 >= n || visited[r + 1][c]) {
                right = true;
                down = false;
                q.push({ r, c + 1 });
            }
            else if (!visited[r + 1][c]) {
                q.push({ r + 1, c });
            }
        }
        else if (up) {
            if (r - 1 < 0 || c - 1 < 0 || visited[r - 1][c - 1]) {
                up = false;
                down = true;
                q.push({ r + 1, c });
            }
            else if (!visited[r - 1][c - 1]) {
                q.push({ r - 1, c - 1 });
            }
        }
        else if (right) {
            if (c + 1 >= n || visited[r][c + 1]) {
                up = true;
                right = false;
                q.push({ r - 1, c - 1 });
            }
            else if (!visited[r][c + 1]) {
                q.push({ r, c + 1 });
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            // cout << map[i][j] << " ";
            answer.push_back(map[i][j]);
        }
        // cout << "\n";
    }
    
    return answer;
}
