// 시간 초과가 난 풀이

#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(vector<int> topping) {
    int answer = 0;
    
    for (int i = 1; i < topping.size(); i++) {
        set <int> s1;
        set <int> s2;
        
        for (int j = 0; j < i; j++) {
            s1.insert(topping[j]);
        }
        for (int j = i; j < topping.size(); j++) {
            s2.insert(topping[j]);
        }
        
        if (s1.size() == s2.size()) {
            answer++;
        }
    }
    
    return answer;
}


// 맞은 풀이

#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> topping) {
    int answer = 0;
    
    vector <int> v1;
    vector <int> v2;
    int cnt1 = 0;   // v1 종류의 개수
    int cnt2 = 0;   // v2 종류의 개수
    
    v1.resize(topping.size());
    v2.resize(topping.size());
    
    // v2에 모든 값들 채워넣기
    for (int i = 0; i < topping.size(); i++) {
        if (v2[topping[i]] == 0) {
            cnt2++;
        }
        
        v2[topping[i]]++;
    }
    
    for (int i = 0; i < topping.size(); i++) {
        if (v1[topping[i]] == 0) {
            cnt1++;
        }
        
        v1[topping[i]]++;
        
        //cout << "v1[topping[i]] : " << v1[topping[i]];
        
        v2[topping[i]]--;
        
        //cout << ", v2[topping[i]] : " << v2[topping[i]] << '\n';
        
        if (v2[topping[i]] == 0) {
            cnt2--;
        }
        
        //cout << cnt1 << " " << cnt2 << '\n';
        
        if (cnt1 == cnt2) {
            answer++;
        }
    }
    
    return answer;
}
