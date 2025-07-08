#include <AESUtils.h>

void setup() {
  Serial.begin(115200);
  
  byte key[16] = { /* 16-byte AES key */ };
  byte iv[16];
  
  String plaintext = "Sensitive data to encrypt";
  String encrypted = AESUtils::encryptPayload(plaintext, key, iv);
  
  Serial.println("Encrypted payload (Base64):");
  Serial.println(encrypted);
}

void loop() {}