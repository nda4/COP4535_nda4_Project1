#include "hashTable.hpp"
#include "user.hpp"


int main(){
    User user;
    user.writeRawData();
    user.encryptData("jones");
    hashTable table("encrypteddata.txt");
    std::string validUserIDs[] = {"COX", "WARD", "WRAGG", "SHOPP", "BORLING"};
    std::string validUncryptPasscodes[] = {"chzdflilr", "svbspkyhs", "pudagynpc", "bgdfitxap", "yvdpdlmeb"};
    std::string invalidUncryptPasscodes[] = {"ahzdflilr", "avbspkyhs", "audagynpc", "agdfitxap", "avdpdlmeb"};
    std::cout << "Legal:\nUserid\tPassword\tResult\n";
    for(int i = 0; i < 5; i++){
        if(table.lookup(validUserIDs[i])->passcode == user.VNCipher(validUncryptPasscodes[i], "jones"))
                std::cout << validUserIDs[i] << '\t' << validUncryptPasscodes[i] << "\t" << "match\n";
    }
    std::cout << "Legal:\nUserid\tPassword\tResult\n";
    for(int i = 0; i < 5; i++){
        if(table.lookup(validUserIDs[i])->passcode != user.VNCipher(invalidUncryptPasscodes[i], "jones"))
                std::cout << validUserIDs[i] << '\t' << invalidUncryptPasscodes[i] << "\t" << "no match\n";
    }
}
