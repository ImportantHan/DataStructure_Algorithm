#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N, P;
    int Sum = 0, Result = 0;
    vector<int> Arr;

    // ��� �� N �� �����ϴµ� �ɸ��� �ð� P �Է�
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> P;
        Arr.push_back(P);
    }

    // ���ð��� ���� ª���� �������� ����
    for (int i = Arr.size() - 1; i >= 0; i--) {
        for (int j = 0; j < i; j++) {
            if (Arr[j] > Arr[j + 1]) {
                int Temp = Arr[j];
                Arr[j] = Arr[j + 1];
                Arr[j + 1] = Temp;
            }
        }
    }

    // ���� �ð� �� - ��ª�� �� �� ������,,,?
    for (int i = 0; i < Arr.size(); i++) {
        Sum += Arr[i];
        Result += Sum;
    }

    cout << Result;

    return 0;
}
