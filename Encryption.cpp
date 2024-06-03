#include <iostream>
#include "Encryption.h"

using namespace std;

int Encryption::encrypt(int num) {

    int first = (num / 1000 + 7) % 10;
    int second = ((num / 100) % 10 + 7) % 10;
    int third = ((num / 10) % 10 + 7) % 10;
    int fourth = (num % 10 + 7) % 10;

    int encryptedNum = third * 1000 + fourth * 100 + first * 10 + second;
    return encryptedNum;
}

int Encryption::decrypt(int encryptedNum) {

	int first = (encryptedNum / 1000 + 3) % 10;
	int second = ((encryptedNum / 100) % 10 + 3) % 10;
	int third = ((encryptedNum / 10) % 10 + 3) % 10;
	int fourth = (encryptedNum % 10 + 3) % 10;

	int originalNum = third * 1000 + fourth * 100 + first * 10 + second;
	return originalNum;
}