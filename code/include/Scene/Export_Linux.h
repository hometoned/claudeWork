#ifndef SCENE_EXPORT_LINUX_H
#define SCENE_EXPORT_LINUX_H

#if defined(Scene_LIB)
#define SCENE_EXPORT __attribute__((visibility("default")))
#else
#define SCENE_EXPORT 
#endif // !Scene_LIB

#endif // !SCENE_EXPORT_LINUX_H