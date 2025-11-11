#pragma once
#include <iostream>
#include <optional>

std::optional<int> get(bool ok) {
    if (ok) return 10;
    return std::nullopt;
}
