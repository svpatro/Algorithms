/*
Implementation of Gallian's Greedy Algorithm for finite abelian groups.
*/

#include <iostream>
#include <vector>
#include <math.h>
#include <queue>
#include <utility>

int main(){
    int mod;
    std::cout << "What is the modulus?: " << std::endl;

    /* 
    define:
    - Integer modulus (i.e. 96 = Z mod 96) 
    - Paired Priority Queue: <order, element>
    - Vector containing max order elements
    - Vector for elements of cyclic group
    */

    std::cin >> mod;
    std::priority_queue<std::pair<int, int>> groupOrders;
    std::vector<int> max_elements;
    std::vector<int> cyclic_group;

    // Get multiplicative inverses and their order
    // Pushed as <order, element> for max heap property.

    for (int i = 1; i < mod; i++){
        for (int j = 1; j < mod; j++){
            if (int(pow(i, j)) % mod == 1){
                groupOrders.push({j, i});
                break;
            }
        }
    }

    // Pop PQ and collect max order elements

    int max_element = 1;
    int max_value = 1;
    while (!groupOrders.empty()){
        auto top = groupOrders.top();
        if (top.first >= max_value){
            max_element = top.second;
            max_value = top.first;
            if (top.second != 1){
                max_elements.push_back(max_element);
            }
        }
        groupOrders.pop();
    }

    // Generate cyclic group from max order elements

    for (int i = 1; i <= max_value; i++){
        cyclic_group.push_back(int(pow(max_elements.at(0), i))%mod);
    }

    if (mod / cyclic_group.size()){
        std::cout << "Z_" << cyclic_group.size() << " x";
    }
    std::cout << std::endl;

    return 0;
}