/*
1번부터 N번까지 N개의 풍선이 원형으로 놓여 있고. i번 풍선의 오른쪽에는 i+1번 풍선이 있고, 왼쪽에는 i-1번 풍선이 있다.
단, 1번 풍선의 왼쪽에 N번 풍선이 있고, N번 풍선의 오른쪽에 1번 풍선이 있다.
각 풍선 안에는 종이가 하나 들어있고, 종이에는 -N보다 크거나 같고, N보다 작거나 같은 정수가 하나 적혀있다.
이 풍선들을 다음과 같은 규칙으로 터뜨린다.

우선, 제일 처음에는 1번 풍선을 터뜨린다.
다음에는 풍선 안에 있는 종이를 꺼내어 그 종이에 적혀있는 값만큼 이동하여 다음 풍선을 터뜨린다.
양수가 적혀 있을 경우에는 오른쪽으로, 음수가 적혀 있을 때는 왼쪽으로 이동한다.
이동할 때에는 이미 터진 풍선은 빼고 이동한다.

예를 들어 다섯 개의 풍선 안에 차례로 3, 2, 1, -3, -1이 적혀 있었다고 하자.
이 경우 3이 적혀 있는 1번 풍선, -3이 적혀 있는 4번 풍선, -1이 적혀 있는 5번 풍선, 1이 적혀 있는 3번 풍선, 2가 적혀 있는 2번 풍선의 순서대로 터지게 된다.

첫째 줄에 자연수 N(1 ≤ N ≤ 1,000)이 주어진다.
다음 줄에는 차례로 각 풍선 안의 종이에 적혀 있는 수가 주어진다.
종이에 0은 적혀있지 않다.

입력 :
5
3 2 1 -3 -1

출력:
1 4 5 3 2
*/

// Circular Doubly Linked List를 이용한 풀이

#include <iostream>
#include <vector>

using namespace std;

class CDLL_Node {
private:
    int Data;
    int Num;
    CDLL_Node* NextNode;
    CDLL_Node* PrevNode;

public:
    CDLL_Node(int NewData, int NewNum) {
        Data = NewData;
        Num = NewNum;
        NextNode = nullptr;
        PrevNode = nullptr;
    }

    ~CDLL_Node() {

    }

    int GetData() {
        return Data;
    }

    int GetNum() {
        return Num;
    }

    CDLL_Node* GetNextNode() {
        return NextNode;
    }

    CDLL_Node* GetPrevNode() {
        return PrevNode;
    }

    void SetData(int NewData) {
        Data = NewData;
    }

    void SetNextNode(CDLL_Node* NewNextNode) {
        NextNode = NewNextNode;
    }

    void SetPrevNode(CDLL_Node* NewPrevNode) {
        PrevNode = NewPrevNode;
    }
};

class CircularDoubleLinkedList {
private:
    CDLL_Node* Head;
    int Count;

public:
    CircularDoubleLinkedList() {
        Head = nullptr;
        Count = 0;
    }

    ~CircularDoubleLinkedList() {
    }

    // 노드 생성
    CDLL_Node* CreateNode(int NewData, int NewNum) {
        return new CDLL_Node(NewData, NewNum);
    }

    // 노드 삭제
    void DeleteNode(CDLL_Node* DeleteNode) {
        delete DeleteNode;
    }

    // 추가
    void AppendNode(CDLL_Node* NewNode) {
        if (NewNode == nullptr) return;

        if (Head == nullptr) {
            Head = NewNode;
            Head->SetNextNode(Head);
            Head->SetPrevNode(Head);
        }
        else {
            NewNode->SetNextNode(Head);
            Head->GetPrevNode()->SetNextNode(NewNode);
            NewNode->SetPrevNode(Head->GetPrevNode());
            Head->SetPrevNode(NewNode);
        }
        Count++;
    }

    CDLL_Node* T_FindNode(int Location) {

        CDLL_Node* CurrentNode = Head;

        if (Location > 0) {
            while (--Location > 0) {
                CurrentNode = CurrentNode->GetNextNode();
            }
        }
        else if (Location < 0) {
            while (++Location < 0)
            {
                CurrentNode = CurrentNode->GetPrevNode();
            }
        }
        return CurrentNode;
    }

    void T_RemoveNode(CDLL_Node* TargetNode) {
        CDLL_Node* temp = TargetNode;
        TargetNode->GetPrevNode()->SetNextNode(temp->GetNextNode());
        TargetNode->GetNextNode()->SetPrevNode(temp->GetPrevNode());
        Head = TargetNode->GetNextNode();

        delete TargetNode;
        Count--;
    }
};


int S02_Baekjoon2346_BalloonPop()
{
    int N;
    cin >> N;

    CircularDoubleLinkedList* List = new CircularDoubleLinkedList();

    int data;
    vector<int> arr;
    for (int i = 0; i < N; i++) {
        cin >> data;
        arr.push_back(data);
        List->AppendNode(List->CreateNode(arr[i], i + 1));
    }

    int RemoveBallon = 0;
    for (int i = 0; i < N; i++) {
        int temp = List->T_FindNode(RemoveBallon)->GetData();
        int ResultCount = List->T_FindNode(RemoveBallon)->GetNum();
        cout << ResultCount << " ";
        List->T_RemoveNode(List->T_FindNode(RemoveBallon));
        if (temp >= 0) {
            RemoveBallon = temp;
        }
        else {
            RemoveBallon = temp - 1;
        }
    }

    return 0;
}