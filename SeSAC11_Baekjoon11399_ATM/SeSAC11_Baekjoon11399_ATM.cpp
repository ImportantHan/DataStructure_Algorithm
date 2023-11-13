#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N, P;
    int Sum = 0, Result = 0;
    vector<int> Arr;

    // 사람 수 N 과 인출하는데 걸리는 시간 P 입력
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> P;
        Arr.push_back(P);
    }

    // 대기시간이 가장 짧도록 오름차순 정렬
    for (int i = Arr.size() - 1; i >= 0; i--) {
        for (int j = 0; j < i; j++) {
            if (Arr[j] > Arr[j + 1]) {
                int Temp = Arr[j];
                Arr[j] = Arr[j + 1];
                Arr[j + 1] = Temp;
            }
        }
    }

    // 인출 시간 합 - 더짧게 할 수 있을까,,,?
    for (int i = 0; i < Arr.size(); i++) {
        Sum += Arr[i];
        Result += Sum;
    }

    cout << Result;

    return 0;
}
