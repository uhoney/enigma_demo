#pragma once
#include "raylib.h"
#include "log.h"
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
	std::vector<enigma::Rotor> rotors{};
	enigma::Reflector reflector{};

	Controller();
	~Controller();

	void handle_key_press();

	void check_rotor_turnovers();

	void pass_through_rotors();

};
