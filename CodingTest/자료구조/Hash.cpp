// Hash : 데이터를 저장할 위치를 간단한 연산으로 구하는 것
// Hash Table :  해시값이 인덱스가 되도록 원래의 키값을 저장한 배열
// Hash 함수 : 키값을 가지고 해시값을 만드는 과정 
// 버킷(bucket) : 해시테이블의 각 요소 
// 충돌 : 저장할 버킷이 중복되는 현상 
// 충돌에 대한 대처 : 1) 체인법_연결리스트로 중복관리 2) 오픈주소법_빈버킷을 찾을때까지 해시를 반복


#include <iostream>
#include <string>
using namespace std;


/*------------------------------------------------------------------------*/


/* 회원데이터  */
typedef struct
{
	int		no;			 /* 회원 번호 */
	char	name[20];    /* 이름 */

}Member;

#define MEMBER_NO 1     /* 번호를 나타내는 정수값 */
#define MEMBER_NAME 2     /* 이름을 나타내는 정수값 */


/*------------------------------------------------------------------------*/

/* 회원번호 비교함수 */
int MemberNoCmp(const Member *x, const Member *y);
/* 회원이름 비교함수 */
int MemberNameCmp(const Member*x, const Member *y);
/* 회원 데이터를 출력(줄바꿈 없음) */
void PrintMember(const Member* x);
/* 회원 데이터를 출력(줄바꿈 있음) */
void PringLnMember(const Member* x);
/* 회원 데이터를 읽어들임 */
Member ScanMember(const char *message, int sw);

/*------------------------------------------------------------------------*/

/* x가 크면 1 같으면 0 y가 크면 -1 */
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
	cout << message << "하는 데이터는 입력하세요" << endl;
	if (sw & MEMBER_NO)
		cout << "번호 : "; cin >> temp.no;
	if (sw & MEMBER_NAME)
		cout << "이름 : "; cin >> temp.name;
	return temp;
}
/*------------------------------------------------------------------------*/

// 체인법 (오픈해시법) : 배열의 각 버킷에 저장하는 값은 그 인덱스를 해시값으로 하는 연결리스트의 첫번째에 대한 포인터 
// 데이터가 하나도 없을 경우 NULL 을 저장한다. 

/*------------------------------------------------------------------------*/


/* 버킷을 나타내는 노드 */
typedef struct __node
{
	Member				data;	/* 데이타 */
	struct				__node* next; /* 다음 노드포인터*/
}Node;

/* 해시테이블 */
typedef struct
{
	int size;		/* 해시테이블의 크기*/
	Node** table;	/* 해시테이블의 첫번째 요소에 대한 포인터*/
}ChainHash;

/*------------------------------------------------------------------------*/

/* 해시 테이블 초기화 */
int Initialize(ChainHash* h, int size);
/* 검색 */
Node* Search(const ChainHash* h, const Member* x);
/* 데이터 추가 */
int Add(ChainHash* h, const Member* x);
/* 데이터 삭제 */
int Remove(ChainHash* h, const Member* x);
/* 해시테이블 덤프 */
void Dump(const ChainHash* h);
/* 모든 데이터 삭제 */
void Clear(ChainHash* h);
/* 해시테이블 종료 */
void Terminate(ChainHash* h);

/*------------------------------------------------------------------------*/

/* 해시함수(Key의 해시값을 반환)*/
static int hash(int key, int size)
{
	return key % size;
}
/* 노드에 값을 설정하는 SetNode 함수*/
static void SetNode(Node* n, Member* x, Node* next)
{
	n->data = *x;
	n->next = next;

}

/* ChainHash 가 가지고 있는 Table은 인덱스로 접근 가능하다. 사이즈도 가지고 있다. */
int Initialize(ChainHash* h, int size)
{
	int i;

	h->table = new Node*[size]; /* 테이블은 Node의 이중포인터 -> 여기서 사이즈만큼 동적할당을 해주게 되면 노드 포인터를 size만큼 가지고 있는 배열*/
	h->size = size;
	for (i = 0; i < size; ++i)
	{
		h->table[i] = nullptr; /* 테이블의 모든 해시값은 nullptr 로 채워준다. */
	}
	return 1;
}

Node* Search(const ChainHash* h, const Member* x)
{
	int key = ::hash(x->no, h->size); /* 검색하는 데이터의 해시값 */
	Node* p = h->table[key];				/* 현재 선택한 노드 */

	while (p != nullptr)
	{
		if (p->data.no == x->no)   /* 검색 성공 */
			return p;   
		p = p->next;
	}

	return nullptr; /* 검색 실패 */
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
		if (p->data.no == x->no) /* 찾았으면 지우고, 해제 */
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
/* 해시 테이블의 내용을 출력하는 덤프함수 */
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

/*모든 데이터 삭제 */
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
/* 오픈주소법 : 충돌이 발생했을때 재해시를 수행 : 닫힌 해시법 */
/* 삭제마침속성값과 비어있음속성값사용*/
