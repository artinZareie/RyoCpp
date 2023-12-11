#pragma once
#include "terminal.hpp"
#include <cstdio>

#ifdef __linux__

namespace Ryo::Terminal {

class KeyPress {
public: 
	/**
	 * @function non-blocking getch function
	 * @returns char
	 */
	int getch() {
		set_noncanonical_mode();

		return getchar();

		restore_canonical_mode();
	}
};

};

#endif
