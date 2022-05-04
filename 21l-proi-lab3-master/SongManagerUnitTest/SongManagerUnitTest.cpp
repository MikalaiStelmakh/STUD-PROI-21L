#include "CppUnitTest.h"
#include "../SongManagerLib/SongManagerLib.h"
#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SongManagerUnitTest
{
	TEST_CLASS(SongManagerUnitTest)
	{
	public:
		
		TEST_METHOD(SongGetName)
		{
			Song c("Sandstorm", 60);
			std::string expected = "Sandstorm";
			Assert::AreEqual(expected, c.getName());
		}
		TEST_METHOD(SongGetDuration)
		{
			Song c("Sandstorm", 60);
			Assert::AreEqual(60, c.getDuration());
		}
		TEST_METHOD(SongSetName)
		{
			Song c("Sandstorm", 60);
			c.setName("Merry Christmas");
			std::string expected = "Merry Christmas";
			Assert::AreEqual(expected, c.getName());
		}
		TEST_METHOD(SongSetDuration)
		{
			Song c("Sandstorm", 60);
			c.setDuration(15);
			Assert::AreEqual(15, c.getDuration());
		}
		TEST_METHOD(SongOperatorEqual)
		{
			Song c("Sandstorm", 60);
			Song v("Sandstorm", 60);
			Assert::IsTrue(c == v);
		}
		TEST_METHOD(SongOperatorNotEqual)
		{
			Song c("Sandstorm", 60);
			Song v("Sandstorm", 120);
			Assert::IsTrue(c != v);
		}
		TEST_METHOD(SongPlayAndInfo)
		{
			Song c("Sandstorm", 90);
			std::string expected = "Song: Sandstorm\nDuration: 90[s].\n";
			Assert::AreEqual(expected, c.play());
			Assert::AreEqual(expected, c.info());
		}
		TEST_METHOD(PlayerGetName)
		{
			Player player("Jack");
			std::string expected = "Jack";
			Assert::AreEqual(expected, player.getName());
		}
		TEST_METHOD(PlaylistGetName)
		{
			Song song1("Sandstorm", 60);
			Song song2("Dream on", 111);
			Player player("Jack");
			Playlist playlist1("Favourite songs", { song1, song2 }, player);
			std::string expected = "Favourite songs";
			Assert::AreEqual(expected, playlist1.getName());
		}
		TEST_METHOD(PlaylistGetSongs)
		{
			Song song1("Sandstorm", 60);
		    Song song2("Dream on", 111);
			Player player("Jack");
			Playlist playlist1("Favourite songs", { song1, song2 }, player);
			std::vector<Song> expected = {song1, song2};
			Assert::IsTrue(expected == playlist1.getSongs());
		}
		TEST_METHOD(PlaylistTwoSameSongs)
		{
			Song song1("Sandstorm", 60);
			Song song2("Sandstorm", 60);
			Player player("Jack");
			Playlist playlist1("Favourite songs", { song1, song2 }, player);
			std::vector<Song> expected = { song1, song2 };
			Assert::IsTrue(expected == playlist1.getSongs());
		}
		TEST_METHOD(PlaylistThreeSameSongs)
		{
			Song song1("Sandstorm", 60);
			Song song2("Sandstorm", 60);
			Song song3("Sandstorm", 60);
			Song song4("Dream on", 120);
			Song song5("Dream on", 120);
			Song song6("Dream on", 120);
			Player player("Jack");
			Playlist playlist1("Favourite songs", { song1, song2, song3, song4, song5, song6 }, player);
			std::vector<Song> expected = { song1, song2, song4, song5 };
			Assert::IsTrue(expected == playlist1.getSongs());
		}
		TEST_METHOD(PlayerOperatorEqual)
		{
			Player player1("Jack");
			Player player2("Jack");
			Assert::IsTrue(player1 == player2);
		}
		TEST_METHOD(PlayerOperatorNotEqual)
		{
			Player player1("Jack");
			Player player2("Mike");
			Assert::IsTrue(player1 != player2);
		}
		TEST_METHOD(PlaylistGetCreator)
		{
			Song song1("Sandstorm", 60);
			Song song2("Dream on", 111);
			Player player("Jack");
			Playlist playlist1("Favourite songs", { song1, song2 }, player);
			Assert::IsTrue(player == playlist1.getCreator());
		}
		TEST_METHOD(PlayerGetPlaylists)
		{
			Song song1("Sandstorm", 60);
			Song song2("Dream on", 111);
			Player player("Jack");
			Playlist playlist1("Favourite songs", { song1, song2 }, player);
			std::vector<Playlist> playlists = player.getPlaylists();
			std::vector<Playlist> expected{ playlist1 };
			Assert::IsTrue(expected == playlists);
		}
		TEST_METHOD(PlayerSetName)
		{
			Player player("Jack");
			player.setName("Mike");
			std::string expected = "Mike";
			Assert::AreEqual(expected, player.getName());
		}
		TEST_METHOD(PlaylistSetCreator)
		{
			Player player1("Jack");
			Song song1("Sandstorm", 60);
			Song song2("Dream on", 111);
			Playlist playlist1("Favourite songs", { song1, song2 }, player1);
			Player player2("Mike");
			playlist1.setCreator(player2);
			Assert::IsTrue(player2 == playlist1.getCreator());
			//std::vector<Playlist> expected_playlists1 = {};
			std::vector<Playlist> expected_playlists2 = {playlist1};
			//Assert::IsTrue(expected_playlists1 == player1.getPlaylists());
			Assert::IsTrue(expected_playlists2 == player2.getPlaylists());
		}
		TEST_METHOD(PlaylistOperatorPlusEqual)
		{
			Player player("Jack");
			Song song1("Sandstorm", 60);
			Playlist playlist("Favourite songs", { song1 }, player);
			Song song2("Dream on", 150);
			playlist.operator+=(song2);
			std::vector<Song> expected = { song1, song2 };
			Assert::IsTrue(expected == playlist.getSongs());
		}
		TEST_METHOD(PlaylistOperatorPlusEqualTwoSameSongs)
		{
			Player player("Jack");
			Song song1("Sandstorm", 60);
			Song song2("Sandstorm", 60);
			Playlist playlist("Favourite songs", { song1 }, player);
			playlist.operator+=(song2);
			std::vector<Song> expected = { song1, song2 };
			Assert::IsTrue(expected == playlist.getSongs());
		}
		TEST_METHOD(PlaylistOperatorPlusEqualThreeSameSongs)
		{
			Player player("Jack");
			Song song1("Sandstorm", 60);
			Song song2("Sandstorm", 60);
			Playlist playlist("Favourite songs", { song1, song2 }, player);
			Song song3("Sandstorm", 60);
			playlist.operator+=(song3);
			std::vector<Song> expected = { song1, song2 };
			Assert::IsTrue(expected == playlist.getSongs());
		}
		TEST_METHOD(PlaylistOperatorMinusEqual)
		{
			Player player("Jack");
			Song song1("Sandstorm", 60);
			Song song2("Dream on", 150);
			Playlist playlist("Favourite songs", { song1, song2 }, player);
			playlist.operator-=(song2);
			std::vector<Song> expected = { song1 };
			Assert::IsTrue(expected == playlist.getSongs());
		}
		TEST_METHOD(PlaylistOperatorEqual)
		{
			Player player("Jack");
			Song song1("Sandstorm", 123);
			Song song2("Dream on", 234);
			Playlist playlist1("Favourite songs", { song1, song2 }, player);
			Playlist playlist2("Favourite songs", { song1, song2 }, player);
			Assert::IsTrue(playlist1 == playlist2);
		}
		TEST_METHOD(PlaylistOperatorNotEqualDifferentPlayers)
		{
			Player player1("Jack");
			Player player2("Mike");
			Song song1("Sandstorm", 123);
			Song song2("Dream on", 234);
			Playlist playlist1("Favourite songs", { song1, song2 }, player1);
			Playlist playlist2("Favourite songs", { song1, song2 }, player2);
			Assert::IsTrue(playlist1 != playlist2);
		}
		TEST_METHOD(PlaylistOperatorNotEqualDifferentSongs)
		{
			Player player("Jack");
			Song song1("Sandstorm", 123);
			Song song2("Dream on", 234);
			Song song3("Beat It", 240);
			Playlist playlist1("Favourite songs", { song1, song2 }, player);
			Playlist playlist2("Favourite songs", { song1, song3 }, player);
			Assert::IsTrue(playlist1 != playlist2);
		}
		TEST_METHOD(PlaylistOperatorNotEqualDifferentNames)
		{
			Player player("Jack");
			Song song1("Sandstorm", 123);
			Song song2("Dream on", 234);
			Song song3("Beat It", 240);
			Playlist playlist1("Favourite songs", { song1, song2, song3 }, player);
			Playlist playlist2("Best songs", { song1, song2, song3 }, player);
			Assert::IsTrue(playlist1 != playlist2);
		}
		TEST_METHOD(PlaylistPlay)
		{
			Player player("Jack");
			Song song1("Sandstorm", 123);
			Song song2("Dream on", 234);
			Song song3("Beat It", 240);
			Playlist playlist("Favourite songs", { song1, song2, song3 }, player);
			std::string expected =
				"Song: Sandstorm\nDuration: 123[s].\n"
				"Song: Dream on\nDuration: 234[s].\n"
				"Song: Beat It\nDuration: 240[s].\n";
			Assert::IsTrue(expected == playlist.play());
		}
		TEST_METHOD(PlaylistPlayReverse)
		{
			Player player("Jack");
			Song song1("Sandstorm", 123);
			Song song2("Dream on", 234);
			Song song3("Beat It", 240);
			Playlist playlist("Favourite songs", { song1, song2, song3 }, player);
			std::string expected =
				"Song: Beat It\nDuration: 240[s].\n"
				"Song: Dream on\nDuration: 234[s].\n"
				"Song: Sandstorm\nDuration: 123[s].\n";
			Assert::IsTrue(expected == playlist.playReverse());
		}
		TEST_METHOD(PlaylistInfo)
		{
			Player player("Jack");
			Song song1("Sandstorm", 123);
			Song song2("Dream on", 234);
			Song song3("Beat It", 240);
			Playlist playlist("Favourite songs", { song1, song2, song3 }, player);
			std::string expected = "Number of songs: 3.\nTotal duration: 597[s].\n";
			Assert::IsTrue(expected == playlist.info());
		}
	};
}
