/*
** EPITECH PROJECT, 2022
** B-YEP-410-STG-4-1-istudio-ethan.husser
** File description:
** Skybox
*/

#include "Skybox.hpp"


namespace istudio
{
    namespace graphic
    {
        Skybox::Skybox()
        {

        }


        Skybox::Skybox(std::string filename)
        {
            _isLoaded = true;
            Mesh cube = GenMeshCube(10.0f, 10.0f, 10.0f);
            _skybox = LoadModelFromMesh(cube);
            Texture2D panorama = LoadTexture(filename.c_str());

            int cub[1] = {MATERIAL_MAP_CUBEMAP};
            int as[1] = {0};
            int ass[1] = {1};
            _skybox.materials[0].shader = LoadShader("./assets/shaders/skybox.vs", "./assets/shaders/skybox.fs");
            SetShaderValue(_skybox.materials[0].shader, GetShaderLocation(_skybox.materials[0].shader, "environmentMap"), cub, SHADER_UNIFORM_INT);
            SetShaderValue(_skybox.materials[0].shader, GetShaderLocation(_skybox.materials[0].shader, "doGamma"), ass, SHADER_UNIFORM_INT);
            SetShaderValue(_skybox.materials[0].shader, GetShaderLocation(_skybox.materials[0].shader, "vflipped"), ass, SHADER_UNIFORM_INT);

            Shader shdrCubemap = LoadShader("./assets/shaders/cubemap.vs", "./assets/shaders/cubemap.fs");

            SetShaderValue(shdrCubemap, GetShaderLocation(shdrCubemap, "equirectangularMap"), as, SHADER_UNIFORM_INT);

            _skybox.materials[0].maps[MATERIAL_MAP_CUBEMAP].texture = GenTextureCubemap(shdrCubemap, panorama, 1024, PIXELFORMAT_UNCOMPRESSED_R8G8B8A8);
        }

        Skybox::~Skybox()
        {
            unload();
        }

        void Skybox::unload()
        {
            if (_isLoaded) {
                UnloadShader(_skybox.materials[0].shader);
                UnloadTexture(_skybox.materials[0].maps[MATERIAL_MAP_CUBEMAP].texture);
                UnloadModel(_skybox);
                _isLoaded = false;
            }
        }

        void Skybox::draw()
        {
            if (!_isLoaded) return;
            rlDisableBackfaceCulling();
            rlDisableDepthMask();
            DrawModel(_skybox, {0, 0, 0}, 1, {255, 255, 255, 255});
            rlEnableBackfaceCulling();
            rlEnableDepthMask();
        }

        void Skybox::load(std::string filename)
        {
            _isLoaded = true;
            Mesh cube =  GenMeshCube(10.0f, 10.0f, 10.0f);
            _skybox = LoadModelFromMesh(cube);
            Texture2D panorama = LoadTexture(filename.c_str());

            int cub[1] = {MATERIAL_MAP_CUBEMAP};
            int as[1] = {0};
            int ass[1] = {1};
            _skybox.materials[0].shader = LoadShader("./assets/shaders/skybox.vs", "./assets/shaders/skybox.fs");
            SetShaderValue(_skybox.materials[0].shader, GetShaderLocation(_skybox.materials[0].shader, "environmentMap"), cub, SHADER_UNIFORM_INT);
            SetShaderValue(_skybox.materials[0].shader, GetShaderLocation(_skybox.materials[0].shader, "doGamma"), ass, SHADER_UNIFORM_INT);
            SetShaderValue(_skybox.materials[0].shader, GetShaderLocation(_skybox.materials[0].shader, "vflipped"), ass, SHADER_UNIFORM_INT);

            Shader shdrCubemap = LoadShader("./assets/shaders/cubemap.vs", "./assets/shaders/cubemap.fs");

            SetShaderValue(shdrCubemap, GetShaderLocation(shdrCubemap, "equirectangularMap"), as, SHADER_UNIFORM_INT);

            _skybox.materials[0].maps[MATERIAL_MAP_CUBEMAP].texture = GenTextureCubemap(shdrCubemap, panorama, 1024, PIXELFORMAT_UNCOMPRESSED_R8G8B8A8);
        }

        TextureCubemap Skybox::GenTextureCubemap(Shader shader, Texture2D panorama, int size, int format)
        {
            TextureCubemap cubemap = {0};

            rlDisableBackfaceCulling(); // Disable backface culling to render inside the cube

            // STEP 1: Setup framebuffer
            //------------------------------------------------------------------------------------------
            unsigned int rbo = rlLoadTextureDepth(size, size, true);
            cubemap.id = rlLoadTextureCubemap(0, size, format);

            unsigned int fbo = rlLoadFramebuffer(size, size);
            rlFramebufferAttach(fbo, rbo, RL_ATTACHMENT_DEPTH, RL_ATTACHMENT_RENDERBUFFER, 0);
            rlFramebufferAttach(fbo, cubemap.id, RL_ATTACHMENT_COLOR_CHANNEL0, RL_ATTACHMENT_CUBEMAP_POSITIVE_X, 0);

            // Check if framebuffer is complete with attachments (valid)
            if (rlFramebufferComplete(fbo))
                TraceLog(LOG_INFO, "FBO: [ID %i] Framebuffer object created successfully", fbo);
            //------------------------------------------------------------------------------------------

            // STEP 2: Draw to framebuffer
            //------------------------------------------------------------------------------------------
            // NOTE: Shader is used to convert HDR equirectangular environment map to cubemap equivalent (6 faces)
            rlEnableShader(shader.id);

            // Define projection matrix and send it to shader
            Matrix matFboProjection = MatrixPerspective(90.0 * DEG2RAD, 1.0, RL_CULL_DISTANCE_NEAR, RL_CULL_DISTANCE_FAR);
            rlSetUniformMatrix(shader.locs[SHADER_LOC_MATRIX_PROJECTION], matFboProjection);

            // Define view matrix for every side of the cubemap
            Matrix fboViews[6] = {
                MatrixLookAt({0.0f, 0.0f, 0.0f}, {1.0f, 0.0f, 0.0f}, {0.0f, -1.0f, 0.0f}),
                MatrixLookAt({0.0f, 0.0f, 0.0f}, {1.0f, 0.0f, 0.0f}, {0.0f, -1.0f, 0.0f}),
                MatrixLookAt({0.0f, 0.0f, 0.0f}, {0.0f, 1.0f, 0.0f}, {0.0f, 0.0f, 1.0f}),
                MatrixLookAt({0.0f, 0.0f, 0.0f}, {0.0f, -1.0f, 0.0f}, {0.0f, 0.0f, -1.0f}),
                MatrixLookAt({0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 1.0f}, {0.0f, -1.0f, 0.0f}),
                MatrixLookAt({0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, -1.0f}, {0.0f, -1.0f, 0.0f})};

            rlViewport(0, 0, size, size); // Set viewport to current fbo dimensions

            // Activate and enable texture for drawing to cubemap faces
            rlActiveTextureSlot(0);
            rlEnableTexture(panorama.id);

            for (int i = 0; i < 6; i++)
            {
                // Set the view matrix for the current cube face
                rlSetUniformMatrix(shader.locs[SHADER_LOC_MATRIX_VIEW], fboViews[i]);

                // Select the current cubemap face attachment for the fbo
                // WARNING: This function by default enables->attach->disables fbo!!!
                rlFramebufferAttach(fbo, cubemap.id, RL_ATTACHMENT_COLOR_CHANNEL0, RL_ATTACHMENT_CUBEMAP_POSITIVE_X + i, 0);
                rlEnableFramebuffer(fbo);

                // Load and draw a cube, it uses the current enabled texture
                rlClearScreenBuffers();
                rlLoadDrawCube();

                // ALTERNATIVE: Try to use internal batch system to draw the cube instead of rlLoadDrawCube
                // for some reason this method does not work, maybe due to cube triangles definition? normals pointing out?
                // rlSetTexture(panorama.id); // WARNING: It must be called after enabling current framebuffer if using internal batch system!
                // rlClearScreenBuffers();
                // DrawCubeV(Vector3Zero(), Vector3One(), WHITE);
                // rlDrawRenderBatchActive();
            }
            //------------------------------------------------------------------------------------------

            // STEP 3: Unload framebuffer and reset state
            //------------------------------------------------------------------------------------------
            rlDisableShader();        // Unbind shader
            rlDisableTexture();       // Unbind texture
            rlDisableFramebuffer();   // Unbind framebuffer
            rlUnloadFramebuffer(fbo); // Unload framebuffer (and automatically attached depth texture/renderbuffer)

            // Reset viewport dimensions to default
            rlViewport(0, 0, rlGetFramebufferWidth(), rlGetFramebufferHeight());
            rlEnableBackfaceCulling();
            //------------------------------------------------------------------------------------------

            cubemap.width = size;
            cubemap.height = size;
            cubemap.mipmaps = 1;
            cubemap.format = format;

            return cubemap;
        }
    }
}
