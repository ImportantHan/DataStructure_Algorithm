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


int main()
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