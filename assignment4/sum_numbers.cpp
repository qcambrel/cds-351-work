#include <iostream>
#include <fstream>
#include <string>
#include <vector>

std::vector<long long> read_integers(std::string filename, int n) {
    std::string line;
    std::vector<long long> integers;
    std::ifstream infile(filename);
    if (!infile){
        std::cerr << "Error: " << filename << " not found in the current directory" << std::endl;
        exit(0);
    }
    for (int i = 0; i < n; i++){
        infile >> line;
        long long integer = std::stoll(line);
        integers.push_back(integer);
    }
    infile.close();
    return integers;
}

long long sum_natural_numbers(long long integer) {
    return integer * (integer + 1) / 2;
}

int main() {
    auto integers = read_integers("integers.txt", 4);
    for (long long integer : integers) {
        std::string result;
        if (integer < 0) {
            result = "Error: integer must be non-negative";
        } else {
            result = std::to_string(sum_natural_numbers(integer));
        }
        std::cout << integer << ": " << result << std::endl;
    }
    return 0;
}