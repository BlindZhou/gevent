
#pragma once

#ifdef WIN32
#  define DIR_SEP_CHAR '\\'
#  define strcasecmp stricmp
#  define strncasecmp strnicmp

typedef int socklen_t; 
typedef void* timer_t; 

#else // WIN32

#  define DIR_SEP_CHAR '/'

#  ifndef MAX_PATH
#  define MAX_PATH PATH_MAX
#  endif

#  define _snprintf snprintf
#  define _vsnprintf vsnprintf
#  define _stat32 stat
#  define _access access
#  define _unlink unlink
#  define INVALID_SOCKET -1
#  define SOCKET_ERROR -1
#  define closesocket ::close
#  define GetLastError() errno
#  define WSAGetLastError() errno

#  ifndef STDMETHOD
#  define STDMETHOD(method) virtual HRESULT method
#  endif

#  ifndef S_FALSE
#  define S_FALSE 1
#  endif

#  ifndef S_OK
#  define S_OK 0
#  endif

//#  ifndef HRESULT
//#  define HRESULT long
//#  endif

typedef int HRESULT; 
typedef int SOCKET; 
typedef struct sockaddr SOCKADDR; 
typedef struct sockaddr_in SOCKADDR_IN; 
typedef unsigned short INTERNET_PORT;
typedef unsigned int DWORD; 
typedef void* HANDLE;
typedef void* HMODULE;
typedef int BOOL; 

#endif

