#ifndef NAMESPACE_H
#define NAMESPACE_H

#include <iostream>

namespace SlowLib {

	class Iterator {
	public:
		void next() const {
			std::cout << ".................Next!" << std::endl;
		}
	};

	void print_info() {
		std::cout << "You...are...using...SlowLib..." << std::endl;
	}
};

namespace FastLib {

	class Iterator {
	public:
		void next() const {
			std::cout << "Next!" << std::endl;
		}
	};

	void print_info() {
		std::cout << "You are using FastLib" << std::endl;
	}
	
};

#endif