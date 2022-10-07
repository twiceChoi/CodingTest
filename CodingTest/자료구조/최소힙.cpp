include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100
int heap[MAX_SIZE];

void push(int item, int* n)
{
	int i = 0;
	i = ++(*n);

	/* ������ �θ�-�ڽ� �� ���ϸ鼭 ��� ���� �ڸ��� �ٲٴ� �������� */
	/* ���� �ڵ� �����󿡼��� ���� �ڽĺ��� �۾Ҵ� �θ�� ���� �� �ڸ��� �ٲ� �� */
	/* while�� �������� �� ���� ���� �ڽ��� ���������� ������ ��. */

	while ((i != 1) && item < heap[i / 2]) {
		heap[i] = heap[i / 2]; // ���� �ڽ� �� �ڸ��� �θ��� �� ����
		i = i / 2; // ���� ���� �ڽ��� ���� �θ��ڸ��� �� ���� ����� i�� �� ����
	}
	heap[i] = item;
}

int main(void)
{
	int input;
	int n = 0, count = 0;

	printf("Min Heap ���� - ���ڸ� �Է��ϼ���.\n");
	printf("*****���� �Է�(-1�� �Է��ϸ� �Է� ����)*****\n");

	while (1)
	{
		scanf("%d", &input);

		if (input == -1)
			break;

		push(input, &n);
		count++;
	}

	printf("Level Order Traversal : ");
	for (int i = 1; i <= count; i++) {
		printf("%d ", heap[i]);
	}

}