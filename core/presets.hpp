#pragma once
typedef long double triple;

std::string original_file_name = "active";
const std::string defined_file_extention = ".fc";

thread_local std::string file_name = "active";
thread_local std::vector <std::string> file_name_bak;

constexpr uint64_t phantom_line = std::numeric_limits<uint64_t>::max();
constexpr uint64_t phantom_hash = std::numeric_limits<uint64_t>::max();
constexpr uint64_t phantom_var = phantom_hash-1;
constexpr uint64_t phantom_array = phantom_var-1;

thread_local uint64_t line = 0;
thread_local std::vector <uint64_t> line_bak;

thread_local uint64_t thread_label = 0;
uint64_t adapted_threads = 1;
uint64_t known_threads = 1;

uint64_t codex_id = 0;

std::map <uint64_t, std::vector<uint64_t>> fc_functions;

thread_local std::vector <std::string> script_reader;
thread_local std::vector <uint64_t> active_script;

struct codex_function_swap { std::vector<uint64_t> script; };

thread_local std::vector <codex_function_swap> active_script_bak;

std::vector <std::string> active_string;
std::vector <int64_t> active_int64;
std::vector <int32_t> active_int32;
std::vector <int16_t> active_int16;
std::vector <int8_t> active_int8;
std::vector <bool> active_bool;
std::vector <float> active_float;
std::vector <double> active_double;
std::vector <triple> active_triple;

struct assignment { uint64_t name; uint64_t line; };
std::vector <assignment> active_assignments;
std::vector <assignment> function_assignments;

//core data types
std::map <uint64_t, std::string> string_var; std::map <uint64_t, std::vector <std::string>> string_var_array;

std::map <uint64_t, int64_t> int64_var; std::map <uint64_t, std::vector <int64_t>> int64_var_array;

std::map <uint64_t, int32_t> int32_var; std::map <uint64_t, std::vector <int32_t>> int32_var_array;

std::map <uint64_t, int16_t> int16_var; std::map <uint64_t, std::vector <int16_t>> int16_var_array;

std::map <uint64_t, int8_t> int8_var; std::map <uint64_t, std::vector <int8_t>> int8_var_array;

std::map <uint64_t, bool> bool_var; std::map <uint64_t, std::vector <bool>> bool_var_array;

std::map <uint64_t, float> float_var; std::map <uint64_t, std::vector <float>> float_var_array;

std::map <uint64_t, double> double_var; std::map <uint64_t, std::vector <double>> double_var_array;

std::map <uint64_t, triple> triple_var; std::map <uint64_t, std::vector <triple>> triple_var_array;

std::map <uint64_t, uint64_t> hash_var; std::map <uint64_t, std::vector <uint64_t>> hash_var_array;

std::map <uint64_t, std::ifstream> chart_var; std::map <uint64_t, std::vector <std::ifstream>> chart_var_array;

std::map <uint64_t, std::ofstream> quantum_var; std::map <uint64_t, std::vector <std::ofstream>> quantum_var_array;