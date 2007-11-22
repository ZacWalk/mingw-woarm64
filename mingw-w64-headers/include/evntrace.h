/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _EVNTRACE_
#define _EVNTRACE_

#if defined(_WINNT_) || defined(WINNT)
#ifndef WMIAPI
#define WMIAPI DECLSPEC_IMPORT WINAPI
#endif

#include <guiddef.h>

DEFINE_GUID (EventTraceGuid,0x68fdd900,0x4a3e,0x11d1,0x84,0xf4,0x00,0x00,0xf8,0x04,0x64,0xe3);
DEFINE_GUID (SystemTraceControlGuid,0x9e814aad,0x3204,0x11d2,0x9a,0x82,0x00,0x60,0x08,0xa8,0x69,0x39);
DEFINE_GUID (EventTraceConfigGuid,0x01853a65,0x418f,0x4f36,0xae,0xfc,0xdc,0x0f,0x1d,0x2f,0xd2,0x35);
DEFINE_GUID (DefaultTraceSecurityGuid,0x0811c1af,0x7a07,0x4a06,0x82,0xed,0x86,0x94,0x55,0xcd,0xf7,0x13);

#define KERNEL_LOGGER_NAMEW L"NT Kernel Logger"
#define GLOBAL_LOGGER_NAMEW L"GlobalLogger"
#define EVENT_LOGGER_NAMEW L"Event Log"

#define KERNEL_LOGGER_NAMEA "NT Kernel Logger"
#define GLOBAL_LOGGER_NAMEA "GlobalLogger"
#define EVENT_LOGGER_NAMEA "Event Log"

#define MAX_MOF_FIELDS 16
typedef ULONG64 TRACEHANDLE,*PTRACEHANDLE;

#define EVENT_TRACE_TYPE_INFO 0x00
#define EVENT_TRACE_TYPE_START 0x01
#define EVENT_TRACE_TYPE_END 0x02
#define EVENT_TRACE_TYPE_DC_START 0x03
#define EVENT_TRACE_TYPE_DC_END 0x04
#define EVENT_TRACE_TYPE_EXTENSION 0x05
#define EVENT_TRACE_TYPE_REPLY 0x06
#define EVENT_TRACE_TYPE_DEQUEUE 0x07
#define EVENT_TRACE_TYPE_CHECKPOINT 0x08
#define EVENT_TRACE_TYPE_RESERVED9 0x09

#define TRACE_LEVEL_NONE 0
#define TRACE_LEVEL_FATAL 1
#define TRACE_LEVEL_ERROR 2
#define TRACE_LEVEL_WARNING 3
#define TRACE_LEVEL_INFORMATION 4
#define TRACE_LEVEL_VERBOSE 5
#define TRACE_LEVEL_RESERVED6 6
#define TRACE_LEVEL_RESERVED7 7
#define TRACE_LEVEL_RESERVED8 8
#define TRACE_LEVEL_RESERVED9 9

#define EVENT_TRACE_TYPE_LOAD 0x0A
#define EVENT_TRACE_TYPE_IO_READ 0x0A
#define EVENT_TRACE_TYPE_IO_WRITE 0x0B

#define EVENT_TRACE_TYPE_MM_TF 0x0A
#define EVENT_TRACE_TYPE_MM_DZF 0x0B
#define EVENT_TRACE_TYPE_MM_COW 0x0C
#define EVENT_TRACE_TYPE_MM_GPF 0x0D
#define EVENT_TRACE_TYPE_MM_HPF 0x0E

#define EVENT_TRACE_TYPE_SEND 0x0A
#define EVENT_TRACE_TYPE_RECEIVE 0x0B
#define EVENT_TRACE_TYPE_CONNECT 0x0C
#define EVENT_TRACE_TYPE_DISCONNECT 0x0D
#define EVENT_TRACE_TYPE_RETRANSMIT 0x0E
#define EVENT_TRACE_TYPE_ACCEPT 0x0F
#define EVENT_TRACE_TYPE_RECONNECT 0x10
#define EVENT_TRACE_TYPE_CONNFAIL 0x11
#define EVENT_TRACE_TYPE_COPY_TCP 0x12
#define EVENT_TRACE_TYPE_COPY_ARP 0x13
#define EVENT_TRACE_TYPE_ACKFULL 0x14
#define EVENT_TRACE_TYPE_ACKPART 0x15
#define EVENT_TRACE_TYPE_ACKDUP 0x16

#define EVENT_TRACE_TYPE_GUIDMAP 0x0A
#define EVENT_TRACE_TYPE_CONFIG 0x0B
#define EVENT_TRACE_TYPE_SIDINFO 0x0C
#define EVENT_TRACE_TYPE_SECURITY 0x0D

#define EVENT_TRACE_TYPE_REGCREATE 0x0A
#define EVENT_TRACE_TYPE_REGOPEN 0x0B
#define EVENT_TRACE_TYPE_REGDELETE 0x0C
#define EVENT_TRACE_TYPE_REGQUERY 0x0D
#define EVENT_TRACE_TYPE_REGSETVALUE 0x0E
#define EVENT_TRACE_TYPE_REGDELETEVALUE 0x0F
#define EVENT_TRACE_TYPE_REGQUERYVALUE 0x10
#define EVENT_TRACE_TYPE_REGENUMERATEKEY 0x11
#define EVENT_TRACE_TYPE_REGENUMERATEVALUEKEY 0x12
#define EVENT_TRACE_TYPE_REGQUERYMULTIPLEVALUE 0x13
#define EVENT_TRACE_TYPE_REGSETINFORMATION 0x14
#define EVENT_TRACE_TYPE_REGFLUSH 0x15
#define EVENT_TRACE_TYPE_REGKCBDMP 0x16

#define EVENT_TRACE_TYPE_CONFIG_CPU 0x0A
#define EVENT_TRACE_TYPE_CONFIG_PHYSICALDISK 0x0B
#define EVENT_TRACE_TYPE_CONFIG_LOGICALDISK 0x0C
#define EVENT_TRACE_TYPE_CONFIG_NIC 0x0D
#define EVENT_TRACE_TYPE_CONFIG_VIDEO 0x0E
#define EVENT_TRACE_TYPE_CONFIG_SERVICES 0x0F
#define EVENT_TRACE_TYPE_CONFIG_POWER 0x10
#define EVENT_TRACE_TYPE_CONFIG_NETINFO 0x11

#define EVENT_TRACE_FLAG_PROCESS 0x00000001
#define EVENT_TRACE_FLAG_THREAD 0x00000002
#define EVENT_TRACE_FLAG_IMAGE_LOAD 0x00000004

#define EVENT_TRACE_FLAG_DISK_IO 0x00000100
#define EVENT_TRACE_FLAG_DISK_FILE_IO 0x00000200

#define EVENT_TRACE_FLAG_MEMORY_PAGE_FAULTS 0x00001000
#define EVENT_TRACE_FLAG_MEMORY_HARD_FAULTS 0x00002000

#define EVENT_TRACE_FLAG_NETWORK_TCPIP 0x00010000

#define EVENT_TRACE_FLAG_REGISTRY 0x00020000
#define EVENT_TRACE_FLAG_DBGPRINT 0x00040000

#define EVENT_TRACE_FLAG_VOLMGR 0x00200000

#define EVENT_TRACE_FLAG_EXTENSION 0x80000000
#define EVENT_TRACE_FLAG_FORWARD_WMI 0x40000000
#define EVENT_TRACE_FLAG_ENABLE_RESERVE 0x20000000

#define EVENT_TRACE_FILE_MODE_NONE 0x00000000
#define EVENT_TRACE_FILE_MODE_SEQUENTIAL 0x00000001
#define EVENT_TRACE_FILE_MODE_CIRCULAR 0x00000002
#define EVENT_TRACE_FILE_MODE_APPEND 0x00000004
#define EVENT_TRACE_FILE_MODE_NEWFILE 0x00000008

#define EVENT_TRACE_FILE_MODE_PREALLOCATE 0x00000020

#define EVENT_TRACE_REAL_TIME_MODE 0x00000100
#define EVENT_TRACE_DELAY_OPEN_FILE_MODE 0x00000200
#define EVENT_TRACE_BUFFERING_MODE 0x00000400
#define EVENT_TRACE_PRIVATE_LOGGER_MODE 0x00000800
#define EVENT_TRACE_ADD_HEADER_MODE 0x00001000
#define EVENT_TRACE_USE_GLOBAL_SEQUENCE 0x00004000
#define EVENT_TRACE_USE_LOCAL_SEQUENCE 0x00008000

#define EVENT_TRACE_RELOG_MODE 0x00010000

#define EVENT_TRACE_USE_PAGED_MEMORY 0x01000000

#define EVENT_TRACE_CONTROL_QUERY 0
#define EVENT_TRACE_CONTROL_STOP 1
#define EVENT_TRACE_CONTROL_UPDATE 2
#define EVENT_TRACE_CONTROL_FLUSH 3

#define TRACE_MESSAGE_SEQUENCE 1
#define TRACE_MESSAGE_GUID 2
#define TRACE_MESSAGE_COMPONENTID 4
#define TRACE_MESSAGE_TIMESTAMP 8
#define TRACE_MESSAGE_PERFORMANCE_TIMESTAMP 16
#define TRACE_MESSAGE_SYSTEMINFO 32
#define TRACE_MESSAGE_FLAG_MASK 0xFFFF

#define TRACE_MESSAGE_MAXIMUM_SIZE 8*1024

#define EVENT_TRACE_USE_PROCTIME 0x0001
#define EVENT_TRACE_USE_NOCPUTIME 0x0002

typedef struct _EVENT_TRACE_HEADER {
  USHORT Size;
  union {
    USHORT FieldTypeFlags;
    struct {
      UCHAR HeaderType;
      UCHAR MarkerFlags;
    };
  };
  union {
    ULONG Version;
    struct {
      UCHAR Type;
      UCHAR Level;
      USHORT Version;
    } Class;
  };
  ULONG ThreadId;
  ULONG ProcessId;
  LARGE_INTEGER TimeStamp;
  union {
    GUID Guid;
    ULONGLONG GuidPtr;
  };
  union {
    struct {
      ULONG ClientContext;
      ULONG Flags;
    };
    struct {
      ULONG KernelTime;
      ULONG UserTime;
    };
    ULONG64 ProcessorTime;
  };
} EVENT_TRACE_HEADER,*PEVENT_TRACE_HEADER;

typedef struct _EVENT_INSTANCE_HEADER {
  USHORT Size;
  union {
    USHORT FieldTypeFlags;
    struct {
      UCHAR HeaderType;
      UCHAR MarkerFlags;
    };
  };
  union {
    ULONG Version;
    struct {
      UCHAR Type;
      UCHAR Level;
      USHORT Version;
    } Class;
  };
  ULONG ThreadId;
  ULONG ProcessId;
  LARGE_INTEGER TimeStamp;
  ULONGLONG RegHandle;
  ULONG InstanceId;
  ULONG ParentInstanceId;
  union {
    struct {
      ULONG ClientContext;
      ULONG Flags;
    };
    struct {
      ULONG KernelTime;
      ULONG UserTime;
    };
    ULONG64 ProcessorTime;
  };
  ULONGLONG ParentRegHandle;
} EVENT_INSTANCE_HEADER,*PEVENT_INSTANCE_HEADER;

#define DEFINE_TRACE_MOF_FIELD(MOF,ptr,length,type) (MOF)->DataPtr = (ULONG64) ptr; (MOF)->Length = (ULONG) length; (MOF)->DataType = (ULONG) type;

typedef struct _MOF_FIELD {
  ULONG64 DataPtr;
  ULONG Length;
  ULONG DataType;
} MOF_FIELD,*PMOF_FIELD;

#ifndef _NTIFS_

typedef struct _TRACE_LOGFILE_HEADER {
  ULONG BufferSize;
  union {
    ULONG Version;
    struct {
      UCHAR MajorVersion;
      UCHAR MinorVersion;
      UCHAR SubVersion;
      UCHAR SubMinorVersion;
    } VersionDetail;
  };
  ULONG ProviderVersion;
  ULONG NumberOfProcessors;
  LARGE_INTEGER EndTime;
  ULONG TimerResolution;
  ULONG MaximumFileSize;
  ULONG LogFileMode;
  ULONG BuffersWritten;
  union {
    GUID LogInstanceGuid;
    struct {
      ULONG StartBuffers;
      ULONG PointerSize;
      ULONG EventsLost;
      ULONG CpuSpeedInMHz;
    };
  };
  LPWSTR LoggerName;
  LPWSTR LogFileName;
  TIME_ZONE_INFORMATION TimeZone;
  LARGE_INTEGER BootTime;
  LARGE_INTEGER PerfFreq;
  LARGE_INTEGER StartTime;
  ULONG ReservedFlags;
  ULONG BuffersLost;
} TRACE_LOGFILE_HEADER,*PTRACE_LOGFILE_HEADER;
#endif

typedef struct EVENT_INSTANCE_INFO {
  HANDLE RegHandle;
  ULONG InstanceId;
} EVENT_INSTANCE_INFO,*PEVENT_INSTANCE_INFO;

#ifndef _NTIFS_

typedef struct _EVENT_TRACE_PROPERTIES {
  WNODE_HEADER Wnode;
  ULONG BufferSize;
  ULONG MinimumBuffers;
  ULONG MaximumBuffers;
  ULONG MaximumFileSize;
  ULONG LogFileMode;
  ULONG FlushTimer;
  ULONG EnableFlags;
  LONG AgeLimit;
  ULONG NumberOfBuffers;
  ULONG FreeBuffers;
  ULONG EventsLost;
  ULONG BuffersWritten;
  ULONG LogBuffersLost;
  ULONG RealTimeBuffersLost;
  HANDLE LoggerThreadId;
  ULONG LogFileNameOffset;
  ULONG LoggerNameOffset;
} EVENT_TRACE_PROPERTIES,*PEVENT_TRACE_PROPERTIES;

typedef struct _TRACE_GUID_PROPERTIES {
  GUID Guid;
  ULONG GuidType;
  ULONG LoggerId;
  ULONG EnableLevel;
  ULONG EnableFlags;
  BOOLEAN IsEnable;
} TRACE_GUID_PROPERTIES,*PTRACE_GUID_PROPERTIES;

typedef struct _TRACE_GUID_REGISTRATION {
  LPCGUID Guid;
  HANDLE RegHandle;
} TRACE_GUID_REGISTRATION,*PTRACE_GUID_REGISTRATION;

typedef struct _EVENT_TRACE {
  EVENT_TRACE_HEADER Header;
  ULONG InstanceId;
  ULONG ParentInstanceId;
  GUID ParentGuid;
  PVOID MofData;
  ULONG MofLength;
  ULONG ClientContext;
} EVENT_TRACE,*PEVENT_TRACE;

typedef struct _EVENT_TRACE_LOGFILEW EVENT_TRACE_LOGFILEW,*PEVENT_TRACE_LOGFILEW;
typedef struct _EVENT_TRACE_LOGFILEA EVENT_TRACE_LOGFILEA,*PEVENT_TRACE_LOGFILEA;
typedef ULONG (WINAPI *PEVENT_TRACE_BUFFER_CALLBACKW)(PEVENT_TRACE_LOGFILEW Logfile);
typedef ULONG (WINAPI *PEVENT_TRACE_BUFFER_CALLBACKA)(PEVENT_TRACE_LOGFILEA Logfile);
typedef VOID (WINAPI *PEVENT_CALLBACK)(PEVENT_TRACE pEvent);
typedef ULONG (WINAPI *WMIDPREQUEST)(WMIDPREQUESTCODE RequestCode,PVOID RequestContext,ULONG *BufferSize,PVOID Buffer);

struct _EVENT_TRACE_LOGFILEW {
  LPWSTR LogFileName;
  LPWSTR LoggerName;
  LONGLONG CurrentTime;
  ULONG BuffersRead;
  ULONG LogFileMode;

  EVENT_TRACE CurrentEvent;
  TRACE_LOGFILE_HEADER LogfileHeader;
  PEVENT_TRACE_BUFFER_CALLBACKW BufferCallback;
  ULONG BufferSize;
  ULONG Filled;
  ULONG EventsLost;
  PEVENT_CALLBACK EventCallback;
  ULONG IsKernelTrace;
  PVOID Context;
};

struct _EVENT_TRACE_LOGFILEA {
  LPSTR LogFileName;
  LPSTR LoggerName;
  LONGLONG CurrentTime;
  ULONG BuffersRead;
  ULONG LogFileMode;
  EVENT_TRACE CurrentEvent;
  TRACE_LOGFILE_HEADER LogfileHeader;
  PEVENT_TRACE_BUFFER_CALLBACKA BufferCallback;
  ULONG BufferSize;
  ULONG Filled;
  ULONG EventsLost;
  PEVENT_CALLBACK EventCallback;
  ULONG IsKernelTrace;
  PVOID Context;
};

#if defined(_UNICODE) || defined(UNICODE)
#define PEVENT_TRACE_BUFFER_CALLBACK PEVENT_TRACE_BUFFER_CALLBACKW
#define EVENT_TRACE_LOGFILE EVENT_TRACE_LOGFILEW
#define PEVENT_TRACE_LOGFILE PEVENT_TRACE_LOGFILEW
#define KERNEL_LOGGER_NAME KERNEL_LOGGER_NAMEW
#define GLOBAL_LOGGER_NAME GLOBAL_LOGGER_NAMEW
#define EVENT_LOGGER_NAME EVENT_LOGGER_NAMEW
#else

#define PEVENT_TRACE_BUFFER_CALLBACK PEVENT_TRACE_BUFFER_CALLBACKA
#define EVENT_TRACE_LOGFILE EVENT_TRACE_LOGFILEA
#define PEVENT_TRACE_LOGFILE PEVENT_TRACE_LOGFILEA
#define KERNEL_LOGGER_NAME KERNEL_LOGGER_NAMEA
#define GLOBAL_LOGGER_NAME GLOBAL_LOGGER_NAMEA
#define EVENT_LOGGER_NAME EVENT_LOGGER_NAMEA
#endif

#ifdef __cplusplus
extern "C" {
#endif

  EXTERN_C ULONG WMIAPI StartTraceW(PTRACEHANDLE TraceHandle,LPCWSTR InstanceName,PEVENT_TRACE_PROPERTIES Properties);
  EXTERN_C ULONG WMIAPI StartTraceA(PTRACEHANDLE TraceHandle,LPCSTR InstanceName,PEVENT_TRACE_PROPERTIES Properties);
  EXTERN_C ULONG WMIAPI StopTraceW(TRACEHANDLE TraceHandle,LPCWSTR InstanceName,PEVENT_TRACE_PROPERTIES Properties);
  EXTERN_C ULONG WMIAPI StopTraceA(TRACEHANDLE TraceHandle,LPCSTR InstanceName,PEVENT_TRACE_PROPERTIES Properties);
  EXTERN_C ULONG WMIAPI QueryTraceW(TRACEHANDLE TraceHandle,LPCWSTR InstanceName,PEVENT_TRACE_PROPERTIES Properties);
  EXTERN_C ULONG WMIAPI QueryTraceA(TRACEHANDLE TraceHandle,LPCSTR InstanceName,PEVENT_TRACE_PROPERTIES Properties);
  EXTERN_C ULONG WMIAPI UpdateTraceW(TRACEHANDLE TraceHandle,LPCWSTR InstanceName,PEVENT_TRACE_PROPERTIES Properties);
  EXTERN_C ULONG WMIAPI UpdateTraceA(TRACEHANDLE TraceHandle,LPCSTR InstanceName,PEVENT_TRACE_PROPERTIES Properties);
  EXTERN_C ULONG WMIAPI FlushTraceW(TRACEHANDLE TraceHandle,LPCWSTR InstanceName,PEVENT_TRACE_PROPERTIES Properties);
  EXTERN_C ULONG WMIAPI FlushTraceA(TRACEHANDLE TraceHandle,LPCSTR InstanceName,PEVENT_TRACE_PROPERTIES Properties);
  EXTERN_C ULONG WMIAPI ControlTraceW(TRACEHANDLE TraceHandle,LPCWSTR InstanceName,PEVENT_TRACE_PROPERTIES Properties,ULONG ControlCode);
  EXTERN_C ULONG WMIAPI ControlTraceA(TRACEHANDLE TraceHandle,LPCSTR InstanceName,PEVENT_TRACE_PROPERTIES Properties,ULONG ControlCode);
  EXTERN_C ULONG WMIAPI QueryAllTracesW(PEVENT_TRACE_PROPERTIES *PropertyArray,ULONG PropertyArrayCount,PULONG LoggerCount);
  EXTERN_C ULONG WMIAPI QueryAllTracesA(PEVENT_TRACE_PROPERTIES *PropertyArray,ULONG PropertyArrayCount,PULONG LoggerCount);
  EXTERN_C ULONG WMIAPI CreateTraceInstanceId(HANDLE RegHandle,PEVENT_INSTANCE_INFO pInstInfo);
  EXTERN_C ULONG WMIAPI EnableTrace(ULONG Enable,ULONG EnableFlag,ULONG EnableLevel,LPCGUID ControlGuid,TRACEHANDLE TraceHandle);
  EXTERN_C ULONG WMIAPI TraceEvent(TRACEHANDLE TraceHandle,PEVENT_TRACE_HEADER EventTrace);
  EXTERN_C ULONG WMIAPI TraceEventInstance(TRACEHANDLE TraceHandle,PEVENT_INSTANCE_HEADER EventTrace,PEVENT_INSTANCE_INFO pInstInfo,PEVENT_INSTANCE_INFO pParentInstInfo);
  EXTERN_C ULONG WMIAPI RegisterTraceGuidsW(WMIDPREQUEST RequestAddress,PVOID RequestContext,LPCGUID ControlGuid,ULONG GuidCount,PTRACE_GUID_REGISTRATION TraceGuidReg,LPCWSTR MofImagePath,LPCWSTR MofResourceName,PTRACEHANDLE RegistrationHandle);
  EXTERN_C ULONG WMIAPI RegisterTraceGuidsA(WMIDPREQUEST RequestAddress,PVOID RequestContext,LPCGUID ControlGuid,ULONG GuidCount,PTRACE_GUID_REGISTRATION TraceGuidReg,LPCSTR MofImagePath,LPCSTR MofResourceName,PTRACEHANDLE RegistrationHandle);
  EXTERN_C ULONG WMIAPI EnumerateTraceGuids(PTRACE_GUID_PROPERTIES *GuidPropertiesArray,ULONG PropertyArrayCount,PULONG GuidCount);
  EXTERN_C ULONG WMIAPI UnregisterTraceGuids(TRACEHANDLE RegistrationHandle);
  EXTERN_C TRACEHANDLE WMIAPI GetTraceLoggerHandle(PVOID Buffer);
  EXTERN_C UCHAR WMIAPI GetTraceEnableLevel(TRACEHANDLE TraceHandle);
  EXTERN_C ULONG WMIAPI GetTraceEnableFlags(TRACEHANDLE TraceHandle);
  EXTERN_C TRACEHANDLE WMIAPI OpenTraceA(PEVENT_TRACE_LOGFILEA Logfile);
  EXTERN_C TRACEHANDLE WMIAPI OpenTraceW(PEVENT_TRACE_LOGFILEW Logfile);
  EXTERN_C ULONG WMIAPI ProcessTrace(PTRACEHANDLE HandleArray,ULONG HandleCount,LPFILETIME StartTime,LPFILETIME EndTime);
  EXTERN_C ULONG WMIAPI CloseTrace(TRACEHANDLE TraceHandle);
  EXTERN_C ULONG WMIAPI SetTraceCallback(LPCGUID pGuid,PEVENT_CALLBACK EventCallback);
  EXTERN_C ULONG WMIAPI RemoveTraceCallback (LPCGUID pGuid);
  EXTERN_C ULONG __cdecl TraceMessage(TRACEHANDLE LoggerHandle,ULONG MessageFlags,LPGUID MessageGuid,USHORT MessageNumber,...);
  EXTERN_C ULONG TraceMessageVa(TRACEHANDLE LoggerHandle,ULONG MessageFlags,LPGUID MessageGuid,USHORT MessageNumber,va_list MessageArgList);

#ifdef __cplusplus
}
#endif

#if defined(UNICODE) || defined(_UNICODE)
#define RegisterTraceGuids RegisterTraceGuidsW
#define StartTrace StartTraceW
#define ControlTrace ControlTraceW
#ifdef __TRACE_W2K_COMPATIBLE
#define StopTrace(a,b,c) ControlTraceW((a),(b),(c),EVENT_TRACE_CONTROL_STOP)
#define QueryTrace(a,b,c) ControlTraceW((a),(b),(c),EVENT_TRACE_CONTROL_QUERY)
#define UpdateTrace(a,b,c) ControlTraceW((a),(b),(c),EVENT_TRACE_CONTROL_UPDATE)
#else
#define StopTrace StopTraceW
#define QueryTrace QueryTraceW
#define UpdateTrace UpdateTraceW
#endif
#define FlushTrace FlushTraceW
#define QueryAllTraces QueryAllTracesW
#define OpenTrace OpenTraceW
#else
#define RegisterTraceGuids RegisterTraceGuidsA
#define StartTrace StartTraceA
#define ControlTrace ControlTraceA
#ifdef __TRACE_W2K_COMPATIBLE
#define StopTrace(a,b,c) ControlTraceA((a),(b),(c),EVENT_TRACE_CONTROL_STOP)
#define QueryTrace(a,b,c) ControlTraceA((a),(b),(c),EVENT_TRACE_CONTROL_QUERY)
#define UpdateTrace(a,b,c) ControlTraceA((a),(b),(c),EVENT_TRACE_CONTROL_UPDATE)
#else
#define StopTrace StopTraceA
#define QueryTrace QueryTraceA
#define UpdateTrace UpdateTraceA
#endif
#define FlushTrace FlushTraceA
#define QueryAllTraces QueryAllTracesA
#define OpenTrace OpenTraceA
#endif
#endif
#endif
#endif
