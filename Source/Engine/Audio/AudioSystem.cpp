#include "AudioSystem.h"
namespace JoeBidenWakeup
{
	AudioSystem gAudioSystem;
	bool AudioSystem::initialize()
	{
		FMOD::System_Create(&fmodSystem);
		void* extradriverdata = nullptr;
		fmodSystem->init(32, FMOD_INIT_NORMAL, extradriverdata);
		return true;
	}
	void AudioSystem::shutdown()
	{
		for (auto sound : sounds) sound.second->release();
		sounds.clear();
		fmodSystem->close();
		fmodSystem->release();
	}
	void AudioSystem::update()
	{
		fmodSystem->update();
	}
	void AudioSystem::addAudio(const std::string& name, const std::string& filename)
	{
		if (sounds.find(name) == sounds.end())
		{
			FMOD::Sound* sound = nullptr;
			fmodSystem -> createSound(filename.c_str(), FMOD_DEFAULT, 0, &sound);
			sounds[name] = sound;
		}
	}
	void AudioSystem::playOneShot(const std::string& name, bool loop)
	{
		auto iter = sounds.find(name);
		if (iter != sounds.end())
		{
			FMOD::Sound* sound = iter->second;
			sound->setMode(loop ? FMOD_LOOP_NORMAL : FMOD_LOOP_OFF);
			FMOD::Channel* channel;
			fmodSystem->playSound(sound, 0, false, &channel);
		}
	}
}