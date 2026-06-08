#ifndef SCENE_EXPORT_H
#define SCENE_EXPORT_H

#if defined(WINDOWS)
    #include <Scene/Export_Windows.h>
#elif defined(LINUX)
    #include <Scene/Export_Linux.h>
#endif

#endif // !SCENE_EXPORT_H
