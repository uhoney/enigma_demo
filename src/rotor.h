#pragma once
#include <string_view>
#include <array>

namespace enigma
{
	class Rotor
	{
	private:

		/*
		* Eli jos roottorissa olis 'D' näkyvissä, se ei vielä avaa R2 lukitusta.
		* Nappia painetaan ja R1 kääntyy nyt näyttämään 'Q'. R2 lukko on kiinni edelleen.
		* NYT jos nappia painetaan, R2 lukko aukeaa ja pyörähtää samalla R1 kanssa.
		* 
		* Tarkista oikeassa järjestyksessä. R1 pyörähtää AINA.
		* R3 voi pyörähtää ilman R2:n pyörähtämistä, mutta R2 ei voi pyörähtää ilman R1:n pyörähtämistä.
		* Eli R1 aina true, R2 ja R3 tarkistetaan erikseen.
		*/

		// Alphabets			"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
		// 
		// Rotor I wiring:		"EKMFLGDQVZNTOWYHXUSPAIBRCJ"
		// Notch at				"Q"

		// Rotor II wiring:		"AJDKSIRUXBLHWTMCQGZNPYFVOE"
		// Notch at:			"E"

		// Rotor III wiring:	"BDFHJLCPRTXVZNYEIWGAKMUSQO"
		// Notch at:			"V"

		static constexpr std::string_view ROTOR1_WIRING{ "EKMFLGDQVZNTOWYHXUSPAIBRCJ" };
		static constexpr std::string_view ROTOR2_WIRING{ "AJDKSIRUXBLHWTMCQGZNPYFVOE" };
		static constexpr std::string_view ROTOR3_WIRING{ "BDFHJLCPRTXVZNYEIWGAKMUSQO" };

		std::array<char, 91> reflector_array{ {} };
		char turnover{};
		char current_position{};

	public:
		Rotor(std::string_view&, char);
		~Rotor();

		char get_turnover() const;
		char get_current_position() const;
		void turn_rotor();
	};
}