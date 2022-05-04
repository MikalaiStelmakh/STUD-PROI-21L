#include "SongManagerLib.h"
#include <string>
#include <vector>

//SONG

Song::Song() noexcept
{
	name = "No name";
	duration = 0;
}
Song::Song(std::string name, int duration) noexcept
{
	this->name = name;
	this->duration = duration;
}
std::string Song::getName() const noexcept
{
	return name;
}
int Song::getDuration() const noexcept
{
	return duration;
}
void Song::setName(std::string const name) noexcept
{
	this->name = name;
}
void Song::setDuration(int const duration) noexcept
{
	this->duration = duration;
}
bool Song::operator==(Song const& c) const noexcept
{
	return this->name == c.name && this->duration == c.duration;
}
bool Song::operator!=(Song const& c) const noexcept
{
	return this->name != c.name || this->duration != c.duration;
}
std::string Song::play() const noexcept
{
	return "Song: " + name + "\n" + "Duration: " + std::to_string(duration) + "[s].\n";
}
std::string Song::info() const noexcept
{
	return "Song: " + name + "\n" + "Duration: " + std::to_string(duration) + "[s].\n";
}


//PLAYLIST


Playlist::Playlist(std::string name, std::vector<Song> songs, Player &player) noexcept
{
	this->name = name;
	for (int i = 0; i < songs.size(); i++) {
		if (std::count(songs.begin(), songs.end(), songs[i]) > 2) {
			songs.erase(songs.begin() + i);
		}
	}
	this->songs = songs;
	this->player = player;
	this->player.operator+=(*this);
	player.operator+=(*this);
	
}
std::string Playlist::getName() const noexcept
{
	return name;
}
std::vector<Song> Playlist::getSongs() const noexcept
{
	return songs;
}
Player Playlist::getCreator() const noexcept
{
	return player;
}
void Playlist::setName(std::string const name) noexcept
{
	this->name = name;
}
void Playlist::setSongs(std::vector<Song> const songs) noexcept
{
	this->songs = songs;
}
void Playlist::setCreator(Player &new_player) noexcept
{
	//player.operator-=(*this);
	this->player = new_player;
	this->player.operator+=(*this);
	new_player.operator+=(*this);
}
void Playlist::operator+=(Song v) noexcept
{
	int counter = std::count(this->songs.begin(), this->songs.end(), v);
	if (counter < 2)
	{
		this->songs.push_back(v);
	}
}
void Playlist::operator-=(Song v) noexcept
{
	for (int i = 0; i < this->songs.size(); i++)
	{
		if (this->songs[i] == v)
		{
			this->songs.erase(this->songs.begin() + i);
		}
	}
}
bool Playlist::operator==(Playlist const& c) const noexcept
{
	return this->name == c.getName() &&  this->songs == c.getSongs() && this->player == c.getCreator();
}
bool Playlist::operator!=(Playlist const& c) const noexcept
{
	return this->name != c.getName() || this->songs != c.getSongs() || this->player != c.getCreator();
}
std::string Playlist::play() const noexcept
{
	std::string data;
	for (int i = 0; i < this->songs.size(); i++)
	{
		data.append(this->songs[i].play());
	}
	return data;
}
std::string Playlist::playReverse() const noexcept
{
	std::string data;
	for (int i = this->songs.size()-1; i >= 0; i--)
	{
		data.append(this->songs[i].play());
	}
	return data;
}

std::string Playlist::info() const noexcept
{
	int totalDuration = 0;
	for (int i = 0; i < this->songs.size(); i++)
	{
		totalDuration += this->songs[i].getDuration();
	}
	int SongsNumber = this->songs.size();
	return "Number of songs: " + std::to_string(SongsNumber) + ".\n" + "Total duration: " + std::to_string(totalDuration) + "[s].\n";
}


//PLAYER


Player::Player() noexcept
{
	name = "No name";
	std::vector<Playlist> playlists;
	this->playlists = playlists;
}
Player::Player(std::string name) noexcept
{
	this->name = name;
	std::vector<Playlist> playlists;
	this->playlists = playlists;
}

std::string Player::getName() const noexcept
{
	return name;
}
std::vector<Playlist> Player::getPlaylists() const noexcept
{
	return playlists;
}
void Player::setName(std::string const name) noexcept
{
	this->name = name;
}
void Player::operator+=(Playlist const& c) noexcept
{
	this->playlists.push_back(c);
}
void Player::operator-=(Playlist const& c) noexcept
{
	for (int i = 0; i < this->playlists.size(); i++)
	{
		if (this->playlists[i] == c)
		{
			this->playlists.erase(this->playlists.begin() + i);
		}
	}
}
bool Player::operator==(Player const& c) const noexcept
{
	return this->name == c.getName();
}
bool Player::operator!=(Player const& c) const noexcept
{
	return this->name != c.getName();
}
