#include <iostream>
#include <queue>
#include <map>

using namespace std;

void processOperations(int k) {
    priority_queue<int> maxHeap; // 최대 힙
    priority_queue<int, vector<int>, greater<int>> minHeap; // 최소 힙
    map<int, int> countMap; // 각 숫자의 개수 저장

    while (k--) {
        char op;
        int num;
        cin >> op >> num;

        if (op == 'I') { // 삽입 연산
            maxHeap.push(num);
            minHeap.push(num);
            countMap[num]++;
        }
        else if (op == 'D') { // 삭제 연산
            if (countMap.empty()) continue; // 큐가 비어 있으면 무시

            if (num == 1) { // 최댓값 삭제
                while (!maxHeap.empty() && countMap[maxHeap.top()] == 0) {
                    maxHeap.pop(); // 이미 삭제된 값 무시
                }
                if (!maxHeap.empty()) {
                    countMap[maxHeap.top()]--;
                    maxHeap.pop();
                }
            }
            else { // 최솟값 삭제
                while (!minHeap.empty() && countMap[minHeap.top()] == 0) {
                    minHeap.pop();
                }
                if (!minHeap.empty()) {
                    countMap[minHeap.top()]--;
                    minHeap.pop();
                }
            }
        }
    }

    // 최종 결과 확인
    while (!maxHeap.empty() && countMap[maxHeap.top()] == 0) {
        maxHeap.pop();
    }
    while (!minHeap.empty() && countMap[minHeap.top()] == 0) {
        minHeap.pop();
    }

    if (maxHeap.empty() || minHeap.empty()) {
        cout << "EMPTY\n";
    } else {
        cout << maxHeap.top() << " " << minHeap.top() << "\n";
    }
}

int main() {
    int T;
    cin >> T; // 테스트 케이스 개수

    while (T--) {
        int k;
        cin >> k; // 연산 개수
        processOperations(k);
    }

    return 0;
}