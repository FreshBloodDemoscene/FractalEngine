#ifndef __FRACTAL_ENGINE_FILE_H__
#define __FRACTAL_ENGINE_FILE_H__

#include <filesystem>
#include <chrono>
#include <thread>
#include <unordered_map>
#include <string>
#include <functional>


#include <window.h>
#include <renderer.h>

enum class E_FileStatus {modified, nothingchanged};

class File
{
public:
    E_FileStatus status;

    const char* fragment_shader_file    = "ShaderFiles/Shader.fs";
    const char* vertex_shader_file      = "ShaderFiles/Shader.vs";

    std::filesystem::file_time_type fs_changed;
    std::filesystem::file_time_type vs_changed;

    explicit File();
    ~File() noexcept;

    void UpdateFile         (Renderer& render, Window& window, float t);
    void CheckModification  ();
};

#endif  //__FRACTAL_ENGINE_FILE_H__

