#pragma once

inline void xternal_record_write_var() {
	return;
}

inline void xternal_record_write() {
	do {
		fc_getline();
		switch(active_script[line]) {
			case COREFC("_line"):
				break;
			case COREFC("_var")://unsure if this needs to be here or if this should be a lib
				break;
			case COREFC("_ret"):
				return;
			default:
				break;
		}
	} loop;
}
inline void xternal_record_read() {
	return;
}

inline void xternal_record() {
	fc_getline();
	switch(active_script[line]) {
		case COREFC("_write"):
			xternal_record_write();
			break;
		case COREFC("_read"):
			xternal_record_read();
			break;
		default:
			break;
	}
}

inline void xternal_stream() {
	do {
		fc_getline();
		switch(active_script[line]) {
			case COREFC("+record"):
				xternal_record();
				break;
			case COREFC("+shell"):
				break;
			case COREFC("+time"):
				break;
			case COREFC("x*"):
			case COREFC("~~~*"):
				return;
			case COREFC(""):
				break;
			default:
				break;
		}
	} loop;
}