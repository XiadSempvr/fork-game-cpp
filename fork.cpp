#include <iostream>
#include <random>
#include <fstream>

auto rand_word(const std::string &f) -> std::string
{
    std::ifstream file(f);

    if (!file)
    {
        throw std::runtime_error("File doesn't exist");
    }

    std::vector<std::string> words;
    std::string line;

    while (std::getline(file, line))
    {
        if (!line.empty())
        {
            words.push_back(line);
        }
    }

    if (words.empty())
    {
        throw std::runtime_error("Empty file");
    }

    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<> dist(
        0,
        words.size() - 1);

    return words[dist(gen)];
}

auto mask(std::string word, char mask) -> std::string
{
    for (auto &c : word)
        c = mask;
    return word;
}

int main()
{
    std::cout << "And your word is: " << mask(rand_word("./dictionary/sla.txt"), '#') << std::endl;
    std::string wS = rand_word("./dictionary/sla.txt");
    std::cout << "Come on! Type your guess down below: " << std::endl;

    char guess;
    std::cin >> guess;

    for(char guess : wS){
        if(wS.find(guess)) std::cout<<"Encontrado.";
        break;
    }

    return 0;
}