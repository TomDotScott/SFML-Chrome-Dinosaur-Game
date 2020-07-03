#pragma once
#include <string>
#include <unordered_map>
#include "SFML/Audio.hpp"

#include "Singleton.h"

class SoundManager final : public Singleton<SoundManager> {
public:
	/**
	 * \brief Constructs a SoundManager object
	 */
	SoundManager();

	/**
	 * \brief Plays a given sound effect
	 * \param _sfxName The file name to play
	 */
	void PlaySFX(const std::string& _sfxName);

	/**
	 * \return the status of the SoundManager
	 */
	sf::SoundSource::Status Status() const { return m_sfx.getStatus(); }

private:
	/**
	 * \brief Loads a given sound effect
	 * \param _fileName The file name to load
	 */
	void LoadSFX(const std::string& _fileName);

	sf::Sound m_sfx;
	std::unordered_map<std::string, sf::SoundBuffer> m_sfxBuffer;

};