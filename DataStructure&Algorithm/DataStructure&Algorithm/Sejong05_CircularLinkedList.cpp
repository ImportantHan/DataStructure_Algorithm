#include <iostream>

using namespace std;

class Node {
private:
    int Data;
    Node* NextNode;
    Node* PrevNode;

public:
    Node(int NewData) {
        Data = NewData;
        NextNode = nullptr;
        PrevNode = nullptr;
    }

    int GetData() {
        return Data;
    }

    Node* GetNextNode() {
        return NextNode;
    }

    Node* GetPrevNode() {
        return PrevNode;
    }

    void SetData(int NewData) {
        Data = NewData;
    }

    void SetNextNode(Node* NewNextNode) {
        NextNode = NewNextNode;
    }

    void SetPrevNode(Node* NewPrevNode) {
        PrevNode = NewPrevNode;
    }
};

class CDLL {
private:
    Node* Head;
    int Count;

public:
    CDLL() {
        Head = nullptr;
        Count = 0;
    }

    ~CDLL() {
    }

    // 노드 생성
    Node* CreateNode(int NewData) {
        return new Node(NewData);
    }

    // 노드 삭제
    void DeleteNode(Node* DeleteNode) {
        delete DeleteNode;
    }

    // 추가
    void AppendNode(Node* NewNode) {
        if (NewNode == nullptr) return;

        // Head가 nullptr 일 경우 Head는 NewNode가 됨
        if (Head == nullptr) {
            Head = NewNode;
            Head->SetNextNode(Head);
            Head->SetPrevNode(Head);
        }
        // Head가 있을 경우
        else {
            NewNode->SetNextNode(Head);
            Head->GetPrevNode()->SetNextNode(NewNode);
            NewNode->SetPrevNode(Head->GetPrevNode());
            Head->SetPrevNode(NewNode);
        }
        Count++;
    }

    // 추가 특정노드 뒤
    void InsertNode(Node* TargetNode, Node* NewNode) {
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

    // 탐색
    Node* GetNodeAt(int Location) {
        if (Location < 0 || Location > Count) return nullptr;

        Node* CurrentNode = Head;

        if (Location < Count / 2) {
            while (CurrentNode != nullptr && --Location >= 0) {
                CurrentNode = CurrentNode->GetNextNode();
            }
        }
        else {
            Location = Count - Location;
            while (CurrentNode != nullptr && --Location >= 0) {
                CurrentNode = CurrentNode->GetPrevNode();
            }
        }
        return CurrentNode;
    }

    // 삭제
    void RemoveNode(Node* TargetNode) {
        if (Head == nullptr || TargetNode == nullptr) return;

        if (TargetNode == Head) {
            TargetNode->GetPrevNode()->SetNextNode(Head->GetNextNode());
            TargetNode->GetNextNode()->SetPrevNode(Head->GetPrevNode());
            Head = TargetNode->GetNextNode();
        }
        else {
            Node* Temp = TargetNode;
            TargetNode->GetPrevNode()->SetNextNode(Temp->GetNextNode());
            TargetNode->GetNextNode()->SetPrevNode(Temp->GetPrevNode());
        }

        delete TargetNode;
        Count--;
    }

    // 출력
    void PrintNode() {
        cout << Count << " : ";
        Node* Current = Head;
        for (int i = 0; i < Count; i++) {
            cout << "(" << Current->GetPrevNode()->GetData() << ")" << Current->GetData() << "(" << Current->GetNextNode()->GetData() << ") ";
            Current = Current->GetNextNode();
        }
        cout << "\n";
    }

    // 전체 노드 갯수
    int GetCount() {
        return Count;
    }
};


int Sejong05_CircularLinkedList()
{
    int N;
    cin >> N;

    CDLL* List = new CDLL();

    for (int i = 0; i < N; i++) {
        int data;
        cin >> data;
        List->AppendNode(List->CreateNode(data));
    }

    cout << "처음 생성된 CDLL >> ";
    List->PrintNode();
    cout << "\n";

    cout << "2번 노드 : " << List->GetNodeAt(2)->GetData() << "\n";
    cout << "4번 노드 : " << List->GetNodeAt(4)->GetData() << "\n";
    cout << "\n";

    cout << "2번 노드 뒤에 22 추가 후 프린트 >> ";
    List->InsertNode(List->GetNodeAt(2), List->CreateNode(22));
    List->PrintNode();
    cout << "4번 노드 뒤에 44 추가 후 프린트 >> ";
    List->InsertNode(List->GetNodeAt(4), List->CreateNode(44));
    List->PrintNode();
    cout << "\n";

    cout << "3번 노드 삭제 후 프린트 : ";
    List->RemoveNode(List->GetNodeAt(3));
    List->PrintNode();

    return 0;
}