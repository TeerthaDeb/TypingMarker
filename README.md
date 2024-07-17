# Typing Marker

Typing Marker is a console-based typing practice tool that allows users to improve their typing speed and accuracy. The program includes various modes for typing practice, scoreboards for tracking progress, and detailed statistics about the user's performance.

## Author
**Teertha Deb**  
- [LinkedIn Profile](https://www.linkedin.com/in/maharaj-teertha-deb/)
- [Portfolio](https://teerthadeb.github.io/Portfolio/)

## Features
- **Typing Modes**: 
  - Capital Letters Only
  - Small Letters Only
  - Mixed Capital and Small Letters
- **Scoreboard**: 
  - Displays top scores with details such as average speed, total score, and total time.
- **Player Profiles**: 
  - Each player can have a profile with their name and typing statistics.
- **About Section**: 
  - Information about the program and its author.

## Technologies Used
- C++ standard libraries
- Windows-specific libraries for console manipulation (conio.h, windows.h)
- File handling for storing player data

## Setup and Installation
1. **Clone the repository**:
    ```sh
    git clone https://github.com/TeerthaDeb/typing-marker.git
    ```
2. **Navigate to the project directory**:
    ```sh
    cd typing-marker
    ```
3. **Compile the program**:
    - On Windows, use a C++ compiler like `g++`:
    ```sh
    g++ -o typing_marker typing_marker.cpp
    ```

## Usage
1. **Run the executable**:
    ```sh
    typing_marker.exe
    ```
2. **Main Menu**:
    - Start Typing: Begin a typing practice session.
    - Detailed Score Board: View the top scores.
    - About: Learn more about the program.
    - Exit: Exit the application.

3. **Typing Practice**:
    - Select the mode (Capital Letters, Small Letters, or Mixed).
    - Enter the number of characters you want to practice.
    - Follow the on-screen prompts to type the displayed characters.

## Score Calculation
- The final score is calculated as:
    ```txt
    score = total correct characters - (wrong key presses * 0.2)
    ```
- The average speed is calculated as:
    ```txt
    average = net score / time taken (in seconds)
    ```

## Contribution Guidelines
- Fork the repository.
- Create a new branch (`git checkout -b feature-branch`).
- Commit your changes (`git commit -am 'Add new feature'`).
- Push to the branch (`git push origin feature-branch`).
- Create a new Pull Request.

## License
This project is licensed under the MIT License.

## Contact
For any queries or issues, please contact [Teertha Deb](mailto:teertha.deb579@gmail.com).

---

Thank you for using Typing Marker! Happy typing!
