#include "AESUtils.h"

size_t AESUtils::padPayload(const byte* input, size_t inputLen, byte* output, size_t blockSize) {
  size_t padLen = blockSize - (inputLen % blockSize);
  size_t totalLen = inputLen + padLen;
  memcpy(output, input, inputLen);
  memset(output + inputLen, padLen, padLen);
  return totalLen;
}

void AESUtils::generateRandomIV(byte* iv, size_t length) {
  for (size_t i = 0; i < length; i++) {
    iv[i] = random(0, 256);
  }
}

bool AESUtils::aesEncryptCBC(const byte* input, size_t inputLen, byte* output, size_t& outputLen, const byte* key, const byte* iv) {
  mbedtls_aes_context aes;
  mbedtls_aes_init(&aes);
  int ret = mbedtls_aes_setkey_enc(&aes, key, 128);
  if (ret != 0) {
    mbedtls_aes_free(&aes);
    return false;
  }

  byte iv_copy[16];
  memcpy(iv_copy, iv, 16);

  ret = mbedtls_aes_crypt_cbc(&aes, MBEDTLS_AES_ENCRYPT, inputLen, iv_copy, input, output);
  mbedtls_aes_free(&aes);
  if (ret != 0) {
    return false;
  }
  outputLen = inputLen;
  return true;
}

String AESUtils::encryptPayload(const String& payload, const byte* key, byte* iv) {
  byte plainBytes[256];
  size_t plainLen = payload.length();
  if (plainLen > 240) {
    return "";
  }

  size_t paddedLen = padPayload((byte*)payload.c_str(), plainLen, plainBytes, 16);
  generateRandomIV(iv, 16);

  byte encrypted[256];
  size_t encryptedLen = 0;
  if (!aesEncryptCBC(plainBytes, paddedLen, encrypted, encryptedLen, key, iv)) {
    return "";
  }

  byte combined[272];
  memcpy(combined, iv, 16);
  memcpy(combined + 16, encrypted, encryptedLen);
  return base64::encode(combined, 16 + encryptedLen);
}