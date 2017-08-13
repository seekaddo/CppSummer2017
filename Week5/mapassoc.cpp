//
// Created by Addo Dennis on 12/08/2017.
//


#include <string>
#include <map>
#include <iostream>
#include <fmt/printf.h>
#include <fstream>

/*static void readFiles(std::string path) {
	std::ifstream inf{path};
	if (!inf.is_open()) {
		std::cerr << "Cannot open the file" << std::endl;
		return;
	}

	std::string line;
	while (std::getline(inf, line)) {
		std::cout << line << std::endl;
	}

}*/

std::vector<std::string> splitWords(const std::string &word, const std::string &del) {

	if (word.empty()) {
		return {};
	}
	std::vector<std::string> ret;
	std::size_t start = 0;
	std::size_t end = word.find(del);
	while (end != std::string::npos) {
		ret.emplace_back(word.substr(start, end - start));
		start = end + del.length();
		end = word.find(del, start);
	}

	ret.emplace_back(word.substr(start, end));
	return ret;


}


//find all the lines that refers to each word.

std::map<std::string, std::vector<int> > wordsWithLineRef(const std::string &fpath,
   std::vector<std::string> findWord(const std::string &word,const std::string &del) = splitWords) {

	using std::vector;
	using std::map;
	using namespace std;

	ifstream inf{fpath};
	if (!inf.is_open()) {
		cerr << "Cannot open the file" << endl;
		return {};
	}

	string line;
	size_t lineNumber = 0;
	map<string, vector<int> > ret;
	vector<string> lwords;
	while (getline(inf, line)) {
		++lineNumber;
		lwords = findWord(line, " ");

		vector<string>::const_iterator wd;
		for (wd = lwords.begin(); wd != lwords.end(); ++wd) {
			ret[*wd].emplace_back(lineNumber);
		}

	}

	return ret;

}


int main() {

	/*std::string s;

	std::map<std::string, int> container;

	while (std::cin >> s) {
		++container[s];
		if(std::cin.peek() == '\n') break;
	}
	std::map<std::string, int>::const_iterator it;
	for (it = container.begin(); it != container.end(); ++it) {
			std::cout << it->first <<"\t" << it->second <<std::endl;
	}

	std::cout<< container.at("hard") <<std::endl;
	std::cout<< container.size() <<std::endl;*/


	/*std::string paths = "names";
	readFiles(paths);

	std::string line = "Jesmes Haldor 83 good to have it";
	std::vector<std::string> lwords = splitWords(line, " ");
	for (std::vector<std::string>::const_iterator wl = lwords.begin(); wl != lwords.end(); ++wl) {
		fmt::printf("read --> %s\n", *wl);
	}*/


	std::map<std::string, std::vector<int> > crosMap = wordsWithLineRef("names",splitWords);

	std::map<std::string, std::vector<int> >::const_iterator wd;
	for (wd = crosMap.begin(); wd != crosMap.end(); ++wd) {

		fmt::printf("The word '%s' occurs on line(s) :",wd->first);
		std::vector<int>::const_iterator l;
		for (l = wd->second.begin();  l != wd->second.end() ; ++l) {
			fmt::printf("%d ",*l);
		}
		fmt::print("\n");
	}


	return 0;

}