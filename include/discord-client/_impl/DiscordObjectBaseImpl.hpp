#ifndef LBVR_IMPL_DISCORDOBJECTBASEIMPL_HPP
#define LBVR_IMPL_DISCORDOBJECTBASEIMPL_HPP

#include "../DiscordObjectBase.hpp"
#include <memory>
#include <string>


namespace lbvr {

template <class T>
class DiscordObjectBase::_base : ParamBase {
public:
	_base(void) noexcept : param_(nullptr) {
		static_assert(std::is_base_of<ParamBase, T>::value, "T is not derived from ParamBase.");
	}

	_base(const _base & cp)
		: param_(cp.param_ ? std::make_unique<T>(*cp.param_) : nullptr) {}

	_base(_base && mv)
		: param_(mv.param_ ? std::move(mv.param_) : nullptr) {}

	virtual void set(const T & value) {
		this->param_ = std::make_unique<T>(value);
	}

	virtual bool isSet(void) const {
		return static_cast<bool>(this->param_);
	}

	virtual std::string toString(void) const noexcept override {
		return (this->isSet() ? this->get()->toString() : "Null");
	};

	virtual json11::Json toJson(void) const noexcept override {
		return (this->isSet() ? this->get()->toJson() : json11::Json(nullptr));
	};

private:
	std::unique_ptr<T> param_;
};


template <class T>
class DiscordObjectBase::_null : public DiscordObjectBase::_base<T> {
public:
	using _base::_base<T>;
	_null(void) noexcept : is_set(false) {
		static_assert(std::is_base_of<ParamBase, T>::value, "T is not derived from ParamBase.");
	}

	virtual void set(const T & value) override {
		_base::set(value);
		this->is_set_ = true;
	}

	void setNull(void) {
		_base::set(nullptr);
	}

	virtual bool isSet(void) const override {
		return this->is_set_;
	}

private:
	bool is_set_;
};

template <class T>
class DiscordObjectBase::_optn : public DiscordObjectBase::_base<T, Key> {
};

}

#endif