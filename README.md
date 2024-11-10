
# Word Spell Checker CLI

A simple command-line interface (CLI) application for checking the spelling of words using a dictionary. This application is built in C++ and provides basic suggestions for misspelled words by modifying each letter in the input word.

## Features

- Loads a dictionary from a text file.
- Checks if a given word is correctly spelled.
- Suggests similar words by changing one letter at a time.
- Fast lookups using an unordered set for the dictionary.

## Getting Started

### Prerequisites

- C++ compiler (GCC, Clang, or Visual Studio)
- A text file containing a list of valid words (one per line) named `dictionary.txt`.

### Installation

1. **Clone the repository**:
   ```bash
   git clone https://github.com/your-username/word-spell-checker-cli.git
   cd word-spell-checker-cli
   ```

2. **Compile the code**:
   ```bash
   g++ spell_checker.cpp -o spell_checker
   ```

3. **Run the program**:
   ```bash
   ./spell_checker
   ```

### Usage

1. When the program starts, it will prompt you to enter a word to check.
2. The program will check if the word is in the dictionary:
   - If the word is found, it will confirm the spelling is correct.
   - If the word is not found, it will suggest similar words by changing one letter at a time.
3. Example:
   ```
   Enter a word to check its spelling: ctt
   'ctt' is not in the dictionary.
   Did you mean: cat cot cut
   ```

## Code Structure

- **`spell_checker.cpp`**: Main program file containing the logic for loading the dictionary, checking spelling, and generating suggestions.
- **`dictionary.txt`**: A text file containing valid words (one word per line). This file is required for the spell checker to work.

## How It Works

1. **Dictionary Loading**: The program loads all words from `dictionary.txt` into an `unordered_set` for quick lookups.
2. **Spelling Check**: The program checks if the input word is present in the dictionary.
3. **Suggestion Generation**: If the word is not found, the program suggests alternative words by replacing each letter with every letter in the alphabet and checking if the result is in the dictionary.

## Example Dictionary File

Make sure to include a `dictionary.txt` file in the same directory as `spell_checker.cpp`. Here’s an example content:

```
cat
cot
cut
bat
rat
...
```

## Potential Improvements

- Implement more advanced suggestion algorithms (e.g., Levenshtein distance).
- Support additional operations like adding, removing, or transposing letters.
- Make the dictionary file path configurable from the command line.

## Contributing

Contributions are welcome! Please fork the repository and open a pull request with any improvements or bug fixes.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for more details.

## Acknowledgments

Inspired by the need for simple spell-checking in CLI applications.
