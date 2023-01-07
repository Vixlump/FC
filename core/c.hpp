#pragma once

inline void control_stream() {
	do {
		fc_getline();
		switch(active_script[line]) {
			case COREFC("+if"):
				break;
			case COREFC("+goto"):
				break;
			case COREFC("+while"):
				break;
			case COREFC("+for"):
				break;
			case COREFC("c*"):
			case COREFC("~~~*"):
				return;
			case COREFC(""):
				break;
			default:
				break;
		}
	} loop;
}