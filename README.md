**Base64 Encoder / Decoder in C++**

This is a simple C++ console application that allows you to encode text into Base64 format and decode Base64 strings back to plain text.

The program handles standard Base64 encoding/decoding and supports only ASCII characters for input text.

**Features**

Encode plain text into Base64

Decode Base64 strings back to text

Handles both uppercase and lowercase commands for encoding and decoding

Simple and intuitive console interface

**Base64 Overview**

Base64 is a binary-to-text encoding scheme that represents binary data in an ASCII string format by translating it into a radix-64 representation.
It is widely used in:

Email via MIME

Embedding image data in HTML/CSS

Storing complex data in text formats like JSON or XML

Example:

Text: Hello World
Base64: SGVsbG8gV29ybGQ=

**Usage**
1. Compile the program

Using g++:

g++ base64.cpp -o base64

2. Run the executable
./base64

3. Program flow

The program asks you to input the text.

Then you choose:

E or e to encode the text to Base64

D or d to decode Base64 to plain text

The program outputs the result to the console.

Example:

Welcome to Base64 Encoder/Decoder!
Please write your text: Hello World
Type 'E' to Encode or 'D' to Decode text: E
Text encoded is: SGVsbG8gV29ybGQ=

**How It Works**

Encoding:

Each 3 bytes of text are converted into 4 Base64 characters.

Pads with = if necessary to make the length a multiple of 4.

Decoding:

Each 4 Base64 characters are converted back into 3 bytes of original text.

Ignores non-Base64 characters and handles padding correctly.

Important Functions:

std::string base64_encode(const std::string& input)

std::string base64_decode(const std::string& input)

bool is_base64(unsigned char c) → checks if a character is valid Base64

**Notes**

Only ASCII characters are supported for encoding.

Inputting invalid Base64 for decoding may result in incorrect output.

The program uses std::getline for input to allow spaces in the text.
