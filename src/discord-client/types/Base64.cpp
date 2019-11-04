#include "discord-client\types\Base64.hpp"
#include <cassert>

lbvr::types::Base64::Base64(const std::string & filepath)
	: Base64(std::ifstream(filepath, std::ios::binary | std::ios::in))
{}

lbvr::types::Base64::Base64(std::ifstream & ifst)
	: __DiscordParam(std::vector<unsigned char>()) {
	if (!ifst) throw FileErrorException("Failed to open file.");
	char p;
	auto & ref = this->ref();
	while (!ifst.eof()) {
		ifst.read(&p, sizeof(unsigned char));
		ref.push_back(static_cast<unsigned char>(p));
	}
}

lbvr::types::Base64::~Base64(void) noexcept
{}

json11::Json lbvr::types::Base64::toJson(void) const {
	return json11::Json(this->toBase64String());
}

std::string lbvr::types::Base64::toString(void) const {
	return "Base64 encoded file. " + std::to_string(this->get().size()) + " Bytes.";
}

std::string lbvr::types::Base64::toBase64String(void) const {
	static_assert(sizeof(unsigned char) == 1, "Type <unsigned char> is not 1byte.");

	// *** Base64 Encode
	unsigned char buf = 0;
	unsigned char res = 0;
	int i = 1;
	std::string base64_str;

	// Covert and put func
	const auto encode = [&base64_str](unsigned char v){
		assert(v <= 63);
		if (v <= 25) base64_str.push_back(v + static_cast<char>('A'));
		else if (v <= 51) base64_str.push_back(v - 26 + static_cast<char>('a'));
		else if (v <= 61) base64_str.push_back(v - 52 + static_cast<char>('0'));
		else if (v == 62) base64_str.push_back(static_cast<char>('+'));
		else base64_str.push_back(static_cast<char>('/'));
	};

	for (auto & c : this->get()) {
		unsigned char tmp = c >> (2 * i);
		res = tmp | buf;
		buf = (c - (tmp << (2 * i))) << (6 - i * 2);
		encode(res);
		
		if (i++ == 3) {
			encode(buf);
			buf = 0;
			i = 1;
		}
	}

	if (i != 0) encode(buf);

	// add '='
	while ((base64_str.size() % 4) != 0) base64_str.push_back('=');

	return base64_str;
}

void lbvr::types::Base64::saveAsFile(const std::string & filepath) const {
	std::ofstream ofst(filepath, std::ios::out | std::ios::binary);
	this->saveAsFile(ofst);
}

void lbvr::types::Base64::saveAsFile(std::ofstream & ofst) const {
	if (!ofst) throw FileErrorException("Failed to open file.");
	for (const auto & c : this->get()) {
		ofst.put(static_cast<unsigned char>(c));
	}
}
