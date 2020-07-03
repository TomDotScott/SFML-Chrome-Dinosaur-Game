#include "SoundManager.h"
SoundManager::SoundManager() {
	LoadSFX("100");
	LoadSFX("dead");
	LoadSFX("jump");
}

void SoundManager::PlaySFX(const std::string& _sfxName) {
	m_sfx.setBuffer(m_sfxBuffer.at(_sfxName));
	m_sfx.play();
}

void SoundManager::LoadSFX(const std::string& _fileName) {
	auto newSound{ sf::SoundBuffer() };
	newSound.loadFromFile("Resources/" + _fileName + ".wav");
	m_sfxBuffer.insert(std::pair<std::string, sf::SoundBuffer>(_fileName, newSound));
}