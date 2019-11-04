/*
#ifndef LBVR_VOICE_VOICEREGIONBASE_HPP
#define LBVR_VOICE_VOICEREGIONBASE_HPP

#include "../DiscordObjectBase.hpp"

namespace lbvr {
namespace voice {

class VoiceRegionId;
class voice_region_d;

/// 
/// Discord document at https://discordapp.com/developers/docs/resources/voice#voice-region-object
class VoiceRegionBase : public DiscordObjectBase {
protected:	
	_base<string_d>		id_;			///< unique ID for the region.
	_base<string_d>		name_;			///< name of the region.
	_base<boolean_d>	vip_;			///< true if this is a vip - only server.
	_base<boolean_d>	optimal_;		///< true for a single server that is closest to the current user's client.
	_base<boolean_d>	deprecated_;	///< whether this is a deprecated voice region(avoid switching to these).
	_base<boolean_d>	custom_;		///< whether this is a custom voice region(used for events / etc).
};

}
}

#endif
*/