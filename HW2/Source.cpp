#include <iostream>
#include <vector>
#include <chrono> 
using namespace std;
using namespace std::chrono;

void Powerset(vector<char>& set, vector<vector<char>>& powerset, vector<char>& currentSet, int index) {

    if (index == set.size()) {// 如果到達了集合的末尾，將當前的子集加入到冪集中
        powerset.push_back(currentSet);
        return;
    }
    Powerset(set, powerset, currentSet, index + 1);    // 不選擇當前元素，遞迴下一個元素  
    currentSet.push_back(set[index]);   // 選擇當前元素，加入到子集並遞迴下一個元素
    Powerset(set, powerset, currentSet, index + 1);
    currentSet.pop_back();      // 回溯，移除當前元素
}

int main() {
    vector<char> set = { 'a', 'b', 'c' };
    vector<vector<char>> powerset;  // 存放冪集
    vector<char> currentSet;    // 存放當前子集 
    auto start = high_resolution_clock::now();  // 開始時間
    Powerset(set, powerset, currentSet, 0);// 計算冪集   
    auto stop = high_resolution_clock::now();   // 結束時間   
    auto duration = duration_cast<microseconds>(stop - start); // 計算執行時間
    cout << "powerset的執行時間: " << duration.count() << " ms" << endl;
    cout << "Powerset的大小: " << powerset.size() << endl;
    cout << "Powerset 結果:" << endl;
    for (const auto& subset : powerset) {
        cout << "{ ";
        for (char elem : subset) {
            cout << elem << " ";
        }
        cout << "}" << endl;
    }
    return 0;
}
