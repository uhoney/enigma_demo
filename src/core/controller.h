#pragma once
#include "raylib.h"
#include "keyboard.h"
#include "key.h"
#include "rotor.h"
#include "reflector.h"
#include "lampboard.h"
#include "../ui/layout.h"
#include <vector>

class Controller
{
public:
	enigma::KeyBoard keyboard{};
	enigma::Lampboard lampboard{};
	//std::vector<enigma::Rotor> rotors{};
	enigma::Reflector reflector{};
	enigma::Rotor rotor{ enigma::ROTOR_I_WIRING, enigma::ROTOR_I_TURNOVER };

	Controller();
	~Controller();

	void handle_key_press();
	

};
