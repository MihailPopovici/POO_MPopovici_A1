#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <cctype>

using namespace std;

ifstream file("input.txt");

vector<string> splitStringIntoWords(const string& phrase,const string& delimiters) {
	vector<string> words;
	size_t start = phrase.find_first_not_of(delimiters);
	while (start != string::npos) {
		size_t end = phrase.find_first_of(delimiters, start);
		words.push_back(phrase.substr(start, end - start));
		start = phrase.find_first_not_of(delimiters, end);
	}
	return words;
}

string toLowercase(const string& word) {
	string result;
	for (int i = 0; i < word.length(); i++) {
		result += tolower(word[i]);
	}
	return result;
}

class Comparator {
public:
	bool operator()(pair<string, int>& a, pair<string, int>& b) {
		if (a.second != b.second) return a.second < b.second;
		return a.first > b.first;
	}
};

int main() {
	string phrase;
	getline(file, phrase);
	string delimiters = " ,?!.";

	vector<string> words=splitStringIntoWords(phrase, delimiters);

	map<string, int> wordCount;

	for (const auto& word : words) {
		string lowercaseWord = toLowercase(word);
		wordCount[lowercaseWord]++;
	}

	priority_queue<pair<string, int>, vector<pair<string, int>>, Comparator> wordQueue;
	
	for (auto& pair : wordCount) {
		wordQueue.push(pair);
	}
	while (!wordQueue.empty()) {
		cout << wordQueue.top().first << " => " << wordQueue.top().second << endl;
		wordQueue.pop();
	}
	file.close();
	return 0;
}