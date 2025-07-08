#ifndef AESUtils_h
#define AESUtils_h

#include <Arduino.h>
#include <base64.h>
#include <mbedtls/aes.h>

class AESUtils {
  public:
    static String encryptPayload(const String& payload, const byte* key, byte* iv);
    
  private:
    static size_t padPayload(const byte* input, size_t inputLen, byte* output, size_t blockSize);
    static void generateRandomIV(byte* iv, size_t length);
    static bool aesEncryptCBC(const byte* input, size_t inputLen, byte* output, size_t& outputLen, const byte* key, const byte* iv);
};

#endif