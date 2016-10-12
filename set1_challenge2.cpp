//fixed XOR

#include "util.h"
#include <iostream>
#include <assert.h>
#include <iomanip>


int main(){

	buffer b1 = parseHexToBinary("1C011100");
	buffer b2 = parseHexToBinary("68697420");

	printBuff(b1);
	printBuff(b2);

	buffer bout = fixedXOR(b1, b2);

	printBuff(bout);
	return 0;
}