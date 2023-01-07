#pragma once

inline void variable_stream() {
	do {
		fc_getline();
		switch(active_script[line]) {
			case COREFC("+store"):
				break;
			case COREFC("+cast"):
				break;
			case COREFC("+array"):
				break;
			case COREFC("+delete"):
				break;
			case COREFC("v*"):
			case COREFC("~~~*"):
				return;
			case COREFC(""):
				break;
			default:
				break;
		}
	} loop;
}