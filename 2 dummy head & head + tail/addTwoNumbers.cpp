// 2. 两数相加

// 给你两个 非空 的链表，表示两个非负的整数。
// 它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。

// 请你将两个数相加，并以相同形式返回一个表示和的链表。

// 你可以假设除了数字 0 之外，这两个数都不会以 0 开头。

#include <iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode
{
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution
{
public:
	ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
	{
		ListNode *p1 = l1, *p2 = l2;
		int carry = 0;
		// 1. dummy head
		ListNode *dummy = new ListNode(0);
		ListNode *p3 = dummy;
		while (p1 || p2 || carry)
		{
			int v1 = p1 == nullptr ? 0 : p1->val;
			int v2 = p2 == nullptr ? 0 : p2->val;
			int total = v1 + v2 + carry;
			carry = (total) / 10;
			int unit = (total) % 10;

			p3->next = new ListNode(unit);

			if (p1)
			{
				p1 = p1->next;
			}
			if (p2)
			{
				p2 = p2->next;
			}
			p3 = p3->next;
		}

		ListNode *ans = dummy->next;
		delete dummy;
		return ans;

		// 2. head & tail
		ListNode *head = nullptr, *tail = nullptr;
		while (p1 || p2 || carry)
		{
			int v1 = p1 == nullptr ? 0 : p1->val;
			int v2 = p2 == nullptr ? 0 : p2->val;
			int total = v1 + v2 + carry;
			carry = (total) / 10;
			int unit = (total) % 10;

			if (!head)
			{
				head = tail = new ListNode(unit);
			}
			else
			{
				tail->next = new ListNode(unit);
				tail = tail->next;
			}

			if (p1)
			{
				p1 = p1->next;
			}
			if (p2)
			{
				p2 = p2->next;
			}
		}

		return head;
	}
};