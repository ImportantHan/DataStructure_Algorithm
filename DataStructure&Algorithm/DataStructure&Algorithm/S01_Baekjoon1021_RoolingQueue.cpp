#include <iostream>

using namespace std;

//��� struct ���� (data���� nextNode�� ����)
struct node {
	int data;
	node* nextNode;
};

//��ũ�� ����Ʈ Ŭ���� ����
class LinkedList {
private:
	node* head;
	node* tail;
public:
	LinkedList() {
		//head �� tail�� �����͸� �ʱ�ȭ;
		head = NULL;
		tail = NULL;
	}
	//ù��°�� node �߰�
	void addFrontNode(int n);
	//�������� node �߰�
	void addNode(int n);

	//node ����
	void insertNode(node* prevNode, int n);
	//node ����
	void deleteNode(node* prevNode);

	//ù��° ��� ��������
	node* getHead() {
		return head;
	}
	//LinkedList ���
	void display(node* head);
};

//ù��°�� node �߰�
void LinkedList::addFrontNode(int n) {
	node* temp = new node;
	//temp�� �����ʹ� n
	temp->data = n;

	//LinkedList�� ���������
	if (head == NULL) {
		//ù node�� temp
		head = temp;
		//������ node�� temp
		tail = temp;
	}
	//LinkedList�� �����Ͱ� ������
	else {
		//temp�� nextNode�� head
		temp->nextNode = head;
		//head�� temp
		head = temp;
	}
}

//�������� node �߰�
void LinkedList::addNode(int n) {
	node* temp = new node;

	//temp�� �����ʹ� n
	temp->data = n;
	//temp�� nextNode = NULL��
	temp->nextNode = NULL;

	//LinkedList�� ���������
	if (head == NULL) {
		//ù node�� temp
		head = temp;
		//������ node�� temp
		tail = temp;
	}
	//LinkedList�� �����Ͱ� ������
	else {
		//���� ������ node�� nextNode�� temp
		tail->nextNode = temp;
		//������ node�� temp
		tail = temp;
	}
}

//node ����
void LinkedList::insertNode(node* prevNode, int n) {
	node* temp = new node;
	//temp�� �����ʹ� n
	temp->data = n;

	//temp�� nextNode ����
	//(���� �� �� node�� nextNode�� temp�� nextNode�� ����)
	temp->nextNode = prevNode->nextNode;

	//temp ����
	//temp���� node�� nextNode�� temp�� ����
	prevNode->nextNode = temp;

	// ******
	// tail ���Ŀ� insert�� ��쿡 ���� �ڵ� �ʿ�
}

//node ����
void LinkedList::deleteNode(node* prevNode) {

	//������ node�� temp�� ����
	//(������ node�� 1�ܰ� �� node�� nextNode) 
	node* temp = prevNode->nextNode;

	//������ node�� ����
	//(������ node�� nextNode�� 1�ܰ� �� node�� nextNode�� ����)
	prevNode->nextNode = temp->nextNode;

	//temp ����
	delete temp;
}

//LinkedList ���
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

int S01_Baekjoon1021_RoolingQueue() {

	int N, M;
	cin >> N >> M;

	LinkedList SSL;

	for (int i = 0; i < N; i++) {
		SSL.addNode(i + 1);
	}

	SSL.display(SSL.getHead());



	return 0;
}