#include "discord-client\Request.hpp"

lbvr::Request::Request(const Method method, const UriPath & path)
	: method_(method), path_(path), body_(json11::Json(nullptr))
{}

lbvr::Request::Request(const Method method, const UriPath & path, const json11::Json & body)
	: method_(method), path_(path), body_(body)
{}
