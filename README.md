## 탐색
### 깊이 우선 탐색(dfs)
### 너비 우선 탐색(bfs)
### 이진 탐색 (binary search)

## 그래프
### 유니온 파인드(union-find)
특정 2개의 노드를 연결해 1개의 집합으로 묶는 `union`연산과 같은 집합에 속하는지를 확인하는 `find`연산으로 구성된 알고리즘
1. 각 노드가 모두 대표 노드가 되도록 배열을 초기화
   
|1|2|3|4|5|
|---|---|---|---|---|
|1|2|3|4|5|

```cpp
void unionfunc(int a,int b){
    a = find(a);
    b = find(b);
  
    if(a!=b){
      parent[b] = a;
    }
}
```
```cpp
int find(int a){
    if(a == parent[a]){
        return a;
    } else {
        return parent[a] = find(parent[a]);
    }
}
```
---
### 위상 정렬(topology sort)
|기능|특징|O(N)|
|---|---|---|
|노드 간의 순서를 결정|사이클이 없어야 함|O(V+E)|

> 위상 정렬에서는 항상 유일한 값으로 정렬되지 않는다.

![Image](https://github.com/user-attachments/assets/6a72798d-2427-46a9-b889-4c9675bf19fb)

![Image](https://github.com/user-attachments/assets/5544c939-b4f2-428c-a8fb-5a42ad5603f3)

**진입 차수 배열 D[N]**
|1|2|3|4|5|
|---|---|---|---|---|
|0|1|1|2|2|

```cpp
for(int i=1;i<=N;i++){
    if(D[i] == 0) {
        queue.push(i);
    }
}

while(!queue.empty()){
    int now = queue.front();
    queue.pop();
    cout << now << " ";
    for(int next: A[now]) {
        D[next]--;
        if(D[next] == 0) {
            queue.push(next);
        }
    }![Uploading ㅇ.svg…]()

}
```
***
### 다익스트라(dijkstra)
### 벨만 포드(bellman-ford)
### 플로이드 워셜(floyd-warshall)
### 최소 신장 트리(minimum spanning tree)
