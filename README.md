# Status
Work in progress. Working build in main.
Missing features:
- Plugboard
- Rotor & reflector selection (not intended to be implemented at this point, but you never know..)
- GUI tweaks (fonts, layout, etc) this is not intended to be fancy
- Naming convention: raylib uses PascalCase and I used snake_case. Maybe fix at some point. or not.

# enigma_demo
Trying to mash C++, CMake, Raylib, Doxygen and unit testing in one project. Let's see how it goes.
There is no plan to support crossplatform, however project is beeing developed with windows and linux, so it might work on both.
Main target is win x64.

The plan is to create a simple enigma machine with GUI using raylib. But, there is no intent to make it "modern" with fancy graphics or keeping taps with ciphered output for you.
Sure, simulators today _can_ keep track of cipher letters automatically, but the original machine did not have that capability.
The purpose is to just demonstrate the machine and not use it as a real ciphering device.

## Simple explanation of Enigma machine
The Enigma machine was an analog electro-mechanical device used for the encryption and decryption of secret messages.
Basically you press a key on the keyboard, and a light bulb turns on. The letter on the light bulb is the encrypted version of the letter you pressed.
You decipher the message by typing the encrypted letters on the keyboard, and the machine lights up the original letters.

Again, this was an analog machine. You literally had to cipher letters one by one. With a lot of patience.

## Rough overview how the machine works
A simplified explanation of the machine would be like this:
You press a key on the keyboard, a rotor spins and the current starts flowing.
- It goes from key to plugboard (swaps a letter if its connected)
- Through 3 (or more) rotors (each rotor swaps letters based on its internal wiring and position)
- To a reflector, reversing current (which swaps letters in a fixed manner)
- Back through the 3 rotors (in reverse order)
- Through the plugboard again (swapping again if connected)
- Finally lights up a letter on the lampboard.

It's a bit more complex than that, but that's the basic idea.

## Enigma machine specifics
Project uses information from [cryptmuseum](https://www.cryptomuseum.com/crypto/enigma/index.htm)
Machine model is the I-type Enigma machine used by the German Army and Air Force during World War II.

## Build instructions
Cmake provided, fetches raylib and catch2. Cmake 3.20 and C++17 required. Builds demo or tests.

## ubuntu x11
Ubuntu 24 LTS wanted additional packages
```bash
sudo apt update
sudo apt install -y libx11-dev libxrandr-dev libxi-dev libxinerama-dev libxcursor-dev libgl1-mesa-dev
```
