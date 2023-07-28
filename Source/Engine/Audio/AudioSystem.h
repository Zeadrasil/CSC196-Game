#pragma once
#include "fmod/core/inc/fmod.hpp"
#include <string>
#include<map>
namespace JoeBidenWakeup
{
	class AudioSystem
	{
	public:
		AudioSystem() = default;
		~AudioSystem() = default;
		bool initialize();
		void shutdown();
		void update();
		void addAudio(const std::string& name, const std::string& filename);
		void playOneShot(const std::string& name, bool loop = false);
	private:
		FMOD::System* fmodSystem;
		std::map<std::string, FMOD::Sound*> sounds;
	};
	extern AudioSystem gAudioSystem;
}

