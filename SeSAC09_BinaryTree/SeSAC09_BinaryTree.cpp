#include <iostream>

using namespace std;

class Node {
private:
    int Data;
    Node* LeftNode;
    Node* RightNode;

public:
    Node(int NewData) {
        Data = NewData;
        LeftNode = nullptr;
        RightNode = nullptr;
    }

    ~Node() {

    }

    int GetData() {
        return Data;
    }

    Node* GetLeftNode() {
        return LeftNode;
    }

    Node* GetRightNode() {
        return RightNode;
    }

    void SetData(int NewData) {
        Data = NewData;
    }

    void SetLeftNode(Node* NewLeftNode) {
        LeftNode = NewLeftNode;
    }

    void SetRightNode(Node* NewRightNode) {
        RightNode = NewRightNode;
    }
};

class BinaryTree {
public:
    // ������
    BinaryTree() {
        // cout << "����";
    }
    // �Ҹ���
    ~BinaryTree() {
        // cout << "�Ҹ�";
    }
    // ��� ����
    Node* CreateNode(int NewData) {
        return new Node(NewData);
    }
    // �� ��ȯ
    int GetData(Node* Node) {
        return Node->GetData();
    }
    // �� ����
    void SetData(Node* Node, int NewData) {
        Node->SetData(NewData);
    }
  
    //���� ��ȸ
    void PreorderPrint(Node* Node) {
        if (Node == nullptr) {
            return;
        }
        cout << Node->GetData() << " ";
        PreorderPrint(Node->GetLeftNode());
        PreorderPrint(Node->GetRightNode());
    }
    //���� ��ȸ
    void InorderPrint(Node* Node) {
        if (Node == nullptr) {
            return;
        }
        InorderPrint(Node->GetLeftNode());
        cout << Node->GetData() << " ";
        InorderPrint(Node->GetRightNode());
    }
    //���� ��ȸ
    void PostorderPrint(Node* Node) {
        if (Node == nullptr) {
            return;
        }
        PostorderPrint(Node->GetLeftNode());
        PostorderPrint(Node->GetRightNode());
        cout << Node->GetData() << " ";
    }
    //��� ����
    void RemoveNode(Node* Node) {
        if (Node == nullptr) {
            return;
        }
        RemoveNode(Node->GetLeftNode());
        RemoveNode(Node->GetRightNode());
        delete Node;
    }
};

void temp() {

    int N;
    char NodeName;
    BinaryTree* BTree = new BinaryTree;

    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> NodeName;
        }
    }

    BinaryTree* BTree = new BinaryTree;

    Node* Node1 = BTree->CreateNode(1);
    Node* Node2 = BTree->CreateNode(2);
    Node* Node3 = BTree->CreateNode(3);
    Node* Node4 = BTree->CreateNode(4);
    Node* Node5 = BTree->CreateNode(5);
    Node* Node6 = BTree->CreateNode(6);
    Node* Node7 = BTree->CreateNode(7);

    Node1->SetLeftNode(Node2);
    Node1->SetRightNode(Node3);
    Node2->SetLeftNode(Node4);
    Node2->SetRightNode(Node5);
    Node3->SetLeftNode(Node6);
    Node3->SetRightNode(Node7);
    
    cout << "���� : ";
    BTree->PreorderPrint(Node1);
    cout << "\n";

    cout << "���� : ";
    BTree->InorderPrint(Node1);
    cout << "\n";

    cout << "���� : ";
    BTree->PostorderPrint(Node1);
    cout << "\n";

}