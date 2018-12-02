#include <vector>
#include <iostream>

// Given an array of ints, return a new array which is the multiplaction of every element in array except the one at index i.
std::vector<int> multiplyleaveoneout(std::vector<int>& vec)
{
    std::vector<int> res;

    int total = 1;

    for(const auto& i : vec)
    {
        total *= i;
    }

    for(int i = 0; i < vec.size(); i++)
    {
        res.emplace_back(total / vec[i]);
    }

    return res;
}

void printvec(std::vector<int>& vec)
{
    for(const auto& i : vec)
    {
        std::cout << i << " ";
    }

    std::cout << std::endl;
}


std::vector<int> nodivans(std::vector<int> vec)
{
    // Holds the multiplication of each element up to the left-most member of vec
    std::vector<int> leftArray(vec.size());

    // Holds the multiplication of each element on the right-side member of vec
    std::vector<int> rightArray(vec.size());

    leftArray[0] = 1;
    rightArray[vec.size() - 1] = 1;

    for(int i = 1; i < vec.size(); i++)
    {
        leftArray[i] = leftArray[i-1] * vec[i-1];
    }

    for(int i = vec.size() - 2; i >= 0; i--)
    {
        rightArray[i] = rightArray[i+1] * vec[i+1];
    }

    // Construct final answer
    std::vector<int> res;
    for(int i = 0; i < vec.size(); i++)
    {
        res.push_back(leftArray[i] * rightArray[i]);
    }

    //printvec(leftArray);
    //printvec(rightArray);
    //printvec(res);

    return res;


}

void testSol(std::vector<int>& input, std::vector<int> sol)
{
    auto res = multiplyleaveoneout(input);
    std::cout << (res == sol) << std::endl;
}

void testSolNoDiv(std::vector<int>& input, std::vector<int> sol)
{
    auto res = nodivans(input);
    std::cout << (res == sol) << std::endl;
}

int main()
{

    std::vector<int> input1{1,2,3,4,5};
    std::vector<int> res1{120,60,40,30,24};

    testSol(input1, res1);

    std::vector<int> input2{3,2,1};
    std::vector<int> res2{2,3,6};
    testSol(input2, res2);

    testSolNoDiv(input1, res1);
    testSolNoDiv(input2, res2);
}