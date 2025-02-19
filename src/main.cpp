#include <iostream>
#include <vector>

bool IsPrime(int n, int c)
{
    if (n < 2)
        return false;

    if (c < 2)
        return true;

    if (n % c == 0)
        return false;

    return IsPrime(n, --c);
}

bool IsPrime(int n)
{
    return IsPrime(n, n - 1);
}

std::vector<int> GetPrimesInRange(int nMin, int nMax)
{
    std::vector<int> primes = std::vector<int>();

    for (int i = nMin; i < nMax; i++)
    {
        if (IsPrime(i))
        {
            primes.push_back(i);
        }
    }

    return primes;
}

int main(int argc, char **argv)
{
    std::cout << "Hello, podman" << std::endl;

    std::vector<int> primes = GetPrimesInRange(1, 100);

    for (auto &&i : primes)
    {
        std::cout << i << " ";
    }

    std::cout << std::endl;

    return 0;
}