#include <iostream>
#include <string>
#include <unordered_map>
#include <mutex>

std::unordered_map<std::string, std::string> url_db;
std::mutex db_mutex;

std::string shortenURL(const std::string& longURL) {
    std::lock_guard<std::mutex> lock(db_mutex);
    std::string shortCode = "abc123"; // placeholder
    url_db[shortCode] = longURL;
    return "short.ly/" + shortCode;
}

int main() {
    std::string longURL;
    std::cout << "Enter a long URL: ";
    std::getline(std::cin, longURL);

    std::string shortURL = shortenURL(longURL);
    std::cout << "Shortened URL: " << shortURL << std::endl;
    return 0;
}
