#include <iostream>
#include <stack>
#include <chrono>  
using namespace std;
using namespace std::chrono;

int ackermann_non_recursive(int m, int n) {
    stack<pair<int, int>> s; // 定義一個堆疊來存儲 (m, n)
    s.push(make_pair(m, n)); // 將初始的 (m, n) 推入堆疊
    while (!s.empty()) {
        m = s.top().first;
        n = s.top().second;
        s.pop();
        if (m == 0) {// 如果 m 等於 0，則根據定義 n+1
            n = n + 1;
            if (!s.empty()) {
                m = s.top().first;
                s.pop();
                s.push(make_pair(m, n));
            }
            else {
                // 如果堆疊為空，返回計算結果 n
                return n;
            }
        }
        else if (n == 0) {  // 如果 m > 0 且 n == 0，則將 (m-1, 1) 推入堆疊
            s.push(make_pair(m - 1, 1));
        }
        else {  // 如果 m > 0 且 n > 0，則推入 (m-1, -1) 和 (m, n-1)
            s.push(make_pair(m - 1, -1));  // 推入 m-1
            s.push(make_pair(m, n - 1));   // 推入 m 和 n-1
        }
    }
    return n;
}

int main() {
    int m, n;
    cout << "輸入 m 和 n : ";
    cin >> m >> n;
    auto start = high_resolution_clock::now();  // 記錄開始時間   
    int result = ackermann_non_recursive(m, n); // 執行阿克曼函數（非遞迴版本）
    auto stop = high_resolution_clock::now();   // 記錄結束時間
    auto duration = duration_cast<milliseconds>(stop - start);// 計算持續時間，並轉換為毫秒
    cout << "Ackermann 非遞迴答案(" << m << ", " << n << ") = " << result << endl;
    cout << "執行時間: " << duration.count() << " ms" << endl;
    return 0;
}
