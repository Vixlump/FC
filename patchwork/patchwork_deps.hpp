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
thread_local uint64_t active_length = 0;

thread_local uint64_t thread_label = 0;
uint64_t adapted_threads = 1;
uint64_t known_threads = 1;

std::map <uint64_t, std::vector<uint64_t>> fc_functions;

thread_local std::vector <std::string> script_reader;
thread_local std::vector <uint64_t> active_script;

struct codex_function_swap { std::vector<uint64_t> script; };

thread_local std::vector <codex_function_swap> active_script_bak;

std::vector <std::string> active_string;
std::vector <int64_t> active_z64;
std::vector <int32_t> active_z32;
std::vector <int16_t> active_z16;
std::vector <int8_t> active_z8;
std::vector <uint64_t> active_n64;
std::vector <uint32_t> active_n32;
std::vector <uint16_t> active_n16;
std::vector <uint8_t> active_n8;
std::vector <bool> active_bool;
std::vector <float> active_float;
std::vector <double> active_double;
std::vector <triple> active_triple;

struct assignment { uint64_t name; uint64_t line; };
std::vector <assignment> active_assignments;
std::vector <std::vector<assignment>> active_assignments_bak;

//core data types
std::map <uint64_t, std::string> string_var; std::map <uint64_t, std::vector <std::string>> string_var_array;

std::map <uint64_t, int64_t> z64_var; std::map <uint64_t, std::vector <int64_t>> z64_var_array;

std::map <uint64_t, int32_t> z32_var; std::map <uint64_t, std::vector <int32_t>> z32_var_array;

std::map <uint64_t, int16_t> z16_var; std::map <uint64_t, std::vector <int16_t>> z16_var_array;

std::map <uint64_t, int8_t> z8_var; std::map <uint64_t, std::vector <int8_t>> z8_var_array;

std::map <uint64_t, bool> bool_var; std::map <uint64_t, std::vector <bool>> bool_var_array;

std::map <uint64_t, float> float_var; std::map <uint64_t, std::vector <float>> float_var_array;

std::map <uint64_t, double> double_var; std::map <uint64_t, std::vector <double>> double_var_array;

std::map <uint64_t, triple> triple_var; std::map <uint64_t, std::vector <triple>> triple_var_array;

std::map <uint64_t, uint64_t> hash_var; std::map <uint64_t, std::vector <uint64_t>> hash_var_array;

std::map <uint64_t, uint64_t> n64_var; std::map <uint64_t, std::vector <uint64_t>> n64_var_array;

std::map <uint64_t, uint32_t> n32_var; std::map <uint64_t, std::vector <uint32_t>> n32_var_array;

std::map <uint64_t, uint16_t> n16_var; std::map <uint64_t, std::vector <uint16_t>> n16_var_array;

std::map <uint64_t, uint8_t> n8_var; std::map <uint64_t, std::vector <uint8_t>> n8_var_array;

std::map <uint64_t, void *> raw_var; std::map <uint64_t, std::vector <void *>> raw_var_array;

std::map <uint64_t, std::FILE *> record_var; std::map <uint64_t, std::vector <std::FILE *>> record_var_array;

//array pushbacks:
template <typename T> void codex_add_var_array(uint64_t name, T &value, std::map <uint64_t, std::vector <T>> & var_array) {
  var_array[name].push_back(value);
}
inline void codex_add_string_array(uint64_t name, std::string &value) {
  string_var_array[name].push_back(value);
}
inline void codex_add_z64_array(uint64_t name, int64_t value) {
  z64_var_array[name].push_back(value);
}
inline void codex_add_z32_array(uint64_t name, int32_t value) {
  z32_var_array[name].push_back(value);
}
inline void codex_add_z16_array(uint64_t name, int16_t value) {
  z16_var_array[name].push_back(value);
}
inline void codex_add_z8_array(uint64_t name, int8_t value) {
  z8_var_array[name].push_back(value);
}
inline void codex_add_bool_array(uint64_t name, bool value) {
  bool_var_array[name].push_back(value);
}
inline void codex_add_float_array(uint64_t name, float value) {
  float_var_array[name].push_back(value);
}
inline void codex_add_double_array(uint64_t name, double value) {
  double_var_array[name].push_back(value);
}
inline void codex_add_triple_array(uint64_t name, triple value) {
  triple_var_array[name].push_back(value);
}
inline void codex_add_hash_array(uint64_t name, uint64_t value) {
  hash_var_array[name].push_back(value);
}
inline void codex_add_n64_array(uint64_t name, uint64_t value) {
  n64_var_array[name].push_back(value);
}
inline void codex_add_n32_array(uint64_t name, uint32_t value) {
  n32_var_array[name].push_back(value);
}
inline void codex_add_n16_array(uint64_t name, uint16_t value) {
  n16_var_array[name].push_back(value);
}
inline void codex_add_n8_array(uint64_t name, uint8_t value) {
  n8_var_array[name].push_back(value);
}

//return variable:
inline std::string codex_return_string(uint64_t name) {
  return string_var[name];
}
inline int64_t codex_return_z64(uint64_t name) {
  return z64_var[name];
}
inline int32_t codex_return_z32(uint64_t name) {
  return z32_var[name];
}
inline int16_t codex_return_z16(uint64_t name) {
  return z16_var[name];
}
inline int8_t codex_return_z8(uint64_t name) {
  return z8_var[name];
}
inline uint64_t codex_return_n64(uint64_t name) {
  return n64_var[name];
}
inline uint32_t codex_return_n32(uint64_t name) {
  return n32_var[name];
}
inline uint16_t codex_return_n16(uint64_t name) {
  return n16_var[name];
}
inline uint8_t codex_return_n8(uint64_t name) {
  return n8_var[name];
}
inline bool codex_return_bool(uint64_t name) {
  return bool_var[name];
}
inline float codex_return_float(uint64_t name) {
  return float_var[name];
}
inline double codex_return_double(uint64_t name) {
  return double_var[name];
}
inline triple codex_return_triple(uint64_t name) {
  return triple_var[name];
}
inline uint64_t codex_return_hash(uint64_t name) {
  return hash_var[name];
}
//array types:
inline std::string codex_return_string_array(uint64_t name, uint64_t pos) {
  return string_var_array[name][pos];
}
inline int64_t codex_return_z64_array(uint64_t name, uint64_t pos) {
  return z64_var_array[name][pos];
}
inline int32_t codex_return_z32_array(uint64_t name, uint64_t pos) {
  return z32_var_array[name][pos];
}
inline int16_t codex_return_z16_array(uint64_t name, uint64_t pos) {
  return z16_var_array[name][pos];
}
inline int8_t codex_return_z8_array(uint64_t name, uint64_t pos) {
  return z8_var_array[name][pos];
}
inline bool codex_return_bool_array(uint64_t name, uint64_t pos) {
  return bool_var_array[name][pos];
}
inline float codex_return_float_array(uint64_t name, uint64_t pos) {
  return float_var_array[name][pos];
}
inline double codex_return_double_array(uint64_t name, uint64_t pos) {
  return double_var_array[name][pos];
}
inline triple codex_return_triple_array(uint64_t name, uint64_t pos) {
  return triple_var_array[name][pos];
}
inline uint64_t codex_return_hash_array(uint64_t name, uint64_t pos) {
  return hash_var_array[name][pos];
}
inline uint64_t codex_return_n64_array(uint64_t name, uint64_t pos) {
  return n64_var_array[name][pos];
}
inline uint32_t codex_return_n32_array(uint64_t name, uint64_t pos) {
  return n32_var_array[name][pos];
}
inline uint16_t codex_return_n16_array(uint64_t name, uint64_t pos) {
  return n16_var_array[name][pos];
}
inline uint8_t codex_return_n8_array(uint64_t name, uint64_t pos) {
  return n8_var_array[name][pos];
}

//constants:
inline uint64_t codex_get_assignment(uint64_t name) {
  for (uint64_t i = 0; i < active_assignments.size(); i++) {
    if (active_assignments[i].name==name) {return active_assignments[i].line;}
  }
  /*for (uint64_t i2 = 0; i2 < function_assignments.size(); i2++) {
    if (function_assignments[i2].name==name) {return function_assignments[i2].line;}
  }*/
  //std::cout<<"Contex Error["<<name<<"] is not an assignment point."<<std::endl;
  exit(42);
}

inline int64_t codex_get_allint(uint64_t input) {
  //possible addition
  return 0;
}
inline uint64_t codex_get_n64(uint64_t input) {
  switch (input) {
    case phantom_var:
      line++;
      return codex_return_n64(active_script[line]);
    case phantom_array:
        line+=2;
        return codex_return_n64_array(active_script[line-1], codex_get_n64(active_script[line]));
    default:
      return active_n64[input];
  }
}
inline std::string codex_get_string(uint64_t input) {
  switch (input) {
    case phantom_var:
      line++;
      return codex_return_string(active_script[line]);
    case phantom_array:
        line+=2;
        return codex_return_string_array(active_script[line-1], codex_get_n64(active_script[line]));
    default:
      return active_string[input];
      
  }
}
inline int64_t codex_get_z64(uint64_t input) {
  switch(input) {
    case phantom_var:
      line++;
      return codex_return_z64(active_script[line]);
    case phantom_array:
        line+=2;
        return codex_return_z64_array(active_script[line-1], codex_get_n64(active_script[line]));
    default:
      return active_z64[input];
  }
}
inline int32_t codex_get_z32(uint64_t input) {
  switch (input) {
    case phantom_var:
      line++;
      return codex_return_z32(active_script[line]);
    case phantom_array:
        line+=2;
        return codex_return_z32_array(active_script[line-1], codex_get_n64(active_script[line]));
    default:
      return active_z32[input];
  }
}
inline int16_t codex_get_z16(uint64_t input) {
  switch(input) {
    case phantom_var:
      line++;
      return codex_return_z16(active_script[line]);
    case phantom_array:
        line+=2;
        return codex_return_z16_array(active_script[line-1], codex_get_n64(active_script[line]));
    default:
      return active_z16[input];
  }
}
inline int8_t codex_get_z8(uint64_t input) {
  switch(input) {
    case phantom_var:
      line++;
      return codex_return_z8(active_script[line]);
    case phantom_array:
        line+=2;
        return codex_return_z8_array(active_script[line-1], codex_get_n64(active_script[line]));
    default:
      return active_z8[input];
  }
}
inline bool codex_get_bool(uint64_t input) {
  switch(input) {
    case phantom_var:
      line++;
      return codex_return_bool(active_script[line]);
    case phantom_array:
        line+=2;
        return codex_return_bool_array(active_script[line-1], codex_get_n64(active_script[line]));
    default:
      return active_bool[input];
  }
}
inline float codex_get_float(uint64_t input) {
  switch(input) {
    case phantom_var:
      line++;
      return codex_return_float(active_script[line]);
    case phantom_array:
        line+=2;
        return codex_return_float_array(active_script[line-1], codex_get_n64(active_script[line]));
    default:
      return active_float[input];
  }
}
inline double codex_get_double(uint64_t input) {
  switch(input) {
    case phantom_var:
      line++;
      return codex_return_double(active_script[line]);
    case phantom_array:
        line+=2;
        return codex_return_double_array(active_script[line-1], codex_get_n64(active_script[line]));
    default:
      return active_double[input];
  }
}
inline triple codex_get_triple(uint64_t input) {
  switch(input) {
    case phantom_var:
      line++;
      return codex_return_triple(active_script[line]);
    case phantom_array:
        line+=2;
        return codex_return_triple_array(active_script[line-1], codex_get_n64(active_script[line]));
    default:
      return active_triple[input];
  }
}

inline uint64_t codex_get_hash(uint64_t input) {
  switch(input) {
    case phantom_var:
      line++;
      return codex_return_hash(active_script[line]);
    case phantom_array:
        line+=2;
        return codex_return_hash_array(active_script[line-1], codex_get_n64(active_script[line]));
    default:
      return input;
  }
}
inline uint32_t codex_get_n32(uint64_t input) {
  switch (input) {
    case phantom_var:
      line++;
      return codex_return_n32(active_script[line]);
    case phantom_array:
        line+=2;
        return codex_return_n32_array(active_script[line-1], codex_get_n64(active_script[line]));
    default:
      return active_n32[input];
  }
}
inline uint16_t codex_get_n16(uint64_t input) {
  switch(input) {
    case phantom_var:
      line++;
      return codex_return_n16(active_script[line]);
    case phantom_array:
        line+=2;
        return codex_return_n16_array(active_script[line-1], codex_get_n64(active_script[line]));
    default:
      return active_n16[input];
  }
}
inline uint8_t codex_get_n8(uint64_t input) {
  switch(input) {
    case phantom_var:
      line++;
      return codex_return_n8(active_script[line]);
    case phantom_array:
        line+=2;
        return codex_return_n8_array(active_script[line-1], codex_get_n64(active_script[line]));
    default:
      return active_n8[input];
  }
}

//store variable:
inline void codex_store_all(uint64_t name, std::string &value) {
  string_var[name] = value;
  std::stringstream temp;
  temp<<value;
  hash_var[name] = static_cast<uint64_t>(std::stoull(value.c_str()));
  n64_var[name] = static_cast<uint64_t>(std::stoull(value.c_str()));
  n32_var[name] = static_cast<uint32_t>(std::stoull(value.c_str()));
  n16_var[name] = static_cast<uint16_t>(std::stoull(value.c_str()));
  n8_var[name] = static_cast<uint8_t>(std::stoull(value.c_str()));
  z64_var[name] = static_cast<int64_t>(std::stoll(value.c_str()));
  z32_var[name] = static_cast<int32_t>(std::stoll(value.c_str()));
  z16_var[name] = static_cast<int16_t>(std::stoll(value.c_str()));
  z8_var[name] = static_cast<int8_t>(std::stoll(value.c_str()));
  if (value=="true"||std::stoll(value.c_str())>=1||value=="True"||value=="TRUE") {bool_var[name] = true;} else {bool_var[name] = false;}
  float_var[name] = std::stof(value.c_str());
  double_var[name] = std::stod(value.c_str());
  triple_var[name] = std::stold(value.c_str());
}
//array types:
inline void codex_store_string_array(uint64_t name, uint64_t pos, std::string &value) {
  string_var_array[name][pos] = value;
}
inline void codex_store_z64_array(uint64_t name, uint64_t pos, int64_t value) {
  z64_var_array[name][pos] = value;
}
inline void codex_store_z32_array(uint64_t name, uint64_t pos, int32_t value) {
  z32_var_array[name][pos] = value;
}
inline void codex_store_z16_array(uint64_t name, uint64_t pos, int16_t value) {
  z16_var_array[name][pos] = value;
}
inline void codex_store_z8_array(uint64_t name, uint64_t pos, int8_t value) {
  z8_var_array[name][pos] = value;
}
inline void codex_store_bool_array(uint64_t name, uint64_t pos, bool value) {
  bool_var_array[name][pos] = value;
}
inline void codex_store_float_array(uint64_t name, uint64_t pos, float value) {
  float_var_array[name][pos] = value;
}
inline void codex_store_double_array(uint64_t name, uint64_t pos, double value) {
  double_var_array[name][pos] = value;
}
inline void codex_store_triple_array(uint64_t name, uint64_t pos, triple value) {
  triple_var_array[name][pos] = value;
}
inline void codex_store_hash_array(uint64_t name, uint64_t pos, uint64_t value) {
  hash_var_array[name][pos] = value;
}
inline void codex_store_n64_array(uint64_t name, uint64_t pos, uint64_t value) {
  n64_var_array[name][pos] = value;
}
inline void codex_store_n32_array(uint64_t name, uint64_t pos, uint32_t value) {
  n32_var_array[name][pos] = value;
}
inline void codex_store_n16_array(uint64_t name, uint64_t pos, uint16_t value) {
  n16_var_array[name][pos] = value;
}
inline void codex_store_n8_array(uint64_t name, uint64_t pos, uint8_t value) {
  n8_var_array[name][pos] = value;
}

inline void codex_store_string(uint64_t name, std::string &value) {
  string_var[name] = value;
}
inline void codex_store_z64(uint64_t name, int64_t value) {
  z64_var[name] = value;
}
inline void codex_store_z32(uint64_t name, int32_t value) {
  z32_var[name] = value;
}
inline void codex_store_z16(uint64_t name, int16_t value) {
  z16_var[name] = value;
}
inline void codex_store_z8(uint64_t name, int8_t value) {
  z8_var[name] = value;
}
inline void codex_store_bool(uint64_t name, bool value) {
  bool_var[name] = value;
}
inline void codex_store_float(uint64_t name, float value) {
  float_var[name] = value;
}
inline void codex_store_double(uint64_t name, double value) {
  double_var[name] = value;
}
inline void codex_store_triple(uint64_t name, triple value) {
  triple_var[name] = value;
}
inline void codex_store_hash(uint64_t name, uint64_t value) {
  hash_var[name] = value;
}
inline void codex_store_n64(uint64_t name, uint64_t value) {
  n64_var[name] = value;
}
inline void codex_store_n32(uint64_t name, uint32_t value) {
  n32_var[name] = value;
}
inline void codex_store_n16(uint64_t name, uint16_t value) {
  n16_var[name] = value;
}
inline void codex_store_n8(uint64_t name, uint8_t value) {
  n8_var[name] = value;
}