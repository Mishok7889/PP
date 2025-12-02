#pragma once

#include <algorithm>

//template <std::sortable T>
template <typename T>
void sort(T begin, T end)
{
    while (begin != end)
    {
        auto src = begin;
        auto next = std::next(begin);
        while (next != end)
        {
            if (*next < *src) {
                std::iter_swap(src, next);
            }
            ++next;
            ++src;
        }
        --end;
    }
}