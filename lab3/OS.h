
#ifndef OS_H
#define OS_H

#include <iostream>

using namespace std;


class OS {

public:
	/**
     * Constructor.
     */
	OS();

	/**
     * Constructor.
     * @param name The name of the OS.
     * @param version The version of the OS.
     */
    OS(const string& name, int version);

    /**
     * Upgrade the operating system.
     */
    void upgrade();

    /**
     * Print the current information of the operating system.
     */
    void print() const;

    /* getter */
    string get_name() const;
	int get_version() const;

private:
	/**
     * The name of the operating system.
     * Its default name is "default".
     */
    string name{"default"};

    /**
     * The version of the operating system.
     * Its default version is 0.
     */
    int version{0};

};


#endif //OS_H
