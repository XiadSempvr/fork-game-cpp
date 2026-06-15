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
    std::string w = rand_word("./dictionary/sla.txt");

    std::cout << "Your word is: "
              << mask(w, '#')
              << std::endl;

    std::cout << "Type a guess!"
              << std::endl;

    char g;
    std::cin >> g;

    int e, a;
    for (int i = 0; i < w.length(); ++i)
    {
        if (w[i] == g)
        {
            w.replace(w[i], g);
            ++a;
        }
        else
        {
            ++e;
        }
    }

    std::cout<<e<<a<<std::endl;

    return 0;
}