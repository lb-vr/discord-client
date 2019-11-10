#ifndef LBVR_REQUEST_HPP
#define LBVR_REQUEST_HPP

#include "UriPath.hpp"
#include "json11.hpp"

namespace lbvr {

class RequestFailedException : public std::runtime_error {
public:
	using std::runtime_error::runtime_error;
};

class Request {
public:
	enum Method {
		GET, POST, PUT, PATCH, DELETE
	};

	Request(const Method method, const UriPath & path);
	Request(const Method method, const UriPath & path, const json11::Json & body);

	json11::Json send(void) const;

private:
	const Method method_;
	const UriPath path_;
	const json11::Json body_;
};

}

#endif