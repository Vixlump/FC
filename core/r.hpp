#pragma once

inline void reserved_stream() {
	do {
		fc_getline();
		switch(active_script[line]) {
			case COREFC("+tap"):
				break;
			case COREFC("+exit"):
				std::exit(42);
				break;
			case COREFC("r*"):
			case COREFC("~~~*"):
				return;
			case COREFC(""):
				break;
			default:
				break;
		}
	} loop;
}