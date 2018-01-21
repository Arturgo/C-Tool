#include <iostream>
#include <fstream>
#include <vector>
#include <cctype>
#include <set>
using namespace std;

set<string> includes;
set<string> solvedReferences;
set<string> unsolvedReferences;

vector<string> readLines(string reference) {
	ifstream fin;
	fin.open("References/" + reference);
	if(!fin.is_open()) {
		cerr << "Référence inconnue : " + reference << endl;
	}

	vector<string> lines;
	while(!fin.fail()) {
		string line;
		getline(fin, line);
		if(!fin.fail())
			lines.push_back(line);
	}

	fin.close();
	return lines;
}

vector<string> getWords(string line) {
	vector<string> words;
	words.push_back("");

	for(char car : line) {
		if(isspace(car)) {
			if(words.back() != "")
				words.push_back("");
		}
		else {
			words.back().push_back(car);
		}
	}

	if(words.back() == "") {
		words.pop_back();
	}

	return words;
}

vector<string> generatedReferences(string line, string macro) {
	vector<string> words = getWords(line);

	if(!words.empty() && words[0] == macro) {
		words.erase(words.begin());
		return words;
	}

	return vector<string>();
}

vector<string> generatedReferences(vector<string> lines, string macro) {
	vector<string> references;
	for(string line : lines) {
		vector<string> refs = generatedReferences(line, macro);
		for(string ref : refs) {
			references.push_back(ref);
		}
	}
	return references;
}

vector<string> getPrototypes(vector<string> lines) {
	vector<string> prototypes;

	for(string line : lines) {
		vector<string> words = getWords(line);
		if(!words.empty() && words[0] == "#main") {
			return prototypes;
		}
		prototypes.push_back(line);
	}

	return prototypes;
}

vector<string> getDefinitions(vector<string> lines) {
	vector<string> definitions;

	bool mainFound = false;
	for(string line : lines) {
		vector<string> words = getWords(line);
		if(mainFound) {
			definitions.push_back(line);
		}
		if(!words.empty() && words[0] == "#main") {
			mainFound = true;
		}
	}

	return definitions;
}

void genCode(vector<string> lines) {
	for(string line : lines) {
		vector<string> words = getWords(line);
		if(words.empty() || (words[0] != "#require" && words[0] != "#std_require"))
			cout << line << endl;
	}
}

int main() {
	vector<string> lines;
	while(!cin.fail()) {
		string line;
		getline(cin, line);
		if(!cin.fail())
			lines.push_back(line);
	}

	vector<string> stdRefs = generatedReferences(lines, "#std_require");
	for(string ref : stdRefs) {
		if(includes.find(ref) == includes.end()) {
			includes.insert(ref);
		}
	}

	vector<string> refs = generatedReferences(lines, "#require");
	for(string ref : refs) {
		if(unsolvedReferences.find(ref) == unsolvedReferences.end()) {
			unsolvedReferences.insert(ref);
		}
	}

	while(!unsolvedReferences.empty()) {
		string first = *unsolvedReferences.begin();
		unsolvedReferences.erase(first);

		if(solvedReferences.find(first) != solvedReferences.end())
			continue;
		solvedReferences.insert(first);

		stdRefs = generatedReferences(readLines(first + ".cpp"), "#std_require");
		for(string ref : stdRefs) {
			if(includes.find(ref) == includes.end()) {
				includes.insert(ref);
			}
		}

		refs = generatedReferences(readLines(first + ".cpp"), "#require");
		for(string ref : refs) {
			if(unsolvedReferences.find(ref) == unsolvedReferences.end()) {
				unsolvedReferences.insert(ref);
			}
		}
	}

	for(string ref : includes) {
		cout << "#include <" << ref << ">" << endl;
	}
	cout << "using namespace std;" << endl << endl;

	for(string ref : solvedReferences) {
		vector<string> prototypes = getPrototypes(readLines(ref + ".cpp"));
		genCode(prototypes);
	}

	genCode(lines);
	cout << endl;

	for(string ref : solvedReferences) {
		vector<string> definitions = getDefinitions(readLines(ref + ".cpp"));
		genCode(definitions);
	}

	return 0;
}
