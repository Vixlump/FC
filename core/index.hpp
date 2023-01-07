#pragma once

inline void index_stream() {
	do {
		fc_getline();
		switch(active_script[line]) {
			case COREFC("*v"):
				variable_stream();
				break;
			case COREFC("*c"):
				control_stream();
				break;
			case COREFC("*m"):
				math_stream();
				break;
			case COREFC("*t"):
				threading_stream();
				break;
			case COREFC("?*"):
				return;
			case COREFC(""):
			case COREFC("~~~*"):
				break;
			case COREFC("*r"):
				reserved_stream();
				break;
			default:
				framework_stream();
				break;
		}
		switch(active_script[line]) {
			case COREFC("*~~~"):
				cswap_stream();
				break;
			case COREFC("*x"):
				xternal_stream();
				break;
			default:
				break;
		}
	} while((line+1) < active_length);

}
