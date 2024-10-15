/*
This software can be freely modified -- Please feel free to add any features or bug fixes
AUTHOR: WorldsDumbestCoder
GitHub: https://github.com/WorldsDumbestCoder
*/
// Today is Monday October 14th, 2024
#include <map>
#include <iostream>
//#include <fstream>
#include <string>
#include <algorithm>

/**
 * This class provides the mapping and functions for/of the intermediate representation (IR) to assembly language.
 * It contains three maps, `x64`, `x32`, and `x16`, that map human-readable instruction names to their corresponding assembly language instructions.
 * The class provides three functions, `get_x16instruction()`, `get_x32instruction()`, and `get_x64instruction()`, that return the assembly language instruction for a given human-readable instruction name, if it is valid.
 * The class is designed to reduce function call overhead by inlining all of its code.
 * By x16, x32 and x64, I am referring to the 16 bit, 32 bit and 64 bit x86 architectures.
 * --WorldsDumbestCoder
 */
class IR{
private:



    // I am inlining all of my code so then I can maintain reduce the function call overhead.
    // And the reason why I am using std:: over using namespace std is because then I don't import the whole entire standard library's namespace which I don't think is
    // needed

    // This is the human readable mapping of x64 assembly -- WorldsDumbestCoder
    std::map<std::string, std::string>x64 = {
        {"ACCUMULATOR", "RAX"},
        {"BASE", "RBX"},
        {"COUNTER", "RCX"},
        {"STACKPOINTER", "RSP"},
        {"DATA", "RDX"},
        {"COMPARE", "CMP"},
        {"JUMP", "JMP"},
        {"JUMPLESS", "JL"},
        {"JUMPEQUAL", "JE"},
        {"JUMPIFNOTEQUAL", "JNE"},
        {"JUMPIFGREATER", "JG"},
        {"JUMPIFNOTGREATER", "JNG"},
        {"PUSH", "PUSH"},
        {"POP", "POP"},
        {"MOVE", "MOV"},
    };
    



    // This is the human readable mapping of x32 assembly -- WorldsDumbestCoder
    std::map<std::string, std::string>x32 = {
        {"ACCUMULATOR", "EAX"},
        {"BASE", "EBX"},
        {"COUNTER", "ECX"},
        {"DATA", "EDX"},
        {"STACKPOINTER", "ESP"},
        {"COMPARE", "CMP"},
        {"PUSH", "PUSH"},
        {"POP", "POP"},
        {"MOVE", "MOV"},
    };
    



    // This is the human readable mapping of x16 ASM -- WorldsDumbestCoder
    std::map<std::string, std::string>x16 = {
        {"ACCUMULATOR", "AX"},
        {"ACCUMULATORLOW", "AL"},
        {"ACCUMULATORHIGH", "AH"},
        {"HIGHSTACK", "SH"},
        {"LOWSTACK", "SL"},
        {"STACKPOINTER", "SP"},
        {"COMPARE", "CMP"},
        {"JUMP", "JMP"},
        {"BASE", "BX"},
        {"LOWBASE", "BL"},
        {"HIGHBASE", "BH"},
        {"HIGHCOUNTER", "CH"},
        {"LOWCOUNTER", "CL"},
        {"HIGHDATA", "DH"},
        {"LOWDATA", "DL"},
        {"PUSH", "PUSH"},
        {"POP", "POP"},
        {"MOVE", "MOV"},
    };



public:
    // Any ideas for anything better than x16, x32 and x64? -- WorldsDumbestCoder
    
    // This function returns the equivalent x16 assembly instruction if the parameter `instruction` is a valid instruction -- WorldsDumbestCoder

    inline std::string get_x16instruction(std::string instruction){
        // This here checks if `instruction` is in xs16
        if(this->x16.find(instruction) != this->x16.end()){
            return this->x16[instruction] + "\n";
        }else{
            return "Invalid x16 instruction \n";
        }
        return "";
    }

                                                                                            


    // This function returns the x32 IR equivalent of the parameter `instruction` if the instruction is a valid instruction -- WorldsDumbestCoder
    inline std::string get_x32instruction(std::string instruction){
        if(this->x32.find(instruction) != this->x32. end()){
            return this->x32[instruction] + "\n";   // This will return the x64 equivalent -- WorldsDumbestCoder
        }else{
            return "Invalid x32 instruction!\n";    
        }
        return "";
    }


    // This function returns the equivalent x64 instruction if the parameter `instruction` is valid. -- WorldsDumbestCoder
    inline std::string get_x64instruction(std::string instruction){
        if(this->x64.find(instruction) != this->x64.end()){
            return this->x64[instruction] + "\n";  // This will return the x64 assembly equivalent -- WorldSDumbestCoder
        }else{
           return "Invalid x64 instruction!\n";
        }
        return "";
    }
};




int main(){
    IR ir;
    /*
    std::fstream f;
    std::string fname;
    std::cout << "Enter the file name > ";
    std::cin >> fname;
    if(f){
    }else{
        std::cout << "The file " << fname << " does not exist!\n";
    }
    f.close();
    */
    std::cout << ir.get_x64instruction("POP"); 
    return 0;
}