#pragma once

inline void math_stream() {
	do {
		fc_getline();
		switch(active_script[line]) {
			case COREFC("m*"):
			case COREFC("~~~*"):
				return;
			case COREFC(""):
				break;
			default:
				break;
		}
	} loop;
}