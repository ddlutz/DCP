#include <vector>
#include <unordered_set>
#include <iostream>

// Given an array of ints and a number k, return if any of the two numbers in the array add to k.
bool twosum(std::vector<int>& vec, int k)
{
    std::unordered_set<int> seen;

    for(const auto& i : vec)
    {
        int need = k - i;
        if (seen.find(need) != seen.end())
        {
            return true;
        }

        seen.insert(i);
    }

    return false;
}

int main()
{

    std::vector<int> arr{10,15,3,7};

    std::cout << twosum(arr, 17) << std::endl;
    std::cout << twosum(arr, 20) << std::endl;
}