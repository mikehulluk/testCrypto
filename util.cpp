//util body functions
#include "util.h"
#include <vector>
#include <assert.h>
#include <iostream>
#include <iomanip>

using namespace std;


void printBuff_hex(const buffer& b){

	for (size_t i=0; i<b.size(); i++)
		cout << setfill('0') << setw(2) << hex << +b[i];
	cout << endl;
}

void printBuff_bin(const buffer& b){

	for (size_t i=0; i<b.size(); i++)
		cout << b[i];
	cout << endl;
}

buffer fixedXOR(const buffer& b1, const buffer& b2){
	assert(b1.size() == b2.size());
	buffer b3(b1.size());
	for (size_t i=0; i<b1.size(); i++){
		b3[i] = b1[i] ^ b2[i];
	}

	return b3;
}

vector<uint8_t> parseHexToBinary(string input_data){
  vector<uint8_t> binaryData;
  long int temp_char;

  for (size_t i=0; i<input_data.length(); i+=2){
    char *junk;
    char temp_str[3];
    temp_str[0] = input_data[i];
    temp_str[1] = input_data[i+1];
    temp_str[2] = '\0';

    temp_char = strtol(temp_str, &junk, 16);
    //printf("temp_char = %ld\n", temp_char);
    binaryData.push_back(temp_char);
  }
  return binaryData;
}