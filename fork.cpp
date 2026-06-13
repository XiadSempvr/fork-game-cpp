#include <iostream>
#include <random>
#include <vector>

auto sort_rand_index(int arr_size) -> int{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, arr_size - 1);
    return dist(gen);
}

auto mask(std::string word, char mask) -> std::string{
    for(auto& c : word) c = mask;
    return word;
}

int main(){
    std::string arr[] = {
        "banana",
        "uva",
        "maca",
        "peira",
        "anima",
        "pessoa"
    };

    std::string word = arr[sort_rand_index(std::size(arr))];
    std::cout<<"Word: "<<mask(word, '*')<<std::endl;
    
    return 0;
}