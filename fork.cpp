#include <iostream>
#include <random>

auto sort_rand_index(int arr_size) -> int{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, arr_size - 1);
    return dist(gen);
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

    std::cout << arr[sort_rand_index(std::size(arr))] << std::endl;
    
    return 0;
}