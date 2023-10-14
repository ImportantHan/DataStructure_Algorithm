/*
1. ������ ����
	1) �޸�
	  - 1byte(8bit) ���� ���� �ּ�
	  - �Ϲ������� 4bytes, 16������ ǥ��

	2) ������ �޸��� ����
	  - �ּҿ�����(&) : ������ �Ҵ�� �޸�
		int a = 0;
		printf("%d : %p", a, &a); // %p : �ּ� 16������ ���

		result. 0 - a�� �ּ�

	3) ������ �ǹ�
	  - �Ҵ�� ����
	  - ����� ��s

	4) ������(�ڷ���)
	  - �ּҸ� ��Ÿ���� Ư�� �ڷ���
	  - �ּҴ� �⺻������ ���� ������ ǥ��, int�� �����Ǿ� ó��

=====

2. ������ ����� ���
	1) ���� �� �տ� *(����������) �߰�
		ex. char *pch;
			int *pnum;
		=> pch�� pnum�� �Ȱ��� �ּҸ� ���������� ����� �ڷ����� �ٸ��� ������ �ٸ� �ڷ��� ���

	2) �ʱ�ȭ
	  - int num, *pnum = &num; // num�� ���� ����Ǿ�� ��

	3) ������ ����(����)
	  - ������(����)�� �ּҸ� �����Ͽ� Ư�� ������ �����Ű�� ���� ����Ų�� ��� ǥ��, �׸����� -> ǥ��
		char ch = 'A', *pch;
		int num = 3, *pnum;

		pch = &ch; // pch�� ���� ch�� �ּ� ����
		pnum = &num; // pnum�� ���� num�� �ּ� ����

	4) ������ ����
	  - �����Ͱ� ����Ű�� ������ �����ϴ� ��
	  - ���� ������ : * (����������, ������ ������)
	  - *pch : ������ pch�� ����Ű�� ����
	  - ���� ���� : *pch = 'B'
	  - ���� ���� : ch = 'B'

	5) �ּҿ����ڿ� ���������� ����
	  - �ּҿ�����(&) : �ش� ������ �ּҰ�
	  - ����������(*) : �����Ͱ� ����Ű�� ������
	  - ���� �̸� : ���� ���� �Ǵ� ������ ����� ��
	  => ��(�Ϲݺ���), o(�����ͺ���), -> : ����

	6) ��� ���ǻ���
	  - ���� �� ���� ���� �ٷ� ����ϸ� ��Ÿ�� ���� �߻� (int *pnum;)
		- Null : �ּҰ� 0, �ƹ��͵� ����Ű�� ����
	  - &(�ּҿ�����)�� �����͸� ������ ��� ������ ��밡��, *(����������)�� ������ ���������� ��� ����
	  - �������� �ڷ����� ����� ������ �ڷ�� ��ġ (num == *pnum)

	7) �������� ũ��
	  - ������ ������ ���� ���� �ּ� ũ��(4byte)

=====

3. �迭�� ������
	1) �迭
	  - �迭 �̸��� �迭�� 0�� ���� ���� �ּ�
	  - �迭 �̸��� �ּ�, ���� �����ڿ� �Բ� ��� ���� (a[0] == *ar)

	2) �迭�� ������ ���� ����
	  - �迭�� �����ʹ� ������ ���·� ��� ����
		int ar[5], *p = ar;
		ar[0] == p[0] == *(ar + 0) == *(p + 0);
	  - �ּҰ� �־����� �� �ּҿ� ����� ���Ұ��� �����ϴ� ���� 2����
		ar[3], p[3] // �迭�� ���� ������[] ���
		*(ar + 3), *(p + 3) // �������� ���� ������ * ���

	3) �迭 �̸��� ������ ������ ����
	  - int num;
		- ���� num�� ����� ��(����, ex.9) ���� ����, �Ҵ�� �ּ�(ex.0x9A) ���� �Ұ�
	  - int *p;
		- ���� p�� ����� ��(�ּ�, ex.0x9A) ���� ����, �Ҵ�� �ּ� ���� �Ұ�
	  - int arr[5];
		- �迭 arr�� ����� �� ���� ����, �Ҵ�� �ּ� ���� �Ұ�
		- �迭 �̸��� ������ ����� �������� ���Ѵ�
		- ���Թ��� ���ʿ��� ���� �� (I-value)���� �߻�

	4) �迭�� ������ ���ǻ���
	  - �����͸� �迭�� �߰� ���ҿ� �����Ű�� �� ���� (int *p = &arr[2])
	  - �������� ���� ������ ��� �� ��ȣ�� ����
		arr[5] = {1, 3, 5, 7, 9}
		*(arr + 2) -> arr[2] -> 5
		*(arr) + 2 -> *(arr) + 2 -> arr[0] + 2 -> 3
	  - ������ ������ �������� ����Ű�� �迭�� ���� ũ�Ⱑ �ƴ϶� ������ �ڽ��� �ڷ����� ���� ����

=====

4. ������ ����
	1) �ּҿ� ������ ���ϰų� ����
	2) �񱳿����� ���
	  - �ּ� �񱳸� �̿��Ͽ� �迭 �Ⱦ��
	  - ���� 2

=====

5. ������ ���ڿ� �ּ� ��ȯ
	1) �迭�� ������ ���� ����
	  - �迭�� index ��� ����� ����
	2) �Լ� ���� ��
	  - ���� ���� ȣ��(call-by-value) : ���� ���̳� ���� ���� ���ڷ� �Լ��� ȣ���ϴ� ��
	  - �ּҿ� ���� ȣ��(cal-by-reference) : �ּҸ� ���ڷ� �Լ��� ȣ���ϴ� ��
	  => �� ȣ�� ����� �Լ��� ȣ�� ����(���� ���� �� �����帧)�� ������ ����

=====

6.������ �迭
	1) ������ �迭
	  - ������ �������� ����
	  - ������ ���� + �迭 ����
	  - ���� 3

=====

7. ���� ������
	1) ���� ������
	  - int ������ ������ �ּҸ� �����ϴ� ����
	  - int** : int ������ ������ �ּҸ� �����ϴ� ������ �ڷ���

*/

#include <iostream>

using namespace std;

int main()
{
	// ���� 1
	int num = 3;
	int* pnum = &num;

	*pnum = *pnum / 2 + 4;

	if (*pnum == 5) {
		++*pnum;
	}
	cout << "���� 1 : " << *pnum << "\n";

	// ���� 2
	int arr[5] = { 2, 3, 5, 7, -1 };
	int* pArr = arr;

	cout << "���� 2 : ";
	for (pArr = arr; pArr < &arr[5]; pArr++) {
		cout << *pArr << ", ";
	}
	cout << "\n";

	// ���� 3
	int a = 1, b = 2, c = 3;
	int* pi[3];
	pi[0] = &a;
	pi[1] = &b;
	pi[2] = &c;

	*pi[0] = -1;

	cout << "���� 3 : ";
	// &pi[i] : pi�迭�� �ּҰ�
	// pi[i] : pi�迭�� �ִ� a, b, c�� �ּҰ�
	// *pi[i] : pi�迭�� �ִ� a, b, c�� ��
	for (int i = 0; i < 3; i++) {
		cout << &pi[i] << "(" << *pi[i] << ")" << ", ";
	}
	cout << "\n";

	return 0;
}