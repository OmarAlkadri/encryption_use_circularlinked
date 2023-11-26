#include "sifreleme.hpp"

void circularlinked::AddNode(int data)
{
	Node* node = new Node;
	node->data = data;
	if (firstNode == nullptr)
	{
		node->next = node;
		node->prev = node;
		endNode = firstNode = node;
	}
	else
	{
		Node* temp = firstNode;
		while (Gcd > gcd(data, temp->data) && temp != endNode)
		{
			temp = temp->next;
		}
		if (Gcd <= gcd(data, temp->data) || temp == endNode)
		{
			if (Gcd < gcd(data, temp->data))
			{
				Gcd = gcd(data, temp->data);
			}
			int mod = mode(data, temp->data);
			if (mod > 0)
			{
				for (int i = 0; i < mod - 1 && temp != firstNode; i++)
				{
					temp = temp->prev;
				}
				if (temp == firstNode)
				{
					node->next = temp;
					if (firstNode == endNode)
						endNode->prev = node;
					temp->prev = node;
					node->prev = endNode;
					endNode->next = node;
					firstNode = node;
				}
				else
				{
					node->next = temp;
					node->prev = temp->prev;
					temp->prev->next = node;
					temp->prev = node;
				}
			}
			else {
				node->next = temp->next;
				node->prev = temp;
				temp->next->prev = node;
				temp->next = node;
			}
		}
	}
}

circularlinked::circularlinked()
{
	Gcd = 0;

	firstNode = endNode = nullptr;
}

int circularlinked::gcd(int a, int b) {
	if (a == 0 || b == 0)
		return 0;
	if (a == b)
		return a;
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

int circularlinked::mode(int a, int b)
{
	if (a == 0 || b == 0)
		return 0;
	if (a < b)
		return b % a;
	else
		return a % b;
}


void circularlinked::DeleteFirst()
{
	Node* temp;
	while ((temp = firstNode) && temp != nullptr)
	{
		if (firstNode == endNode)
		{
			temp = temp->next = temp->prev = nullptr;
			firstNode = nullptr;
			delete temp;
			return;
		}
		firstNode = firstNode->next;
		firstNode->next = firstNode->next;
		firstNode->prev = endNode;
		endNode->next = firstNode;
		delete temp;
	}
}


ostream& operator<<(ostream & out, circularlinked & data) {

	Node* temp;
	temp = data.firstNode;
	if (temp != NULL) {
		do {
			out << (char)temp->data;
			temp = temp->next;
		} while (temp != data.endNode);
		if (temp != NULL)
			out << (char)temp->data;
	}
	return out;
}


circularlinked::~circularlinked()
{
	DeleteFirst();
}
