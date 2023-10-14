#include <iostream>
using namespace std;

typedef struct Node
{
	int Data;
	Node* PrevNode;
	Node* NextNode;

	Node(int NewData) : Data(NewData), PrevNode(nullptr), NextNode(nullptr) {}
}Node;

class DoubleLinkedList
{
public:
	DoubleLinkedList() : Head(nullptr), Tail(nullptr), Count(0) { }
	~DoubleLinkedList()
	{
		while (Head != nullptr)
		{
			Node* DeleteTarget = Head;
			Head = Head->NextNode;
			delete DeleteTarget;
		}
	}

	// 1. 생성
	Node* CreateNode(int NewData)
	{
		return new Node(NewData);
	}
	// 1. 소멸
	void DeleteNode(Node* DeleteTarget)
	{
		if (DeleteTarget != nullptr) delete DeleteTarget;
	}

	// 2. 추가
	void AddNode(Node* NewNode)
	{
		if (NewNode == nullptr) return;

		if (Head == nullptr)
		{
			Head = NewNode;
			Tail = NewNode;
		}
		else
		{
			NewNode->PrevNode = Tail;
			Tail->NextNode = NewNode;
			Tail = NewNode;
		}

		Count++;

		Print();
	}

	// 3. 탐색
	Node* FindNode(int Location)
	{
		if (Location < 0 || Location >= Count) return nullptr;

		Node* TargetNode;
		if (Location < Count / 2)
		{
			TargetNode = Head;
			while (TargetNode != nullptr && --Location >= 0)
			{
				TargetNode = TargetNode->NextNode;
			}
		}
		else
		{
			Location = Count - Location - 1;
			TargetNode = Tail;
			while (TargetNode != nullptr && --Location >= 0)
			{
				TargetNode = TargetNode->PrevNode;
			}
		}

		return TargetNode;
	}

	// 4. 삭제
	void RemoveNode(Node* RemoveTarget)
	{
		if (Head == nullptr || RemoveTarget == nullptr) return;

		if (Head == RemoveTarget)
		{
			Head = RemoveTarget->NextNode;
			Head->PrevNode = nullptr;
			if (Head == nullptr) Tail = nullptr;
		}
		else if (Tail == RemoveTarget)
		{
			Tail = Tail->PrevNode;
			Tail->NextNode = nullptr;
			// 이미 원소 1개는 1번 if 에서 걸렀으므로 예외처리 필요 없음
		}
		else
		{
			RemoveTarget->PrevNode->NextNode = RemoveTarget->NextNode;
			RemoveTarget->NextNode->PrevNode = RemoveTarget->PrevNode;
		}

		DeleteNode(RemoveTarget);
		Count--;

		Print();
	}

	// 5. 삽입(뒤)
	void InsertNode(Node* Current, Node* NewNode)
	{
		if (Current == nullptr || NewNode == nullptr) return;

		if (Current == Tail)
		{
			Tail->NextNode = NewNode;
			NewNode->PrevNode = Tail;

			Tail = NewNode;
		}
		else
		{
			NewNode->PrevNode = Current;
			NewNode->NextNode = Current->NextNode;
			Current->NextNode->PrevNode = NewNode;
			Current->NextNode = NewNode;
		}

		Count++;

		Print();
	}

	// 6. 원소 수 세기
	int GetCount()
	{
		return Count;
	}

	void Print()
	{
		cout << Count << " : ";
		Node* Current = Head;
		while (Current != nullptr)
		{
			cout << Current->Data << ' ';
			Current = Current->NextNode;
		}
		cout << '\n';
	}

private:
	Node* Head;
	Node* Tail;
	int Count;
};

int main()
{
	DoubleLinkedList* DLL = new DoubleLinkedList();

	DLL->AddNode(DLL->CreateNode(10));
	DLL->AddNode(DLL->CreateNode(20));
	DLL->AddNode(DLL->CreateNode(30));
	DLL->AddNode(DLL->CreateNode(40));

	DLL->InsertNode(DLL->FindNode(0), DLL->CreateNode(50));
	DLL->InsertNode(DLL->FindNode(DLL->GetCount() - 1), DLL->CreateNode(60));
	DLL->InsertNode(DLL->FindNode(DLL->GetCount() - 2), DLL->CreateNode(70));

	DLL->RemoveNode(DLL->FindNode(0));
	DLL->RemoveNode(DLL->FindNode(DLL->GetCount() - 1));
	DLL->RemoveNode(DLL->FindNode(2));

	delete DLL;

	return 0;
}