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
	int Capacity; // 용량
	int Top; // 최상위 노드 위치 >> default -1
	Node* Nodes; // 노드 배열
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
	
	// top은 함부로 바꾸면 안되므로 Set생략
	// Nodes도 함부로 바꾸며 안되므로 Set생략  

	// 스택 노드 생성
	void CreateStack(ArrayStack Stack, int Capacity) {

	}

};

int main()
{
	

}
