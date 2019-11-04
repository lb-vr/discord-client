#ifndef LBVR_TYPES_BASE64_HPP
#define LBVR_TYPES_BASE64_HPP

#include "__DiscordParam.hpp"
#include <vector>
#include <fstream>

namespace lbvr {
namespace types {

class Base64 : public __internal::__DiscordParam<std::vector<unsigned char>> {
public:
	class FileErrorException : public std::runtime_error {
	public:
		using std::runtime_error::runtime_error;
	};

	Base64(const std::string & filepath);
	Base64(std::ifstream & ifst);
	virtual ~Base64(void) noexcept;

	virtual json11::Json toJson(void) const override;
	virtual std::string toString(void) const override;
	std::string toBase64String(void) const;
	void saveAsFile(const std::string & filepath) const;
	void saveAsFile(std::ofstream & ofst) const;
};

}
}

#endif