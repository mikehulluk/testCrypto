//util body functions
#include "util.h"


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