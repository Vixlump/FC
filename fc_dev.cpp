//cstd control
#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include <cinttypes>
#include <cstring>

//stream control
#include <iostream>
#include <fstream>
#include <sstream>

//filesystem control
//#include <filesystem>

//variable expantion
#include <string>
#include <memory>
#include <new>
#include <map>
#include <type_traits>
//#include <cctype>

//math control
#include <cmath>
#include <complex>
#include <random>
#include <limits>
#include <functional>

//time control
#include <ctime>
#include <chrono>

//threading control
#include <thread>
#include <atomic>
#include <mutex>
#include <vector>

#define loop while(true)

//pre var deps
#define loop while(true)
   //Platforms specific inclusion controller:
   //Agnostic = 0
   //Windows = 1
   //MacOSX = 2
   //Linux = 3
   //Android = 4
   //Ubuntu Touch = 5
   //BSD = 6
   //Raspberry PI = 7
   //IOS = 8
   //PineTime = 9
   //Oculus = 10
   //Custom = 11
#define FCPLATFORM 0

//Comment out if you do not want to compile with aspectu
#define ASPECTUFXTOOLS

//Patchwork System
#include "patchwork/hash.h"
#include "patchwork/patchwork_deps.h"
#include "patchwork/patchwork.h"

//FC Core
#include "core/version.hpp"
#include "core/presets.hpp"

#include "core/error.hpp"
#include "core/debug.hpp"

#include "core/v.hpp"
#include "core/c.hpp"
#include "core/m.hpp"
#include "core/t.hpp"
#include "core/x.hpp"
#include "core/r.hpp"

#include "core/livepatch.hpp"
#include "core/cswap.hpp"
#include "core/abreg.hpp"
#include "core/overloading.hpp"
#include "core/framework_driver.hpp"


#include "core/index.hpp"

int main(int argc, char *argv[]) {
	
	return 42;
}
