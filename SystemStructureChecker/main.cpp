//
//  main.cpp
//  SystemStructureChecker
//
//  Created by Yoshihiro Furukawa on 2023/11/29.
//

#include <memory>
#include <iostream>
#include <string>
#include "System.h"

int main(int argc, const char * argv[]) {
    auto system = std::make_unique<System>("System");
    
    return EXIT_SUCCESS;
}
