#pragma once
#include "public.h"
#define _WIN32_DCOM

#include <iostream>
#include <stdio.h>
#include <comdef.h>
//  Include the task header file.
#include <taskschd.h>
#include <vector>
#include <functional>
#pragma comment(lib, "taskschd.lib")
#pragma comment(lib, "comsupp.lib")

class SchduleTask {
	std::wstring path;
	std::wstring name;
	SYSTEMTIME start_time;
	SYSTEMTIME end_time;
	DWORD count;
	PSYSTEMTIME run_times;
	TASK_STATE taskState;
	IRegisteredTask* _task;
public:
	SchduleTask(IRegisteredTask* task);
};


class SchduleTaskMgr {
	HRESULT hr1;
	HRESULT hr2;
	ITaskFolder* pRootFolder;

public:
	static SchduleTaskMgr* _single;
	static SchduleTaskMgr* GetMgr();
	SchduleTaskMgr();
	SchduleTask& NextTask();
	std::vector<SchduleTask> GetTasks();
	void EnumTasks(std::function<void(SchduleTask*)> callback);
	~SchduleTaskMgr();
};