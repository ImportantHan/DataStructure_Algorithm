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
			// NewNode의 다음 노드는 헤드로 변경
			NewNode->SetNextNode(Head);
			// 가장 뒤 노드의 다음 노드*는 NewNode로 변경
			Head->GetPrevNode()->SetNextNode(NewNode);
			// NewNode의 이전 노드는 헤드의 이전노드로 변경 
			NewNode->SetPrevNode(Head->GetPrevNode());
			// 헤드의 이전 노드는 NewNode
			Head->SetPrevNode(NewNode);
		}
		Count++;
	}

	// 탐색
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