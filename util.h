//util functions
#include <string>
#include <vector>
#include <cstdint>
#include <assert.h>


using namespace std;

typedef vector<uint8_t> buffer;

void printBuff_hex(const buffer& b);
void printBuff_bin(const buffer& b);
vector<uint8_t> parseHexToBinary(string input_data);
buffer fixedXOR(const buffer& b1, const buffer& b2);