#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef unsigned long long ll;

string HEX = "0123456789ABCDEF";

vector<int> IP = {	58, 50, 42, 34, 26, 18, 10, 2, 60, 52, 44, 36, 28, 20, 12, 4, 62, 54, 46, 38, 30, 22, 14, 6, 64, 56, 48, 40, 32, 24, 16, 8,
					57, 49, 41, 33, 25, 17, 9, 1, 59, 51, 43, 35, 27, 19, 11, 3, 61, 53, 45, 37, 29, 21, 13, 5, 63, 55, 47, 39, 31, 23, 15, 7 };

vector<int> PI = {	40, 8, 48, 16, 56, 24, 64, 32, 39, 7, 47, 15, 55, 23, 63, 31, 38, 6, 46, 14, 54, 22, 62, 30, 37, 5, 45, 13, 53, 21, 61, 29,
					36, 4, 44, 12, 52, 20, 60, 28, 35, 3, 43, 11, 51, 19, 59, 27, 34, 2, 42, 10, 50, 18, 58, 26, 33, 1, 41, 9, 49, 17, 57, 25 };

vector<int> PC1 = { 57, 49, 41, 33, 25, 17, 9, 1, 58, 50, 42, 34, 26, 18, 10, 2, 59, 51, 43, 35, 27, 19, 11, 3, 60, 52, 44, 36,
					63, 55, 47, 39, 31, 23, 15, 7, 62, 54, 46, 38, 30, 22, 14, 6, 61, 53, 45, 37, 29, 21, 13, 5, 28, 20, 12, 4 };

vector<int> PC2 = { 14, 17, 11, 24, 1, 5, 3, 28, 15, 6, 21, 10, 23, 19, 12, 4, 26, 8, 16, 7, 27, 20, 13, 2,
					41, 52, 31, 37, 47, 55, 30, 40, 51, 45, 33, 48, 44, 49, 39, 56, 34, 53, 46, 42, 50, 36, 29, 32 };

vector<int> leftShifts = { 1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1 };

vector<int> E = {	32, 1, 2, 3, 4, 5, 4, 5, 6, 7, 8, 9, 8, 9, 10, 11, 12, 13, 12, 13, 14, 15, 16, 17,
					16, 17, 18, 19, 20, 21, 20, 21, 22, 23, 24, 25, 24, 25, 26, 27, 28, 29, 28, 29, 30, 31, 32, 1 };

vector<vector<int>> S1 = {	{ 14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7 }, { 0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8 },
							{ 4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0 }, { 15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13 } };

vector<vector<int>> S2 = {	{ 15, 1, 8, 14, 6, 11, 3, 4, 9, 7, 2, 13, 12, 0, 5, 10 }, { 3, 13, 4, 7, 15, 2, 8, 14, 12, 0, 1, 10, 6, 9, 11, 5 },
							{ 0, 14, 7, 11, 10, 4, 13, 1, 5, 8, 12, 6, 9, 3, 2, 15 }, { 13, 8, 10, 1, 3, 15, 4, 2, 11, 6, 7, 12, 0, 5, 14, 9 } };

vector<vector<int>> S3 = {	{ 10, 0, 9, 14, 6, 3, 15, 5, 1, 13, 12, 7, 11, 4, 2, 8 }, { 13, 7, 0, 9, 3, 4, 6, 10, 2, 8, 5, 14, 12, 11, 15, 1 },
							{ 13, 6, 4, 9, 8, 15, 3, 0, 11, 1, 2, 12, 5, 10, 14, 7 }, { 1, 10, 13, 0, 6, 9, 8, 7, 4, 15, 14, 3, 11, 5, 2, 12 } };

vector<vector<int>> S4 = {	{ 7, 13, 14, 3, 0, 6, 9, 10, 1, 2, 8, 5, 11, 12, 4, 15 }, { 13, 8, 11, 5, 6, 15, 0, 3, 4, 7, 2, 12, 1, 10, 14, 9 },
							{ 10, 6, 9, 0, 12, 11, 7, 13, 15, 1, 3, 14, 5, 2, 8, 4 }, { 3, 15, 0, 6, 10, 1, 13, 8, 9, 4, 5, 11, 12, 7, 2, 14 } };

vector<vector<int>> S5 = {	{ 2, 12, 4, 1, 7, 10, 11, 6, 8, 5, 3, 15, 13, 0, 14, 9 }, { 14, 11, 2, 12, 4, 7, 13, 1, 5, 0, 15, 10, 3, 9, 8, 6 },
							{ 4, 2, 1, 11, 10, 13, 7, 8, 15, 9, 12, 5, 6, 3, 0, 14 }, { 11, 8, 12, 7, 1, 14, 2, 13, 6, 15, 0, 9, 10, 4, 5, 3 } };

vector<vector<int>> S6 = {	{ 12, 1, 10, 15, 9, 2, 6, 8, 0, 13, 3, 4, 14, 7, 5, 11 }, { 10, 15, 4, 2, 7, 12, 9, 5, 6, 1, 13, 14, 0, 11, 3, 8 },
							{ 9, 14, 15, 5, 2, 8, 12, 3, 7, 0, 4, 10, 1, 13, 11, 6 }, { 4, 3, 2, 12, 9, 5, 15, 10, 11, 14, 1, 7, 6, 0, 8, 13 } };

vector<vector<int>> S7 = {	{ 4, 11, 2, 14, 15, 0, 8, 13, 3, 12, 9, 7, 5, 10, 6, 1 }, {13, 0, 11, 7, 4, 9, 1, 10, 14, 3, 5, 12, 2, 15, 8, 6 },
							{ 1, 4, 11, 13, 12, 3, 7, 14, 10, 15, 6, 8, 0, 5, 9, 2 }, { 6, 11, 13, 8, 1, 4, 10, 7, 9, 5, 0, 15, 14, 2, 3, 12 } };

vector<vector<int>> S8 = {	{ 13, 2, 8, 4, 6, 15, 11, 1, 10, 9, 3, 14, 5, 0, 12, 7 }, { 1, 15, 13, 8, 10, 3, 7, 4, 12, 5, 6, 11, 0, 14, 9, 2 },
							{ 7, 11, 4, 1, 9, 12, 14, 2, 0, 6, 10, 13, 15, 3, 5, 8 }, { 2, 1, 14, 7, 4, 10, 8, 13, 15, 12, 9, 0, 3, 5, 6, 11 } };

vector<vector<vector<int>>> S = { S1, S2, S3, S4, S5, S6, S7, S8 };

vector<int> P = { 16, 7, 20, 21, 29, 12, 28, 17, 1, 15, 23, 26, 5, 18, 31, 10, 2, 8, 24, 14, 32, 27, 3, 9, 19, 13, 30, 6, 22, 11, 4, 25 };

class DES {
	vector<ll> encKeys, decKeys; ll key = 0; DES() {}

	vector<ll> generateKeys() {
		ll CD0 = 0; for (int i = 0; i < 56; i++)
			CD0 |= (1ull << (55 - i)) * ((key >> (64 - PC1[i])) & 1);

		ll mask = 0xFFFFFFF; vector<ll> CD(16, 0ll);
		ll C = CD0 >> 28, D = CD0 & mask;
		for (int i = 0; i < 16; i++) {
			C = ((C << leftShifts[i]) | (C >> (28 - leftShifts[i]))) & mask;
			D = ((D << leftShifts[i]) | (D >> (28 - leftShifts[i]))) & mask;
			CD[i] = (C << 28) | D;
		}

		vector<ll> res(16, 0ll);
		for (int i = 0; i < 16; i++) for (int j = 0; j < 48; j++)
			res[i] |= (1ull << (47 - j)) * ((CD[i] >> (56 - PC2[j])) & 1);

		return move(res);
	}

	ll sBox(ll x, vector<vector<int>> sB) {
		int row = ((x >> 4) & 2) | (x & 1);
		int col = (x & 0x1F) >> 1;
		return sB[row][col];
	}

	ll F(ll block, ll fKey) {
		ll e = 0; for (int i = 0; i < 48; i++)
			e |= (1ull << (47 - i)) * ((block >> (32 - E[i])) & 1);

		ll B = fKey ^ e, SB = 0;
		int rightShift = 42, leftShift = 28;
		for (int i = 0; i < 8; i++) {
			SB |= sBox((B >> rightShift) & 0x3F, S[i]) << leftShift;
			rightShift -= 6; leftShift -= 4;
		}

		ll res = 0; for (int i = 0; i < 32; i++)
			res |= (1ull << (31 - i)) * ((SB >> (32 - P[i])) & 1);

		return res;
	}

	ll dataEncryptionAlgorithm(ll text, vector<ll>& keys) {
		ll LR0 = 0; for (int i = 0; i < 64; i++)
			LR0 |= (1ull << (63 - i)) * ((text >> (64 - IP[i])) & 1);

		ll mask = 0xFFFFFFFF;
		ll L = LR0 >> 32, R = LR0 & mask;
		for (int i = 0; i < 16; i++) {
			ll newL = R, newR = L ^ F(R, keys[i]);
			L = newL; R = newR;
		}

		ll RL = (R << 32) | L, res = 0;
		for (int i = 0; i < 64; i++)
			res |= (1ull << (63 - i)) * ((RL >> (64 - PI[i])) & 1);

		return res;
	}

public:

	DES(ll _key) : key(_key) {
		decKeys = encKeys = generateKeys();
		reverse(decKeys.begin(), decKeys.end());
	}

	ll encryptDES(ll text) {
		return dataEncryptionAlgorithm(text, encKeys);
	}

	ll decryptDES(ll text) {
		return dataEncryptionAlgorithm(text, decKeys);
	}

};

string toBinary(ll x, int len) {
	string res = "";
	while (x) { res.push_back((x & 1) + '0'); x >>= 1; }
	while ((int) res.size() < len) { res.push_back('0'); }
	reverse(res.begin(), res.end()); return move(res);
}

void print(ll k, int len, int sp) {
	string K = toBinary(k, len);
	for (int i = 0; i < len; i++) {
		if (i && i % sp == 0) cout << ' ';
		cout << K[i];
	}
	cout << '\n' << '\n';
}

string toHex(ll x) {
	string res; 
	for (int i = 0; i < 16; i++, x >>= 4)
		res.push_back(HEX[x & 0xF]);
	reverse(res.begin(), res.end()); 
	return move(res);
}

ll fromHex(string h) {
	ll res = 0, first = find(HEX.begin(), HEX.end(), h[0]) - HEX.begin();
	for (int i = 1; i < 16; i++, res <<= 4)
		res += find(HEX.begin(), HEX.end(), h[i]) - HEX.begin();
	return (res >> 4) | ((1ull << 60) * first);
}

int main() {
	ll K = 0b0001001100110100010101110111100110011011101111001101111111110001;
	DES des(K); string message = "0123456789ABCDEF";
	ll binaryMessage = fromHex(message);
	ll encDES = des.encryptDES(binaryMessage);
	string encMessage = toHex(encDES);
	ll binaryEncMessage = fromHex(encMessage);
	ll decDES = des.decryptDES(binaryEncMessage);
	string decMessage = toHex(decDES);

	cout << "Message:           " << message << '\n' << '\n';
	cout << "In Binary:         "; print(binaryMessage, 64, 4);
	cout << "After Encryption:  "; print(encDES, 64, 4);
	cout << "Encrypted Message: " << encMessage << '\n' << '\n';
	cout << "In Binary:         "; print(binaryEncMessage, 64, 4);
	cout << "After Decryption:  "; print(decDES, 64, 4);
	cout << "Decrypted Message: " << decMessage << '\n' << '\n';
	cin.ignore(2); return 0;
}