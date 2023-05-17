#ifndef INPUT_HPP
#define INPUT_HPP

#include <iostream>

using namespace std;

class Input {
public:
    int WaitChoice() {
		int ch;
		cin >> ch;

		return ch;
	}

    string WaitString() {
        string ch;

        cin >> ch;

        return ch;
    }

};

//instanciei no próprio arquivo.
Input getInput;

#endif