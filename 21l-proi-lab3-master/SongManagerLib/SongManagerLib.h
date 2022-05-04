#pragma once
#include <string>
#include <vector>

class Playlist;

class Song
{
private:
	std::string name;
	int duration;
public:
	Song() noexcept;
	Song(std::string name, int duration) noexcept;
	std::string getName() const noexcept;
	int getDuration() const noexcept;
	void setName(std::string const name) noexcept;
	void setDuration(int const duration) noexcept;

	bool operator==(Song const& c) const noexcept;
	bool operator!=(Song const& c) const noexcept;

	std::string play() const noexcept;
	std::string info() const noexcept;
};

class Player
{
private:
	std::string name;
	std::vector<Playlist> playlists;
public:
	Player() noexcept;
	Player(std::string name) noexcept;
	std::string getName() const noexcept;
	std::vector<Playlist> getPlaylists() const noexcept;
	void setName(std::string const name) noexcept;

	void operator+=(Playlist const& c) noexcept;
	void operator-=(Playlist const& c) noexcept; //except
	bool operator==(Player const& c) const noexcept;
	bool operator!=(Player const& c) const noexcept;
};

class Playlist
{
private:
	std::string name;
	std::vector<Song> songs;
	Player player;
	Player player_ptr;
public:
	Playlist(std::string name, std::vector<Song> songs, Player &player) noexcept;
	std::string getName() const noexcept;
	std::vector<Song> getSongs() const noexcept;

	Player getCreator() const noexcept;

	void setName(std::string const name) noexcept;
	void setSongs(std::vector<Song> const songs) noexcept; //except
	void setCreator(Player &new_player) noexcept;

	void operator+=(Song v) noexcept; //except
	void operator-=(Song v) noexcept; //except

	bool operator==(Playlist const& c) const noexcept;
	bool operator!=(Playlist const& c) const noexcept;

	std::string play() const noexcept;
	std::string playReverse() const noexcept;
	std::string info() const noexcept;
};
