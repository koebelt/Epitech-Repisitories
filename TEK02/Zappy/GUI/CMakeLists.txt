cmake_minimum_required(VERSION 3.12)
set(CMAKE_CXX_STANDARD 20)


if (NOT raylib_FOUND)
  INCLUDE(FetchContent)

  FetchContent_Declare(raylib URL https://github.com/raysan5/raylib/archive/refs/tags/4.0.0.tar.gz)
  FetchContent_GetProperties(raylib)
  if (NOT raylib_POPULATED)
    SET(FETCHCONTENT_QUIET NO)
    FetchContent_Populate(raylib)
    SET(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
    ADD_SUBDIRECTORY(${raylib_SOURCE_DIR} ${raylib_BINARY_DIR})
    SET(raylib_FOUND TRUE)
  endif()
endif()

project (zappy)

#Here add you'r .cpp
file (GLOB_RECURSE zappy_SOURCES CONFIGURE_DEPENDS "src/Main.cpp"
                                                  "src/display/Display.cpp"
                                                  "src/display/engine/audio/Audio.cpp"
                                                  "src/display/engine/audio/music/Music.cpp"
                                                  "src/display/engine/audio/sound/Sound.cpp"
                                                  "src/display/engine/event/keyboard/Keyboard.cpp"
                                                  "src/display/engine/event/mouse/Cursor.cpp"
                                                  "src/display/engine/event/mouse/Mouse.cpp"
                                                  "src/display/engine/graphic/2d/animation/Animation.cpp"
                                                  "src/display/engine/graphic/2d/gui/button/Button.cpp"
                                                  "src/display/engine/graphic/2d/gui/text/Text.cpp"
                                                  "src/display/engine/graphic/2d/gui/text/font/Font.cpp"
                                                  "src/display/engine/graphic/2d/image/Image.cpp"
                                                  "src/display/engine/graphic/2d/texture/Texture.cpp"
                                                  "src/display/engine/graphic/2d/sprite/Sprite.cpp"
                                                  "src/display/engine/graphic/3d/model/Model.cpp"
                                                  "src/display/engine/graphic/3d/model/animated_model/AnimatedModel.cpp"
                                                  "src/display/engine/graphic/3d/mesh/Mesh.cpp"
                                                  "src/display/engine/graphic/3d/material/Material.cpp"
                                                  "src/display/engine/graphic/3d/shader/Shader.cpp"
                                                  "src/display/engine/graphic/3d/skybox/Skybox.cpp"
                                                  "src/display/engine/graphic/camera/Camera.cpp"
                                                  "src/display/engine/time/Time.cpp"
                                                  "src/display/engine/window/Window.cpp"
                                                  "src/display/engine/graphic/3d/billboard/Billboard.cpp"
                                                  "src/display/fruits/Fruits.cpp"
                                                  "src/common/Player.cpp"
                                                  "src/common/Tile.cpp"
                                                  "src/display/teams/Teams.cpp"
                                                  "src/listener/Listener.cpp"
                                                  "src/interpreter/Interpreter.cpp"
                                                  )
#Here add you'r .hpp
file (GLOB_RECURSE zappy_HEADERS CONFIGURE_DEPENDS "src/display/Display.cpp"
                                                  "src/display/engine/Engine.hpp"
                                                  "src/display/engine/audio/Audio.hpp"
                                                  "src/display/engine/event/Event.hpp"
                                                  "src/display/engine/event/keyboard/Keyboard.hpp"
                                                  "src/display/engine/event/mouse/Cursor.hpp"
                                                  "src/display/engine/event/mouse/Mouse.hpp"
                                                  "src/display/engine/graphic/Graphic.hpp"
                                                  "src/display/engine/graphic/2d/2d.hpp"
                                                  "src/display/engine/graphic/2d/animation/Animation.hpp"
                                                  "src/display/engine/graphic/2d/gui/GUI.hpp"
                                                  "src/display/engine/graphic/2d/gui/button/Button.hpp"
                                                  "src/display/engine/graphic/2d/gui/text/Text.hpp"
                                                  "src/display/engine/graphic/2d/gui/text/font/Font.hpp"
                                                  "src/display/engine/graphic/2d/image/Image.hpp"
                                                  "src/display/engine/graphic/2d/texture/Texture.hpp"
                                                  "src/display/engine/graphic/2d/sprite/Sprite.hpp"
                                                  "src/display/engine/graphic/3d/3d.hpp"
                                                  "src/display/engine/graphic/3d/material/Material.hpp"
                                                  "src/display/engine/graphic/3d/mesh/Mesh.hpp"
                                                  "src/display/engine/graphic/3d/model/Model.hpp"
                                                  "src/display/engine/graphic/3d/model/animated_model/AnimatedModel.cpp"
                                                  "src/display/engine/graphic/3d/skybox/Skybox.hpp"
                                                  "src/display/engine/graphic/3d/shader/Shader.hpp"
                                                  "src/display/engine/graphic/camera/Camera.hpp"
                                                  "src/display/engine/graphic/color/Color.hpp"
                                                  "src/display/engine/math/Math.hpp"
                                                  "src/display/engine/math/rectangle/Rectangle.hpp"
                                                  "src/display/engine/math/vector/Vector2.hpp"
                                                  "src/display/engine/math/vector/Vector3.hpp"
                                                  "src/display/engine/math/vector/Vector4.hpp"
                                                  "src/display/engine/time/Time.hpp"
                                                  "src/display/engine/window/Window.hpp"
                                                  "src/display/engine/graphic/3d/billboard/Billboard.hpp"
                                                  "src/display/fruits/Fruits.hpp"
                                                  "src/common/Map.hpp"
                                                  "src/common/Player.hpp"
                                                  "src/common/Tile.hpp"
                                                  "src/common/Matrix.hpp"
                                                  "src/display/teams/Teams.hpp"
                                                  "src/listener/Listener.hpp"
                                                  "src/interpreter/Interpreter.hpp"
                                                  "src/common/ErrorManager.hpp"
                                                  )

set (zappy_INCLUDE_DIRS "")
foreach (_headerFile ${zappy_HEADERS})
    get_filename_component(_dir ${_headerFile} PATH)
    list (APPEND zappy_INCLUDE_DIRS ${_dir})
endforeach()
list (REMOVE_DUPLICATES zappy_INCLUDE_DIRS)

set(CMAKE_CXX_FLAGS "-g")
add_executable(zappy_gui ${zappy_SOURCES})
target_include_directories(zappy_gui PUBLIC ${zappy_INCLUDE_DIRS})
target_link_libraries(zappy_gui raylib)