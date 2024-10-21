#include <iostream>
#include <stack>
#include <chrono>  
using namespace std;
using namespace std::chrono;

int ackermann_non_recursive(int m, int n) {
    stack<pair<int, int>> s; // �w�q�@�Ӱ��|�Ӧs�x (m, n)
    s.push(make_pair(m, n)); // �N��l�� (m, n) ���J���|
    while (!s.empty()) {
        m = s.top().first;
        n = s.top().second;
        s.pop();
        if (m == 0) {// �p�G m ���� 0�A�h�ھکw�q n+1
            n = n + 1;
            if (!s.empty()) {
                m = s.top().first;
                s.pop();
                s.push(make_pair(m, n));
            }
            else {
                // �p�G���|���šA��^�p�⵲�G n
                return n;
            }
        }
        else if (n == 0) {  // �p�G m > 0 �B n == 0�A�h�N (m-1, 1) ���J���|
            s.push(make_pair(m - 1, 1));
        }
        else {  // �p�G m > 0 �B n > 0�A�h���J (m-1, -1) �M (m, n-1)
            s.push(make_pair(m - 1, -1));  // ���J m-1
            s.push(make_pair(m, n - 1));   // ���J m �M n-1
        }
    }
    return n;
}

int main() {
    int m, n;
    cout << "��J m �M n : ";
    cin >> m >> n;
    auto start = high_resolution_clock::now();  // �O���}�l�ɶ�   
    int result = ackermann_non_recursive(m, n); // ������J�Ҩ�ơ]�D���j�����^
    auto stop = high_resolution_clock::now();   // �O�������ɶ�
    auto duration = duration_cast<milliseconds>(stop - start);// �p�����ɶ��A���ഫ���@��
    cout << "Ackermann �D���j����(" << m << ", " << n << ") = " << result << endl;
    cout << "����ɶ�: " << duration.count() << " ms" << endl;
    return 0;
}
