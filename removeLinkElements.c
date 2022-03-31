#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>


typedef struct ListNode {
	int val; // ������
	struct ListNode* next; // ָ����
}listNode;

// ��ʼ������
listNode* createLink(int n) {
	listNode* p = (listNode*)malloc(sizeof(listNode));// ����һ��ͷ���
	listNode* temp = p;
	int data = 0;

	for (int i = 1; i <= n; i++) {
		listNode* a = (listNode*)malloc(sizeof(listNode));
		printf("�����%d����:", i);
		scanf("%d", &data);
		a->val = data;
		a->next = NULL;
		temp->next = a;
		temp = temp->next;
	}
	return p;
}


// �Ƴ�����Ԫ��
listNode* removeElements(struct ListNode* head, int val) {
	listNode* shead;
	shead = (listNode*)malloc(sizeof(listNode));
	shead->next = head;
	listNode* cur = shead;
	while (cur->next != NULL) {
		if (cur->next->val == val) {
			listNode* tmp = cur->next;
			cur->next = cur->next->next;
			free(tmp);
		}
		else {
			cur = cur->next;
		}
	}
	head = shead->next;
	free(shead);
	return head;
}


void displayLink(listNode* p) {
	listNode* temp = p;
	while (temp->next) {
		temp = temp->next;
		printf("%d", temp->val);
	}
	printf("\n");
}


int main(void)
{
	printf("��ʼ������Ϊ��\n");
	listNode* h = createLink(7);
	displayLink(h);
	int val = 6;
	listNode* re = removeElements(h, val);
	displayLink(re);

}
