#include <iostream>
#include <vector>

using namespace std;


int main() {

    double N, M;
    string PostfixNotation;

    // N 과 후위표기식 출력
    cin >> N;
    cin >> PostfixNotation;

    // Vector 에 피연산자 숫자 대입 (같은 알파벳 여러번 나올 수 있으므로)
    vector<double> NumArr;
    for (int i = 0; i < N; i++) {
        cin >> M;
        NumArr.push_back(M);
    }

    vector<double> StackArr;
    double Result;
    for (int i = 0; i < PostfixNotation.size(); i++) {
        // 대문자 A~Z 일 경우 arr 의 알파벳과 매칭 되는 값을 가져옴
        if (PostfixNotation[i] >= 65 && PostfixNotation[i] <= 90) {
            StackArr.push_back(NumArr[PostfixNotation[i] - 65]);
        }
        // 사칙연산의 경우 스택에서 꺼내서 계산
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

    // C++로 소수점 2자리 표기법 알려주세요,,,ㅎㅎ
    // printf("%.2f", Result);
    cout << fixed;
    cout.precision(2);
    cout << Result;

    return 0;
}