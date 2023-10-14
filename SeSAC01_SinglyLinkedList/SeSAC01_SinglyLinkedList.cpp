#include <iostream>
#include <vector>
using namespace std;

vector<int> V;

typedef struct Node
{
	int Data;
	Node* NextNode;

	// 1. 생성 / 소멸
	Node(int NewData) : Data(NewData), NextNode(nullptr) {}

} Node;

typedef struct SingleLinkedList
{
	Node* Head;

	SingleLinkedList()
	{
		Head = nullptr;
	}

	~SingleLinkedList()
	{
		while (Head != nullptr)
		{
			Node* DeleteNode = Head;
			Head = Head->NextNode;
			delete DeleteNode;
		}
	}
	// 1. 생성
	Node* CreateNode(int NewData)
	{
		Node* NewNode = new Node(NewData);

		return NewNode;
	}

	// 1. 소멸
	void DeleteNode(Node* DeleteTarget)
	{
		delete DeleteTarget;
	}

	// 2. 추가
	void AddNode(Node* NewNode)
	{
		if (Head == nullptr)
		{
			Head = NewNode;
		}
		else
		{
			// Head != NULL;

			// Find Tail
			Node* Tail = Head;
			while (Tail->NextNode != nullptr)
			{
				Tail = Tail->NextNode;
			}

			Tail->NextNode = NewNode;
		}

		Print();
	}

	// 3. 탐색
	Node* FindNode(int Location)
	{
		Node* Current = Head;

		while (Current != nullptr && --Location >= 0)
		{
			Current = Current->NextNode;
		}

		return Current;
	}

	// 5. 삽입 (뒤)
	void InsertNodeAfter(Node* Current, Node* NewNode)
	{
		NewNode->NextNode = Current->NextNode;
		Current->NextNode = NewNode;

		Print();
	}

	// 7. 삽입 (앞)
	void InsertNodeBefore(Node* Current, Node* NewNode)
	{
		if (Current == Head)
		{
			NewNode->NextNode = Current;

			Head = NewNode;
		}
		else
		{
			Node* BeforeNode = Head;

			while (BeforeNode != nullptr && BeforeNode->NextNode != Current)
			{
				BeforeNode = BeforeNode->NextNode;
			}

			if (BeforeNode != nullptr)
			{
				NewNode->NextNode = Current;
				BeforeNode->NextNode = NewNode;
			}
		}

		Print();
	}

	// 4. 삭제
	void RemoveNode(Node* Remove)
	{
		Node* Current = Head;

		if (Head == Remove)
		{
			Head = Head->NextNode;
			DeleteNode(Remove);
		}
		else
		{
			while (Current != nullptr && Current->NextNode != Remove)
			{
				Current = Current->NextNode;
			}

			if (Current != nullptr)
			{
				Current->NextNode = Remove->NextNode;
				DeleteNode(Remove);
			}
		}

		Print();
	}

	// 6. 노드 수 세기
	int CountNode()
	{
		Node* Current = Head;
		int Count = 0;

		while (Current != nullptr)
		{
			Count++;
			Current = Current->NextNode;
		}

		return Count;
	}

	// 8. 해당 위치부터 뒤로 전부 삭제
	void RemoveAll(Node* List)
	{
		if (List != Head)
		{
			// Find BeforeNode
			Node* Current = Head;
			while (Current != nullptr && Current->NextNode != List)
			{
				Current = Current->NextNode;
			}
			if (Current != nullptr)
			{
				Current->NextNode = nullptr;
			}
		}
		else
		{
			Head = nullptr;
		}


		while (List != nullptr)
		{
			Node* DeleteTarget = List;
			List = List->NextNode;

			DeleteNode(DeleteTarget);
		}

		Print();
	}

	void Print()
	{
		cout << CountNode() << " : ";
		Node* Current = Head;

		while (Current != nullptr)
		{
			cout << Current->Data << ' ';
			Current = Current->NextNode;
		}
		cout << '\n';
	}


} SingleLinkedList;

int main()
{
	SingleLinkedList* SLL = new SingleLinkedList();

	SLL->AddNode(new Node(10));
	SLL->AddNode(new Node(20));
	SLL->AddNode(new Node(30));

	SLL->RemoveNode(SLL->FindNode(1));
	SLL->RemoveNode(SLL->FindNode(0));

	SLL->InsertNodeAfter(SLL->FindNode(0), SLL->CreateNode(40));
	SLL->InsertNodeAfter(SLL->FindNode(0), SLL->CreateNode(50));
	SLL->InsertNodeAfter(SLL->FindNode(0), SLL->CreateNode(60));

	SLL->InsertNodeBefore(SLL->FindNode(0), SLL->CreateNode(70));
	SLL->InsertNodeBefore(SLL->FindNode(1), SLL->CreateNode(80));
	SLL->InsertNodeBefore(SLL->FindNode(SLL->CountNode() - 1), SLL->CreateNode(90));

	SLL->RemoveAll(SLL->FindNode(4));



	delete SLL;

	return 0;
}