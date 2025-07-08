# 🔐 AESUtils Library for Arduino

AESUtils adalah library ringan untuk melakukan enkripsi data menggunakan algoritma **AES-128 dalam mode CBC** pada perangkat berbasis Arduino seperti **ESP32** dan **ESP8266**.

---

## 📚 Deskripsi

Library ini menyediakan antarmuka sederhana untuk mengenkripsi data string menggunakan AES-128-CBC dengan padding dan IV acak. Cocok untuk pengamanan data pada aplikasi IoT.

---

## ✨ Fitur

- 🔒 Enkripsi AES-128 dengan mode CBC
- 🔁 Padding otomatis (PKCS#7 style)
- 🔐 IV (Initialization Vector) acak setiap kali enkripsi
- 📦 Output dalam format Base64 (mudah dikirim via HTTP/MQTT)
- ⚙️ Cocok untuk ESP32 & ESP8266

---

## 📦 Dependensi

Library ini menggunakan pustaka berikut (biasanya sudah tersedia dalam core ESP32/ESP8266):

- `mbedtls/aes.h` – Untuk operasi enkripsi AES
- `base64.h` – Untuk encoding hasil enkripsi
- `Arduino.h` – Header dasar platform Arduino

---

## 📁 Struktur File

```
AESUtils/
├── AESUtils.h           # Header class AESUtils
├── AESUtils.cpp         # Implementasi metode enkripsi
├── basicaes.ino         # Contoh penggunaan
└── library.properties   # Metadata library Arduino
```

---

## 🛠️ Instalasi

1. Clone atau unduh repository ini.
2. Tempatkan folder `AESUtils` ke dalam direktori `libraries/` Arduino Anda.
3. Di sketch Arduino Anda, tambahkan:

```cpp
#include <AESUtils.h>
```

---

## 🚀 Contoh Penggunaan

```cpp
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
```

---

## 🔍 Cara Kerja

1. Data akan di-*pad* menggunakan PKCS-style padding agar genap terhadap blok AES (16 byte).
2. IV acak sepanjang 16 byte akan dibuat.
3. Data akan dienkripsi menggunakan AES-128-CBC (`mbedtls_aes_crypt_cbc()`).
4. IV + hasil enkripsi akan digabung dan diencode ke Base64 agar mudah dikirim.

---

## ✅ Kompatibilitas

Telah diuji dan bekerja baik pada:

- ✅ ESP32
- ✅ ESP8266

---

## 📄 License

MIT License — bebas digunakan untuk kebutuhan pribadi maupun komersial.

---

## 📋 Metadata (library.properties)

```
name=AESUtils
version=1.0.0
author=YourName
maintainer=YourEmail@example.com
sentence=AES-128-CBC Encryption Library
paragraph=Provides simple interface for AES encryption with CBC mode
category=Data Processing
url=https://github.com/yourusername/AESUtils
architectures=esp32,esp8266
```

---

## ✍️ Penulis

- **Author:** YourName  
- **Maintainer:** [YourEmail@example.com](mailto:YourEmail@example.com)

---

## 🔗 Referensi

- 🔗 [AES CBC Mode Explanation](https://en.wikipedia.org/wiki/Block_cipher_mode_of_operation#Cipher_Block_Chaining_(CBC))
- 🔗 [Base64 Encoding](https://en.wikipedia.org/wiki/Base64)