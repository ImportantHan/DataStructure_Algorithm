#include <iostream>

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

    // ��� ����
    CDLL_Node* CreateNode(int NewData, int NewNum) {
        return new CDLL_Node(NewData, NewNum);
    }

    // ��� ����
    void DeleteNode(CDLL_Node* DeleteNode) {
        delete DeleteNode;
    }

    // �߰�
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

    // �߰� Ư����� ��
    void InsertNode(CDLL_Node* TargetNode, CDLL_Node* NewNode) {
        if (TargetNode == nullptr || NewNode == nullptr) return;

        if (TargetNode == Head) {
            NewNode->SetNextNode(Head);
            NewNode->SetPrevNode(Head->GetPrevNode());
            Head->GetPrevNode()->SetNextNode(NewNode);
            Head->SetPrevNode(NewNode);
            Head = NewNode;
        }
        else {
            NewNode->SetNextNode(TargetNode->GetNextNode());
            NewNode->SetPrevNode(TargetNode);
            TargetNode->GetNextNode()->SetPrevNode(NewNode);
            TargetNode->SetNextNode(NewNode);
        }
        Count++;
    }

    CDLL_Node* FindRight(int Location) {
        CDLL_Node* CurrentNode = Head;
        while (CurrentNode != nullptr && --Location >= 0) {
            CurrentNode = CurrentNode->GetNextNode();
        }

        return CurrentNode;
    }

    CDLL_Node* FindLeft(int Location) {
        CDLL_Node* CurrentNode = Head;
        while (CurrentNode != nullptr && ++Location <= 0) {
            CurrentNode = CurrentNode->GetPrevNode();
        }

        return CurrentNode;
    }

    //// ����
    //void RemoveNode(CDLL_Node* TargetNode) {
    //    if (Head == nullptr || TargetNode == nullptr) return;

    //    if (TargetNode == Head) {
    //        TargetNode->GetPrevNode()->SetNextNode(Head->GetNextNode());
    //        TargetNode->GetNextNode()->SetPrevNode(Head->GetPrevNode());
    //        Head = TargetNode->GetNextNode();
    //    }
    //    else {
    //        CDLL_Node* Temp = TargetNode;
    //        TargetNode->GetPrevNode()->SetNextNode(Temp->GetNextNode());
    //        TargetNode->GetNextNode()->SetPrevNode(Temp->GetPrevNode());
    //    }

    //    delete TargetNode;
    //    Count--;
    //}
 

    // ����
    //void RemoveRight(CDLL_Node* TargetNode) {
    //    if (Head == nullptr || TargetNode == nullptr) return;

    //    TargetNode->GetPrevNode()->SetNextNode(Head->GetNextNode());
    //    TargetNode->GetNextNode()->SetPrevNode(Head->GetPrevNode());
    //    Head = TargetNode->GetNextNode();

    //    delete TargetNode;
    //    Count--;
    //}

    //void RemoveLeft(CDLL_Node* TargetNode) {
    //    if (Head == nullptr || TargetNode == nullptr) return;

    //    TargetNode->GetPrevNode()->SetNextNode(Head->GetNextNode());
    //    TargetNode->GetNextNode()->SetPrevNode(Head->GetPrevNode());
    //    Head = TargetNode->GetPrevNode();

    //    delete TargetNode;
    //    Count--;
    //}

    void RemoveNode(CDLL_Node* TargetNode) {
        if (Head == nullptr || TargetNode == nullptr) return;

        TargetNode->GetPrevNode()->SetNextNode(Head->GetNextNode());
        TargetNode->GetNextNode()->SetPrevNode(Head->GetPrevNode());
        Head = TargetNode->GetNextNode();

        delete TargetNode;
        Count--;
    }

    // ���
    void Print() {
        cout << Count << " : ";
        CDLL_Node* Current = Head;
        for (int i = 0; i < Count; i++) {
            cout << Current->GetData() << "(" << Current->GetNum() << ") ";
            Current = Current->GetNextNode();
        }
        cout << "\n";
    }

    // ��ü ��� ����
    int GetCount() {
        return Count;
    }
};


int S02_Baekjoon2346_BalloonPop()
{
    int N;
    cin >> N;

    CircularDoubleLinkedList* List = new CircularDoubleLinkedList();

    for (int i = 0; i < N; i++) {
        int data;
        cin >> data;
        List->AppendNode(List->CreateNode(data, i + 1));
    }

    int RemoveBalloon = 0;
    for (int i = 0; i < N; i++) {
        if (RemoveBalloon >= 0) {
            int Move = List->FindRight(RemoveBalloon)->GetData();
            List->RemoveNode(List->FindRight(RemoveBalloon));
            if (Move >= 0) {
                RemoveBalloon = Move - 1;
            }
            else {
                RemoveBalloon = Move;
            }
        }
        else {
            int Move = List->FindLeft(RemoveBalloon)->GetData();
            List->RemoveNode(List->FindLeft(RemoveBalloon));
            if (Move >= 0) {
                RemoveBalloon = Move - 1;
            }
            else {
                RemoveBalloon = Move;
            }
        }

        cout << i + 1 << "ȸ ���� �� ����Ʈ >> ";
        List->Print();
    }

    return 0;
}