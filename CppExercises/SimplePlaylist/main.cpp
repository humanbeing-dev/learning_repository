#include <iostream>
#include <list>
#include <string>
#include <cctype>
#include <iomanip>
#include <limits>
#include <fstream>

class Song {
    friend std::ostream &operator<<(std::ostream &os, const Song &s);
    std::string name;
    std::string artist;
    int rating;
public:
    Song() = default;
    Song(std::string name, std::string artist, int rating)
            : name{name}, artist{artist}, rating{rating} {}
    std::string get_name() const {
        return name;
    }
    std::string get_artist() const {
        return artist;
    }
    int get_rating() const {
        return rating;
    }
    
    bool operator<(const Song &rhs) const  {
        return this->name < rhs.name;
    }
    
    bool operator==(const Song &rhs) const  {
        return this->name == rhs.name;
    }
};

std::ostream &operator<<(std::ostream &os, const Song &s) {
    os << std::setw(20) << std::left << s.name
       << std::setw(30) << std::left << s.artist
       << std::setw(2) << std::left << s.rating;
       return os;
}

void display_menu() {
    std::cout << "\nF - Play First Song" << std::endl;
    std::cout << "N - Play Next song" << std::endl;
    std::cout << "P - Play Previous song" << std::endl;
    std::cout << "A - Add and play a new Song at current location" << std::endl;
    std::cout << "L - List the current playlist" << std::endl;
    std::cout << "===============================================" << std::endl;
    std::cout << "Enter a selection (Q to quit): ";
}

void play_current_song(const Song &song) {
    std::cout << "Playing: " << std::endl;
    std::cout << song << std::endl;
}

void display_playlist(const std::list<Song> &playlist, const Song &current_song) {
    auto it = playlist.begin();
    std::cout << std::setw(51) << std::left << std::setfill('-') << "" << std::setfill(' ') << std::endl;
    do {
        std::cout << *it << std::endl;
        ++it;
    }
    while (it != playlist.end());
    std::cout << std::setw(51) << std::left << std::setfill('-') << "" << std::endl;
    std::cout << std::setfill(' ') << "Current song: " << std::endl;
    std::cout << current_song << std::endl;
}



int main() {

    std::fstream file;
    file.open("SimplePlaylist/playlist.txt");
    if(!file)
        std::cout << "No saved playlist" << std::endl;
    
    std::string new_name, new_artist;
    int new_rating;
    std::list<Song> playlist;
    file.clear();
    file.seekp(0);
    while (!file.eof()) {
        std::getline(file, new_name); 
        std::getline(file, new_artist); 
        file >> new_rating >> std::ws;
        playlist.push_back(Song(new_name, new_artist, new_rating));
    }
    
    std::list<Song>::iterator current_song = playlist.begin();
    display_playlist(playlist, *current_song);
    
    char choice {};
    
    
    
    do {
    display_menu();
    std::cin >> choice;
    choice = std::toupper(choice);
    switch (choice) {
    case 'F' : 
        std::cout << "Playing first song" << std::endl;
            current_song = playlist.begin();
            play_current_song(*current_song);
        break;
    case 'N' :
        std::cout << "Playing next song" << std::endl;
        current_song++;
        if (current_song == playlist.end()) {
            std::cout << "Wrapping to start of playlist" << std::endl;
            current_song = playlist.begin();
        }
        play_current_song(*current_song);
        break;
    case 'P' :
        std::cout << "Playing previous song" << std::endl;
        if (current_song == playlist.begin()) {
            current_song = playlist.end();
        }
        current_song--;
        play_current_song(*current_song); 
        break;
    case 'A' :
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Adding and playing new song" << std::endl;
        std::cout << "Enter song name: ";
        std::getline (std::cin, new_name);
        std::cout << "Enter song artist: ";
        std::getline (std::cin, new_artist);
        std::cout << "Enter song rating: ";
        std::cin >> new_rating;
        current_song = playlist.insert(current_song, Song{new_name, new_artist, new_rating});
        play_current_song(*current_song);
        break;
    case 'L' :
        std::cout << "\nCurrent playlist" << std::endl;
        display_playlist(playlist, *current_song);
        break;
    case 'Q' :
        break;  
    default :
        std::cout << "Invalid choice, try again..." << std::endl;
    }
    } while (choice != 'Q');

    std::cout << "Thanks for listening!" << std::endl;
    file.close();
    
    file.open("SimplePlaylist/playlist.txt", std::ios::out | std::ios::trunc);
    if (!file) {
        std::cout << "Failed to open playlist.txt for writing" << std::endl;
        return 1;
    }
    for (auto song: playlist) {
        file << song.get_name() << std::endl
             << song.get_artist() << std::endl
             << song.get_rating() << std::endl;
    }
    file.close();
    return 0;
}