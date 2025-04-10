CMAKE_MINIMUM_REQUIRED(VERSION 3.22.1)
PROJECT(2024_project_s0231527)

IF (CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
    SET (CMAKE_INSTALL_PREFIX "${CMAKE_BINARY_DIR}/installed" CACHE PATH "default install path" FORCE)
ENDIF()

SET(CMAKE_CXX_STANDARD 17)

# This creates a library from the game logic
SET(LOGIC_SRC
        Src/Model/Player.cpp
        Src/Model/Camera.cpp
        Src/Model/Bonus.cpp
        Src/Model/BGTile.cpp
        Src/Model/Platform.cpp
        Src/Model/Random.cpp
        Src/Model/Stopwatch.cpp
        Src/Model/Observer.h
        Src/Model/Entity.cpp
        Src/Model/AEntityFactory.h
        Src/Model/Score.cpp
        Src/Model/Subject.h
        Src/Model/Obstacle.cpp
        Src/Control/BGTileGenerator.cpp
        Src/Control/PlatformGenerator.cpp
        Src/Control/BonusGenerator.cpp
        Src/Control/ObstacleGenerator.cpp
        Src/Control/World.cpp
        Src/StatePattern/PlayerState.h
        Src/StatePattern/SuctionState.cpp
        Src/StatePattern/SpringState.cpp
        Src/StatePattern/JetpackState.cpp
        Src/Configs/GameConfig.h
        Src/Exceptions/Exception.h
        Src/Exceptions/FileLoadException.h
        Src/Exceptions/InitializeException.h
        Src/Exceptions/TextureLoadException.h
        Src/Exceptions/FontLoadException.h
)

ADD_LIBRARY(doodle_jump STATIC ${LOGIC_SRC})
# ----------------------------

SET(GUI_SRC
        Src/View/Game.cpp
        Src/View/CEntityFactory.cpp
        Src/View/PlatformView.cpp
        Src/View/PlayerView.cpp
        Src/View/BonusView.cpp
        Src/View/BGTileView.cpp
        Src/View/ObstacleView.cpp
        Src/View/EntityView.cpp
        Src/View/ScoreView.cpp
        Src/Events/Event.h
        Src/Events/WindowCloseEvent.cpp
        Src/Events/KeyPressEvent.cpp
        Src/Events/SpaceKeyEvent.cpp
        Src/Events/EventHandler.cpp
        Src/AssetManager/TextureManager.cpp
        Src/AssetManager/FontManager.cpp
)

ADD_EXECUTABLE(DoodleJump main.cpp ${GUI_SRC})

TARGET_LINK_LIBRARIES(DoodleJump doodle_jump sfml-system sfml-graphics sfml-window)



