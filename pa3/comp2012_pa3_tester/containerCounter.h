#ifndef CONTAINER_COUNTER_H
#define CONTAINER_COUNTER_H

class ContainerCounter {
public:
	ContainerCounter(){ counter++; }
	ContainerCounter(const ContainerCounter&){ counter++; }
	~ContainerCounter(){ counter--; }
	static int counter;
};

#endif