#include "dnl.hh"

#include <algorithm>
#include <vector>

size_t min_elt_length(const std::vector<std::string>& req)
{
    std::string res = *std::min_element(req.begin(), req.end(),
                                        [](std::string s1, std::string s2) {
                                            return s1.length() < s2.length();
                                        });
    return res.length();
}

size_t max_elt_length(const std::vector<std::string>& req)
{
    std::string res = *std::min_element(req.begin(), req.end(),
                                        [](std::string s1, std::string s2) {
                                            return s1.length() > s2.length();
                                        });
    return res.length();
}

size_t sum_elt_length(const std::vector<std::string>& req)
{
    std::vector<std::size_t> req_size_t(req.size());

    std::transform(req.begin(), req.end(), req_size_t.begin(),
                   [](std::string str) { return str.length(); });

    std::size_t sum = std::accumulate(req_size_t.begin(), req_size_t.end(), 0);
    return sum;
}

size_t count_elt(const std::vector<std::string>& req, const std::string& elt)
{
    return std::count(req.begin(), req.end(), elt);
}

size_t count_duplicate(const std::vector<std::string>& req)
{
    auto req_tmp = req;
    std::sort(req_tmp.begin(), req_tmp.end());
    auto last = std::unique(req_tmp.begin(), req_tmp.end());
    return std::distance(last, req_tmp.end());
}