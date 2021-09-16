#include "hashTable.hpp"
#include "user.hpp"


int main(){
    User user;
    user.writeRawData();
    user.encryptData("jones");
    hashTable table("encrypteddata.txt");
    std::string validUserIDs[] = {"COX", "WARD", "WRAGG", "SHOPP", "BORLING"};
    std::string validUncryptPasscodes[] = {"chzdflilr", "svbspkyhs", "pudagynpc", "bgdfitxap", "yvdpdlmeb"};
}