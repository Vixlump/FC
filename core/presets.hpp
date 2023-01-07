#pragma once

inline void fc_getline() {
	line++;
}

void fc_collect_args(int &argc, char *argv[]) {
	for (size_t i = 0; i < argc; i++) {
		string_var_array[COREFC("_contex.terminal.args")].push_back(argv[i]);
	}
}

void fc_define_presets() {
	record_var[COREFC("_contex.terminal.output")] = stdout;
	record_var[COREFC("_contex.terminal.input")] = stdin;
}