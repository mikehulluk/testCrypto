#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <cstdint>

using namespace std;

vector<uint8_t> parseHexToBinary(string input_data){
  vector<uint8_t> binaryData;
  long int temp_char;
  
  for (size_t i=0; i<input_data.length(); i+=2){
    char *junk;
    char temp_str[3];
    temp_str[0] = input_data[i];
    temp_str[1] = input_data[i+1];
    temp_str[2] = NULL;
    
    temp_char = strtol(temp_str, &junk, 16);
    //printf("temp_char = %ld\n", temp_char);
    binaryData.push_back(temp_char);  
  }
  return binaryData; 
}

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
