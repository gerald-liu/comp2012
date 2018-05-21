#ifndef PAIR_COUNTER_H
#define PAIR_COUNTER_H

class PairCounter {
public:
	PairCounter(){ counter++; }
	PairCounter(const PairCounter&){ counter++; }
	~PairCounter(){ counter--; }
	static int counter;
};

#endif