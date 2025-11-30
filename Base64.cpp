#include <iostream>
#include <string>
#include <cctype>
#include <vector>

//Program that Encodes and Decodes text based on user input.

// String of base64 characters.

static const std::string Base64Chars = 
             "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
             "abcdefghijklmnopqrstuvwxyz"
             "0123456789+/";

// Function to check if a character is base64.

bool is_base64(unsigned char c){
    return(isalnum(c) || c =='+' || c == '/');
}

// Function to Decode Base64 to text.
std::string base64_decode(const std::string &input){

    std::vector<int> T(256 , -1);
    for (int i = 0; i < 64; i++) T[Base64Chars[i]] = i;

    std::string decodedString;
    int val = 0, valb = -8;

    for(unsigned char c : input){
        if (T[c] == -1) break;
        val = (val << 6) + T[c];
        valb += 6;

        if(valb >= 0){
            decodedString.push_back(char((val >> valb) & 255));
            valb -= 8;
        }
    }

    return decodedString;
}

// Function to Encode text to Base64.

std::string base64_encode(const std::string& input){
    std::string encodedString;
    int val = 0, valb = -6;

    for(unsigned char c : input){
        val = (val << 8) + c;
        valb += 8;

        while (valb >= 0){
            encodedString.push_back(Base64Chars[(val >> valb) & 63]);
            valb -= 6;
        }
    }

    if (valb > -6){
        encodedString.push_back(Base64Chars[((val << 8) >> (valb + 8 )) & 63]);
    }

    while(encodedString.size() % 4){
        encodedString.push_back('=');
    }

    return encodedString;

}

// Main function
int main(){
    std::string choice;
    std::string text;

    std::cout <<"Welcome to Base64 Encoder/Decoder!" << std::endl;
    std::cout <<"Please write your text: ";
    std::getline (std:: cin , text);

    std:: cout << "Type 'E' to Encode or 'D' to Decode text: ";
    std:: cin >> choice;

    /*if(choice == "E" || choice == "e"){

    }else if(choice =="D" || choice == "d"){

    }else{
        std:: cout << "Invalid choice. Please type E or D"
    }*/

    while(true){

    if(choice == "E" || choice == "e"){

        //Print encoded text.
        std:: string encodedText = base64_encode(text);
        std:: cout <<"Text encoded is: " << encodedText << std::endl;
        break;

    }else if(choice =="D" || choice == "d"){

        //Print decoded text.
        std:: string decodedString = base64_decode(text);
        std:: cout <<"Text decoded is: " << decodedString << std::endl;
        break;

    }else{

        std:: cout << "Invalid choice. Please type E or D" <<std:: endl;
        
    }
}

//Prevent console from closing immediately.
std::cout << "Press Enter to exit...";
std::cin.ignore();  
std::cin.get(); 

return 0;
}
