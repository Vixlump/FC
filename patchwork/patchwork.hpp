#pragma once

void patchwork_security() {
	//ensure that script_reader and active_script have same number of lines
	//verify codex_id authentication
	//verity and resolve patchwork errors and terminate compilation if needed
}

void patchwork_livepatch() {

}
void patchwork_error(std::string message) {
	return;
}
constexpr uint64_t hash_location = 1;

int64_t patchwork_z_base_converter(std::string & input) {
	if (input.empty()) {return 0;}
	switch(input[0]) {
		case 'b':
			input.erase(input.begin());
			return static_cast<int64_t>(std::stoll(input.c_str(), nullptr, 2));
		case 'x':
			input.erase(input.begin());
			return static_cast<int64_t>(std::stoll(input.c_str(), nullptr, 16));
		default:
			return static_cast<int64_t>(std::stoll(input.c_str()));
	}
}
uint64_t patchwork_n_base_converter(std::string & input) {
	if (input.empty()) {return 0;}
	switch(input[0]) {
		case 'b':
			input.erase(input.begin());
			return static_cast<uint64_t>(std::stoull(input.c_str(), nullptr, 2));
		case 'x':
			input.erase(input.begin());
			return static_cast<uint64_t>(std::stoull(input.c_str(), nullptr, 16));
		default:
			return static_cast<uint64_t>(std::stoull(input.c_str()));
	}
}


void patchwork_compiler() {
	for (uint64_t i = 0; i < active_length; i++) {
		if (script_reader[i][hash_location]!='#') {
			active_script.push_back(COREFC_RUNTIME(script_reader[i].c_str()));
		} else {
			std::string script_reinterpretor;
			uint64_t temp_length = script_reader[i].length();
			for (uint64_t i2 = hash_location+1; i2<temp_length; i2++) {
				script_reinterpretor += script_reader[i][i2];
			}
			switch(script_reader[i][hash_location-1]) {
				case 'z'://intager z#64#213213 z#
					{
        				std::stringstream xseport(script_reinterpretor);
        				uint64_t i3 = 0;
        				std::string xsesubstr[2] = {"",""};
        				while (xseport.good() && i3<2) {
          					std::getline(xseport, xsesubstr[i3], '#');
         					i3++;
        				}
        				if (xsesubstr[1]=="") {
        					active_z64.push_back(patchwork_z_base_converter(xsesubstr[0]));
        					active_script.push_back(active_z64.size()-1);
        					break;
        				}
        				if (xsesubstr[0]=="64") {
        					active_z64.push_back(patchwork_z_base_converter(xsesubstr[1]));
        					active_script.push_back(active_z64.size()-1);
        					break;
        				} else if (xsesubstr[0]=="32") {
        					active_z32.push_back(static_cast<int32_t>(patchwork_z_base_converter(xsesubstr[1])));
        					active_script.push_back(active_z32.size()-1);
        					break;
        				} else if (xsesubstr[0]=="16") {
        					active_z16.push_back(static_cast<int16_t>(patchwork_z_base_converter(xsesubstr[1])));
        					active_script.push_back(active_z16.size()-1);
        					break;
        				} else if (xsesubstr[0]=="8") {
        					active_z8.push_back(static_cast<int8_t>(patchwork_z_base_converter(xsesubstr[1])));
        					active_script.push_back(active_z8.size()-1);
        					break;
        				} else if (xsesubstr[0]=="all") {
        					//maybe someday
        					patchwork_error("angry message");
        					break;
        				} else {
        					//error
        					patchwork_error("angry message");
        					break;
        				}
						break;
					}
				case 'n'://natural
					{
        				std::stringstream xseport(script_reinterpretor);
        				uint64_t i3 = 0;
        				std::string xsesubstr[2] = {"",""};
        				while (xseport.good() && i3<2) {
          					std::getline(xseport, xsesubstr[i3], '#');
         					i3++;
        				}
        				if (xsesubstr[1]=="") {
        					active_n64.push_back(patchwork_n_base_converter(xsesubstr[0]));
        					active_script.push_back(active_n64.size()-1);
        					break;
        				}
        				if (xsesubstr[0]=="64") {
        					active_n64.push_back(patchwork_n_base_converter(xsesubstr[1]));
        					active_script.push_back(active_n64.size()-1);
        					break;
        				} else if (xsesubstr[0]=="32") {
        					active_n32.push_back(static_cast<uint32_t>(patchwork_n_base_converter(xsesubstr[1])));
        					active_script.push_back(active_n32.size()-1);
        					break;
        				} else if (xsesubstr[0]=="16") {
        					active_n16.push_back(static_cast<uint16_t>(patchwork_n_base_converter(xsesubstr[1])));
        					active_script.push_back(active_n16.size()-1);
        					break;
        				} else if (xsesubstr[0]=="8") {
        					active_n8.push_back(static_cast<uint8_t>(patchwork_n_base_converter(xsesubstr[1])));
        					active_script.push_back(active_n8.size()-1);
        					break;
        				} else if (xsesubstr[0]=="all") {
        					//maybe someday
        					patchwork_error("angry message");
        					break;
        				} else {
        					//error
        					patchwork_error("angry message");
        					break;
        				}
						break;
					}
					break;
				case 'r'://real
					{
						std::stringstream xseport(script_reinterpretor);
        				uint64_t i3 = 0;
        				std::string xsesubstr[2] = {"",""};
        				while (xseport.good() && i3<2) {
          					std::getline(xseport, xsesubstr[i3], '#');
         					i3++;
        				}
        				if (xsesubstr[1]=="") {
        					active_float.push_back(std::stof(xsesubstr[0].c_str()));
        					active_script.push_back(active_float.size()-1);
        					break;
        				}
        				if (xsesubstr[0]=="f") {
        					active_float.push_back(std::stof(xsesubstr[1].c_str()));
        					active_script.push_back(active_float.size()-1);
        					break;
        				} else if (xsesubstr[0]=="d") {
        					active_double.push_back(std::stod(xsesubstr[1].c_str()));
        					active_script.push_back(active_double.size()-1);
        					break;
        				} else if (xsesubstr[0]=="t") {
        					active_triple.push_back(std::stold(xsesubstr[1].c_str()));
        					active_script.push_back(active_triple.size()-1);
        					break;
        				} else if (xsesubstr[0]=="all") {
        					patchwork_error("angry message");
        					break;
        				} else {
        					patchwork_error("angry message");
        					break;
        				}
						break;
					}
				case 'b'://bools
					if (script_reinterpretor=="true"||script_reinterpretor=="True"||script_reinterpretor=="TRUE"||std::stoll(script_reinterpretor.c_str())>=1) {
						active_bool.push_back(true);
					} else {
						active_bool.push_back(false);
					}
					active_script.push_back(active_bool.size()-1);
					break;
				case 's'://string
					active_string.push_back(script_reinterpretor);
					active_script.push_back(active_string.size()-1);
					break;
				case '#'://raw hash
					active_script.push_back(static_cast<uint64_t>(std::stoull(script_reinterpretor.c_str())));
					break;
				case 'v'://var
					active_script.push_back(phantom_var);
					break;
				case 'a'://array
					active_script.push_back(phantom_array);
					break;
				case '&'://interject
					{
				        uint64_t i3 = 1;
				        script_reinterpretor += defined_file_extention;
				        std::ifstream new_append_file(script_reinterpretor);
				        std::string appended_process_m;
				        while (std::getline(new_append_file, appended_process_m)) {
				          script_reader.insert(script_reader.begin() + i + i3, appended_process_m);
				          i3++;
				        }
				        active_length+=i3-1;
				        new_append_file.close();
						break;
				    }
					break;
				case '/'://comment
					active_script.push_back(COREFC(""));
					break;
				case '*'://framework declaration
					break;
				case '0'://framework end
					break;
				case ';'://decombiner
					break;
				case '%'://register
					break;
				case '+'://merger
					break;
				case '^'://base converter
					break;
				case 'f'://pre hash math expression
					break;
				case '@'://assignment
					active_script.push_back(COREFC(""));
					
					break;
				case '!'://startingpoint
					break;
				case 'e'://error
					break;
				default://patchwork error
					break;
			}
		}
	}
}

void patchwork_reader() {
	std::ifstream read_file;
	read_file.open(file_name+defined_file_extention);
	uint64_t i = 0;
	std::string temp_str;
	while(std::getline(read_file, temp_str)) {
		script_reader.push_back(temp_str);
		i++;
	}
	active_length = i;
	read_file.close();
}

void patchwork_init() {
	patchwork_reader();
	patchwork_compiler();
}