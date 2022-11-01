#include <vector>
#include <iostream>
 
int main()
{
    std::vector<char> letters;

    std::cout << "size of letters: " << letters.size() << std::endl;
    std::cout << "capacity of letters: " << letters.capacity() << std::endl;

    letters.push_back('o');
    letters.push_back('m');
    letters.push_back('g');
    letters.push_back('w');
    letters.push_back('t');
    letters.push_back('f');

    std::cout << "size of letters: " << letters.size() << std::endl;
    std::cout << "capacity of letters: " << letters.capacity() << std::endl;

    if (!letters.empty()) {
        std::cout << "The first character is '" << letters.front() << "'.\n";
        std::cout << "The last character is '" << letters.back() << "'.\n";
    }
}
