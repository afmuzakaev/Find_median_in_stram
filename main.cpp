#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void findMedian(int arr[], int n) {
    priority_queue<int> maxHeap;  // Left half of the numbers
    priority_queue<int, vector<int>, greater<int>> minHeap;  // Right half of the numbers

    maxHeap.push(arr[0]);
    cout << arr[0] << endl;

    for (int i = 1; i < n; i++) {
        if (maxHeap.size() > minHeap.size()) {
            if (arr[i] < maxHeap.top()) {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
                maxHeap.push(arr[i]);
            } else {
                minHeap.push(arr[i]);
            }
            cout << (maxHeap.top() + minHeap.top()) / 2 << endl;
        } else {
            if (arr[i] > minHeap.top()) {
                maxHeap.push(minHeap.top());
                minHeap.pop();
                minHeap.push(arr[i]);
            } else {
                maxHeap.push(arr[i]);
            }
            cout << maxHeap.top() << endl;
        }
    }
}

int main() {
    int N;
    cin >> N;
    int X[N];
    for (int i = 0; i < N; i++) {
        cin >> X[i];
    }
    findMedian(X, N);
    return 0;
}
