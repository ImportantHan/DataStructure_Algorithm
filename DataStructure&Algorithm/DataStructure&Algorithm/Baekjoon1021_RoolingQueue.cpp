#include <iostream>

using namespace std;

//노드 struct 구현 (data값과 nextNode가 존재)
struct node {
	int data;
	node* nextNode;
};

//링크드 리스트 클래스 생성
class LinkedList {
private:
	node* head;
	node* tail;
public:
	LinkedList() {
		//head 와 tail의 포인터를 초기화;
		head = NULL;
		tail = NULL;
	}
	//첫번째의 node 추가
	void addFrontNode(int n);
	//마지막의 node 추가
	void addNode(int n);

	//node 삽입
	void insertNode(node* prevNode, int n);
	//node 삭제
	void deleteNode(node* prevNode);

	//첫번째 노드 가져오기
	node* getHead() {
		return head;
	}
	//LinkedList 출력
	void display(node* head);
};

//첫번째의 node 추가
void LinkedList::addFrontNode(int n) {
	node* temp = new node;
	//temp의 데이터는 n
	temp->data = n;

	//LinkedList가 비어있으면
	if (head == NULL) {
		//첫 node는 temp
		head = temp;
		//마지막 node는 temp
		tail = temp;
	}
	//LinkedList에 데이터가 있으면
	else {
		//temp의 nextNode는 head
		temp->nextNode = head;
		//head는 temp
		head = temp;
	}
}

//마지막의 node 추가
void LinkedList::addNode(int n) {
	node* temp = new node;

	//temp의 데이터는 n
	temp->data = n;
	//temp의 nextNode = NULL값
	temp->nextNode = NULL;

	//LinkedList가 비어있으면
	if (head == NULL) {
		//첫 node는 temp
		head = temp;
		//마지막 node는 temp
		tail = temp;
	}
	//LinkedList에 데이터가 있으면
	else {
		//현재 마지막 node의 nextNode는 temp
		tail->nextNode = temp;
		//마지막 node는 temp
		tail = temp;
	}
}

//node 삽입
void LinkedList::insertNode(node* prevNode, int n) {
	node* temp = new node;
	//temp의 데이터는 n
	temp->data = n;

	//temp의 nextNode 저장
	//(삽입 할 앞 node의 nextNode를 temp의 nextNode에 저장)
	temp->nextNode = prevNode->nextNode;

	//temp 삽입
	//temp앞의 node의 nextNode를 temp로 저장
	prevNode->nextNode = temp;
}

//node 삭제
void LinkedList::deleteNode(node* prevNode) {

	//삭제할 node를 temp에 저장
	//(삭제할 node의 1단계 전 node의 nextNode) 
	node* temp = prevNode->nextNode;

	//삭제할 node를 제외
	//(삭제할 node의 nextNode를 1단계 전 node의 nextNode에 저장)
	prevNode->nextNode = temp->nextNode;

	//temp 삭제
	delete temp;
}

//LinkedList 출력
void LinkedList::display(node* head) {
	if (head == NULL) {
		cout << "\n";
	}
	else {
		cout << head->data << " ";
		display(head->nextNode);
	}
	cout << endl;
}

int Baekjoon1021_RollingQueue() {

	int N, M;
	cin >> N >> M;

	LinkedList SSL;

	for (int i = 0; i < N; i++) {
		SSL.addFrontNode(i);
	}



	return 0;
}