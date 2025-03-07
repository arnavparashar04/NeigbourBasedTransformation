#include <iostream>
#include <vector>

long long NBT(long long num);

std::vector<int> toBinaryVector(int num)
{
    std::vector<int> binary;
    while (num > 0)
    {
        binary.push_back(num % 2);
        num /= 2;
    }
    return binary;
}

int main()
{
    int num;
    std::cout << "Enter a number: ";
    std::cin >> num;

    std::vector<int> binaryNum = toBinaryVector(num);

    std::cout << "Binary: ";
    for (auto it = binaryNum.rbegin(); it != binaryNum.rend(); ++it)
    {
        std::cout << *it;
    }
    std::cout << std::endl;

    std::cout << "Neighbor Based Transformation:" << std::endl;
    std::cout << NBT(num) << std::endl;

    return 0;
}

long long NBT(long long num)
{
    std::vector<int> binary = toBinaryVector(num);
    size_t count = binary.size();

    std::vector<int> transformed(count, 0);

    for (size_t i = 0; i < count - 1; i++)
    {
        transformed[i] = binary[i] ^ binary[i + 1]; 
    }

    long long result = 0;
    for (size_t i = 0; i < count; i++)
    {
        result = (result << 1) | transformed[i]; 
    }

    return result;
}
