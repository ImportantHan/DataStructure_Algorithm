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

	// ���ʿ� ���ϱ� (��带 ���� �ڿ��� �����ؾ���, O(1)�� �ִ��� ���� ����� ����)
	void AddFrontNode(Node* NewNode) {
		if (NewNode == nullptr) return;

		// Head�� nullptr �� ��� Head�� NewNode�� ��
		if (Head == nullptr) {
			Head = NewNode;
		}
		// Head�� ���� ���
		else {
			// NewNode�� NextNode�� Head��
			NewNode->SetNextNode(Head->GetNextNode());
			NewNode->SetPrevNode(Head);
			
		}
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
		int M;
		cin >> M;
	}

	return 0;
}