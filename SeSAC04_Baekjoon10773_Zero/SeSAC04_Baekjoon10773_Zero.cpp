#include <iostream>

using namespace std;

class Node {
private:
	int Data;
public:
	Node(int NewData) {
		Data = NewData;
	}
	
	~Node() {
	
	}

	int GetData() {
		return Data;
	}

	void SetData(int NewData) {
		Data = NewData;
	}
};

class ArrayStack {
public:
	int Capacity; // �뷮
	int Top; // �ֻ��� ��� ��ġ >> default -1
	Node* Nodes; // ��� �迭
private:
	ArrayStack(int NewCapacity) {
		Capacity = NewCapacity;
		Top = -1;
		Nodes = nullptr;
	}

	~ArrayStack() {

	}

	int GetCapacity() {
		return Capacity;
	}

	int GetTop() {
		return Top;
	}
	
	Node* GetNodes() {
		return Nodes;
	}

	void SetCapacity(int NewCapacity) {
		Capacity = NewCapacity;
	}
	
	// top�� �Ժη� �ٲٸ� �ȵǹǷ� Set����
	// Nodes�� �Ժη� �ٲٸ� �ȵǹǷ� Set����  

	// ���� ��� ����
	void CreateStack(ArrayStack Stack, int Capacity) {

	}

};

int main()
{
	

}
