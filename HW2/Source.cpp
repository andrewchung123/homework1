#include <iostream>
#include <vector>
#include <chrono> 
using namespace std;
using namespace std::chrono;

void Powerset(vector<char>& set, vector<vector<char>>& powerset, vector<char>& currentSet, int index) {

    if (index == set.size()) {// �p�G��F�F���X�������A�N��e���l���[�J�쾭����
        powerset.push_back(currentSet);
        return;
    }
    Powerset(set, powerset, currentSet, index + 1);    // ����ܷ�e�����A���j�U�@�Ӥ���  
    currentSet.push_back(set[index]);   // ��ܷ�e�����A�[�J��l���û��j�U�@�Ӥ���
    Powerset(set, powerset, currentSet, index + 1);
    currentSet.pop_back();      // �^���A������e����
}

int main() {
    vector<char> set = { 'a', 'b', 'c' };
    vector<vector<char>> powerset;  // �s�񾭶�
    vector<char> currentSet;    // �s���e�l�� 
    auto start = high_resolution_clock::now();  // �}�l�ɶ�
    Powerset(set, powerset, currentSet, 0);// �p�⾭��   
    auto stop = high_resolution_clock::now();   // �����ɶ�   
    auto duration = duration_cast<microseconds>(stop - start); // �p�����ɶ�
    cout << "powerset������ɶ�: " << duration.count() << " ms" << endl;
    cout << "Powerset���j�p: " << powerset.size() << endl;
    cout << "Powerset ���G:" << endl;
    for (const auto& subset : powerset) {
        cout << "{ ";
        for (char elem : subset) {
            cout << elem << " ";
        }
        cout << "}" << endl;
    }
    return 0;
}
