#include <cmath>
#include <iostream>

// Compute the number of grains of rice on the nth square when
// each square yields 2^(n-1) grains of rice then find the number of
// squares it takes to add up to at least 1,000, at least 1,000,000,
// and at least 1,000,000,000 grains of rice respectively.

int main(){
    long long grains_total = 0;
    int squares = 64;
    int squares_thousand = 0, squares_million = 0, squares_billion = 0;

    int square;
    long long grains_square;

    for (int i = 0; i < squares; i++){
        std::cout << "\ni = " << i << std::endl;

        grains_square = pow(2, i);
        grains_total += grains_square;
        std::cout << "grains_square = " << grains_square << std::endl;

        square = i + 1;
        std::cout << "square = " << square << std::endl;

        if (!squares_thousand && grains_total >= 1000){
            squares_thousand = i + 1;
            std::cout << "squares_thousand = " << squares_thousand << std::endl;
        }

        if (!squares_million && grains_total >= 1000000){
            squares_million = i + 1;
            std::cout << "squares_million = " << squares_million << std::endl;
        }

        if (!squares_billion && grains_total >= 1000000000){
            squares_billion = i + 1;
            std::cout << "squares_billion = " << squares_billion << std::endl;
        }

        std::cout << "grains_total = " << grains_total << std::endl;
    }

    std::cout << "\nFinal Results:" << std::endl;
    std::cout << "squares_thousand = " << squares_thousand << std::endl;
    std::cout << "squares_million = " << squares_million << std::endl;
    std::cout << "squares_billion = " << squares_billion << std::endl;

    return 0;
}