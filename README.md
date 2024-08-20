# Hess 

This project is a simple music player application (and also video player in the future) built using Raylib in C++. The application allows users to drag and drop audio files to play them.
The project is still in development, with plans to integrate video playback functionality using FFmpeg in the future.

## Features

- **Drag and Drop**: Load audio files by dragging and dropping them into the application window.
- **Playback Controls**: 
  - **Play/Pause**: Toggle playback using the spacebar.
  - **Volume Control**: Increase/decrease volume using the arrow keys.
- **Progress Bar**: Visual representation of the music playback progress.
- **Volume Bar**: Visual indication of the current volume level.

## Planned Features

- **Video Playback**: Integration with FFmpeg to support video playback alongside audio.

## Getting Started

### Prerequisites

- **Raylib**: The application is built using Raylib. Raylib is included in the `include` and `lib` folders of this project, so you don't need to install it.
- **FFmpeg**: For future video playback functionality, FFmpeg will be required.

### Building the Project

1. Clone the repository:

   ```bash
   git clone https://github.com/4hm3d57/Hess.git
   cd Hess
   # Building the project
   make
   # executable file 
   main.exe
   ```

2. Usage

  - Drag and Drop: Drag an audio file (e.g., .mp3, .wav) into the window to start playback.
  - Spacebar: Toggle between play and pause.
  - Arrow Up/Down: Increase or decrease the volume.

3. Contribution
   
  - Contributions are welcome! If you have ideas for improvements or new features, feel free to fork the repository and submit a pull request.
