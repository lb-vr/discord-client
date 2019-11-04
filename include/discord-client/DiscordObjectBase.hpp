#ifndef LBVR_DISCORDOBJECTBASE_HPP
#define LBVR_DISCORDOBJECTBASE_HPP

#include <memory>
#include <string>
#include "Param.hpp"

namespace lbvr {

class DiscordObjectBase : public ParamBase{
public:
	using ParamBase::ParamBase;
	virtual std::string toString(void) const noexcept override { return "tst";  };
	virtual json11::Json toJson(void) const noexcept override { return json11::Json(2); };

protected:

	template <class T>
	class _base;

	template <class T>
	class _null;

	template <class T>
	class _optn;
};

}

#endif