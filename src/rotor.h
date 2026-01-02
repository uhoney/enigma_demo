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
		// Turnover:			"Q"

		static constexpr std::string_view ALPHABETS{ "ABCDEFGHIJKLMNOPQRSTUVWXYZ" };

		std::string_view rotor_wiring{};
		char turnover{};
		int position_index{ 0 };

	public:
		Rotor(std::string_view, char&);
		~Rotor();

		char get_turnover() const;

		char rotor_substitute() const;
		char rotor_reverse_substitute() const;

		int get_position_index() const;
		void set_position_index(int);	// for debug only
		void add_position_index();
		void substract_position_index();

		std::string_view get_wiring() const;
		std::string_view get_alphabets() const;
	};
}