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

    ~Node() {

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
    int Size;
public:
    CDLL() {
        Head = nullptr;
        Size = 0;
    }

    ~CDLL() {
        while (Head != nullptr) {
            Node* CurrentNode = Head;
            Head = Head->GetNextNode();
            delete CurrentNode;
        }
     }

    Node* GetHead() {
        return Head;
    }

    int GetSize() {
        return Size;
    }

    Node* CreateNode(int NewData) {
        return new Node(NewData);
    }

    void DeleteNode(Node* DeleteNode) {
        delete DeleteNode;
    }

    // 노드 추가 메소드
    void AppendNode(Node* NewNode) {
        if (Head == nullptr) {
            Head = NewNode;
            NewNode->SetNextNode(Head);
            NewNode->SetPrevNode(Head);
        }
        else {
            NewNode->SetNextNode(Head);
            Head->GetPrevNode()->SetNextNode(NewNode);
            NewNode->SetPrevNode(Head->GetPrevNode());
            Head->SetPrevNode(NewNode);
        }
        Size++;
    }

    // 요세푸스 순열 메소드
    void JosephusPermutation(int Location) {

        cout << "<";
        while (true) {
            Node* CurrentNode = Head;

            // Location을 매 반복마다 유지시켜 주기 위해 설정
            int T_Location = Location;

            // 중단점 설정 - Head 본인 밖에 안남았을 경우 본인 데이터 출력 후 반복문 종료
            if (Head->GetNextNode() == Head && Head->GetPrevNode() == Head) {
                cout << Head->GetData();
                break;
            }

            // Location만큼 이동
            while (--T_Location > 0) {
                CurrentNode = CurrentNode->GetNextNode();
            }

            // 출력
            cout << CurrentNode->GetData() << ", ";

            // Head 변경, 사이즈 축소, CurrentNode 제거
            CurrentNode->GetNextNode()->SetPrevNode(CurrentNode->GetPrevNode());
            CurrentNode->GetPrevNode()->SetNextNode(CurrentNode->GetNextNode());
            Head = CurrentNode->GetNextNode();
            Size--;
            delete CurrentNode;
        }
        cout << ">";
    }

    void PrintNode() {
        Node* CurrentNode = Head;

        cout << Size << " : ";

        for (int i = 0; i < Size; i++) {
            cout << "(" << CurrentNode->GetPrevNode()->GetData() << ")" << CurrentNode->GetData() << "(" << CurrentNode->GetNextNode()->GetData() << ") ";
            CurrentNode = CurrentNode->GetNextNode();
        }
        cout << "\n";
    }
};

int main()
{
    int N, K;
    cin >> N >> K;

    CDLL* List = new CDLL();

    for (int i = 0; i < N; i++) {
        List->AppendNode(List->CreateNode(i + 1));
    }

    List->JosephusPermutation(K);
}