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

    // ��� ����
    Node* CreateNode(int NewData) {
        return new Node(NewData);
    }

    // ��� ����
    void DeleteNode(Node* DeleteNode) {
        delete DeleteNode;
    }

    // �߰�
    void AppendNode(Node* NewNode) {
        if (NewNode == nullptr) return;

        // Head�� nullptr �� ��� Head�� NewNode�� ��
        if (Head == nullptr) {
            Head = NewNode;
            Head->SetNextNode(Head);
            Head->SetPrevNode(Head);
        }
        // Head�� ���� ���
        else {
            NewNode->SetNextNode(Head);
            Head->GetPrevNode()->SetNextNode(NewNode);
            NewNode->SetPrevNode(Head->GetPrevNode());
            Head->SetPrevNode(NewNode);
        }
        Count++;
    }

    // �߰� Ư����� ��
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

    // Ž��
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

    // ����
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

    // ���
    void PrintNode() {
        cout << Count << " : ";
        Node* Current = Head;
        for (int i = 0; i < Count; i++) {
            cout << "(" << Current->GetPrevNode()->GetData() << ")" << Current->GetData() << "(" << Current->GetNextNode()->GetData() << ") ";
            Current = Current->GetNextNode();
        }
        cout << "\n";
    }

    // ��ü ��� ����
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

    cout << "ó�� ������ CDLL >> ";
    List->PrintNode();
    cout << "\n";

    cout << "2�� ��� : " << List->GetNodeAt(2)->GetData() << "\n";
    cout << "4�� ��� : " << List->GetNodeAt(4)->GetData() << "\n";
    cout << "\n";

    cout << "2�� ��� �ڿ� 22 �߰� �� ����Ʈ >> ";
    List->InsertNode(List->GetNodeAt(2), List->CreateNode(22));
    List->PrintNode();
    cout << "4�� ��� �ڿ� 44 �߰� �� ����Ʈ >> ";
    List->InsertNode(List->GetNodeAt(4), List->CreateNode(44));
    List->PrintNode();
    cout << "\n";

    cout << "3�� ��� ���� �� ����Ʈ : ";
    List->RemoveNode(List->GetNodeAt(3));
    List->PrintNode();

    return 0;
}