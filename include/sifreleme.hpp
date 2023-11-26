#ifndef SIFRELEME_HPP
#define SIFRELEME_HPP
#include "Node.hpp"
#include <iostream>
using namespace std;
class circularlinked
{
public:
	circularlinked();
	~circularlinked();
	void AddNode(int);
	void DeleteFirst();

private:
	friend ostream &operator<<(ostream &, circularlinked &);
	Node *firstNode;
	Node *endNode;
	int Gcd;
	int gcd(int, int);
	int mode(int, int);
};
#endif