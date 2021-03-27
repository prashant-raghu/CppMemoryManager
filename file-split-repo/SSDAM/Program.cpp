#include <bits/stdc++.h>
#include "../PracticalClass.cpp"
#include "../ProgramEnv.h"
#include "../ProgramEnv.cpp"
#include "../BenchmarkFunction.cpp"
#include "./SSDAM.cpp"

using namespace std;

int main()
{
    SSDAM<MyPracticalClass> memMan(BASE_SIZE);

    BENCHMARK(MyPracticalClass, memMan, BASE_SIZE, NO_OF_TIMES)

    return 0;
} 
