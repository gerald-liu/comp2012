#ifndef HASHING_VAULT_COUNTER_H
#define HASHING_VAULT_COUNTER_H

class HashingVaultCounter {
public:
	HashingVaultCounter(){ counter++; }
	HashingVaultCounter(const HashingVaultCounter&){ counter++; }
	~HashingVaultCounter(){ counter--; }
	static int counter;
};

#endif