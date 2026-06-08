#ifndef SCENE_EXPORT_WINDOWS_H
#define SCENE_EXPORT_WINDOWS_H

#if defined(Scene_LIB)
#define SCENE_EXPORT __declspec(dllexport)
#else
#define SCENE_EXPORT __declspec(dllimport)
#endif // Scene_LIB


#endif // !SCENE_EXPORT_WINDOWS_H
