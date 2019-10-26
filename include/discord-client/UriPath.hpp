#ifndef LBVR_URIPATH_HPP
#define LBVR_URIPATH_HPP

#include <string>
#include <unordered_map>

namespace lbvr {

class UriPath {
public:

	UriPath(const std::string & path, const std::unordered_map<std::string, std::string> & args);
	const std::string & getUri() const;
	operator const std::string & () const;
	
	// const std::string bucket(const RequestMethod & method) const;


private:
	const std::string path_;
	const std::unordered_map<std::string, std::string> args_;
	std::string uri_;
};

}

#endif