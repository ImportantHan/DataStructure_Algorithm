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
			// NewNode�� ���� ���� ���� ����
			NewNode->SetNextNode(Head);
			// ���� �� ����� ���� ���*�� NewNode�� ����
			Head->GetPrevNode()->SetNextNode(NewNode);
			// NewNode�� ���� ���� ����� �������� ���� 
			NewNode->SetPrevNode(Head->GetPrevNode());
			// ����� ���� ���� NewNode
			Head->SetPrevNode(NewNode);
		}
		Count++;
	}

	// Ž��
	Node* GetNodeAt(int Location) {
		if (Location < 0 || Location > Count) return nullptr;

		Node* CurrentNode = Head;

		if (Location <= Count / 2) {
			while (CurrentNode != nullptr && --Location >= 0) {
				CurrentNode = CurrentNode->GetNextNode();
			}
		} else {
			Location = Count - Location + 1;
			while (CurrentNode != nullptr && --Location >= 0) {
				CurrentNode = CurrentNode->GetPrevNode();
			}
		}
		return CurrentNode;
	}


	int GetCount() {
		return Count;
	}
};

int S02_Baekjoon2346_BalloonPop() {
	int N;
	cin >> N;

	CDLL* List = new CDLL();

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		List->AppendNode(List->CreateNode(num));
	}

	cout << List->GetNodeAt(4)->GetData() << "\n";


	return 0;
}