#ifndef USER_HPP
#define USER_HPP
#include <string>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

class User{
    private:
        std::string username;
        std::string passcode;
    public:
    
        void setUsername(std::string userName);
        void setPasscode(std::string passcode);

        std::string getUsername();
        std::string getPasscode();

        void writeRawData();
        std::string generatePasscode();
        void encryptData(std::string key);
        std::string VNCipher(std::string passcode, std::string key);

        User(std::string username, std::string passcode);
        User();


        
};






#endif