//Convert hex to base64

#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <cstdint>
#include "util.h"

using namespace std;


vector<uint8_t> EncodetoBase64(vector<uint8_t> binaryData){
  vector<uint8_t> encodedData;

  for(size_t i=0;i<binaryData.size();i+=3){

    encodedData.push_back(binaryData[i] >> 2);
    encodedData.push_back(((binaryData[i] & 0x03) << 4) | ((binaryData[i+1] & 0xF0) >> 4));
    encodedData.push_back(((binaryData[i+1] & 0x0F) << 2) | ((binaryData[i+2] & 0xC0) >>  6));
    encodedData.push_back((binaryData[i+2] & 0x2F));
    //printf("%d %d %d %d \n", encodedData[i], encodedData[i+1], encodedData[i+2], encodedData[i+3]);

  }
  return encodedData;
}

int main(){
  string str_input("49276d");
  //printf("input %c\n", str_input[0]);
  vector<uint8_t> binaryData = parseHexToBinary(str_input);

  for (size_t i=0;i<binaryData.size();i++)
    printf("binaryDate: %u\n", (unsigned int)binaryData[i]);

  vector<uint8_t> encodedData = EncodetoBase64(binaryData);


  for(int i=0;i<encodedData.size();i++)
    printf("data: %d\n", encodedData[i]);



}
