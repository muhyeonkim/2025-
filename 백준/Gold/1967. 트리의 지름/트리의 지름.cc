#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector<pair<int, int>> tree[10001];
bool visited[10001];
int maxDist = 0; // 최대 거리 저장
int farthestNode = 0; // 가장 먼 노드 저장

// DFS 함수: 현재 노드와 현재까지의 거리를 매개변수로 받음
void DFS(int node, int dist) {
    visited[node] = true;

    if (dist > maxDist) {
        maxDist = dist;
        farthestNode = node;
    }

    for (int i = 0; i < tree[node].size(); i++) {
        int nextNode = tree[node][i].first;
        int nextDist = tree[node][i].second;

        if (!visited[nextNode]) {
            DFS(nextNode, dist + nextDist);
        }
    }
}

int main() {
    int n;
    cin >> n;

    // 트리 입력 받기
    for (int i = 0; i < n - 1; i++) {
        int parent, child, weight;
        cin >> parent >> child >> weight;
        tree[parent].push_back({ child, weight });
        tree[child].push_back({ parent, weight }); // 무방향 트리이므로 양방향 저장
    }

    // 1. 임의의 노드(여기서는 루트 1)에서 가장 먼 노드 찾기
    memset(visited, false, sizeof(visited));
    DFS(1, 0);

    // 2. 찾은 노드에서 가장 먼 노드까지 거리 계산
    memset(visited, false, sizeof(visited));
    maxDist = 0;
    DFS(farthestNode, 0);

    // 트리의 지름 출력
    cout << maxDist << endl;

    return 0;
}