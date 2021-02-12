#include <iterator>
#include <ostream>

template <typename T>
auto operator<<(std::ostream& out, const std::vector<T>& v) -> std::ostream& {
    if (!v.empty()) {
        out << '[';
        std::copy(v.begin(), v.end(), std::ostream_iterator<T>(out, ", "));
        out << "\b\b]";
    }
    return out;
}