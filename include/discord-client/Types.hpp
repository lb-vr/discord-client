#ifndef LBVR_TYPES_HPP
#define LBVR_TYPES_HPP

#include "Param.hpp"
#include <string>
#include <vector>

namespace lbvr {

class snowflake_d : public Param<std::string> {

};

class integer_d : public Param<int64_t> {

};

class string_d : public Param<std::string> {

};

class boolean_d : public Param<bool> {

};

class timestamp_d : public Param<time_t> {

};

class base64_d : public string_d {

};

template <class Item>
class array_d : public Param<std::vector<Item>> {

};

}

#endif