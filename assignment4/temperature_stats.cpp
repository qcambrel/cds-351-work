#include <iostream>
#include <fstream>
#include <string>
#include <vector>

std::vector<double> read_temperatures(std::string filename) {
    std::string line;
    std::vector<double> temperatures;
    std::ifstream infile(filename);
    if (!infile){
        std::cerr << "Error: " << filename << " not found in the current directory" << std::endl;
        exit(0);
    }
    while (infile >> line){
        double temperature = std::stod(line);
        temperatures.push_back(temperature);
    }
    infile.close();
    return temperatures;
}

double get_max_temperature(std::vector<double> temperatures) {
    double max_temperature = temperatures.at(0);
    for (double temperature : temperatures){
        if (temperature > max_temperature){
            max_temperature = temperature;
        }
    }
    return max_temperature;
}

double get_mean_temperature(std::vector<double> temperatures) {
    double temperature_sum = 0;
    for (double temperature : temperatures){
        temperature_sum += temperature;
    }
    return temperature_sum / temperatures.size();
}

int main() {
    std::vector<double> temperatures = read_temperatures("temperatures.txt");
    double max_temperature = get_max_temperature(temperatures);
    double mean_temperature = get_mean_temperature(temperatures);
    std::cout << "Size: " << temperatures.size() << std::endl;
    std::cout << "Max: " << max_temperature << std::endl;
    std::cout << "Mean: " << mean_temperature << std::endl;
    return 0;
}