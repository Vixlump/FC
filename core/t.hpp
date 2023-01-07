#pragma once

inline void threading_stream() {
	do {
		fc_getline();
		switch(active_script[line]) {
			case COREFC("t*"):
			case COREFC("~~~*"):
				return;
			case COREFC(""):
				break;
			default:
				break;
		}
	} loop;
}