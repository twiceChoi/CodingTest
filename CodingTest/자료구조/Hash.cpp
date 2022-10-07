// Hash : �����͸� ������ ��ġ�� ������ �������� ���ϴ� ��
// Hash Table :  �ؽð��� �ε����� �ǵ��� ������ Ű���� ������ �迭
// Hash �Լ� : Ű���� ������ �ؽð��� ����� ���� 
// ��Ŷ(bucket) : �ؽ����̺��� �� ��� 
// �浹 : ������ ��Ŷ�� �ߺ��Ǵ� ���� 
// �浹�� ���� ��ó : 1) ü�ι�_���Ḯ��Ʈ�� �ߺ����� 2) �����ּҹ�_���Ŷ�� ã�������� �ؽø� �ݺ�


#include <iostream>
#include <string>
using namespace std;


/*------------------------------------------------------------------------*/


/* ȸ��������  */
typedef struct
{
	int		no;			 /* ȸ�� ��ȣ */
	char	name[20];    /* �̸� */

}Member;

#define MEMBER_NO 1     /* ��ȣ�� ��Ÿ���� ������ */
#define MEMBER_NAME 2     /* �̸��� ��Ÿ���� ������ */


/*------------------------------------------------------------------------*/

/* ȸ����ȣ ���Լ� */
int MemberNoCmp(const Member *x, const Member *y);
/* ȸ���̸� ���Լ� */
int MemberNameCmp(const Member*x, const Member *y);
/* ȸ�� �����͸� ���(�ٹٲ� ����) */
void PrintMember(const Member* x);
/* ȸ�� �����͸� ���(�ٹٲ� ����) */
void PringLnMember(const Member* x);
/* ȸ�� �����͸� �о���� */
Member ScanMember(const char *message, int sw);

/*------------------------------------------------------------------------*/

/* x�� ũ�� 1 ������ 0 y�� ũ�� -1 */
int MemberNoCmp(const Member* x, const Member* y)
{
	return x->no < y->no ? -1 :x->no > y->no ? 1 : 0;
}

int MemberNameCmp(const Member* x, const Member* y)
{
	return strcmp(x->name,y->name);
}

void PrintMember(const Member* x)
{
	cout << x->no << x->name;
}

void PringLnMember(const Member* x)
{
	cout << x->no << x->name << endl;
}

Member ScanMember(const char* message, int sw)
{
	Member temp;
	cout << message << "�ϴ� �����ʹ� �Է��ϼ���" << endl;
	if (sw & MEMBER_NO)
		cout << "��ȣ : "; cin >> temp.no;
	if (sw & MEMBER_NAME)
		cout << "�̸� : "; cin >> temp.name;
	return temp;
}
/*------------------------------------------------------------------------*/

// ü�ι� (�����ؽù�) : �迭�� �� ��Ŷ�� �����ϴ� ���� �� �ε����� �ؽð����� �ϴ� ���Ḯ��Ʈ�� ù��°�� ���� ������ 
// �����Ͱ� �ϳ��� ���� ��� NULL �� �����Ѵ�. 

/*------------------------------------------------------------------------*/


/* ��Ŷ�� ��Ÿ���� ��� */
typedef struct __node
{
	Member				data;	/* ����Ÿ */
	struct				__node* next; /* ���� ���������*/
}Node;

/* �ؽ����̺� */
typedef struct
{
	int size;		/* �ؽ����̺��� ũ��*/
	Node** table;	/* �ؽ����̺��� ù��° ��ҿ� ���� ������*/
}ChainHash;

/*------------------------------------------------------------------------*/

/* �ؽ� ���̺� �ʱ�ȭ */
int Initialize(ChainHash* h, int size);
/* �˻� */
Node* Search(const ChainHash* h, const Member* x);
/* ������ �߰� */
int Add(ChainHash* h, const Member* x);
/* ������ ���� */
int Remove(ChainHash* h, const Member* x);
/* �ؽ����̺� ���� */
void Dump(const ChainHash* h);
/* ��� ������ ���� */
void Clear(ChainHash* h);
/* �ؽ����̺� ���� */
void Terminate(ChainHash* h);

/*------------------------------------------------------------------------*/

/* �ؽ��Լ�(Key�� �ؽð��� ��ȯ)*/
static int hash(int key, int size)
{
	return key % size;
}
/* ��忡 ���� �����ϴ� SetNode �Լ�*/
static void SetNode(Node* n, Member* x, Node* next)
{
	n->data = *x;
	n->next = next;

}

/* ChainHash �� ������ �ִ� Table�� �ε����� ���� �����ϴ�. ����� ������ �ִ�. */
int Initialize(ChainHash* h, int size)
{
	int i;

	h->table = new Node*[size]; /* ���̺��� Node�� ���������� -> ���⼭ �����ŭ �����Ҵ��� ���ְ� �Ǹ� ��� �����͸� size��ŭ ������ �ִ� �迭*/
	h->size = size;
	for (i = 0; i < size; ++i)
	{
		h->table[i] = nullptr; /* ���̺��� ��� �ؽð��� nullptr �� ä���ش�. */
	}
	return 1;
}

Node* Search(const ChainHash* h, const Member* x)
{
	int key = ::hash(x->no, h->size); /* �˻��ϴ� �������� �ؽð� */
	Node* p = h->table[key];				/* ���� ������ ��� */

	while (p != nullptr)
	{
		if (p->data.no == x->no)   /* �˻� ���� */
			return p;   
		p = p->next;
	}

	return nullptr; /* �˻� ���� */
}

int Add(ChainHash* h, Member* x)
{
	int key = ::hash(x->no, h->size);
	Node* p = h->table[key];
	Node* temp;
	while (p != nullptr)
	{
		if (p->data.no == x->no)
			return 1;
		p = p->next;
	}

	temp = new Node;
	SetNode(temp, x, h->table[key]);
	h->table[key] = temp;
	return 0;
}

int Remove(ChainHash* h, const Member* x)
{
	int key = ::hash(x->no,h->size );
	Node* p = h->table[key];
	Node** pp = &h->table[key];
	while (p != nullptr)
	{
		if (p->data.no == x->no) /* ã������ �����, ���� */
		{
			*pp = p->next;
			delete p;
			return 0;
		}
		pp = &p->next;
		p = p->next;
	}
	return 1;
}
/* �ؽ� ���̺��� ������ ����ϴ� �����Լ� */
void Dump(const ChainHash* h)
{
	int i;
	for (i = 0; i < h->size; i++)
	{
		Node* p = h->table[i];
		cout << i;
		while (p != nullptr)
		{
			cout << "->" << p->data.no << p->data.name;
			p = p->next;
		}
		cout << endl;
	}
}

/*��� ������ ���� */
void Clear(ChainHash* h)
{
	int i;
	for (i = 0; i < h->size; ++i)
	{
		Node* p = h->table[i];
		while (p != nullptr)
		{
			Node* next = p->next;
			delete p;
			p = next;
		}
		h->table = nullptr;

	}
}

void Terminate(ChainHash* h)
{
	Clear(h);
	delete h->table;
	h->size = 0;
}
/*------------------------------------------------------------------------*/
/* �����ּҹ� : �浹�� �߻������� ���ؽø� ���� : ���� �ؽù� */
/* ������ħ�Ӽ����� ��������Ӽ������*/
