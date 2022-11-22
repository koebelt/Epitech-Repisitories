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

project (indie)

#Here add you'r .cpp
file (GLOB_RECURSE indie_SOURCES CONFIGURE_DEPENDS "src/main.cpp"
                                                  "src/IndieStudio.cpp"
                                                  "src/LocalClient.cpp"
                                                  "src/server/linux/LinuxServer.cpp"
                                                  "src/game/managers/SceneManager.cpp"
                                                  "src/game/scenes/GameScene.cpp"
                                                  "src/game/scenes/MenuScene.cpp"
                                                  "src/game/scenes/SettingScene.cpp"
                                                  "src/game/scenes/PreGameScene.cpp"
                                                  "src/game/scenes/TutoScene.cpp"
                                                  "src/game/system/entities/EntityPlayer.cpp"
                                                  "src/game/system/components/Transformable.cpp"
                                                  "src/game/system/components/ModelComponent.cpp"
                                                  "src/game/system/components/IAComponent.cpp"
                                                  "src/game/system/components/Positionable.cpp"
                                                  "src/game/system/components/AnimatedModelComponent.cpp"
                                                  "src/game/system/entities/EntityAI.cpp"
                                                  "src/game/system/entities/EntityLiving.cpp"
                                                  "src/game/algorithms/patterns/Pattern.cpp"
                                                  "src/game/algorithms/patterns/FillMap.cpp"
                                                  "src/engine/audio/Audio.cpp"
                                                  "src/engine/audio/music/Music.cpp"
                                                  "src/engine/audio/sound/Sound.cpp"
                                                  "src/engine/event/keyboard/Keyboard.cpp"
                                                  "src/engine/event/mouse/Cursor.cpp"
                                                  "src/engine/event/mouse/Mouse.cpp"
                                                  "src/engine/graphic/2d/gui/button/Button.cpp"
                                                  "src/engine/graphic/2d/gui/text/Text.cpp"
                                                  "src/engine/graphic/2d/gui/text/TextBox.cpp"
                                                  "src/engine/graphic/2d/gui/text/font/Font.cpp"
                                                  "src/engine/graphic/2d/image/Image.cpp"
                                                  "src/engine/graphic/2d/texture/Texture.cpp"
                                                  "src/engine/graphic/2d/sprite/Sprite.cpp"
                                                  "src/engine/graphic/3d/model/Model.cpp"
                                                  "src/engine/graphic/3d/model/animated_model/AnimatedModel.cpp"
                                                  "src/engine/graphic/3d/mesh/Mesh.cpp"
                                                  "src/engine/graphic/3d/material/Material.cpp"
                                                  "src/engine/graphic/3d/shader/Shader.cpp"
                                                  "src/engine/graphic/3d/skybox/Skybox.cpp"
                                                  "src/engine/graphic/camera/Camera.cpp"
                                                  "src/engine/time/Time.cpp"
                                                  "src/engine/window/Window.cpp"
                                                  "src/engine/graphic/3d/billboard/Billboard.cpp"
                                                  "src/game/system/ECS.cpp"
                                                  "src/game/system/items/Bomb.cpp"
                                                  "src/game/system/items/Item.cpp"
                                                  "src/game/system/items/bombs/FireResidue.cpp"
                                                  "src/game/system/items/PowerUp.cpp"
                                                )
#Here add you'r .hpp
file (GLOB_RECURSE indie_HEADERS CONFIGURE_DEPENDS "src/IndieStudio.hpp"
                                                  "src/game/system/ECS.hpp"
                                                  "src/game/system/IComponent.hpp"
                                                  "src/game/system/IEntityContainer.hpp"
                                                  "src/game/scenes/GameScene.hpp"
                                                  "src/game/scenes/MenuScene.hpp"
                                                  "src/game/scenes/PreGameScene.hpp"
                                                  "src/game/scenes/Scene.hpp"
                                                  "src/game/managers/ItemManager.hpp"
                                                  "src/game/scenes/SettingScene.hpp"
                                                  "src/game/system/components/Transformable.hpp"
                                                  "src/game/system/components/IAComponent.hpp"
                                                  "src/game/system/components/BombExplosionable.hpp"
                                                  "src/game/system/components/Positionable.hpp"
                                                  "src/game/system/components/AnimatedModelComponent.hpp"
                                                  "src/game/system/entities/EntityPlayer.hpp"
                                                  "src/game/system/entities/EntityAI.hpp"
                                                  "src/game/system/entities/EntityLiving.hpp"
                                                  "src/game/managers/EntityManager.hpp"
                                                  "src/game/managers/IManager.hpp"
                                                  "src/game/managers/SceneManager.hpp"
                                                  "src/game/scenes/GameScene.hpp"
                                                  "src/game/scenes/MenuScene.hpp"
                                                  "src/game/scenes/Scene.hpp"
                                                  "src/game/scenes/TutoScene.hpp"
                                                  "src/server/IServer.hpp"
                                                  "src/server/linux/LinuxServer.hpp"
                                                  "src/game/system/entities/ItemEntity.hpp"
                                                  "src/tools/LocalClient.hpp"
                                                  "src/tools/PropertyLoader.hpp"
                                                  "src/game/utils/Matrix.hpp"
                                                  "src/game/algorithms/patterns/Pattern.hpp"
                                                  "src/game/system/entities/EntityBomb.hpp"
                                                  "src/engine/Engine.hpp"
                                                  "src/engine/audio/Audio.hpp"
                                                  "src/engine/event/Event.hpp"
                                                  "src/engine/event/keyboard/Keyboard.hpp"
                                                  "src/engine/event/mouse/Cursor.hpp"
                                                  "src/engine/event/mouse/Mouse.hpp"
                                                  "src/engine/graphic/Graphic.hpp"
                                                  "src/engine/graphic/2d/2d.hpp"
                                                  "src/engine/graphic/2d/gui/GUI.hpp"
                                                  "src/engine/graphic/2d/gui/button/Button.hpp"
                                                  "src/engine/graphic/2d/gui/text/Text.hpp"
                                                  "src/engine/graphic/2d/gui/text/TextBox.hpp"
                                                  "src/engine/graphic/2d/gui/text/font/Font.hpp"
                                                  "src/engine/graphic/2d/image/Image.hpp"
                                                  "src/engine/graphic/2d/texture/Texture.hpp"
                                                  "src/engine/graphic/2d/sprite/Sprite.hpp"
                                                  "src/engine/graphic/3d/3d.hpp"
                                                  "src/engine/Models.hpp"
                                                  "src/engine/graphic/3d/material/Material.hpp"
                                                  "src/engine/graphic/3d/mesh/Mesh.hpp"
                                                  "src/engine/graphic/3d/model/Model.hpp"
                                                  "src/engine/graphic/3d/model/animated_model/AnimatedModel.hpp"
                                                  "src/engine/graphic/3d/skybox/Skybox.hpp"
                                                  "src/engine/graphic/3d/shader/Shader.hpp"
                                                  "src/engine/graphic/camera/Camera.hpp"
                                                  "src/engine/graphic/color/Color.hpp"
                                                  "src/engine/math/Math.hpp"
                                                  "src/engine/math/rectangle/Rectangle.hpp"
                                                  "src/engine/math/vector/Vector2.hpp"
                                                  "src/engine/math/vector/Vector3.hpp"
                                                  "src/engine/math/vector/Vector4.hpp"
                                                  "src/engine/time/Time.hpp"
                                                  "src/engine/window/Window.hpp"
                                                  "src/engine/graphic/3d/billboard/Billboard.hpp"
                                                  "src/game/system/items/Bomb.hpp"
                                                  "src/game/system/items/Item.hpp"
                                                  "src/game/system/items/bombs/FireResidue.hpp"
                                                  "src/game/system/items/bombs/SpawnableBomb.hpp"
                                                  "src/game/system/components/ModelComponent.hpp"
                                                  "src/game/system/items/PowerUp.hpp"
                                                  "src/game/system/items/powerups/BombUP.hpp"
                                                  "src/game/system/items/powerups/FireUP.hpp"
                                                  "src/game/system/items/powerups/SpeedUP.hpp"
                                                  "src/game/system/items/powerups/WallPass.hpp"
                                                  )

set (indie_INCLUDE_DIRS "")
foreach (_headerFile ${indie_HEADERS})
    get_filename_component(_dir ${_headerFile} PATH)
    list (APPEND indie_INCLUDE_DIRS ${_dir})
endforeach()
list (REMOVE_DUPLICATES indie_INCLUDE_DIRS)

set(CMAKE_CXX_FLAGS "-g")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${indie_SOURCE_DIR})
add_executable(bomberman ${indie_SOURCES})
target_include_directories(bomberman PUBLIC ${indie_INCLUDE_DIRS})
target_link_libraries(bomberman raylib)