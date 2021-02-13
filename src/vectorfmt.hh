#include <iterator>
#include <ostream>

template <typename T>
auto operator<<(std::ostream& out, const std::vector<T>& v) -> std::ostream& {
    if (!v.empty()) {
        out << '[';
        for (auto const& i : v) {
            out << i << ", ";
        }

        out << "\b\b]";
    }
    return out;
}