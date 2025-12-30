#pragma once
#include "raylib.h"
#include <vector>
#include <string>

/**
 * @name Button constants
 * Button drawing constants
 */
///@{
static constexpr float BUTTON_PADDING{75.0f};		///< Distance between button centers
static constexpr float BUTTON_OUTER_RING{30.0f};	///< Outer ring radius
static constexpr float BUTTON_INNER_RING{25.0f};	///< Inner ring radius
///@}

/**
 * @brief Represents a button (key) in the Enigma machine	
 */
class M_button
{
private:
	/**
	 * @brief Character label of the button. Includes null terminate '\0'
	 */
	char character[2]{};
	/**
	 * @brief Position of the button center
	 */
	Vector2 position{};
	/**
	 * @brief Size multiplier for button scaling (e.g. when pressed)
	 */
	float size_multiplier{1.0f};
	/**
	 * @brief Constants for button drawing
	 */
	float outer_ring{BUTTON_OUTER_RING};
	/**
	 * @brief Constants for button drawing
	 */
	float inner_ring{BUTTON_INNER_RING};

public:
	/**
	 * @brief Constructor
	 * @param char Character label of the button
	 * @param pos Position of the button center
	 */
	M_button(char, Vector2 pos);
	~M_button();

	/**
	 * @brief Returns the character label of the button
	 */
	char get_label() const;
	/**
	 * @brief Returns the character label as a C-string (for raylib DrawTextEx())
	 */
	const char *get_text();
	/**
	 * @brief Returns the position of the button center
	 */
	Vector2 get_position() const;
	/**
	 * @brief Returns the button size (outer ring radius)
	 */
	float get_button_size() const;
	/**
	 * @brief Sets the size multiplier for button scaling
	 */
	void set_size_multiplier(float);
	/**
	 * @brief Draws the button using the provided font and offset
	 */
	void draw_button(Font, Vector2);

	// STATIC METHODS
	/**
	 * @brief Creates all buttons based on the provided starting position and button characters
	 * @param x Starting x position
	 * @param y Starting y position
	 * @param button_characters String of characters representing the buttons to create
	 * @return Vector of created M_button objects
	 */
	static std::vector<M_button> create_all_buttons(float, float, std::string);
};