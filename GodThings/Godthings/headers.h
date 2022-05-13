#pragma once
#ifndef _HEADERS
#define _HEADERS

#include <ntifs.h>
#include <ntddk.h>

#define IOCTL_GTCTL_METHOD_READ_MEMORY \
	CTL_CODE(FILE_DEVICE_UNKNOWN,0x800,METHOD_NEITHER,FILE_ANY_ACCESS)
#define IOCTL_GTCTL_METHOD_WRITE_MEMORY \
	CTL_CODE(FILE_DEVICE_UNKNOWN,0x801,METHOD_NEITHER,FILE_ANY_ACCESS)
#define IOCTL_GTCTL_METHOD_ALLOC_MEMORY \
	CTL_CODE(FILE_DEVICE_UNKNOWN,0x802,METHOD_NEITHER,FILE_ANY_ACCESS)
#define IOCTL_GTCTL_METHOD_FREE_MEMORY \
	CTL_CODE(FILE_DEVICE_UNKNOWN,0x803,METHOD_NEITHER,FILE_ANY_ACCESS)
#define IOCTL_GTCTL_METHOD_OPEN_PROCESS \
	CTL_CODE(FILE_DEVICE_UNKNOWN,0X804,METHOD_NEITHER,FILE_ANY_ACCESS)
#define DEVICE_OBJECT_NAME L"\\Device\\Godthings"
#define DEVICE_LINK_NAME L"\\??\\Godthings"

DRIVER_INITIALIZE DriverEntry;
VOID DriverUnload(PDRIVER_OBJECT DriverObject);
NTSTATUS PassThroughDispatch(PDEVICE_OBJECT DeviceObject, PIRP Irp);
NTSTATUS ControlThroughDispatch(PDEVICE_OBJECT DeviceObject, PIRP Irp);
#ifdef ALLOC_PRAGMA
#pragma alloc_text(INIT,DriverEntry)
#endif // ALLOC_PRAGMA

#endif // !_HEADERS