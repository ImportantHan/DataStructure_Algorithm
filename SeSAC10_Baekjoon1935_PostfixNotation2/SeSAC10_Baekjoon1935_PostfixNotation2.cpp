#include <iostream>
#include <vector>

using namespace std;


int main() {

    double N, M;
    string PostfixNotation;

    // N �� ����ǥ��� ���
    cin >> N;
    cin >> PostfixNotation;

    // Vector �� �ǿ����� ���� ���� (���� ���ĺ� ������ ���� �� �����Ƿ�)
    vector<double> NumArr;
    for (int i = 0; i < N; i++) {
        cin >> M;
        NumArr.push_back(M);
    }

    vector<double> StackArr;
    double Result;
    for (int i = 0; i < PostfixNotation.size(); i++) {
        // �빮�� A~Z �� ��� arr �� ���ĺ��� ��Ī �Ǵ� ���� ������
        if (PostfixNotation[i] >= 65 && PostfixNotation[i] <= 90) {
            StackArr.push_back(NumArr[PostfixNotation[i] - 65]);
        }
        // ��Ģ������ ��� ���ÿ��� ������ ���
        else {
            double Temp2 = StackArr.back();
            StackArr.pop_back();
            double Temp1 = StackArr.back();
            StackArr.pop_back();

            if (PostfixNotation[i] == '+') {
                Result = Temp1 + Temp2;
            }
            if (PostfixNotation[i] == '-') {
                Result = Temp1 - Temp2;
            }
            if (PostfixNotation[i] == '*') {
                Result = Temp1 * Temp2;
            }
            if (PostfixNotation[i] == '/') {
                Result = Temp1 / Temp2;
            }
            StackArr.push_back(Result);
        }
    }

    // C++�� �Ҽ��� 2�ڸ� ǥ��� �˷��ּ���,,,����
    // printf("%.2f", Result);
    cout << fixed;
    cout.precision(2);
    cout << Result;

    return 0;
}