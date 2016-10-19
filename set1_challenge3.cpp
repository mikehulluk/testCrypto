// Single-byte XOR cipher

#include "util.h"
#include <iomanip>
#include <iostream>
#include <algorithm>

using namespace std;

struct highScores{
		float score;
		buffer message;
	};

/*struct highScoresNode
{
	highScores data;
	highScoresNode* pNext;
}
*/

buffer XORbuff_char(const buffer& b1, char c){
	buffer b2(b1.size());
	for (size_t i=0; i<b1.size(); i++)
		b2[i] = b1[i] ^ c;
	return b2;
}

bool isValidASCII(uint8_t val){
	if (val <= '9' && val >= '0' )
		return true;
	if (val <= 'Z' && val >= 'A')
		return true;
	if (val <= 'z' && val >= 'a')
		return true;
	if (val == '\'' || val == ' '
	 || val == '.' || val == ':'
	 || val == ';' || val == ',')
		return true;
	return false;
}

float validASCIImetric(const buffer& b){

	int count =0 ;
	for (size_t i=0; i< b.size(); i++)
		if (isValidASCII(b[i]))
			count++;
	float perc = static_cast<float>(count) / b.size();
	return perc;
}

bool sortMsgfunc(const highScores& m0, const highScores& m1){
	return (m0.score < m1.score);

}

int main(){

	buffer encoded = parseHexToBinary("1b37373331363f78151b7f2b783431333d78397828372d363c78373e783a393b3736");
	//printBuff_bin(encoded);
	buffer decrypted(encoded.size());

	vector <highScores> decryptedmsgs;

	for (int i=0; i<256; i++){
		buffer decrypt = XORbuff_char(encoded, i);
		float scorevalid = validASCIImetric(decrypt);
		if (scorevalid > 0.8 || i ==120){
			highScores decryptedmsg;
			decryptedmsg.score = scorevalid;
			decryptedmsg.message = decrypt;
			decryptedmsgs.push_back(decryptedmsg);
			//printf("%d %f \t", i, score);
			//printBuff_bin(decrypted);
		}
	}
	sort(decryptedmsgs.begin(), decryptedmsgs.end(),sortMsgfunc);
	printf("%lu\n", decryptedmsgs.size());
	for (size_t i=0; i<decryptedmsgs.size(); i++){
		printf("%f \t", decryptedmsgs[i].score);
		printBuff_bin(decryptedmsgs[i].message);
	}

	return 0;
}