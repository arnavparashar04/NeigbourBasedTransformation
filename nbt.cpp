#include <iostream>
long long POR(long long num);

long long decimalToBinaryNumber(int num)
{
    long long binaryNumber = 0;
    long long placeValue = 1;
    while (num > 0)
    {
        int bit = num % 2;
        binaryNumber += bit * placeValue;
        placeValue *= 10;
        num /= 2;
    }
    return binaryNumber;
}
int main()
{
    int num;
    std::cout << "Enter a number: ";
    std::cin >> num;
    long long binaryNum = decimalToBinaryNumber(num);
    std::cout << binaryNum << std::endl;
    std::cout << "Neigbour Based Transformation:" << std::endl;
    std::cout << NBT(binaryNum) << std::endl;
    return 0;
}

long long NBT(long long num)
{
    long long temp_num = num;
    if (temp_num == 0)
        return 1;
    int count = 0;
    if (temp_num < 0)
    {
        temp_num *= -1;
    }
    while (temp_num > 0)
    {
        temp_num /= 10;
        count++;
    }
    long long m = 1;
    for (int i = 0; i <= count; i++)
    {
        m *= 10;
    }
    num += m;
    int a[count + 1] = {0};
    for (int i = 0; i <= count; i++)
    {
        a[i] = num % 10;
        num /= 10;
    }
    for (int i = 0; i < count; i++)
    {
        if (a[i] == 0 && a[i + 1] == 1)
            a[i] = 1;
        else if (a[i] == 1 && a[i + 1] == 0)
            a[i] = 1;
        else
            a[i] = 0;
    }
    long long result = 0;
    for (int i = count; i >= 0; i--)
    {
        result = result * 10 + a[i];
    }
    return result;
}
