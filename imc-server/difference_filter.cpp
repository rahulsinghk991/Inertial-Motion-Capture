#include "difference_filter.hpp"

double DifferenceFilter::value(double value) {
    // Get value
    double return_value = zero_value;

    for(int i = 0; i < list.size(); i++) {
        if(fabs(list[i] - value) >= difference_threshold) {
            return_value = value;
            break;
        }
    }

    // Add to list
    list.push_back(value);

    while(list.size() > list_size) {
        list.pop_back();
    }

    return return_value;
}