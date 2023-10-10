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

	// 앞쪽에 더하기 (헤드를 가장 뒤에로 지정해야함, O(1)을 최대한 많이 만들기 위해)
	void AddFrontNode(Node* NewNode) {
		if (NewNode == nullptr) return;

		// Head가 nullptr 일 경우 Head는 NewNode가 됨
		if (Head == nullptr) {
			Head = NewNode;
		}
		// Head가 있을 경우
		else {
			// NewNode의 NextNode는 Head의
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