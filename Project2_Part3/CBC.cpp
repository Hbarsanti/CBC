#include "DES.h"
#include <bitset>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// The blocks has been padded and is already a vector of binary string
// The key and IV are also binary strings

string CBC_encryption(vector<string> blocks, string key, string IV) {
  string encrypted;
  vector<string> c(blocks.size());
  c[0] = encryption(XOR(blocks[0], IV, 64), key_gen(key));
  encrypted += c[0];
  for (int i = 1; i < blocks.size(); i++) {
     c[i] = encryption(XOR(blocks[i], c[i-1], 64), key_gen(key));
    encrypted += c[i];
  }
  return encrypted;
}

string CBC_decryption(vector<string> blocks, string key, string IV) {
  string decrypted;
  vector<string> p(blocks.size());
  p[0] = XOR(decryption(blocks[0], key_gen(key)), IV, 64);
  decrypted += p[0];
  for (int i = 1; i < blocks.size(); i++) {
    p[i] = XOR(decryption(blocks[i], key_gen(key)), blocks[i-1], 64);
    decrypted += p[i];
  }
  return decrypted;
}