
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    std::string str = "1.3pt \"Fira Sans\", sans-serif";
    float size = 0; char name[128]; char ptx = 0;
	char* start = const_cast<char*>(str.c_str());
	while(*start != '\0' && !isdigit(*start)){ start++; }
	sscanf(start, "%fp%1[tx]%*[\"' ]%63[^\"']", &size, &ptx, name);
    if( ptx == 't' ) { size = std::ceilf(size* 4.0 / 3.0); }
    
    return 0;
}