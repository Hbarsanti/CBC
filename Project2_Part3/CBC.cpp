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
  string xordinit = XOR(blocks[0], IV, 64);
  string c[0] = encryption(xordinit, key_gen(key));
  for (int i = 1; i < blocks.size(); i++) {
    string xord = XOR(blocks[i], c[i-1], 64);
     c[i] = encryption(xord, key_gen(key));
    encrypted += c[i];
  }
  return encrypted;
}

string CBC_decryption(vector<string> blocks, string key, string IV) {
  string decrypted;
  
  return decrypted;
}