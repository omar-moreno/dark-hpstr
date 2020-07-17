//~~~~~~~~~~~~~~~~//
//   C++ StdLib   //
//~~~~~~~~~~~~~~~~//
#include <csignal>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <stdexcept> 

//~~~~~~~~~~~~~~~~//
//   processing   //
//~~~~~~~~~~~~~~~~//
#include "ConfigurePython.h"

using namespace std; 

void displayUsage(); 

int main(int argc, char **argv) { 

    if (argc < 2) {
        displayUsage(); 
        return EXIT_FAILURE;
    }

    int ptrpy = 1;
    for (ptrpy = 1; ptrpy < argc; ptrpy++) {
        std::cout << argv[ptrpy] << std::endl;
        if (strstr(argv[ptrpy], ".py"))
            break;
    }

    if (ptrpy == argc) {
        displayUsage(); 
        std::cout << "  ~~~ No python script provided (must end in .py). ~~~" << std::endl;
        return EXIT_FAILURE;
    }

    try {
        
        std::cout << "~~~~ [ dark-hpstr ]: Loading configuration ~~~~~~~~" << std::endl;
        
        ConfigurePython cfg(argv[ptrpy], argv + ptrpy + 1, argc - ptrpy);

        std::cout << "~~~~ [ dark-hpstr ]: Configuration load complete  ~~~~~~~~" << std::endl;

        std::unique_ptr<Process> p = cfg.makeProcess();
        
        std::cout << "~~~~ [ dark-hpstr ]: Process initialized.  ~~~~~~~~" << std::endl;

        // If Ctrl-c is used, immediately exit the application.
        struct sigaction act;
        memset (&act, '\0', sizeof(act));
        if (sigaction(SIGINT, &act, NULL) < 0) {
            perror ("sigaction");
            return 1;
        }

        std::cout << "~~~~ [ dark-hpstr ]: Starting event processing ~~~~~~~~" << std::endl;
        
        p->run();
        
        std::cout << "~~~~ [ dark-hpstr ]: Event processing complete  ~~~~~~~~" << std::endl;

    } catch (exception& e) { 
    
    } 

    return EXIT_SUCCESS;

}

void displayUsage() {
    printf("Usage: dark-hpstr [application arguments] {configuration_script.py}"
           " [arguments to configuration script]\n");
}
