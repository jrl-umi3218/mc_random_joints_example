#pragma once

#if defined _WIN32 || defined __CYGWIN__
#define RandomJointsExample_DLLIMPORT __declspec(dllimport)
#define RandomJointsExample_DLLEXPORT __declspec(dllexport)
#define RandomJointsExample_DLLLOCAL
#else
// On Linux, for GCC >= 4, tag symbols using GCC extension.
#if __GNUC__ >= 4
#define RandomJointsExample_DLLIMPORT __attribute__((visibility("default")))
#define RandomJointsExample_DLLEXPORT __attribute__((visibility("default")))
#define RandomJointsExample_DLLLOCAL __attribute__((visibility("hidden")))
#else
// Otherwise (GCC < 4 or another compiler is used), export everything.
#define RandomJointsExample_DLLIMPORT
#define RandomJointsExample_DLLEXPORT
#define RandomJointsExample_DLLLOCAL
#endif  // __GNUC__ >= 4
#endif  // defined _WIN32 || defined __CYGWIN__

#ifdef RandomJointsExample_STATIC
// If one is using the library statically, get rid of
// extra information.
#define RandomJointsExample_DLLAPI
#define RandomJointsExample_LOCAL
#else
// Depending on whether one is building or using the
// library define DLLAPI to import or export.
#ifdef RandomJointsExample_EXPORTS
#define RandomJointsExample_DLLAPI RandomJointsExample_DLLEXPORT
#else
#define RandomJointsExample_DLLAPI RandomJointsExample_DLLIMPORT
#endif  // RandomJointsExample_EXPORTS
#define RandomJointsExample_LOCAL RandomJointsExample_DLLLOCAL
#endif  // RandomJointsExample_STATIC
