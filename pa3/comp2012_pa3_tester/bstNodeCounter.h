#ifndef BSTNODE_COUNTER_H
#define BSTNODE_COUNTER_H

class BSTNodeCounter {
public:
	BSTNodeCounter(){ counter++; }
	BSTNodeCounter(const BSTNodeCounter&){ counter++; }
	~BSTNodeCounter(){ counter--; }
	static int counter;
};

#endif