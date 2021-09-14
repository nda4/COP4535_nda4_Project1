#ifndef USER_HPP
#define USER_HPP
#include <string>
#include <iostream>
#include <fstream>

class User{
    private:
        std::string username;
        std::string passcode;
    public:
    
        void setUsername(std::string userName);
        void setPasscode(std::string passcode);

        std::string getUsername();
        std::string getPasscode();

        void writeRawData(std::string fileName);
        std::string generatePasscode();
        void encryptData(std::string fileName, std::string key);

        User(std::string username, std::string passcode);

        
};






#endif