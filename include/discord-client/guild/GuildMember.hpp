#ifndef LBVR_GUILD_GUILDMEMBERBASE_HPP
#define LBVR_GUILD_GUILDMEMBERBASE_HPP

#include "../object/__DiscordObjectBase.hpp"

namespace lbvr {
namespace guild {

class GuildMember : public object::__internal::__DiscordObjectBase {
public:
	GuildMember() {}
protected:
	class __Impl;
	std::unique_ptr<__Impl> __impl;
	/*
	using user_d = user::UserBase;
	using roles_d = array_d<role::RoleId>;
	_base<user_d>			user_;			///< the user this guild member represents.
	_base<string_d>			nick_;			///< optional. this users guild nickname(if one is set).
	_base<roles_d>			roles_;			///< array of role object ids.
	_base<timestamp_d>		joined_at_;		///< when the user joined the guild.
	_base<timestamp_d>		premium_since_;	///< nullable and optional. when the user used their Nitro boost on the server.
	_base<boolean_d>		deaf_;			///< whether the user is deafened in voice channels.
	_base<boolean_d>		mute_;			///< whether the user is muted in voice channels.
	*/
};

}
}

#endif