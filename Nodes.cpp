#include "Nodes.h"
#include "Branch.h"
#include <iostream>

Nodes::Nodes()
{
	for (int i = 0; i < max; i++) {
		nodes[i] = NULL;
	}
}


Nodes::~Nodes()
{
	for (int i = 0; i < max; i++) {
		if (nodes[i])
			delete nodes[i];
	}
}

Node& Nodes::operator[](int n) {
	if (n<0 || n>max)
		throw std::exception("Invalid node number");
	if (nodes[n])
		return *nodes[n];
	nodes[n] = new Node(n);
	return *nodes[n];

}

void Nodes::applyKCL(Eigen::MatrixXcd& m1, Eigen::MatrixXcd& m2, int & row)
{
	int cn = 0;
	bool first = true;
	for (int i = 0; i < max; i++) {
		if (!nodes[i] || nodes[i]->isSimple())
			continue;
		std::vector<Branch*> bs = nodes[i]->getBranches();
		for (int i = 0; i < bs.size(); i++) {
			bs[i]->assumeCurrent(cn);

		}
		if (first) {
			first = false;
			continue;
		}
		nodes[i]->applyKCL(m1, m2, row);
	}
}

void Nodes::calcV()
{
	if (!nodes[0])
		return;
	nodes[0]->setVoltage(0);
	std::vector<Node*> list;
	list.push_back(nodes[0]);
	Node* node;
	std::vector<Branch*> bs;
	while (list.size() != 0) {
		node = list.back();
		list.pop_back();
		bs = node->getBranches();
		for (int i = 0; i < bs.size(); i++) {
			if (bs[i]->has(CS) || bs[i]->getEnd()->isCalculated())
				continue;
			bs[i]->getEnd()->setVoltage(bs[i]->getVoltageValue());
			list.push_back(bs[i]->getEnd());
		}
	}

}

void Nodes::display() const
{
	for (int i = 0; i < max; i++) {
		if (nodes[i])
			std::cout << "V(" << i << ") " << nodes[i]->getVoltage() << std::endl;
	}
}
