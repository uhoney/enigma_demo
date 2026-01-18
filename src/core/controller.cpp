#include "controller.h"

Controller::Controller()
{
	this->rotors.reserve(3);
	this->sfx_key.reserve(4);

	// Compiler can't figure out the type when curlybrace init, so give the type explicitly
	this->rotors.emplace_back(enigma::ROTOR_I_WIRING, enigma::ROTOR_I_TURNOVER, Vector2{ enigma::ROTOR_POSITION_1, enigma::ROTOR_POSITION_Y });
	this->rotors.emplace_back(enigma::ROTOR_II_WIRING, enigma::ROTOR_II_TURNOVER, Vector2{ enigma::ROTOR_POSITION_2, enigma::ROTOR_POSITION_Y });
	this->rotors.emplace_back(enigma::ROTOR_III_WIRING, enigma::ROTOR_III_TURNOVER, Vector2{ enigma::ROTOR_POSITION_3, enigma::ROTOR_POSITION_Y });

	this->load_sfx();
}

Controller::~Controller()
{
}

void Controller::handle_key_press_event()
{
	Vector2 mouse_position = GetMousePosition();

	if (this->keyboard.is_key_pressed(mouse_position, IsMouseButtonPressed(MOUSE_LEFT_BUTTON)))
	{
		this->play_random_key_sfx();

		char temp_char{ this->keyboard.get_pressed_key()->get_label() };

		this->handle_rotor_turnovers();

		for (auto& rotor : this->rotors)
		{
			temp_char = rotor.pass_through(temp_char);
		}

		temp_char = this->reflector.swap_character(temp_char);

		for (auto rotor = this->rotors.rbegin(); rotor != this->rotors.rend(); ++rotor)
		{
			temp_char = rotor->reverse_pass_through(temp_char);
		}

		this->lampboard.turn_on_lamp(temp_char);
	}

	if (this->keyboard.is_key_released(IsMouseButtonReleased(MOUSE_LEFT_BUTTON)))
	{
		this->lampboard.reset_lamps();
	}
}

char Controller::debug_handle_key_press_event(char input_char)
{
	enigma::Log::debug("-----debug_handle_key_press_event(input: %c)", input_char);
	char temp_char{ input_char };

	// check & turn rest of rotors if needed
	this->handle_rotor_turnovers();

	enigma::Log::debug("Rotor positions after turnover handling: R1:%d R2:%d R3:%d",
		this->rotors.at(0).get_rotor_index(),
		this->rotors.at(1).get_rotor_index(),
		this->rotors.at(2).get_rotor_index());

	// run through rotors 1,2,3
	for (auto& rotor : this->rotors)
	{
		temp_char = rotor.pass_through(temp_char);
	}

	// swap and change direction
	temp_char = this->reflector.swap_character(temp_char);

	// run through rotors in reverse
	for (auto rotor = this->rotors.rbegin(); rotor != this->rotors.rend(); ++rotor)
	{
		temp_char = rotor->reverse_pass_through(temp_char);
	}

	enigma::Log::debug("output: %c", temp_char);

	return temp_char;
}

void Controller::handle_rotor_turnovers()
{
	int temp0 = this->rotors.at(0).get_rotor_index();
	int temp1 = this->rotors.at(1).get_rotor_index();

	this->rotors.at(0).turn_rotor();

	if (this->rotors.at(0).get_turnover_index() == temp0)
	{
		this->rotors.at(1).turn_rotor();
	}

	if (this->rotors.at(1).get_turnover_index() == temp1 &&
		(this->rotors.at(0).get_turnover_index() == temp0))
	{
		this->rotors.at(2).turn_rotor();
	}
}

void Controller::load_sfx()
{
	Sound sfx_key_press_1{ LoadSound("assets/sfx/typewriter_1.wav") };
	Sound sfx_key_press_2{ LoadSound("assets/sfx/typewriter_2.wav") };
	Sound sfx_key_press_3{ LoadSound("assets/sfx/typewriter_3.wav") };
	Sound sfx_key_press_4{ LoadSound("assets/sfx/typewriter_4.wav") };

	if (sfx_key_press_1.frameCount == 0 || sfx_key_press_2.frameCount == 0 ||
		sfx_key_press_3.frameCount == 0 || sfx_key_press_4.frameCount == 0)
	{
		std::cerr << "Error loading sound effects!" << std::endl;
		CloseAudioDevice();
		CloseWindow();
		exit(1);
	}

	this->sfx_key.emplace_back(sfx_key_press_1);
	this->sfx_key.emplace_back(sfx_key_press_2);
	this->sfx_key.emplace_back(sfx_key_press_3);
	this->sfx_key.emplace_back(sfx_key_press_4);
}

void Controller::play_random_key_sfx()
{
	int random_index = GetRandomValue(0, static_cast<int>(this->sfx_key.size()) - 1);
	PlaySound(this->sfx_key.at(random_index));
}