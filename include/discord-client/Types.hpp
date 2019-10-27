#ifndef LBVR_TYPES_HPP
#define LBVR_TYPES_HPP

#include "Param.hpp"
#include <string>
#include <vector>

namespace lbvr {

class snowflake_d : public Param<std::string> {

};

class integer_d : public Param<int> {
public:
	using Param<int>::Param;
	// TEMP
	virtual std::string toString(void) const noexcept {
		return std::to_string(this->get());
	};

	virtual json11::Json toJson(void) const noexcept {
		return json11::Json(this->get());
	}
};

class string_d : public Param<std::string> {
public:
	using Param<std::string>::Param;

	virtual std::string toString(void) const noexcept {
		return this->get();
	}
	virtual json11::Json toJson(void) const noexcept {
		return json11::Json(this->get());
	}
};

class boolean_d : public Param<bool> {

};

class timestamp_d : public Param<time_t> {

};

class base64_d : public string_d {

};

template <class Item>
class array_d : public Param<std::vector<Item>> {
public:
	array_d(void) noexcept : Param({}) {}
	using Param<std::vector<Item>>::Param;

	void add(const Item & item) { this->getRef().push_back(item); }
	void add(Item && item) { this->getRef().emplace_back(std::move(item)); }

	virtual std::string toString(void) const noexcept {
		static_assert(std::is_base_of<ParamBase, Item>::value, "Item is not derived from ParamBase.");
		std::string ret = "";
		for (const auto & item : this->get()) {
			ret += (ret.empty() ? "( " : ", ") + item.toString();
		}
		ret += " )";
		return ret;
	}
	virtual json11::Json toJson(void) const noexcept {
		static_assert(std::is_base_of<ParamBase, Item>::value, "Item is not derived from ParamBase.");
		std::vector<json11::Json> ret;
		for (const auto & item : this->get()) {
			ret.emplace_back(item.toJson());
		}
		return json11::Json(ret);
	}
};

}

#endif