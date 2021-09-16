To run, simply use Linux console and type "make"
This will run test.cpp's main funtion. I chose to pick random names and passcodes by hand, but it would be somewhat easy to write a method that randomly selects names and passcodes to "test" in the hash method. The output looks correct, and it is run through a function that uses classes and most methods.


A few notes:
    You may notice encrypteddata.txt has a newline on firstline. I had to do that to fix an error that caused the FINAL name to be printed twice in encrypteddata.txt. I couldn't think of another fix at the time.

    I tried to use test driven development for this project, but it was the first time I have ever done so. I pretty much just made up random tests with no outside help to guide me, so they are pretty rough. They can be found in testDriven.cpp and I failed to write tests for the entirety of test.cpp
    If you want to see the tests in action type "make testDriven.exe" and it will run.

    I was not sure i was doing the key correctly for the hash function to be honest, the instructions didnt seem extremely clear on that specific portion. As a result, i simply used "jones" as a key for every single instance, and I wasnt sure what I was supposed to compare, so I ended up choosing to pull from the first letter of each name. It currently hard codes this key into each method, but it would be easy to change it to accept any key for all methods. 

    "make clean" will remove all .o .exe and .txt except for names.txt




    Final thought: To be honest, i felt extremely powerful when i was able to write the VN Cipher by hand, no help involved. Prolly not that impressive, but i felt pretty cool. Here's hoping i actually did it correctly.