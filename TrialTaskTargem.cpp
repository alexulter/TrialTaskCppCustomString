#include "String.h"
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char* argv[])
{
    vector<String> strings;
    int i = 1;
    while (i < argc) {
        /*std::cout << "Argument " << i + 1 << ": " << argv[i]
            << std::endl;*/
        strings.push_back(String(argv[i]));
        i++;
    }

    sort(strings.rbegin(), strings.rend());

    cout << "Sorted:" << endl;
    for (int i = 0; i < strings.size(); i++)
    {
        cout << strings[i] << endl;
    }
}
