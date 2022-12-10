#ifndef CONSTANTS_H
#define CONSTANTS_H

const double PI = 3.14;

#endif

/*
Include guard:          
--------------          // Tells pre-processor:
#ifndef CONSTANTS_H      // if CONSTANTS_H is not defined
#define CONSTANTS_H      // then define CONSTANTS_H and include <contents>
                        // otherwise, if CONSTANTS_H is defined
<contents>              // don't include its contents again

#endif

The include guard is an instruction to the preprocessor to only include something only once, even when there are more than one include statements, including the same thing. Because the include guard only allows the preprocessor to include the file only once, the same thing will not the defined multiple times and we don't get a compiler re-definition error.
*/