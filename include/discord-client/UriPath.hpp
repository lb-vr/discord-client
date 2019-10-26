#ifndef LBVR_URIPATH_HPP
#define LBVR_URIPATH_HPP

#include <string>
#include <unordered_map>

namespace lbvr {

class UriPath {
public:
	
	/// @brief Constructor with value.
	/// @param path uri path with {placeholders}.
	/// @param args arguments.
	UriPath(const std::string & path, const std::unordered_map<std::string, std::string> & args);

	/// @brief get uri replaced placeholder
	/// @return uri
	const std::string & getUri() const;
	
	/// @brief cast to string
	/// @sa getUri()
	operator const std::string & () const;

private:
	const std::string path_;
	const std::unordered_map<std::string, std::string> args_;
	std::string uri_;
};

}

#endif