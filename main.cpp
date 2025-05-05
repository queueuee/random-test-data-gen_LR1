#include <iostream>
#include <fstream>
#include <vector>
#include <random>
#include <limits>
#include <cmath>

void writeArray(std::ofstream& file, const std::vector<double>& array)
{
    for (size_t i = 0; i < array.size(); ++i)
    {
        file << array[i];
        if (i != array.size() - 1)
            file << " ";
    }
    file << "\n";
}

int main()
{
    std::ofstream out("../../test_data.txt");

    out << "\n";
    writeArray(out, {5.0});
    writeArray(out, {1.0, 2.0, 3.0, 4.0});
    writeArray(out, {10.0, 20.0, 30.0});
    writeArray(out, {std::numeric_limits<double>::min(), -1.0});

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(-100.0, 100.0);
    std::vector<double> normal;

    for (int i = 0; i < 6; ++i)
        normal.push_back(dis(gen));

    writeArray(out, normal);
    writeArray(out, {1.0, std::numeric_limits<double>::max()});
    writeArray(out, {-INFINITY, 2.0});
    writeArray(out, {2.0, INFINITY});
    writeArray(out, {NAN, 5.0});

    out.close();
    return 0;
}
