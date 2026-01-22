#include "rotor.h"

namespace enigma
{
	Rotor::Rotor(std::string_view wiring, char turnover, const Vector2& position) :
		wiring{ wiring },
		turnover{ turnover },
		rotor_position{ position }
	{
		// Can't set button position in rotorbutton constructor, so do it here
		this->button_down.set_button_position(
			{ this->rotor_position.x,
			  this->rotor_position.y + ROTOR_BUTTON_OFFSET_Y });
		this->button_up.set_button_position(
			{ this->rotor_position.x,
			  this->rotor_position.y - ROTOR_BUTTON_OFFSET_Y });
	}

	Rotor::~Rotor()
	{
	}

	char Rotor::pass_through(char input_character) const
	{
		enigma::Log::debug("Rotor pass through called with input character: %c", input_character);
		int index_of_input = this->get_index_of_char(enigma::ALPHABETS, input_character);
		int index_of_output = (index_of_input + this->rotor_index) % 26;
		enigma::Log::debug("Rotor output: %c", this->wiring[index_of_output]);

		return this->wiring[index_of_output];
	}

	char Rotor::reverse_pass_through(char input_character) const
	{
		enigma::Log::debug("Rotor reverse pass through called with input character: %c", input_character);
		int index_of_input = this->get_index_of_char(this->get_wiring(), input_character);
		int index_of_output = (index_of_input - this->rotor_index + 26) % 26;
		enigma::Log::debug("Rotor reverse output: %c", enigma::ALPHABETS[index_of_output]);

		return enigma::ALPHABETS[index_of_output];
	}

	void Rotor::set_rotor_index(int new_index)
	{
		if (new_index < 0 || new_index > 25)
		{
			enigma::Log::error("Error: Rotor index out of bounds. Must be between 0 and 25.");
			this->rotor_index = 0;
			return;
		}

		this->rotor_index = new_index;
	}

	void Rotor::turn_rotor()
	{
		if (this->rotor_index < 25)
		{
			++this->rotor_index;
		}
		else
		{
			this->rotor_index = 0;
		}
	}

	void Rotor::turn_back_rotor()
	{
		if (this->rotor_index > 0)
		{
			--this->rotor_index;
		}
		else
		{
			this->rotor_index = 25;
		}
	}

	int Rotor::get_rotor_index() const
	{
		return this->rotor_index;
	}

	int Rotor::get_index_of_char(std::string_view stringview, char character) const
	{
		int character_position = stringview.find(character);

		if (character_position != std::string::npos)
		{
			return character_position;
		}

		// Should be impossible to reach this point, since user can not insert chars.
		assert(false && "Invalid character lookup in Rotor::get_index_of_char");
	}

	char Rotor::get_turnover_char() const
	{
		return this->turnover;
	}

	int Rotor::get_turnover_index() const
	{
		return this->get_index_of_char(this->wiring, this->turnover);
	}

	std::string_view Rotor::get_wiring() const
	{
		return this->wiring;
	}

	Vector2 enigma::Rotor::get_rotor_position() const
	{
		return this->rotor_position;
	}


	bool Rotor::is_button_pressed(const Vector2& mouse_position, const bool& mouse_pressed)
	{
		if (mouse_pressed && this->p_button_pressed == nullptr)
		{

			// Check button up
			if (CheckCollisionPointRec(mouse_position, 
				Rectangle{ this->button_up.get_button_position().x,
						   this->button_up.get_button_position().y,
						   ROTOR_BUTTON_SIZE.x,
						   ROTOR_BUTTON_SIZE.y }))
			{
				this->p_button_pressed = &this->button_up;
				enigma::Log::debug("Rotor button UP pressed");
				return true;
			}

			// Check button down
			if (CheckCollisionPointRec(mouse_position,
				Rectangle{ this->button_down.get_button_position().x,
						   this->button_down.get_button_position().y,
						   ROTOR_BUTTON_SIZE.x,
						   ROTOR_BUTTON_SIZE.y }))
			{
				this->p_button_pressed = &this->button_down;
				enigma::Log::debug("Rotor button DOWN pressed");
				return true;
			}

		}
		return false;
	}

	void Rotor::check_if_button_released(bool& mouse_released)
	{
		if (mouse_released && this->p_button_pressed != nullptr)
		{
			this->p_button_pressed = nullptr;
			enigma::Log::debug("Rotor button released");
		}
	}

	RotorButton* Rotor::get_pressed_button()
	{
		return this->p_button_pressed;
	}
}