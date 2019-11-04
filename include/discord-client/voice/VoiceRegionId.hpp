#ifndef LBVR_VOICE_VOICEREGIONID_HPP
#define LBVR_VOICE_VOICEREGIONID_HPP

#include "VoiceRegionBase.hpp"
namespace lbvr {
namespace voice {

/// 
/// Discord document at https://discordapp.com/developers/docs/resources/voice#voice-region-object
class VoiceRegionId : public VoiceRegionBase {
	VoiceRegionId(const string_d & id);
protected:
};
}
}

#endif