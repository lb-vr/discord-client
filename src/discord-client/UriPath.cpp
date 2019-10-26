#include "discord-client/UriPath.hpp"
#include <cassert>

lbvr::UriPath::UriPath(const std::string & path, const std::unordered_map<std::string, std::string>& args)
	: path_(path), args_(args)
{
	// replace placeholder
	this->uri_ = this->path_;
	size_t start = std::string::npos;
	size_t end = std::string::npos;
	const auto _findNextPlaceholder = [&]() -> bool {
		start = this->uri_.find('{');
		end = this->uri_.find('}');
		return (start != std::string::npos && end != std::string::npos);
	};

	while (_findNextPlaceholder()) {
		const std::string placeholder = this->uri_.substr(start + 1, end - start - 1);
		assert(args.count(placeholder));
		const std::string value = args.at(placeholder);
		this->uri_ = this->uri_.substr(0, start) + value + this->uri_.substr(end + 1);
	}
}

const std::string & lbvr::UriPath::getUri() const {
	return this->uri_;
}

lbvr::UriPath::operator const std::string & () const {
	return this->getUri();
}

