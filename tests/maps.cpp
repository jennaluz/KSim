#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>

struct cityRecord {
    std::string name;
    uint64_t population;
    double longitude;
    double latitude;
}

int main()
{
    std::vector<cityRecord> cities;
    cities.emplace_back("Melbourne", 5000000, 2.4, 9.4);
    cities.emplace_back("Moscow", 5000000, 2.4, 9.4);
    cities.emplace_back("Ewa Beach", 5000000, 2.4, 9.4);
    cities.emplace_back("Kailua", 5000000, 2.4, 9.4);

    std::map<std::string, cityRecord> cityMap;
    cityMap["Melbourne"] = {"Melbourne", 5000000, 2.4, 9.4};
    cityMap["Kailua"] = {"Kailua", 5000000, 2.4, 9.4};
}
