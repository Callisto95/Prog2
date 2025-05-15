#ifndef BLATT3_CONSTANTS_H
#define BLATT3_CONSTANTS_H


#include <vector>


namespace GameObjects {

    class Constants {
    public:
        static unsigned int constexpr seaSizeX = 3;
        static unsigned int constexpr seaSizeY = 3;

        static std::vector<unsigned int> const shipSizes;
    };

}


#endif //BLATT3_CONSTANTS_H
