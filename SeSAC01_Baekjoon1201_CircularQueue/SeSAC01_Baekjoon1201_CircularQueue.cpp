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
    // Node(int NewData) : Data(NewData), NextNode(nullptr), PrevNode(nullptr) {}

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

    int SetData(int NewData) {
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
    // CDLL() : Head(nullptr), Size(0) {}

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

    // ��ũ�� ����Ʈ�� ��� �߰�
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

    // 1�� ���� ��� �̾Ƴ���
    void RemoveHead() {
        Node* Temp = Head;

        Head->GetPrevNode()->SetNextNode(Temp->GetNextNode());
        Head->GetNextNode()->SetPrevNode(Temp->GetPrevNode());
        Head = Head->GetNextNode();

        Size--;
    }

    // 2, 3�� ���� �¿�� �̵�
    int MoveNode(int Location) {
        int Left = 0;
        int Right = 0;

        // �������� �ϳ��� �̵��ϴ� Ƚ�� ī��Ʈ
        Node* CurrentNode = Head;
        while (CurrentNode->GetData() != Location) {
            CurrentNode = CurrentNode->GetNextNode();
            Left++;
        }

        // �������� �ϳ��� �̵��ϴ� Ƚ�� ī��Ʈ
        CurrentNode = Head;
        while (CurrentNode->GetData() != Location) {
            CurrentNode = CurrentNode->GetPrevNode();
            Right++;
        }

        // ��忡 Ž���� ��ģ ��� ����
        Head = CurrentNode;
        // ��� ���������� ���� ����
        RemoveHead();

        if (Left < Right) {
            // cout << "Left : " << Left << "\n";
            return Left;
        }
        else {
            // cout << "Right : " << Right << "\n";
            return Right;
        }
    }

    // ��ü ��� ����Ʈ �Լ�
    void PrintList() {
        cout << Size << " : ";
        Node* CurrentNode = Head;
        for (int i = 0; i < Size; i++) {
            cout << "(" << CurrentNode->GetPrevNode()->GetData() << ")" << CurrentNode->GetData() << "(" << CurrentNode->GetNextNode()->GetData() << ") ";
            CurrentNode = CurrentNode->GetNextNode();
        }
        cout << "\n";
    }

};

/*
    ó���� �̾Ƽ� �ٽ� �ִ� �� �� �˰� ������..
    RemoveHead()�� �̾Ƽ� ��������
*/
int main() {
    int N, M, Select;
    cin >> N >> M;

    CDLL* List = new CDLL();

    for (int i = 0; i < N; i++) {
        List->AppendNode(List->CreateNode(i + 1));
    }

    int Answer = 0;
    for (int i = 0; i < M; i++) {
        cin >> Select;
        if (List->GetHead()->GetData() == Select) {
            List->RemoveHead();
        }
        else {
            Answer += List->MoveNode(Select);
        }
        // List->PrintList();
    }
    cout << Answer;

    return 0;
}