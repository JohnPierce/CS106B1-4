//
//  main.cpp
//  CS106B1-4
//  Problem Set 1 pdf problem number 4
//
//  Created by John Pierce on 9/30/16.
//  Copyright © 2016 JohnPierce. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <ctime>


using std::vector;

struct heroT {
    std::string name;
    std::string weakness;
    int powerLevel;
};

struct villianT {
    std::string name;
    std::string evilPlan;
    int attackLevel;
};

void Battle (heroT aang, villianT & zuko)
{
    long int pos = 1;  // changed to long int to match type with std::string::size_type
    
    int level = aang.powerLevel;
    std::string name = zuko.name;
    
    // debug code: std::cout << zuko.name << "\n"; // debug data
    // debug code: std::cout << level << "\n"; // debug data
    
    while (level > 20)
    {
        // std::cout << "evil plan :" << zuko.evilPlan[pos--] << "\n|";
        zuko.evilPlan[pos--] -= ( level / 10 );
        // debug code: std::cout << (level/10) << "\n";
        level /= 2;
        
        std::cout << zuko.evilPlan << "\n";
    }
    
    // debug code: std::cout << "zuko attack level" << zuko.attackLevel << "\n";
    
    zuko.attackLevel -= level; // zuko.attackLevel = zuko.attackLevel - level
    
    // debug code: std::cout << "zuko attack level after " << zuko.attackLevel << "\n";
    
    pos = name.find(aang.weakness);
    while(pos != std::string::npos)  //npos is what it appears to be - no position. This executes, while pos has a value
    {
        
        aang.powerLevel /= 2;
        name.replace(pos, 2, "");
        pos = name.find(aang.weakness, pos);
        
    }
    if (aang.powerLevel > zuko.attackLevel)
    {
        zuko.name = "Loser";
    }
    else
    {
        aang.name = "Big Baby";
    }
    std::cout << "aang name :" << aang.name  << "\n";
    std::cout << "zuko name :" << zuko.name  << "\n";
    
    /* State of the memory here
     * Stack memory:
     * 
     * Battle()
     *   heroT type called ang -> local copy
     *   villianT type called zuko -> pointer to the villianT originally created in main() called tom
     * main()
     *   heroT type named julie, villianT type named tom, pos integer
     *
     * Heap memory
     * - there is no memory used in the heap due to the fact that we do not call a new operator
     * - Heap was allocated in C using malloc and in CPP using the new operator.
     * - Advantage of heap is performance, disadvantage is the maintanence of the memory.
    */
    
    return;
    
}


int main(int argc, const char * argv[]) {
    heroT julie;
    villianT tom;

    /* clean up testing
     * The following code was primarily used to confirm pos-- --> increments negatively on the next occurance
     * and the string[pos] -= int is really saying string char value at position pos will be modified down int characters
     */
    // debug code: int pos =4;
    
    // debug code: std::string foo = "";
    
    // debug code: std::string myString = "happy days are here again happy days are here again";
    
    // debug code: std::string::size_type whatReallyAStringSizeType; // std::string::size_type is an integer guaranteed to support any string length; e.g. a short int may not.
    
    // debug code: std::cout << myString[4] << "\n";
    
    // debug code: std::cout << myString[pos] << "\n";
    
    // debug code: foo = myString[pos--] -= 4;
    
    // debug code: std::cout << "foo: " << foo << " " << myString << "\n";
    
    
    
    
    
    julie.name = "Super Lecturer";
    julie.weakness = "Gr";
    julie.powerLevel = 60;
    
    tom.name = "grumpy grad student";
    tom.evilPlan = "frowning";
    tom.attackLevel = 30;
    
    Battle(julie, tom);
    
    
    return 0;
}
