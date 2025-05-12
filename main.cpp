#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <random>
#include <sstream>
#include <algorithm>
#include <limits>

std::string vectorToString(const std::vector<double>& vec) {
    std::ostringstream oss;
    oss << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        oss << vec[i];
        if (i != vec.size() - 1)
            oss << ", ";
    }
    oss << "]";
    return oss.str();
}

int main() {
    std::ofstream file("../../test_data.txt");

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dist(-100.0, 100.0);

    const std::string dbl_min = "-1.7976931348623157E+308";

    file << "null|[]|" << dbl_min << "|[\"Input array is null.\"]\n";

    file << "[]|[]|" << dbl_min << "|[\"Input array is empty.\"]\n";

    double v3 = dist(gen);
    double v3_trans = v3 * 2;
    file << "[" << v3 << "]|[" << v3_trans << "]|" << v3_trans << "|[]\n";

    double v4a = dist(gen), v4b = dist(gen);
    file << "[" << v4a << ", " << v4b << "]|[" << v4a << ", " << v4b << "]|" << (v4a + v4b) << "|[]\n";

    double v5a = dist(gen), v5b = dist(gen), v5c = dist(gen);
    double v5c_trans = v5c * 2;
    file << "[" << v5a << ", " << v5b << ", " << v5c << "]|[" << v5a << ", " << v5b << ", " << v5c_trans << "]|"
         << (v5a + v5b) << "|[]\n";

    double v6[] = { dist(gen), dist(gen), dist(gen), dist(gen), dist(gen) };
    double v6_trans[] = { v6[0], v6[1], v6[2], v6[3], v6[4] * 2 };
    double max_pair_sum_v6 = std::max(v6[0] + v6[1], v6[2] + v6[3]);

    file << "[" << v6[0] << ", " << v6[1] << ", " << v6[2] << ", " << v6[3] << ", " << v6[4] << "]|["
         << v6_trans[0] << ", " << v6_trans[1] << ", " << v6_trans[2] << ", " << v6_trans[3] << ", " << v6_trans[4]
         << "]|" << max_pair_sum_v6 << "|[]\n";

    for (int i = 7; i <= 20; ++i) {
        int len = 2 + (i % 5);
        std::vector<double> arr;
        for (int j = 0; j < len; ++j) {
            arr.push_back(dist(gen));
        }

        std::vector<double> transformed = arr;
        if (transformed.size() % 2 != 0) {
            transformed.back() *= 2;
        }

        double maxPairSum = std::numeric_limits<double>::lowest();
        for (size_t j = 0; j + 1 < transformed.size(); j += 2) {
            double sum = transformed[j] + transformed[j + 1];
            if (sum > maxPairSum)
                maxPairSum = sum;
        }

        // Если только один элемент — он умножен на 2 и является и Transformed, и MaxPairSum
        if (transformed.size() == 1) {
            maxPairSum = transformed[0];
        }

        file << vectorToString(arr) << "|" << vectorToString(transformed) << "|" << maxPairSum << "|[]\n";
    }

    file.close();
    return 0;
}
